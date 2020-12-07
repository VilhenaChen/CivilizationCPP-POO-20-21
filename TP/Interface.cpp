#include "Interface.h"

bool Interface::Menu_Inicial()
{
	string com_completo, com, nome_aux;
	vector <string> vet_var_comando;
	bool verifica;
	int k=0, num_aux;
	com.clear();//Limpar variavel
	cout << "MENU INICIAL" << endl;
	cout << "\tcarrega <nomeFicheiro>" << endl;
	cout << "\tcria <tipo> <n>" << endl;
	cout << "\tlista <nome>" << endl;
	cout << "\tcomeca" << endl;
	cout << "\tsair" << endl;
	cout << "Insira um comando: ";
	getline(cin, com_completo);
	//DIVIDIR COMANDO
	vet_var_comando=logica.spitComando(com_completo);
	com = vet_var_comando[k];
	k++;
	if (com == "carrega")
	{
		cout << "LI\n";
		//ler ficheiro
	}
	else
	{
		if (com == "cria")
		{
			cout << "CRIA" << endl;
			nome_aux = vet_var_comando[k];
			k++;
			num_aux = stoi(vet_var_comando[k]);
			k++;
			if (logica.criaNTerritorios(nome_aux,num_aux) == false) 
			{
				cout << "Erro ao criar territorios" << endl;
				return false;
			}
			else 
			{
				cout << "Criados com sucesso" << endl;
			}
		}
		else {
			if (com == "lista") 
			{
				if (vet_var_comando.size() != 2)
				{
					listaInicial();
				}
				else
				{
					//lista teritorio
				}
			}
			else 
			{
				if (com == "comeca")
				{
					cout << "COMECA\n";
					logica.preparaJogo();
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
}

bool Interface::Menu_Primeira_Fase() //Conquista/Passa
{
	string com_completo, com;
	int k=0;
	vector <string> vet_var_comando;
	com.clear();//Limpar variavel
	cout << "1 Fase do Turno "<< logica.getTurno() << " Ano " << logica.getAno() <<" (Conquistar/Passar)" << endl;
	cout << "\nMenu" << endl;
	cout << "\tconquista<nome>" << endl;
	cout << "\tpassa" << endl;
	cout << "\tlista<nome>" << endl;
	cout << "\tsair" << endl;
	cout << "Insira um comando: ";
	getline(cin, com_completo);
	//DIVIDIR COMANDO
	vet_var_comando = logica.spitComando(com_completo);
	com = vet_var_comando[k];
	k++;
	if(com == "conquista")
	{
		//Conquista
		return true;
	}
	else
	{
		if(com == "passa")
		{
			//Passa
			return true;
		}
		else
		{

			if (com == "lista")
			{
				if (vet_var_comando.size() != 2) 
				{
					lista();
				}
				else 
				{
					//lista teritorio
				}
			}
			else
			{
				if (com == "sair") 
				{
					exit(0);
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

bool Interface::Menu_Segunda_Fase() //Recolha de produtos e ouro
{
	string com_completo, com;
	vector <string> vet_var_comando;
	cout << "2 Fase do Turno "<< logica.getTurno() << " Ano " << logica.getAno() <<" (Recolha de Produtos/Ouro)" << endl;
	cout << "\nMenu" << endl;
	cout << "\tlista<nome>" << endl;
	cout << "\tavanca" << endl;
	cout << "\tsair" << endl;
	/*
	cout << "\tmaisouro" << endl;
	cout << "\tmaisprod" << endl;
	cout << "\tgrava<nome>" << endl;
	cout << "\tativa<nome>" << endl;
	cout << "\tapaga<nome>" << endl;
	cout << "\ttoma<qual><nome>" << endl;
	cout << "\tmodifica<ouro|prod>N(DEBUG)" << endl;
	cout << "\tfevento<nome_evento>(DEBUG)" << endl;
	*/
	cout << "Insira um comando: ";
	getline(cin, com);
	if (com == "lista") {
		if (vet_var_comando.size() != 2)
		{
			lista();
		}
		else
		{
			//lista teritorio
		}
	} 
	else {
		if (com == "avanca") {
			return true;
		}
		else {
			if(com == "sair") {
				exit(0);
			}
		}
	}
	return false;
}

bool Interface::Menu_Terceira_Fase() //Compra de militares e tecnologia
{
	cout << "3 Fase do Turno "<< logica.getTurno() << " Ano " << logica.getAno() <<" (Comprar de Forca Militar/Tecnologia)" << endl;
	cout << "\nMenu" << endl;
	cout << "\tmaismilitar" << endl;
	cout << "\tadquire<tipo>" << endl;
	return false;
}

bool Interface::Menu_Quarta_Fase() //Fase de Evento
{
	cout << "4 Fase do Turno "<< logica.getTurno() << " Ano " << logica.getAno() <<" (Eventos)" << endl;
	cout << "\nMenu" << endl;
	return false;
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
		do
		{
			flag = Menu_Primeira_Fase();
		} while (flag != true);
		flag = false;
		do
		{
			flag = Menu_Segunda_Fase();
		} while (flag != true);
		if (logica.getAno() == 1 || (logica.getAno()==2 && logica.getTurno() < 6)) 
		{
			logica.increaseTurno();
		}
		else 
		{
			break;
		}
	} while (1);
	logica.calculaPontuacaoFinal();
	cout << "***************************" << endl;
	cout << "Fim do Jogo" << endl;
	lista();
}

void Interface::listaInicial()
{
	cout << "***************************" << endl;
	cout << "Estado atual do Mundo" << endl;
	if (logica.getMundo()->verificaSeExistemTerritorios() == false)
	{
		cout << "\tNão existem Territorios" << endl;
	}
	else
	{
		cout << "\tTerritorios : " << endl;
		for (int i = 0; i < logica.getMundo()->getTamTerritorios(); i++)
		{
			cout << "\t\tNome: " << logica.getMundo()->getNomeTerritorio(i) << " Resistência: " << logica.getMundo()->getResistenciaTerritorio(i) << endl;
		}
	}
	cout << "***************************" << endl;
}

void Interface::lista() {
	cout << "***************************" << endl;
	cout << "Dados do jogo:" << endl;
	cout << "\t Ano: " << logica.getAno() << "Turno: " << logica.getTurno() << endl;
	cout << "\t Fator Sorte: " << logica.getImperioJogador()->getFatorSorte() << endl;

	cout << "***************************" << endl;
	cout << "Estado atual do Imperio" << endl;
	if (logica.getImperioJogador()->verificaSeVetorTerritoriosEstaVazio() == true) 
	{
		cout << "\tNão existem Territorios Conquistados" << endl;
	}
	else 
	{
		cout << "\tTerritorios Conquistados: " << endl; 
		for (int i = 0; i < logica.getImperioJogador()->getTamTerritorios(); i++)
		{ 
			cout << "\t\tNome: " << logica.getImperioJogador()->getNomeTerritorio(i) << endl; 
			cout << "\t\t\t- Resistência: " << logica.getImperioJogador()->getResistenciaTerritorio(i) << endl;
			cout << "\t\t\t- Producao:" << endl; 
			cout << "\t\t\t\t- Ouro: " << logica.getImperioJogador()->getOuroTerritorio(i) << endl; 
			cout << "\t\t\t\t- Produtos: "<< logica.getImperioJogador()->getProdutosTerritorio(i) << endl;
		}
	}
	cout << "\tOuro:" << endl;
	cout << "\t\t- Valor em Armazem: " << logica.getImperioJogador()->getNumOuro() << endl;
	cout << "\t\t- Valor Maximo: " << logica.getImperioJogador()->getLimiteAtualOuro() << endl;
	cout << "\t\t- Producao atual: " << logica.getImperioJogador()->getProducaoOuro() << endl;
	cout << "\tProdutos:" << endl;
	cout << "\t\t Valor em Armazem: " << logica.getImperioJogador()->getProdutos() << endl;
	cout << "\t\t Valor Maximo: " << logica.getImperioJogador()->getLimiteAtualProdutos() << endl;
	cout << "\t\t Producao atual: " << logica.getImperioJogador()->getProducaoProdutos() << endl;
	cout << "\tForca Militar:" << endl;
	cout << "\t\t Valor Atual: " << logica.getImperioJogador()->getForcaMilitar() << endl;
	cout << "\t\t Valor Maximo: " << logica.getImperioJogador()->getLimiteAtualMilitar() << endl;

	cout << "***************************" << endl;
	cout << "Territorios Nao Conquistados: " << endl; 
	for (int i = 0; i < logica.getMundo()->getTamTerritorios(); i++)
	{
		if (logica.verificaSeTerritorioEstaConquistado(i) == false) 
		{
			cout << "\tNome: " << logica.getMundo()->getNomeTerritorio(i) << " Resistência: " << logica.getMundo()->getResistenciaTerritorio(i) << endl;
		}
	}
	cout << "***************************" << endl;
	if(logica.getTurno() == 6 && logica.getAno() == 2) {
		cout << "Pontuacao Final: " << logica.getPontuacaoFinal() << endl;
	}
	
}
