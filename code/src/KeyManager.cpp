#include <KeyManager.hpp>

void KeyManager::PrintPrivateKey(const DL_PrivateKey_EC<ECP>& key, std::ostream& out)
{
    out << "------------ X ------------ X ------------ X ------------" << std::endl;
    out << "Chave Privada:" << std::endl;

    const std::ios_base::fmtflags flags = out.flags();
    const DL_GroupParameters_EC<ECP>& params = key.GetGroupParameters();
    const DL_FixedBasePrecomputation<ECPPoint>& bpc = params.GetBasePrecomputation();
    const ECPPoint point = bpc.Exponentiate(params.GetGroupPrecomputation(), key.GetPrivateExponent());

    out << "Módulo (p): " << std::hex << params.GetCurve().GetField().GetModulus() << std::endl;
    out << "Cofator (h): " << std::hex << params.GetCofactor() << std::endl;
    out << "Coeficientes da curva:" << std::endl;
    out << "  -> a: " << std::hex << params.GetCurve().GetA() << std::endl;
    out << "  -> b: " << std::hex << params.GetCurve().GetB() << std::endl;
    out << "Ponto base/gerador (G)" << std::endl;
    out << "  x: " << std::hex << params.GetSubgroupGenerator().x << std::endl;
    out << "  y: " << std::hex << params.GetSubgroupGenerator().y << std::endl;
    out << "Ponto - Chave pública (Q)" << std::endl;
    out << "  x: " << std::hex << point.x << std::endl;
    out << "  y: " << std::hex << point.y << std::endl;
    out << "Multiplicando - Chave privada (d): " << std::endl;
    out << "  d: " << std::hex << key.GetPrivateExponent() << std::endl;

    out << std::endl;
    out.flags(flags);
}

void KeyManager::PrintPublicKey(const DL_PublicKey_EC<ECP>& key, std::ostream& out)
{
    out << "------------ X ------------ X ------------ X ------------" << std::endl;
    out << "Chave Pública:" << std::endl;

    const std::ios_base::fmtflags flags = out.flags();

    const DL_GroupParameters_EC<ECP>& params = key.GetGroupParameters();
    const ECPPoint& point = key.GetPublicElement();
    
    out << "Modulus: " << std::hex << params.GetCurve().GetField().GetModulus() << std::endl;
    out << "Cofactor: " << std::hex << params.GetCofactor() << std::endl;
    out << "Coefficients" << std::endl;
    out << "  A: " << std::hex << params.GetCurve().GetA() << std::endl;
    out << "  B: " << std::hex << params.GetCurve().GetB() << std::endl;
    out << "Base Point" << std::endl;
    out << "  x: " << std::hex << params.GetSubgroupGenerator().x << std::endl;
    out << "  y: " << std::hex << params.GetSubgroupGenerator().y << std::endl;
    out << "Public Point" << std::endl;
    out << "  x: " << std::hex << point.x << std::endl;
    out << "  y: " << std::hex << point.y << std::endl;

    out << std::endl;
    out.flags(flags);
}

void KeyManager::SavePrivateKey(const PrivateKey& key, const std::string& file)
{
    
}

void KeyManager::SavePublicKey(const PublicKey& key, const std::string& file)
{
    
}

void KeyManager::LoadPrivateKey(PrivateKey& key, const std::string& file)
{
    
}
void KeyManager::LoadPublicKey(PublicKey& key, const std::string& file)
{
    
}
