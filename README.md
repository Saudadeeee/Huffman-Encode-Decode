# Huffman Encode/Decode

## Overview

This project implements the Huffman encoding and decoding algorithm in C++. Huffman coding is a widely used method of lossless data compression. The algorithm assigns variable-length codes to input characters, with shorter codes assigned to more frequent characters, thereby reducing the overall size of the data.

## Features

- **Encoding**: Compresses input data using Huffman coding.
- **Decoding**: Decompresses the encoded data back to its original form.
- **Custom Input**: Accepts any text input for encoding and decoding.
- **File I/O**: Can read from and write to files for both encoding and decoding.

## How It Works

### Encoding

1. **Frequency Calculation**: The program calculates the frequency of each character in the input.
2. **Tree Construction**: A binary tree is built based on the frequencies, with more frequent characters closer to the root.
3. **Code Generation**: Each character is assigned a binary code based on its position in the tree.
4. **Encoding**: The input data is encoded into a binary string using the generated codes.

### Decoding

1. **Tree Reconstruction**: The binary tree is reconstructed from the encoded data.
2. **Decoding**: The encoded data is traversed using the tree to retrieve the original characters.

## Installation

To use this project, clone the repository and compile the code with a C++ compiler.

```bash
git clone https://github.com/Saudadeeee/Huffman-Encode-Decode.git
cd Huffman-Encode-Decode
g++ -o huffman main.cpp
