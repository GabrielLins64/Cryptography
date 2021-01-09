#pragma once

#include <KeyManager.hpp>

class Cryptographer
{
public:

    Cryptographer() {}
    ~Cryptographer() {}

    std::string EncryptMessage(const std::string message, 
                               ECIES<ECP>::Encryptor publicKey, 
                               AutoSeededRandomPool& prng);
    std::string DecryptMessage(const std::string cypher, 
                               ECIES<ECP>::Decryptor privateKey, 
                               AutoSeededRandomPool& prng);
};
