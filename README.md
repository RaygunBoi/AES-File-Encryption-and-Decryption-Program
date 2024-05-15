## Introduction	
> This program utilizes two different algorithms to encrypt and decrypt a simple text file: the Vigenere Cipher and the Columnar Transitional Cipher. Both algorithms were programmed entirely in C++, and an example file called `example.txt` is provided to test them both.

## How To Use
- Make sure you have the g++ (or gcc) compiler installed.
- Clone the repository, open command prompt, and navigate to the directory: `cd Vigenere-and-Columnar-Transposition-Encryption-and-Decryption`
- To run the program, enter the following command: `g++ main.cpp -o main`
- After running the command, an executable called `main.exe` will be created in the repo. To run the encryption and decryption for the Vigenere Cipher, run the following commands respectively: `./main vigenere encrypt example.txt` and `./main vigenere decrypt encrypted-file.txt`. Make sure you run the encryption command first before running the decryption command.
- To run the encryption and decryption for the Columnar Transposition Cipher, run the following commands respectively: `./main transposition encrypt example.txt` and `./main transposition decrypt encrypted-file.txt`. Make sure you run the encryption command first before running the decryption command.