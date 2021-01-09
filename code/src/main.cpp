#include <Cryptographer.hpp>

int main()
{
    AutoSeededRandomPool prng;
    KeyManager* km = new KeyManager();
    Cryptographer* cryp = new Cryptographer();

    static const std::string msg = "Teste. Lorem ipsum blablabla. Não! Sím? @$";

    ECIES<ECP>::Decryptor alicePrivateKey(prng, ASN1::secp256r1());
    ECIES<ECP>::Encryptor alicePublicKey(alicePrivateKey);

    km->PrintPrivateKey(alicePrivateKey.GetKey());
    km->PrintPublicKey(alicePublicKey.GetKey());

    std::string cipherText = cryp->EncryptMessage(msg, alicePublicKey, prng);
    std::string decryptedText = cryp->DecryptMessage(cipherText, alicePrivateKey, prng);

    std::cout << "------------ X ------------ X ------------ X ------------" << std::endl;
    std::cout << "Original message (" << msg.size() << "):" << std::endl << "  ";
    std::cout << msg << std::endl;
    std::cout << "Ciphertext (" << cipherText.size() << "):" << std::endl << "  ";
    std::cout << cipherText << std::endl;
    std::cout << "Recovered (" << decryptedText.size() << "):" << std::endl << "  ";
    std::cout << decryptedText << std::endl;

    delete(km);
    delete(cryp);

    return 0;
}
