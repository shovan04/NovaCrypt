#include "novacrypt.hpp"

NovaCrypt::NovaCrypt(int secureKey, int salt)
    : secureKey(secureKey), salt(salt == 0 ? 9 : salt) {}

std::string NovaCrypt::encrypt(const std::string &text)
{
    std::string encryptedString;
    for (char c : text)
    {
        int genSpecCode = ((static_cast<int>(c) + (secureKey * salt)) + salt);
        encryptedString += static_cast<char>(genSpecCode%256);
    }
    return encryptedString;
}

std::string NovaCrypt::decrypt(const std::string &text)
{
    std::string deCryptedString;

    for (char c : text)
    {
        deCryptedString += ((static_cast<int>(c) - salt) - (secureKey * salt));
    }
    return deCryptedString;
}