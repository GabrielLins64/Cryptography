#include <Cryptographer.hpp>

std::string Cryptographer::EncryptMessage(const std::string message, 
                                          ECIES<ECP>::Encryptor publicKey, 
                                          AutoSeededRandomPool& prng)
{
    std::string em;
    StringSource ss (message, true, new PK_EncryptorFilter(prng, publicKey, new StringSink(em)));
    return em;
}

std::string Cryptographer::DecryptMessage(const std::string cypher, 
                                          ECIES<ECP>::Decryptor privateKey, 
                                          AutoSeededRandomPool& prng)
{
    std::string dm;
    StringSource ss (cypher, true, new PK_DecryptorFilter(prng, privateKey, new StringSink(dm)));
    return dm;
}
