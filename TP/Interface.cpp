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
				return true;
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

bool Interface::Menu_Jogo()
{
	string com_completo, com;
	vector <string> vet_var_comando;
	com.clear();//Limpar variavel
	cout << "\nMENU JOGO" << endl;
	cout << "\tconquista<nome>" << endl;
	cout << "\tpassa" << endl;
	cout << "\tmaisouro" << endl;
	cout << "\tmaisprod" << endl;
	cout << "\tmaismilitar" << endl;
	cout << "\tadquire<tipo>" << endl;
	cout << "\tlista<nome>" << endl;
	cout << "\tavanca" << endl;
	cout << "\tgrava<nome>" << endl;
	cout << "\tativa<nome>" << endl;
	cout << "\tapaga<nome>" << endl;
	cout << "\ttoma<qual><nome>" << endl;
	cout << "\tmodifica<ouro|prod>N(DEBUG)" << endl;
	cout << "\tfevento<nome_evento>(DEBUG)" << endl;
	cout << "Insira um comando: ";
	getline(cin, com);
	if(com == "conquista")
	{
		//Conquista
	}
	else
	{
		if(com == "passa")
		{
			//Passa
		}
		else
		{
			if (com == "maisouro")
			{
				//1 ouro por 2 de produto
			}
			else
			{
				if (com == "maisprod")
				{
					//1 produto por 2 ouro
				}
				else
				{
					if (com == "maismilitar")
					{
						//1 Militar por 1 ouro, nao pode ultrapassar o maximo
					}
					else
					{
						if (com == "adquire")
						{
							//Compra Tecnologia
						}
						else
						{
							if (com == "lista")
							{
								//Informacao do Jogo, tanto global como especifico caso o nome do territorio seja passado
							}
							else
							{
								if (com == "avanca")
								{
									//Acabam os comandos e avanca pro proximo turno
								}
								else
								{
									if (com == "grava") 
									{
										// Grava estado do jogo
									}
									else
									{
										if (com == "ativa")
										{
											//Recupera um jogo gravado
										}
										else
										{
											if (com == "toma")
											{
												//Toma de assalto um determinado território ou tecnologia desde que esteja disponível
											}
											else
											{
												if (com == "modifica")
												{
													//Modifica dados de um imperio, quantidade de ouro ou de produtos
												}
												else
												{
													cout << "Comando Invalido. Por favor insira um comando valido!!!" << endl;
													return false;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

void Interface::Lanca_Menu_Inicial()
{
	bool flag = false;
	do
	{
		flag = Menu_Inicial();
	} while (flag != true);
	//INFORMACOES
	Lanca_Menu_Jogo();
}

void Interface::Lanca_Menu_Jogo()
{
	bool flag = false;
	do
	{
		flag = Menu_Jogo();
	} while (flag != true);
	//Continuar
}
