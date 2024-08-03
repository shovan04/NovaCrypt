#ifndef NOVACRYPT_HPP
#define NOVACRYPT_HPP

#include <string>

class NovaCrypt {
public:
    NovaCrypt(int secureKey, int salt = 0);

    std::string encrypt(const std::string& text);
    // Optionally, you can add a decrypt method
    std::string decrypt(const std::string& text);

private:
    int secureKey;
    int salt;
};

#endif // NOVACRYPT_HPP
