#include <string>
#include <array>
#ifndef ENCRYPT_H
#define ENCRYPT_H
namespace chiffrement {
    class Encrypt
    {
    protected:
        std::string _plain, _cypher;
        bool _type;
    public:
        Encrypt(bool pType);
        std::string getPlain();
        std::string getCypher();
        virtual void encode() = 0;
        virtual void decode() = 0;
        void read();
        void write();
    };

    class Caesar : public Encrypt
    {
    private :
        int decalage;
    public :
        Caesar(bool pType, int pDecalage);
        void encode(); //override;
        void decode(); //override;
    };

    class Caesar2 : public Encrypt
    {
    private :
        int decalage;
    public :
        Caesar2(bool pType ,int pDecalage);
        void encode(); //override;
        void decode(); //override;
    };

    class Vigenere : public Encrypt
    {
    private :
        std::array<int,4> _cleChiffrement;
    public :
        Vigenere(bool pType);
        void encode(); //override;
        void decode(); //override;
    };
}

#endif

