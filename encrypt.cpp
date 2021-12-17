#include "encrypt.h"
#include <iostream>
#include <fstream>
#include <array>

namespace chiffrement {
    Encrypt::Encrypt(bool pType) : _type(pType)
    {}

    std::string Encrypt::getPlain()
    {
        return _plain;
    }
    std::string Encrypt::getCypher()
    {
        return _cypher;
    }

    void Encrypt::write()
    {
        if(_type)
        {
            std::ofstream fichierEncode("phraseEncode.txt", std::ios::app);
            if (fichierEncode)
                fichierEncode << std::endl << _cypher << std::endl;
            else
                std::cout << "Impossible d'ouvrir le fichier phraseEncode.txt";
        }
        else
        {
            std::ofstream fichierDecode("phraseDecode.txt", std::ios::app);
                if (fichierDecode)
                    fichierDecode << std::endl << _plain << std::endl;
                else
                    std::cout << "Impossible d'ouvrir le fichier phraseDecode.txt";
        }
    }

    void Encrypt::read()
    {
        std::string save;
        if(_type)
        {
            std::ifstream fichierDecode("phraseDecode.txt");
            if (fichierDecode)
            {
                while (getline(fichierDecode, save))
                {
                    _plain += save;
                }
                this->encode();
            }
            else
                std::cout << "Impossible d'ouvrir le fichier phraseDecode.txt";
        }
        else{
            std::ifstream fichierEncode("phraseEncode.txt");
                if (fichierEncode)
                {
                    while (getline(fichierEncode, save))
                    {
                         _cypher += save;
                    }
                    this->decode();
                }
                else
                    std::cout << "Impossible d'ouvrir le fichier phraseEncode.txt";
        }

    }

    Caesar::Caesar(bool pType,int pDecalage) : Encrypt(pType){
        if (pDecalage > 25 || pDecalage < -25)
            pDecalage %= 25;
        decalage = pDecalage;
    }

    void Caesar::encode()
    {
        int index, i;
        _cypher = "";
        for (i = 0; i < _plain.length(); i++)
        {
            index = int(_plain[i]);
            if (index >= 97 && index <= 122)
            {
                index += decalage;
                if (index > 122)
                    index -= 25;
                else
                    if( index < 97)
                        index += 25;
            }
            _cypher += char(index);
        }
    }
    void Caesar::decode()
    {
        int index, i;
        _plain = "";
        for (i = 0; i < _cypher.length(); i++)
        {
            index = int(_plain[i]);
            if (index >= 97 && index <= 122)
            {
                index =- decalage;
                if (index < 97)
                    index += 25;
                else
                    if(index > 122)
                        index -= 25;
            }
            _plain += char(index);
        }
    }

     Caesar2::Caesar2(bool pType,int pDecalage) : Encrypt(pType){
        if (pDecalage > 127 || pDecalage < -127)
            pDecalage %= 127;
        decalage = pDecalage;
    }

    void Caesar2::encode()
    {
        int index, i;
        _cypher = "";
        for (i = 0; i < _plain.length(); i++)
        {
            index = int(_plain[i]);
            index += decalage;
            if (index > 127)
                index -= 127;
            else
                if( index < 0)
                    index += 127;
            _cypher += char(index);
        }
    }

    void Caesar2::decode()
    {
        int index, i;
        _plain = "";
        for (i = 0; i < _cypher.length(); i++)
        {
            index = int(_cypher[i]);
            index -= decalage;
                if (index < 0)
                    index += 127;
                else
                    if(index > 127)
                        index -= 127;
            _plain += char(index);
        }
    }

   Vigenere::Vigenere(bool pType) : Encrypt(pType){
       for (auto i =0; i<4 ;i++)
       {
           std::cout << i << "ème élément de la clé de chiffrement" << std::endl;
           std::cin >> _cleChiffrement.at(i);
       }
   }

   void Vigenere::encode()
   {
       int index, i;
       auto it = _cleChiffrement.begin();
       _cypher = "";
       for (i = 0; i < _plain.length(); i++)
       {
           index = int(_plain[i]);
           index += *it;
           if (index > 127)
               index -= 127;
           else
               if( index < 0)
                   index += 127;
           it++;
           if(it==_cleChiffrement.end())
               it = _cleChiffrement.begin();
           _cypher += char(index);
       }
   }

   void Vigenere::decode()
   {
       int index, i;
       auto it = _cleChiffrement.begin();
       _plain = "";
       for (i = 0; i < _cypher.length(); i++)
       {
           index = int(_cypher[i]);
           index -= *it;
               if (index < 0)
                   index += 127;
               else
                   if(index > 127)
                       index -= 127;
           it++;
           if(it==_cleChiffrement.end())
               it = _cleChiffrement.begin();
           _plain += char(index);
       }
   }
}
