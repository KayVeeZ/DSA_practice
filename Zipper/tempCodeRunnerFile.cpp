#include <iostream>
#include <fstream>
#include <filesystem>
#include <bitset>
#include <vector>  // Include vector header

namespace fs = std::filesystem;

// Structure for Huffman nodes
struct HuffmanNode {
    char ch;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;
    HuffmanNode(char ch, int freq) : ch(ch), freq(freq), left(nullptr), right(nullptr) {}
};

// Read the Huffman tree during decompression
HuffmanNode* readHuffmanTree(std::ifstream& inputFile) {
    char isLeaf;
    inputFile.get(isLeaf);  // Read if it's a leaf node
    
    if (isLeaf == '1') {
        // If leaf, read the character
        char leafChar;
        inputFile.get(leafChar);
        return new HuffmanNode(leafChar, 0);
    } else {
        // Otherwise, it's an internal node, recursively read children
        HuffmanNode* leftNode = readHuffmanTree(inputFile);
        HuffmanNode* rightNode = readHuffmanTree(inputFile);
        return new HuffmanNode('\0', 0); // Internal nodes have no character
    }
}

// Decompress the bitstream using the Huffman tree
void decodeCompressedData(std::ifstream& inputFile, HuffmanNode* root, const std::string& outputPath, std::streampos fileSize) {
    std::ofstream outputFile(outputPath, std::ios::binary);
    
    HuffmanNode* currentNode = root;
    char byte;
    int bitsProcessed = 0;
    
    while (inputFile.get(byte) && bitsProcessed < fileSize * 8) {
        std::bitset<8> bits(byte);
        for (int i = 0; i < 8 && bitsProcessed < fileSize * 8; ++i) {
            // Traverse the tree based on the bit value
            currentNode = bits.test(i) ? currentNode->right : currentNode->left;
            
            if (!currentNode->left && !currentNode->right) {
                // Leaf node, write the character to output
                outputFile.put(currentNode->ch);
                currentNode = root;  // Go back to the root for the next character
            }
            
            bitsProcessed++;
        }
    }
    
    outputFile.close();
}

// Main function for decompression
void readCompressedFile(const std::string& compressedFilename, const std::string& outputDirectory) {
    std::ifstream inputFile(compressedFilename, std::ios::binary);
    
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open compressed file." << std::endl;
        return;
    }
    
    // Read metadata (e.g., number of files, their paths, and sizes)
    size_t entryCount;
    inputFile.read(reinterpret_cast<char*>(&entryCount), sizeof(entryCount));
    
    std::vector<std::string> filePaths(entryCount);
    std::vector<std::streampos> fileSizes(entryCount);
    
    for (size_t i = 0; i < entryCount; ++i) {
        size_t pathSize;
        inputFile.read(reinterpret_cast<char*>(&pathSize), sizeof(pathSize));
        filePaths[i].resize(pathSize);
        inputFile.read(&filePaths[i][0], pathSize);
        inputFile.read(reinterpret_cast<char*>(&fileSizes[i]), sizeof(fileSizes[i]));
    }
    
    // Rebuild directories
    for (const auto& filePath : filePaths) {
        fs::path fullPath = fs::path(outputDirectory) / filePath;
        if (!fs::exists(fullPath.parent_path())) {
            fs::create_directories(fullPath.parent_path());
        }
    }
    
    // Reconstruct the Huffman tree
    HuffmanNode* root = readHuffmanTree(inputFile);
    
    // Decompress files using the tree
    for (size_t i = 0; i < entryCount; ++i) {
        std::string outputPath = (fs::path(outputDirectory) / filePaths[i]).string();
        decodeCompressedData(inputFile, root, outputPath, fileSizes[i]);
    }
    
    inputFile.close();
}

int main() {
    std::string compressedFilename;
    std::string decompressedDirectory;

    // Decompression
    std::cout << "Enter the path of the compressed file (e.g., compressed.bin): ";
    std::getline(std::cin, compressedFilename);
    
    std::cout << "Enter the directory to decompress into (enter 0 for current directory): ";
    std::getline(std::cin, decompressedDirectory);
    
    if (decompressedDirectory == "0") {
        decompressedDirectory = fs::current_path().string();
    }

    readCompressedFile(compressedFilename, decompressedDirectory);

    return 0;
}
