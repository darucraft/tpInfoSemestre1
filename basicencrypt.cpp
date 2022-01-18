#include "basicencrypt.h"
#include <iostream>

namespace chiffrement {
	#accesseur de la variable _plain
    std::string BasicEncrypt::getPlain()
    {
        return _plain;
    }
	#accesseur de la variable _cypher
    std::string BasicEncrypt::getCypher()
    {
        return _cypher;
    }
	#methode permettant d'encoder le texte de la variable _plain
    void BasicEncrypt::encode()
    {
        _cypher = _plain;
    }
	#methode permettant de decoder le texte de la variable _cypher
    void BasicEncrypt::decode()
    {
        _plain = _cypher;
    }
	#setter de la variable _plain
    void BasicEncrypt::write(std::string message)
    {
        _plain = message;
    }
}
