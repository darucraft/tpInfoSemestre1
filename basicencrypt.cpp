#include "basicencrypt.h"
#include <iostream>

namespace chiffrement {
    std::string BasicEncrypt::getPlain()
    {
        return _plain;
    }
    std::string BasicEncrypt::getCypher()
    {
        return _cypher;
    }
    void BasicEncrypt::encode()
    {
        _cypher = _plain;
    }
    void BasicEncrypt::decode()
    {
        _plain = _cypher;
    }
    void BasicEncrypt::write(std::string message)
    {
        _plain = message;
    }
}
