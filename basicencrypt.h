#include <string>
#ifndef BASICENCRYPT_H
#define BASICENCRYPT_H
namespace chiffrement {
    class BasicEncrypt
    {
    protected:
        std::string _plain, _cypher;
    public:
        std::string getPlain();
        std::string getCypher();
        void encode();
        void decode();
        void read();
        void write(std::string message);
    };
}

#endif
