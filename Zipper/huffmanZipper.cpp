#include <iostream>
#include <fstream>
#include <filesystem>
#include <unordered_map>
#include <vector>
#include <string>
#include <bitset>
#include <queue>

namespace fs = std::filesystem;

struct FileMetadata {
    std::string relativePath;
    std::streampos size;
    bool isDirectory;
};

struct HuffmanNode {
    char ch;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;
    HuffmanNode(char ch, int freq) : ch(ch), freq(freq), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(HuffmanNode* l, HuffmanNode* r) {
        return l->freq > r->freq;
    }
};

void collectFilesAndDirectories(const std::string& directory, std::vector<FileMetadata>& entries, const std::string& baseDirectory) {
    for (const auto& entry : fs::recursive_directory_iterator(directory)) {
        FileMetadata metadata;
        metadata.relativePath = fs::relative(entry.path(), baseDirectory).string();
        metadata.isDirectory = fs::is_directory(entry.path());
        metadata.size = metadata.isDirectory ? 0 : fs::file_size(entry.path());
        entries.push_back(metadata);
    }
}

std::unordered_map<char, int> countFrequencies(const std::string& filename) {
    std::unordered_map<char, int> frequencies;
    std::ifstream file(filename, std::ios::binary);
    char ch;
    while (file.get(ch)) {
        frequencies[ch]++;
    }
    file.close();
    return frequencies;
}

HuffmanNode* buildHuffmanTree(const std::unordered_map<char, int>& frequencies) {
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, Compare> minHeap;
    
    for (const auto& pair : frequencies) {
        minHeap.push(new HuffmanNode(pair.first, pair.second));
    }

    while (minHeap.size() > 1) {
        HuffmanNode* left = minHeap.top();
        minHeap.pop();
        HuffmanNode* right = minHeap.top();
        minHeap.pop();
        
        HuffmanNode* merged = new HuffmanNode('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        minHeap.push(merged);
    }

    return minHeap.top();
}

void generateHuffmanCodes(HuffmanNode* root, std::string str, std::unordered_map<char, std::string>& huffmanCodes) {
    if (!root) return;
    
    if (!root->left && !root->right) {
        huffmanCodes[root->ch] = str;
    }
    
    generateHuffmanCodes(root->left, str + "0", huffmanCodes);
    generateHuffmanCodes(root->right, str + "1", huffmanCodes);
}

std::unordered_map<char, std::string> getHuffmanCodes(HuffmanNode* root) {
    std::unordered_map<char, std::string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);
    return huffmanCodes;
}

std::string encodeFile(const std::string& filename, const std::unordered_map<char, std::string>& huffmanCodes) {
    std::ifstream file(filename, std::ios::binary);
    std::string encodedContent;
    char ch;
    while (file.get(ch)) {
        encodedContent += huffmanCodes.at(ch);
    }
    file.close();
    return encodedContent;
}

void writeCompressedFile(const std::string& outputFilename, const std::vector<FileMetadata>& entries, const std::unordered_map<std::string, std::unordered_map<char, std::string>>& fileHuffmanCodes) {
    std::ofstream outputFile(outputFilename, std::ios::binary);
    
    // Writing number of entries (files + directories)
    size_t entryCount = entries.size();
    outputFile.write(reinterpret_cast<const char*>(&entryCount), sizeof(entryCount));
    
    // Writing metadata
    for (const auto& entry : entries) {
        size_t pathSize = entry.relativePath.size();
        outputFile.write(reinterpret_cast<const char*>(&pathSize), sizeof(pathSize));
        outputFile.write(entry.relativePath.c_str(), pathSize);
        outputFile.write(reinterpret_cast<const char*>(&entry.size), sizeof(entry.size));
        outputFile.write(reinterpret_cast<const char*>(&entry.isDirectory), sizeof(entry.isDirectory));
    }
    
    // Writing compressed files
    for (const auto& entry : entries) {
        if (!entry.isDirectory) {
            std::ifstream inputFile(entry.relativePath, std::ios::binary);
            const auto& huffmanCodes = fileHuffmanCodes.at(entry.relativePath);
            std::string encodedContent;
            char ch;
            while (inputFile.get(ch)) {
                encodedContent += huffmanCodes.at(ch);
            }
            inputFile.close();

            std::bitset<8> bits;
            int bitIndex = 0;
            for (char bit : encodedContent) {
                if (bit == '1') {
                    bits.set(bitIndex);
                }
                bitIndex++;
                if (bitIndex == 8) {
                    outputFile.put(static_cast<unsigned char>(bits.to_ulong()));
                    bits.reset();
                    bitIndex = 0;
                }
            }
            if (bitIndex > 0) {
                outputFile.put(static_cast<unsigned char>(bits.to_ulong()));
            }
        }
    }
    
    outputFile.close();
}

HuffmanNode* readHuffmanTree(std::ifstream& inputFile) {
    char ch = inputFile.get();
    if (ch == 1) {
        char leaf = inputFile.get();
        return new HuffmanNode(leaf, 0);
    } else {
        HuffmanNode* left = readHuffmanTree(inputFile);
        HuffmanNode* right = readHuffmanTree(inputFile);
        HuffmanNode* node = new HuffmanNode('\0', 0);
        node->left = left;
        node->right = right;
        return node;
    }
}

