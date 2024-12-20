#include "md5.hpp"

int main() {
    int choice;
    std::cout << "Choose an option:\n1. Hash a string\n2. Hash a file\nEnter your choice: ";
    std::cin >> choice;
    std::cin.ignore();

    if (choice == 1) {
        std::string input;
        std::cout << "Enter a string to hash: ";
        std::getline(std::cin, input);

        std::string hash = md5(input);
        std::cout << "MD5 hash: " << hash << std::endl;

    } else if (choice == 2) {
        std::string filename;
        std::cout << "Enter the file name: ";
        std::getline(std::cin, filename);

        try {
            std::string hash = md5FromFile(filename);
            std::cout << "MD5 hash of the file: " << hash << std::endl;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

    } else {
        std::cout << "Invalid choice." << std::endl;
    }

    return 0;
}