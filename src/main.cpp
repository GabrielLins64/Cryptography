#include <Cryptographer.hpp>
#include <FileManagement.hpp>

int main()
{
    AutoSeededRandomPool prng;
    KeyManager* km = new KeyManager();
    Cryptographer* cryp = new Cryptographer();

    static const std::string msg(ReadFromFile("res/message"));

    ECIES<ECP>::Decryptor alicePrivateKey(prng, ASN1::secp256r1());
    ECIES<ECP>::Encryptor alicePublicKey(alicePrivateKey);

    km->PrintKey(alicePrivateKey.GetKey());
    km->PrintKey(alicePublicKey.GetKey());

    std::string cipherText = cryp->EncryptMessage(msg, alicePublicKey, prng);
    std::string decryptedText = cryp->DecryptMessage(cipherText, alicePrivateKey, prng);

    WriteToFile("res/ciphertext", cipherText);
    WriteToFile("res/decrypted", decryptedText);

    km->SavePrivateKey(alicePrivateKey.GetPrivateKey());
    km->SavePublicKey(alicePublicKey.GetPublicKey());

    delete(km);
    delete(cryp);

    return 0;
}
