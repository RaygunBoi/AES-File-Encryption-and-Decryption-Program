#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

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
            ciphertext += plainChar;
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
            plaintext += cipherChar;
        }
    }

    return plaintext;
}

string cTEncrypt(const string& plaintext, const string& keyword) {
    int keywordLength = keyword.length();
    vector<string> columns(keywordLength);

    for (int i = 0; i < plaintext.length(); ++i) {
        columns[i % keywordLength] += plaintext[i];
    }

    string sortedKeyword = keyword;
    sort(sortedKeyword.begin(), sortedKeyword.end());
    string ciphertext;
    for (char c : sortedKeyword) {
        int index = keyword.find(c);
        ciphertext += columns[index];
    }

    return ciphertext;
}

string cTDecrypt(const string& ciphertext, const string& keyword) {
    int keywordLength = keyword.length();
    int columnLength = ciphertext.length() / keywordLength;
    vector<string> columns(keywordLength);

    string ciphertextCopy = ciphertext;

    int incompleteColumns = ciphertext.length() % keywordLength;

    int idx = 0;
    for (char c : keyword) {
        int count = columnLength;
        if (idx < incompleteColumns) {
            count++;
        }
        columns[idx++] = ciphertextCopy.substr(0, count);
        ciphertextCopy.erase(0, count);
    }

    string plaintext;
    for (int i = 0; i < columnLength + (incompleteColumns > 0 ? 1 : 0); ++i) {
        for (const string& column : columns) {
            if (i < column.length()) {
                plaintext += column[i];
            }
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

        cout << "File has been encrypted! Please check the encrypted-file.txt file in the program." << endl;
    }
    // ./main vigenere decrypt encrypted-file.txt
    else if(argc < 5 && type == "vigenere" && action == "decrypt") {
        ifstream inputFile("encrypted-file.txt");
        ofstream outputFile("decrypted-file.txt");

        string line;
        while(getline(inputFile, line)){
            outputFile << vigenereDecrypt(line, key) << endl;
        }

        cout << "File has been decrypted! Please check the decrypted-file.txt file in the program." << endl;
    }
    // ./main transposition encrypt example.txt
    else if(argc < 5 && type == "transposition" && action == "encrypt") {
        ifstream inputFile(fileName);
        ofstream outputFile("encrypted-file.txt");

        string line;
        while(getline(inputFile, line)){
            outputFile << cTEncrypt(line, key) << endl;
        }

        cout << "File has been encrypted! Please check the encrypted-file.txt file in the program." << endl;
    }
    // ./main transposition decrypt encrypted-file.txt
    else if(argc < 5 && type == "transposition" && action == "decrypt") {
        ifstream inputFile("encrypted-file.txt");
        ofstream outputFile("decrypted-file.txt");

        string line;
        while(getline(inputFile, line)){
            outputFile << cTDecrypt(line, key) << endl;
        }

        cout << "File has been decrypted! Please check the decrypted-file.txt file in the program." << endl;
    }
    else {
        cout << "Invalid command! Please enter a valid one." << endl;
    }

    return 0;
}