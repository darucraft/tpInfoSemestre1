#include <string>
#include <vector>
#ifndef ENCRYPT_H
#define ENCRYPT_H
namespace chiffrement {
    template <class typeCle>
    class Encrypt
    {
    protected:
        std::string _plain, _cypher;
        bool _type;
    public:
        Encrypt(bool pType);
        virtual void encode() = 0;
        virtual void decode() = 0;
        void read();
        void write(const typeCle pCleChiffrement);
    };


    class Caesar : public Encrypt<int>
    {
    private :
        int _decalage;
    public :
        Caesar(bool pType);
        void encode() override;
        void decode() override;
    };


    class Caesar2 : public Encrypt<int>
    {
    private :
        int _decalage;
    public :
        Caesar2(bool pType);
        void encode() override;
        void decode() override;
    };


    class Vigenere : public Encrypt<std::string>
    {
    private :
        std::vector<int> _cleChiffrement;
        std::string _cleFormeChaineCaracteres;

    public :
        Vigenere(bool pType);
        void encode() override;
        void decode() override;
    };
	
	int saisieDecalage();
}

#endif

