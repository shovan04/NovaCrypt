#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
#include "novacrypt.hpp"

void novaCryptInit(std::string text, int SECURE_KEY, int SALT, int MODE, std::vector<std::string> filePaths = {});
std::string getFileContent(const std::string &filePath);
void saveFileContent(const std::string &filePath, const std::string &content);

int main()
{
    std::string textContent;
    int SECURE_KEY = 0, MODE = 0, SALT = 0;
    std::vector<std::string> filePaths(2);

    do
    {
        std::cout << "To Encrypt & Decrypt Data Choose the Mode for Example: (1)Encryption (2)Decryption (31)Encrypt File (32)Decrypt File \n";
        std::cout << "Enter MODE (1/2/31/32) : ";
        std::cin >> MODE;
        std::cout << "Enter SECURE_KEY(int) : ";
        std::cin >> SECURE_KEY;
        std::cout << "Enter SALT(int) : ";
        std::cin >> SALT;
        std::cout << std::endl;
    } while (SECURE_KEY == 0 && MODE == 0 && SALT == 0);

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (MODE == 1 || MODE == 2)
    {
        std::cout << "Enter the content: ";
        std::getline(std::cin, textContent);
    }
    else if (MODE == 31 || MODE == 32)
    {
        std::cout << "Enter File Path for Encryption (Source): ";
        std::getline(std::cin, filePaths[0]);
        std::cout << "Enter File Path for Decryption (Destination): ";
        std::getline(std::cin, filePaths[1]);
    }

    std::cout << std::endl;
    novaCryptInit(textContent, SECURE_KEY, SALT, MODE, filePaths);

    return 0;
}

void novaCryptInit(std::string text, int SECURE_KEY, int SALT, int MODE, std::vector<std::string> filePaths)
{
    // Initialize NovaCrypt with provided text, SECURE_KEY, SALT, and MODE
    NovaCrypt cryption(SECURE_KEY, SALT);

    if (MODE == 1)
    {
        std::string encrypted = cryption.encrypt(text);
        std::cout << "Encrypted Data: " << encrypted << std::endl;
    }
    else if (MODE == 2)
    {
        std::string decrypted = cryption.decrypt(text);
        std::cout << "Decrypted Data: " << decrypted << std::endl;
    }
    else if (MODE == 31)
    {
        std::string fileContents = getFileContent(filePaths[0]);
        std::string encryptedData = cryption.encrypt(fileContents);
        saveFileContent(filePaths[1], encryptedData);
        std::cout << "Encrypted data saved to: " << filePaths[1] << std::endl;
    }
    else if (MODE == 32)
    {
        std::string fileContents = getFileContent(filePaths[0]);
        std::string decryptedData = cryption.decrypt(fileContents);
        saveFileContent(filePaths[1], decryptedData);
        std::cout << "Decrypted data saved to: " << filePaths[1] << std::endl;
    }
}

std::string getFileContent(const std::string &filePath)
{
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        std::cerr << "Could not open the file: " << filePath << std::endl;
        exit(1);
    }

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    return content;
}

void saveFileContent(const std::string &filePath, const std::string &content)
{
    std::ofstream file(filePath);
    if (!file.is_open())
    {
        std::cerr << "Could not open the file: " << filePath << std::endl;
        exit(1);
    }

    file << content;
    file.close();
}
