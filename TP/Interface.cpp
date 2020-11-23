#include "Interface.h"

bool Interface::Menu_Inicial()
{
	string com_completo, com;
	vector <string> vet_var_comando;
	com.clear();//Limpar variavel
	cout << "MENU INICIAL" << endl;
	cout << "\tcarrega <nomeFicheiro>" << endl;
	cout << "\tcria <tipo> <n>" << endl;
	cout << "\tcomeca" << endl;
	cout << "\tsair" << endl;
	cout << "Insira um comando: ";
	getline(cin, com);
	//DIVIDIR COMANDO
	if (com == "carrega")
	{
		cout << "LI\n";
		//ler ficheiro
	}
	else
	{
		if (com == "cria")
		{
			cout << "CRIA\n";
			//Criar territorios
		}
		else {
			if (com == "comeca")
			{
				cout << "COMECA\n";
				//Comecar jogo
			}
			else
			{
				if (com == "sair") {
					exit(0); //Sair do jogo
				}
				else
				{
					cout << "Comando Invalido, Insira um comando valido!!!" << endl;
				}
			}
		}
	}
}

void Interface::Lanca_Menu_Inicial()
{
	bool mp;
	do
	{
		mp = Menu_Inicial();
	} while (mp != false);
	//Continuar
}
