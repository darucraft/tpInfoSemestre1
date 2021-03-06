#include <iostream>
#include "basicencrypt.h"
#include "encrypt.h"
#include <fstream>
#include <array>
#include <cstdlib>
#include <cstdio>

int main(int argc, char const *argv[])
{
    int menu,choix;
	std::string pMenu, pChoix;
    bool type;
    
	//boucle permettant d'executer le programme tant que l'utilisateur ne demande pas à quitter
	do{
		//boucle permettant d'afficher un menu guidant l'utilisateur dans ses choix d'algorithme d'encodage
		do{
			std::system("clear");
			std::cout << "Saisir 1 pour utiliser la methode du chiffrement de Cesar sans les caracteres speciaux." << std::endl << std::endl;
			std::cout << "Saisir 2 pour utiliser la methode du chiffrement de Cesar avec tout les caracteres speciaux." << std::endl << std::endl;
			std::cout << "Saisir 3 pour utiliser la methode du chiffrement de Vigenere."<< std::endl << std::endl;
			std::cout << "Saisir 4 pour Quitter." << std::endl;
			std::cin >> pMenu;
			try 
			{
				menu = std::stoi(pMenu);				
			}
			catch(const std::exception& e)
			{
				menu =-1;
			}
			}while(menu != 1 && menu != 2 && menu != 3 && menu != 4);
			
			if(menu!= 4)
			{
				//boucle permettant d'afficher un menu permettant à l'utilisateur de choisir entre encoder ou décoder les phrases
				do{
					std::cout << std::endl << "Saisir 1 pour Encoder le fichier ou 2 pour Decoder le fichier." << std::endl;
					std::cin >> pChoix;
					try 
					{
						choix = std::stoi(pChoix);				
					}
					catch(const std::exception& e)
					{
						choix =-1;
					}
				}while(choix != 1 && choix != 2);
				type = (choix==1);
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
					break;
				}
			}
		if(menu!= 4)
			{
				//instructions permettant de mettre l'application en pause
				std::cin.ignore();
				std::cout << "Appuyer sur entrée pour continuer...";
				std::cin.get();
			}
	
	}while(menu!=4);
	return 0;
}
