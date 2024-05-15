#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string vigenereEncrypt(const string& plaintext, const string& keyword) {
    string ciphertext = "";
    int keyIndex = 0;

    for (char plainChar : plaintext) {
        if (isalpha(plainChar)) {
            char base = isupper(plainChar) ? 'A' : 'a';
            char cipherChar = (plainChar + keyword[keyIndex] - 2 * base) % 26 + base;
            ciphertext += cipherChar;
            keyIndex = (keyIndex + 1) % keyword.length();
        } else {
            ciphertext += plainChar; // Non-alphabetic characters remain unchanged
        }
    }

    return ciphertext;
}

string vigenereDecrypt(const string& ciphertext, const string& keyword) {
    string plaintext = "";
    int keyIndex = 0;

    for (char cipherChar : ciphertext) {
        if (isalpha(cipherChar)) {
            char base = isupper(cipherChar) ? 'A' : 'a';
            char plainChar = (cipherChar - keyword[keyIndex] + 26) % 26 + base;
            plaintext += plainChar;
            keyIndex = (keyIndex + 1) % keyword.length();
        } else {
            plaintext += cipherChar; // Preserve non-alphabetic characters unchanged
        }
    }

    return plaintext;
}

int main(int argc, char* argv[]) {
    const string type = argv[1];
    const string action = argv[2];
    const string fileName = argv[3];
    const string key = "key";

    // ./main vigenere encrypt example.txt
    if(argc < 5 && type == "vigenere" && action == "encrypt") {
        ifstream inputFile(fileName);
        ofstream outputFile("encrypted-file.txt");

        string line;
        while(getline(inputFile, line)){
            outputFile << vigenereEncrypt(line, key) << endl;
        }

        std::cout << "File has been encrypted! Please check the encrypted-file.txt file in the program." << endl;
    }
    // ./main vigenere decrypt encrypted-file.txt
    else if(argc < 5 && type == "vigenere" && action == "decrypt") {
        ifstream inputFile("encrypted-file.txt");
        ofstream outputFile("decrypted-file.txt");

        string line;
        while(getline(inputFile, line)){
            outputFile << vigenereDecrypt(line, key) << endl;
        }

        std::cout << "File has been decrypted! Please check the decrypted-file.txt file in the program." << endl;
    }
    else {
        std::cout << "Invalid command! Please enter a valid one." << endl;
    }

    return 0;
}