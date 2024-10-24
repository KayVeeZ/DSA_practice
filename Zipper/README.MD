# File Zipper Software

## Overview
This project is a **file and folder compression/decompression tool** implemented in C++ using the **Huffman Coding algorithm**. It allows users to compress a file or an entire folder (including its structure) and later decompress it to restore the original files and folder hierarchy. The compressed data is stored in a single binary file.

## Features
- Compress individual files or entire directories.
- Preserve the folder structure during compression.
- Decompress the compressed file to restore the original files and directories.
- Simple command-line interface to choose between compression and decompression.

## Algorithms & Libraries
- **Huffman Coding Algorithm**: Used to compress file data efficiently.
- **C++ STL**: Includes libraries like `<filesystem>` for handling files and directories.
- **Binary File I/O**: For reading and writing compressed data in binary format.

## Requirements
- C++17 or higher
- A C++ compiler like `g++`

## Installation

1. **Clone the repository**:
   ```bash
   git clone https://github.com/KayVeeZ/DSA_practice/tree/main/Zipper
   cd Zipper

2. **Compile the project**:
   ```bash
   g++ -std=c++17 huffmanZipper.cpp -o huffmanZipper

## Usage
After compiling the code, you can run the program from the terminal to either compress or decompress files/folders.

## Compressing Files or Folders

1. Run the program:
   ```bash
   ./huffmanZipper

2. Enter 1 to compress, then provide the file or folder path when prompted:
   ```vbnet
   Enter 1 to compress, 2 to decompress: 1
   Enter the file or folder path to compress: /path/to/file/or/folder

The program will compress the file/folder into a compressed.bin file.

## Decompressing files

Note: Decompression is not working as of the moment, this will be fixed soon.
1. Run the program:
   ```bash
   ./huffmanZipper

2. Enter 2 to decompress, then provide the path of the compressed file (e.g., compressed.bin) and the output directory::
   ```vbnet
   Enter 1 to compress, 2 to decompress: 2
   Enter the path of the compressed file (e.g., compressed.bin): /path/to/compressed.bin
   Enter the directory to decompress into (enter 0 for current directory): /path/to/output/directory

If you enter 0, the decompressed files will be extracted in the current directory.

## Future Improvements
- Add support for multi-threaded compression.
- Improve the compression ratio with more advanced techniques.
- Add a progress indicator during compression and decompression.

## License
