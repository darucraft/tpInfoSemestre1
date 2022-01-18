#include <iostream>
#include "basicencrypt.h"
#include "encrypt.h"
#include <fstream>
#include <array>
#include <cstdlib>

int main(int argc, char const *argv[])
{
    int menu,choix;
    bool type;
    
	do{
		std::system("clear");
		do{
			std::cout << "Saisir 1 pour utiliser la methode du chiffrement de Cesar sans les caracteres speciaux." << std::endl << std::endl;
			std::cout << "Saisir 2 pour utiliser la methode du chiffrement de Cesar avec tout les caracteres speciaux." << std::endl << std::endl;
			std::cout << "Saisir 3 pour utiliser la methode du chiffrement de Vigenere."<< std::endl << std::endl;
			std::cout << "Saisir 4 pour Quitter." << std::endl;
			std::cin >> menu;
			}while(menu != 1 && menu != 2 && menu != 3 && menu != 4);
			
			if(menu!= 4)
			{
				do{
					std::cout << std::endl << "Saisir 1 pour Encoder le fichier ou 2 pour Decoder le fichier." << std::endl;
					std::cin >> choix;
				}while(choix != 1 && choix != 2);
				type = choix==1;
			}
			
			switch(menu)
			{
				case(1) :
				{
					chiffrement::Caesar cryptage(type);
					break;
				}
				case(2) :
				{
					chiffrement::Caesar2 cryptage(type);
					break;
				}
				case(3) :
				{
					chiffrement::Vigenere cryptage(type);
					cryptage.read();
					break;
				}
			}
		if(menu!= 4)
			{
				std::system("PAUSE");
			}
	
	}while(menu!=4);
	return 0;
}
