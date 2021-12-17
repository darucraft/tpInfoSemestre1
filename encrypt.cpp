#include "encrypt.h"
#include <iostream>
#include <fstream>
#include <array>

namespace chiffrement {
    template <class typeCle>
    Encrypt<typeCle>::Encrypt(bool pType) : _type(pType)
    { }
    template <class typeCle>
    std::string Encrypt<typeCle>::getPlain()
    {
        return _plain;
    }
    template <class typeCle>
    std::string Encrypt<typeCle>::getCypher()
    {
        return _cypher;
    }
    template <class typeCle>
    void Encrypt<typeCle>::write(const typeCle pCleChiffrement)
    {
        if(_type)
        {
            std::ofstream fichierEncode("phraseEncode.txt", std::ios::app);
            if (fichierEncode)
            {
                fichierEncode << std::endl << _cypher << std::endl;
                std::cout << "Phrase(s) décryptées : " << std::endl << _plain << std::endl << "Phrase(s) cryptées avec la clé : " << pCleChiffrement << std::endl << _cypher << std::endl;
            }
            else
                std::cout << "Impossible d'ouvrir le fichier phraseEncode.txt";
        }
        else
        {
            std::ofstream fichierDecode("phraseDecode.txt", std::ios::app);
            if (fichierDecode)
            {
                fichierDecode << std::endl << _plain << std::endl;
              	std::cout << "Phrase(s) cryptées : " << std::endl << _cypher << std::endl << "Phrase(s) décryptées avec la clé : " << pCleChiffrement << std::endl << _plain << std::endl;
            }
            else
                std::cout << "Impossible d'ouvrir le fichier phraseDecode.txt";
        }
    }
    template <class typeCle>
    void Encrypt<typeCle>::read()
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

    Caesar::Caesar(bool pType,int pDecalage) : Encrypt<int>(pType){
        if (pDecalage > 25 || pDecalage < -25)
            pDecalage %= 25;
        _decalage = pDecalage;
        this->read();
    }

    void Caesar::encode()
    {
        int index, i;
        _cypher = "";
        for (i = 0; i < int(_plain.length()); i++)
        {
            index = int(_plain[i]);
            if (index >= 97 && index <= 122)
            {
                index += _decalage;
                if (index > 122)
                    index -= 25;
                else
                    if( index < 97)
                        index += 25;
            }
            _cypher += char(index);
        }
        this->write(_decalage);
    }
    void Caesar::decode()
    {
        int index, i;
        _plain = "";
        for (i = 0; i < int(_cypher.length()); i++)
        {
            index = int(_plain[i]);
            if (index >= 97 && index <= 122)
            {
                index =- _decalage;
                if (index < 97)
                    index += 25;
                else
                    if(index > 122)
                        index -= 25;
            }
            _plain += char(index);
        }
        this->write(_decalage);
    }

     Caesar2::Caesar2(bool pType,int pDecalage) : Encrypt<int>(pType){
        if (pDecalage > 127 || pDecalage < -127)
            pDecalage %= 127;
        _decalage = pDecalage;
        this->read();
    }

    void Caesar2::encode()
    {
        int index, i;
        _cypher = "";
        for (i = 0; i < int(_plain.length()); i++)
        {
            index = int(_plain[i]);
            index += _decalage;
            if (index > 127)
                index -= 127;
            else
                if( index < 0)
                    index += 127;
            _cypher += char(index);
        }
        this->write(_decalage);
    }

    void Caesar2::decode()
    {
        int index, i;
        _plain = "";
        for (i = 0; i < int(_cypher.length()); i++)
        {
            index = int(_cypher[i]);
            index -= _decalage;
                if (index < 0)
                    index += 127;
                else
                    if(index > 127)
                        index -= 127;
            _plain += char(index);
        }
        this->write(_decalage);
    }

   Vigenere::Vigenere(bool pType) : Encrypt<std::string>(pType){
       int longueur;
       char saisi;
       do{
       		std::cout <<  "Saisir la longueur de la clé :" << std::endl;
           	std::cin >> longueur;
           }while(longueur <= 0);
       for (auto i =0; i<longueur ;i++)
       {
           do{
           		std::cout << i+1 << "ème élément de la clé de chiffrement" << std::endl;
           		std::cin >> saisi;
           		if((int(saisi) <= 90) && (int(saisi) >= 65))
           			saisi = char(int(saisi)+32);
           	}while((int(saisi) < 97) || (int(saisi) > 122));
           _cleFormeChaineCaracteres += saisi;
           _cleChiffrement.push_back(int(saisi)-96);
       }
       this->read();
   }

   void Vigenere::encode()
   {
       int index,i;
       auto it = _cleChiffrement.begin();
       _cypher = "";
       for ( i = 0; i < int(_plain.length()); i++)
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
       this->write(_cleFormeChaineCaracteres);
   }

   void Vigenere::decode()
   {
       int index, i;
       auto it = _cleChiffrement.begin();
       _plain = "";
       for (i = 0; i < int(_cypher.length()); i++)
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
       this->write(_cleFormeChaineCaracteres);
   }
}