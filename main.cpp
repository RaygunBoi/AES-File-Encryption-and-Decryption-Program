#include <iostream>
#include <String>

int main(int argc, char* argv[]) {
    std::string action = argv[1];
    std::string fileName = argv[2];

    if(argc < 4 && action == "encrypt") {
        std::cout << "File has been encrypted!" << std::endl;
    }
    else if(argc < 4 && action == "decrypt") {
        std::cout << "File has been decrypted!" << std::endl;
    }
    else {
        std::cout << "Invalid command! Please enter a valid one." << std::endl;
    }

    return 0;
}