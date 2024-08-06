#include "novacrypt.hpp"

NovaCrypt::NovaCrypt(int secureKey, int salt)
    : secureKey(secureKey), salt(salt == 0 ? 9 : salt) {}

std::string NovaCrypt::encrypt(const std::string &content)
{
    std::string encrypted_content;
    for (char c : content)
    {
        int genSpecCode = (static_cast<int>(c) + (secureKey * salt) + salt) % 256;
        encrypted_content += static_cast<char>(genSpecCode);
    }
    return encrypted_content;
}

std::string NovaCrypt::decrypt(const std::string &encrypted_content)
{
    std::string decrypted_content;
    for (char c : encrypted_content)
    {
        int decSpecCode = (static_cast<int>(c) - salt - (secureKey * salt)) % 256;
        if (decSpecCode < 0)
        {
            decSpecCode += 256;
        }
        decrypted_content += static_cast<char>(decSpecCode);
    }
    return decrypted_content;
}