void readCompressedFile(const std::string& compressedFilename, const std::string& outputDirectory) {
    std::ifstream inputFile(compressedFilename, std::ios::binary);
    
    // Reading number of entries
    size_t entryCount;
    inputFile.read(reinterpret_cast<char*>(&entryCount), sizeof(entryCount));
    
    // Reading metadata
    std::vector<FileMetadata> entries(entryCount);
    for (auto& entry : entries) {
        size_t pathSize;
        inputFile.read(reinterpret_cast<char*>(&pathSize), sizeof(pathSize));
        entry.relativePath.resize(pathSize);
        inputFile.read(&entry.relativePath[0], pathSize);
        inputFile.read(reinterpret_cast<char*>(&entry.size), sizeof(entry.size));
        inputFile.read(reinterpret_cast<char*>(&entry.isDirectory), sizeof(entry.isDirectory));
    }
    
    // Recreating directory structure
    for (const auto& entry : entries) {
        if (entry.isDirectory) {
            fs::create_directories(fs::path(outputDirectory) / entry.relativePath);
        }
    }
    
    // Reading and decompressing files
    for (const auto& entry : entries) {
        if (!entry.isDirectory) {
            HuffmanNode* root = readHuffmanTree(inputFile);
            
            std::ofstream outputFile(fs::path(outputDirectory) / entry.relativePath, std::ios::binary);
            HuffmanNode* currentNode = root;
            char byte;
            while (inputFile.get(byte)) {
                std::bitset<8> bits(static_cast<unsigned char>(byte));
                for (int i = 0; i < 8; ++i) {
                    if (bits.test(i)) {
                        currentNode = currentNode->right;
                    } else {
                        currentNode = currentNode->left;
                    }
                    if (!currentNode->left && !currentNode->right) {
                        outputFile.put(currentNode->ch);
                        currentNode = root;
                    }
                }
            }
            
            outputFile.close();
        }
    }
    
    inputFile.close();
}

int main() {
    int choice;
    std::string inputPath;
    std::string compressedFilename = "compressed.bin";
    std::string decompressedDirectory;

    // Ask the user whether they want to compress or decompress
    std::cout << "Enter 1 to compress, 2 to decompress: ";
    std::cin >> choice;
    std::cin.ignore(); // To clear the newline character from the buffer

    if (choice == 1) {
        // Compression
        std::cout << "Enter the file or folder path to compress: ";
        std::getline(std::cin, inputPath);

        // Determine if input is file or directory
        if (fs::is_directory(inputPath)) {
            std::vector<FileMetadata> entries;
            collectFilesAndDirectories(inputPath, entries, inputPath);
            
            std::unordered_map<std::string, std::unordered_map<char, int>> allFrequencies;
            for (const auto& entry : entries) {
                if (!entry.isDirectory) {
                    allFrequencies[entry.relativePath] = countFrequencies(entry.relativePath);
                }
            }
            
            std::unordered_map<std::string, HuffmanNode*> allRoots;
            for (const auto& pair : allFrequencies) {
                allRoots[pair.first] = buildHuffmanTree(pair.second);
            }
            
            std::unordered_map<std::string, std::unordered_map<char, std::string>> allHuffmanCodes;
            for (const auto& pair : allRoots) {
                allHuffmanCodes[pair.first] = getHuffmanCodes(pair.second);
            }
            
            writeCompressedFile(compressedFilename, entries, allHuffmanCodes);
        } else if (fs::is_regular_file(inputPath)) {
            std::vector<FileMetadata> entries;
            entries.push_back({fs::relative(inputPath).string(), fs::file_size(inputPath), false});
            
            std::unordered_map<std::string, std::unordered_map<char, int>> allFrequencies;
            allFrequencies[entries[0].relativePath] = countFrequencies(inputPath);
            
            HuffmanNode* root = buildHuffmanTree(allFrequencies[entries[0].relativePath]);
            
            std::unordered_map<std::string, std::unordered_map<char, std::string>> allHuffmanCodes;
            allHuffmanCodes[entries[0].relativePath] = getHuffmanCodes(root);
            
            writeCompressedFile(compressedFilename, entries, allHuffmanCodes);
        } else {
            std::cerr << "Invalid path. Please enter a valid file or directory path." << std::endl;
            return 1;
        }

    } else if (choice == 2) {
        // Decompression
        std::cout << "Enter the path of the compressed file (e.g., compressed.bin): ";
        std::getline(std::cin, compressedFilename);
        
        std::cout << "Enter the directory to decompress into (enter 0 for current directory): ";
        std::getline(std::cin, decompressedDirectory);
        
        if (decompressedDirectory == "0") {
            decompressedDirectory = fs::current_path().string();
        }

        readCompressedFile(compressedFilename, decompressedDirectory);
    } else {
        std::cerr << "Invalid choice. Please enter 1 to compress or 2 to decompress." << std::endl;
        return 1;
    }

    return 0;
}