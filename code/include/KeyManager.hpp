#pragma once

#include <iostream>
#include <string>
#include <cryptopp/files.h>
#include <cryptopp/hex.h>
#include <cryptopp/filters.h>
#include <cryptopp/osrng.h>
#include <cryptopp/integer.h>
#include <cryptopp/pubkey.h>
#include <cryptopp/eccrypto.h>
#include <cryptopp/pubkey.h>
#include <cryptopp/asn.h>
#include <cryptopp/oids.h>
#include <cryptopp/cryptlib.h>

using namespace CryptoPP;

class KeyManager
{
public:

    void PrintPrivateKey(const DL_PrivateKey_EC<ECP>& key, std::ostream& out = std::cout);
    void PrintPublicKey(const DL_PublicKey_EC<ECP>& key, std::ostream& out = std::cout);
    void SavePrivateKey(const PrivateKey& key, const std::string& file = "res/ecies.private.key");
    void SavePublicKey(const PublicKey& key, const std::string& file = "res/ecies.public.key");
    void LoadPrivateKey(PrivateKey& key, const std::string& file = "res/ecies.private.key");
    void LoadPublicKey(PublicKey& key, const std::string& file = "res/ecies.public.key");
};
