#include <iostream>
#include "basicencrypt.h"
#include "encrypt.h"
#include <fstream>
#include <array>

int main(int argc, char const *argv[])
{
    //int decalage;
    std::string choix;
    bool type;
    std::array<int,4> cleChiffrement;
    //std::cout << "Saisir le decalage voulu" << std::endl;
    //std::cin >> decalage;
    do{
        std::cout << "Saisir 1 pour Encoder le fichier ou 2 pour Décoder le fichier." << std::endl;
        std::cin >> choix;
    }while(choix != "1" && choix != "2");

    if(choix=="1")
        type = true;
    else
        type = false;

    chiffrement::Vigenere cryptage(type);
    cryptage.read();
    cryptage.write();
    std::cout << cryptage.getPlain() << std::endl << cryptage.getCypher() << std::endl;
    return 0;
}
