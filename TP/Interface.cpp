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
	if (com_completo.empty()) 
	{
		cout << "Comando Invalido. Os argumentos inseridos sao insuficientes" << endl;
		return false;
	}
	//DIVIDIR COMANDO
	vet_var_comando=logica->splitComando(com_completo);
	com = vet_var_comando[k];
	k++;
	if (com == "carrega")
	{
		if (vet_var_comando.size() > 2)
		{
			cout << "Comando Invalido. Foram inseridos demasiados argumentos" << endl;
			return false;
		}
		if (vet_var_comando.size() < 2)
		{
			cout << "Comando Invalido. Os argumentos inseridos sao insuficientes" << endl;
			return false;
		}
		nome_aux = vet_var_comando[k];
		logica->carrega(nome_aux);
	}
	else
	{
		if (com == "cria")
		{
			if (vet_var_comando.size() > 3)
			{
				cout << "Comando Invalido. Foram inseridos demasiados argumentos" << endl;
				return false;
			}
			if (vet_var_comando.size() < 3)
			{
				cout << "Comando Invalido. Os argumentos inseridos sao insuficientes" << endl;
				return false;
			}
			nome_aux = vet_var_comando[k];
			k++;
			if (!isdigit(vet_var_comando[k][0])) 
			{
				cout << "Comando Invalido. O numero de territorios deve ser um inteiro" << endl;
				return false;
			}
			num_aux = stoi(vet_var_comando[k]);
			k++;
			if (logica->criaNTerritorios(nome_aux,num_aux) == false) 
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
				if (vet_var_comando.size() > 2)
				{
					cout << "Comando Invalido. Foram inseridos demasiados argumentos" << endl;
					return false;
				}
				if (vet_var_comando.size() < 1)
				{
					cout << "Comando Invalido. Os argumentos inseridos sao insuficientes" << endl;
					return false;
				}
				if (vet_var_comando.size() != 2)
				{
					listaInicial();
				}
				else
				{
					listaTerritorio(vet_var_comando[k]);
				}
			}
			else 
			{
				if (com == "comeca")
				{
					if (vet_var_comando.size() > 1)
					{
						cout << "Comando Invalido. Foram inseridos demasiados argumentos" << endl;
						return false;
					}
					if (vet_var_comando.size() < 1)
					{
						cout << "Comando Invalido. Os argumentos inseridos sao insuficientes" << endl;
						return false;
					}
					if (logica->getMundo()->getTamTerritorios() >= 5) {
						logica->preparaJogo();
						lista();
						return true;
					}
					else
					{
						cout << "Insira no minimo 5 Territorios!!!" << endl;
						return false;
					}
				}
				else
				{
					if (com == "sair") {
						if (vet_var_comando.size() > 1)
						{
							cout << "Comando Invalido. Foram inseridos demasiados argumentos" << endl;
							return false;
						}
						if (vet_var_comando.size() < 1)
						{
							cout << "Comando Invalido. Os argumentos inseridos sao insuficientes" << endl;
							return false;
						}
						exit(0);
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
	cout << "1 Fase do Turno "<< logica->getTurno() << " Ano " << logica->getAno() <<" (Conquistar/Passar)" << endl;
	cout << "\nMenu" << endl;
	cout << "\tconquista<nome>" << endl;
	cout << "\tpassa" << endl;
	cout << "\tlista<nome>" << endl;
	cout << "\tmodifica<ouro|prod>" << endl;
	cout << "\tfevento<nome-evento>" << endl;
	cout << "\ttoma<qual><nome>" << endl;
	cout << "\tgrava<nome>" << endl;
	cout << "\tativa<nome>" << endl;
	cout << "\tapaga<nome>" << endl;
	cout << "\tsair" << endl;
	cout << "Insira um comando: ";
	getline(cin, com_completo);
	if (com_completo.empty())
	{
		cout << "Comando Invalido. Os argumentos inseridos sao insuficientes" << endl;
		return false;
	}
	//DIVIDIR COMANDO
	vet_var_comando = logica->splitComando(com_completo);
	com = vet_var_comando[k];
	k++;
	if(com == "conquista")
	{
		if (vet_var_comando.size() > 2)
		{
			cout << "Comando Invalido. Foram inseridos demasiados argumentos" << endl;
			return false;
		}
		if (vet_var_comando.size() < 2)
		{
			cout << "Comando Invalido. Os argumentos inseridos sao insuficientes" << endl;
			return false;
		}
		if (logica->conquista(vet_var_comando[k]) == true) {
			return true;
		}
		return false;
	}
	else
	{
		if(com == "passa")
		{
			if (vet_var_comando.size() > 1)
			{
				cout << "Comando Invalido. Foram inseridos demasiados argumentos" << endl;
				return false;
			}
			if (vet_var_comando.size() < 1)
			{
				cout << "Comando Invalido. Os argumentos inseridos sao insuficientes" << endl;
				return false;
			}
			return true;
		}
		else
		{

			if (com == "lista")
			{
				if (vet_var_comando.size() > 2) 
				{
					cout << "Comando Invalido. Foram inseridos demasiados argumentos" << endl;
					return false;
				}
				if (vet_var_comando.size() < 1)
				{
					cout << "Comando Invalido. Os argumentos inseridos sao insuficientes" << endl;
					return false;
				}
				if (vet_var_comando.size() != 2) 
				{
					lista();
				}
				else 
				{
					listaTerritorio(vet_var_comando[k]);
				}
			}
			else
			{
				if (com == "sair") {
					if (vet_var_comando.size() > 1) {
						cout << "Comando Invalido. Foram inseridos demasiados argumentos" << endl;
						return false;
					}
					if (vet_var_comando.size() < 1) {
						cout << "Comando Invalido. Os argumentos inseridos sao insuficientes" << endl;
						return false;
					}
					exit(0);
				}
				else {
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
	int k = 0, quant = 0;
	vector <string> vet_var_comando;
	com.clear();//Limpar variavel
	cout << "2 Fase do Turno "<< logica->getTurno() << " Ano " << logica->getAno() <<" (Recolha de Produtos/Ouro)" << endl;
	cout << "\nMenu" << endl;
	cout << "\tlista<nome>" << endl;
	cout << "\tavanca" << endl;
	cout << "\tsair" << endl;
	cout << "\tmaisouro" << endl;
	cout << "\tmaisprod" << endl;
	cout << "\tgrava<nome>" << endl;
	cout << "\tativa<nome>" << endl;
	cout << "\tapaga<nome>" << endl;
	cout << "\ttoma<qual><nome>" << endl;
	cout << "\tmodifica<ouro|prod>N(DEBUG)" << endl;
	cout << "\tfevento<nome_evento>(DEBUG)" << endl;
	cout << "\tsair" << endl;
	cout << "Insira um comando: ";
	getline(cin, com_completo);
	if (com_completo.empty()) {
		cout << "Comando Invalido. Os argumentos inseridos sao insuficientes" << endl;
		return false;
	}
	//DIVIDIR COMANDO
	vet_var_comando = logica->splitComando(com_completo);
	com = vet_var_comando[k];
	k++;
	if (com == "lista") {
		if (vet_var_comando.size() > 2) {
			cout << "Comando Invalido. Foram inseridos demasiados argumentos" << endl;
			return false;
		}
		if (vet_var_comando.size() < 1) {
			cout << "Comando Invalido. Os argumentos inseridos sao insuficientes" << endl;
			return false;
		}
		if (vet_var_comando.size() == 1) {
			lista();
		}
		else {
			listaTerritorio(vet_var_comando[k]);
		}
	} 
	else {
		if (com == "avanca") {
			if (vet_var_comando.size() > 1) {
				cout << "Comando Invalido. Foram inseridos demasiados argumentos" << endl;
				return false;
			}
			if (vet_var_comando.size() < 1) {
				cout << "Comando Invalido. Os argumentos inseridos sao insuficientes" << endl;
				return false;
			}
			return true;
		}
		else {
			if (com == "maisouro") { //Mais Ouro
				if (vet_var_comando.size() > 1) {
					cout << "Comando Invalido. Foram inseridos demasiados argumentos" << endl;
					return false;
				}
				if (vet_var_comando.size() < 1) {
					cout << "Comando Invalido. Os argumentos inseridos sao insuficientes" << endl;
					return false;
				}
				return logica->maisOuroProdutosMilitar('o');
			}
			else {
				if (com == "maisprod") { //Mais Produtos
					if (vet_var_comando.size() > 1) {
						cout << "Comando Invalido. Foram inseridos demasiados argumentos" << endl;
						return false;
					}
					if (vet_var_comando.size() < 1) {
						cout << "Comando Invalido. Os argumentos inseridos sao insuficientes" << endl;
						return false;
					}
					return logica->maisOuroProdutosMilitar('p');
				}
				else {
					if(com == "modifica") {
						if (vet_var_comando.size() > 1) {
							cout << "Comando Invalido. Foram inseridos demasiados argumentos" << endl;
							return false;
						}
						if (vet_var_comando.size() < 1) {
							cout << "Comando Invalido. Os argumentos inseridos sao insuficientes" << endl;
							return false;
						}
						k++;
						quant = stoi(vet_var_comando[k]);
						k--;
						return logica->modificaOuroOuProdutos(vet_var_comando[k], quant);
					}
				}
			}
			if(com == "sair") {
				exit(0);
			}
		}
	}
	return false;
}

bool Interface::Menu_Terceira_Fase(bool* militar, bool* tecnologia) //Compra de militares e tecnologia
{
	string com_completo, com;
	int k = 0;
	vector <string> vet_var_comando;
	com.clear();//Limpar variavel
	cout << "3 Fase do Turno "<< logica->getTurno() << " Ano " << logica->getAno() <<" (Comprar de Forca Militar/Tecnologia)" << endl;
	cout << "\nMenu" << endl;
	cout << "\tmaismilitar" << endl;
	cout << "\tadquire<tipo>" << endl;
	cout << "\tmodifica<ouro|prod>" << endl;
	cout << "\tfevento<nome-evento>" << endl;
	cout << "\ttoma<qual><nome>" << endl;
	cout << "\tgrava<nome>" << endl;
	cout << "\tativa<nome>" << endl;
	cout << "\tapaga<nome>" << endl;
	cout << "\tlista<nome>" << endl;
	cout << "\tavanca" << endl;
	cout << "Insira um comando: ";
	getline(cin, com_completo);
	if (com_completo.empty()){
		cout << "Comando Invalido. Os argumentos inseridos sao insuficientes" << endl;
		return false;
	}
	vet_var_comando = logica->splitComando(com_completo); //DIVIDIR COMANDO
	com = vet_var_comando[k];
	k++;
	if (com == "maismilitar") {
		if (*militar == true) {
			cout << "Ja comprou forca militar este turno" << endl;
			return false;
		}
		if (vet_var_comando.size() > 1) {
			cout << "Comando Invalido. Foram inseridos demasiados argumentos" << endl;
			return false;
		}
		if (vet_var_comando.size() < 1) {
			cout << "Comando Invalido. Os argumentos inseridos sao insuficientes" << endl;
			return false;
		}
		logica->maisOuroProdutosMilitar('m');
		*militar = true;
		return false;
	}
	else {
		if (com == "adquire") {
			if (*tecnologia == true) {
				cout << "Ja comprou forca militar este turno" << endl;
				return false;
			}
			if (vet_var_comando.size() > 2) {
				cout << "Comando Invalido. Foram inseridos demasiados argumentos" << endl;
				return false;
			}
			if (vet_var_comando.size() < 1) {
				cout << "Comando Invalido. Os argumentos inseridos sao insuficientes" << endl;
				return false;
			}
			logica->adquireTecnologia(vet_var_comando[k]);
			*tecnologia = true;
			return false;
		}
		else {
			if (com == "avanca") {
				if (vet_var_comando.size() > 1) {
					cout << "Comando Invalido. Foram inseridos demasiados argumentos" << endl;
					return false;
				}
				if (vet_var_comando.size() < 1) {
					cout << "Comando Invalido. Os argumentos inseridos sao insuficientes" << endl;
					return false;
				}
				return true;
			}
		}
	}
	
	return false;
}

bool Interface::Menu_Quarta_Fase() //Fase de Evento
{
	string com_completo, com;
	int k = 0;
	vector <string> vet_var_comando;
	com.clear();//Limpar variavel
	cout << "4 Fase do Turno " << logica->getTurno() << " Ano " << logica->getAno() << " (Eventos)" << endl;
	cout << "\nMenu" << endl;
	cout << "\tlista<nome>" << endl;
	cout << "\tmodifica<ouro|prod>" << endl;
	cout << "\tfevento<nome-evento>" << endl;
	cout << "\ttoma<qual><nome>" << endl;
	cout << "\tgrava<nome>" << endl;
	cout << "\tativa<nome>" << endl;
	cout << "\tapaga<nome>" << endl;
	cout << "\tavanca" << endl;
	cout << "Insira um comando: ";
	getline(cin, com_completo);
	if (com_completo.empty()) {
		cout << "Comando Invalido. Os argumentos inseridos sao insuficientes" << endl;
		return false;
	}
	vet_var_comando = logica->splitComando(com_completo); //DIVIDIR COMANDO
	com = vet_var_comando[k];
	k++;
	k++;
	if (com == "lista") {
		if (vet_var_comando.size() > 2) {
			cout << "Comando Invalido. Foram inseridos demasiados argumentos" << endl;
			return false;
		}
		if (vet_var_comando.size() < 1) {
			cout << "Comando Invalido. Os argumentos inseridos sao insuficientes" << endl;
			return false;
		}
		if (vet_var_comando.size() == 1) {
			lista();
		}
		else {
			listaTerritorio(vet_var_comando[k]);
		}
	}
	else {
		if (com == "avanca") {
			if (vet_var_comando.size() > 1) {
				cout << "Comando Invalido. Foram inseridos demasiados argumentos" << endl;
				return false;
			}
			if (vet_var_comando.size() < 1) {
				cout << "Comando Invalido. Os argumentos inseridos sao insuficientes" << endl;
				return false;
			}
			return true;
		}
	}
	return false;
}



void Interface::Lanca_Menu_Inicial()
{
	bool flag = false;
	do
	{
		flag = Menu_Inicial();
	} while (flag != true);
	Lanca_Menu_Jogo();
}

void Interface::Lanca_Menu_Jogo()
{
	bool flag = false;
	bool militar,tecnologia;
	do
	{
		logica->atualizaProdutosEOuroTerritorios();
		do
		{
			flag = Menu_Primeira_Fase();
		} while (flag != true);
		flag = false;
		logica->getImperioJogador()->increaseNumOuro(logica->getImperioJogador()->getProducaoOuro());
		logica->getImperioJogador()->increaseNumProdutos(logica->getImperioJogador()->getProducaoProdutos());
		do
		{
			flag = Menu_Segunda_Fase();
		} while (flag != true);
		militar = false;
		tecnologia = false;
		flag = false;
		do {
			flag = Menu_Terceira_Fase(&militar, &tecnologia);
		}while (flag != true);
		do {
			flag = Menu_Quarta_Fase();
		} while (flag != true);
		if (logica->getAno() == 1 || (logica->getAno()==2 && logica->getTurno() < 6)) 
		{
			logica->increaseTurno();
			logica->getImperioJogador()->atualizaProducaoOuro();
			logica->getImperioJogador()->atualizaProducaoProdutos();
			
		}
		else 
		{
			break;
		}
	} while (1);
	logica->calculaPontuacaoFinal();
	cout << "***************************" << endl;
	cout << "Fim do Jogo" << endl;
	lista();
}

void Interface::listaInicial()
{
	cout << "***************************" << endl;
	cout << "Estado atual do Mundo" << endl;
	if (logica->getMundo()->verificaSeExistemTerritorios() == false)
	{
		cout << "\tNão existem Territorios" << endl;
	}
	else
	{
		cout << "\tTerritorios : " << endl;
		for (int i = 0; i < logica->getMundo()->getTamTerritorios(); i++)
		{
			cout << "\t\tNome: " << logica->getMundo()->getNomeTerritorio(i) << " Resistencia: " << logica->getMundo()->getResistenciaTerritorio(i) << endl;
		}
	}
	cout << "***************************" << endl;
}

void Interface::lista() {
	cout << "***************************" << endl;
	cout << "Dados do jogo:" << endl;
	cout << "\t Ano: " << logica->getAno() << " Turno: " << logica->getTurno() << endl;
	cout << "\t Fator Sorte: " << logica->getImperioJogador()->getFatorSorte() << endl;

	cout << "***************************" << endl;
	cout << "Estado atual do Imperio" << endl;
	if (logica->getImperioJogador()->verificaSeVetorTerritoriosEstaVazio() == true) 
	{
		cout << "\tNão existem Territorios Conquistados" << endl;
	}
	else 
	{
		cout << "\tTerritorios Conquistados: " << endl; 
		for (int i = 0; i < logica->getImperioJogador()->getTamTerritorios(); i++)
		{ 
			cout << "\t\tNome: " << logica->getImperioJogador()->getNomeTerritorio(i) << endl; 
			cout << "\t\t\t- Resistencia: " << logica->getImperioJogador()->getResistenciaTerritorio(i) << endl;
			cout << "\t\t\t- Producao:" << endl; 
			cout << "\t\t\t\t- Ouro: " << logica->getImperioJogador()->getOuroTerritorio(i) << endl; 
			cout << "\t\t\t\t- Produtos: "<< logica->getImperioJogador()->getProdutosTerritorio(i) << endl;
		}
	}
	cout << "\tOuro:" << endl;
	cout << "\t\t- Valor em Armazem: " << logica->getImperioJogador()->getNumOuro() << endl;
	cout << "\t\t- Valor Maximo: " << logica->getImperioJogador()->getLimiteAtualOuro() << endl;
	cout << "\t\t- Producao atual: " << logica->getImperioJogador()->getProducaoOuro() << endl;
	cout << "\tProdutos:" << endl;
	cout << "\t\t Valor em Armazem: " << logica->getImperioJogador()->getProdutos() << endl;
	cout << "\t\t Valor Maximo: " << logica->getImperioJogador()->getLimiteAtualProdutos() << endl;
	cout << "\t\t Producao atual: " << logica->getImperioJogador()->getProducaoProdutos() << endl;
	cout << "\tForca Militar:" << endl;
	cout << "\t\t Valor Atual: " << logica->getImperioJogador()->getForcaMilitar() << endl;
	cout << "\t\t Valor Maximo: " << logica->getImperioJogador()->getLimiteAtualMilitar() << endl;

	cout << "***************************" << endl;
	cout << "Territorios Nao Conquistados: " << endl; 
	for (int i = 0; i < logica->getMundo()->getTamTerritorios(); i++)
	{
		if (logica->verificaSeTerritorioEstaConquistado(i) == false) 
		{
			cout << "\tNome: " << logica->getMundo()->getNomeTerritorio(i) << " Resistencia: " << logica->getMundo()->getResistenciaTerritorio(i) << endl;
		}
	}
	cout << "***************************" << endl;
	if(logica->getTurno() == 6 && logica->getAno() == 2) {
		cout << "Pontuacao Final: " << logica->getPontuacaoFinal() << endl;
	}
	
}

void Interface::listaTerritorio(string nome)
{
	if(logica->getMundo()->verificaExistenciaTerritorio(nome) == true) {
		if(logica->getImperioJogador()->verificaSeTerritorioEstaConquistado(nome) == true) {
			cout << "Nome: " << logica->getImperioJogador()->encontraTerritorio(nome)->getNome() << endl;
			cout << "\t- Resistencia: " << logica->getImperioJogador()->encontraTerritorio(nome)->getResistencia() << endl;
			cout << "\t- Producao:" << endl; 
			cout << "\t\t- Ouro: " << logica->getImperioJogador()->encontraTerritorio(nome)->getOuro() << endl;
			cout << "\t\t- Produtos: "<< logica->getImperioJogador()->encontraTerritorio(nome)->getProdutos() << endl;
		}
		else 
		{
			cout << "Nome: " << logica->getMundo()->encontraTerritorio(nome)->getNome() << endl;
			cout << "\t- Resistencia: " << logica->getMundo()->encontraTerritorio(nome)->getResistencia() << endl;
		}
	}
	else
	{
		cout << "O territorio " << nome << " nao existe" << endl;
	}
}
