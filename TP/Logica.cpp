#include "Logica.h"


int Logica::getTurno() {
	return turno;
}

int Logica::getAno()
{
	return ano;
}

Imperio_Jogador* Logica::getImperioJogador()
{
	return &imperio_jogador;
}

int Logica::getPontuacaoFinal()

{
	return pontuacao_final;
}

Mundo* Logica::getMundo()
{
	return &mundo;
}

void Logica::adquireTecnologia(string nome)
{
	imperio_jogador.compraTecnologia(nome);
}

void Logica::increaseTurno() {
	if (turno == 6) 
	{
		turno = 1;
		increaseAno();
	}
	else 
	{
		turno++;
	}
}

void Logica::increaseAno()
{
	ano++;
}

void Logica::adicionaNovoTerritorioAoImperio(string nome)
{
	Territorio* terr;
	terr = mundo.encontraTerritorio(nome);
	imperio_jogador.addTerritorio(terr);
}

bool Logica::criaNTerritorios(string nome, int num)
{
	bool criou;
	for (int i = 0; i < num; i++) 
	{
		criou = true;
		criou = mundo.addTerritorio(nome);
		if (criou == false) 
		{
			return false;
		}
	}
	return true;
}

vector<string> Logica::splitComando(string comando)


{
	vector<string> tokens;
	stringstream com(comando);
	string token;
	while (getline(com, token, ' ')) 
	{
		tokens.push_back(token);
	}
	return tokens;
}

void Logica::carrega(string nomefich)
{
	string linha;
	int num;
	vector <string> vet_var_comando;
	ifstream ficheiro(nomefich);
	if (ficheiro.is_open()) 
	{
		while (getline(ficheiro, linha))
		{
			vet_var_comando = splitComando(linha);
			if (vet_var_comando[0] == "cria") {
				num = stoi(vet_var_comando[2]);
				criaNTerritorios(vet_var_comando[1], num);
			}
		}
		ficheiro.close();
	}
	else 
	{
		cout << "Erro ao abrir ficheiro" << endl;
	}
}

void Logica::preparaJogo()
{
	adicionaNovoTerritorioAoImperio("TerritorioInicial");
	turno = 1;
	ano = 1;
	imperio_jogador.atualizaProducaoOuro();
	imperio_jogador.atualizaProducaoProdutos();
}

bool Logica::verificaSeTerritorioEstaConquistado(int posicao_mundo)
{
	string nome = mundo.getNomeTerritorio(posicao_mundo);
	bool flag;
	flag = imperio_jogador.verificaSeTerritorioEstaConquistado(nome);
	return flag;
}

bool Logica::verificaSeTodosOsTerritoriosEstaoConquistados()
{
	for (int i = 0; i < mundo.getTamTerritorios(); i++) 
	{
		if (imperio_jogador.verificaSeTerritorioEstaConquistado(mundo.getNomeTerritorio(i)) == false) 
		{
			return false;
		}
	}
	return true;
}

void Logica::calculaPontuacaoFinal()
{
	//Somatorio Pontos Territorios Conquistados
	for (int i = 0; i < imperio_jogador.getTamTerritorios(); i++) 
	{
		pontuacao_final = (pontuacao_final + imperio_jogador.getPontosVitoriaTerritorio(i));
	}
	//Verificação de Ponto Bónus por conquistar todos os territorios
	if (verificaSeTodosOsTerritoriosEstaoConquistados() == true) 
	{
		pontuacao_final = (pontuacao_final + 3);
	}
	//Verificação de Ponto Bónus por adquirir todas as tecnologias
	if (imperio_jogador.getTecnologia()->verificaSePossuiTodasAsTecnologias()) {
		pontuacao_final = (pontuacao_final + 1);
	}
	//Soma de um ponto bónus por cada tecnologia
	pontuacao_final = pontuacao_final + imperio_jogador.getTecnologia()->getNumeroTecnologias();

}

bool Logica::modificaOuroOuProdutos(string tipo, int quantidade)
{
	if (tipo == "ouro") 
	{
		if(quantidade <= imperio_jogador.getLimiteAtualOuro())
		{
			imperio_jogador.setOuro(quantidade);
			cout << "Foi alterado para "<< quantidade <<" o numero de ouro" << endl;
			return true;
		}
		else 
		{
			cout << "A quantidade inserida ultrapassa o limite atual do cofre que tem neste momento como valor: " << imperio_jogador.getLimiteAtualOuro() << endl;
			return false;
		}	
	}
	else 
	{
		if (tipo == "prod") 
		{
			if(quantidade <= imperio_jogador.getLimiteAtualProdutos())
			{
				imperio_jogador.setProdutos(quantidade);
				cout << "Foi alterado para " << quantidade << " o numero de produtos" << endl;
				return true;
			}
			else 
			{
				cout << "A quantidade inserida (" << quantidade <<") ultrapassa o limite atual do armazém que tem neste momento como valor: " << imperio_jogador.getLimiteAtualProdutos() << endl;
				return false;
			}
		}
		else 
		{
			cout << "Tipo de elemento a modificar inválido!" << endl;
			return false;
		}
	}
}

void Logica::atualizaProdutosEOuroTerritorios()
{
	imperio_jogador.atualizaProdutosEOutroTerritorios(ano, turno);
}

bool Logica::conquista(string nome) {
	int forca = 0;
	imperio_jogador.geraFatorSorte();
	if (mundo.verificaExistenciaTerritorio(nome) == true)
	{
		if (imperio_jogador.verificaSeTerritorioEstaConquistado(nome) == false) {
			if (mundo.encontraTerritorio(nome)->getMeuTipo() == "RefugioDosPiratas" || mundo.encontraTerritorio(nome)->getMeuTipo() == "Pescaria") {
				if (imperio_jogador.getTecnologia()->isMisseis() == false) {
					cout << "Territorio nao conquistado! Nao possui a tecnologia Missies teleguiados" << endl;
					return false;
				}
			}
			forca = imperio_jogador.getFatorSorte() + imperio_jogador.getForcaMilitar();
			if(mundo.encontraTerritorio(nome)->getResistencia() < forca) {
				imperio_jogador.addTerritorio(mundo.encontraTerritorio(nome));
				cout << "Territorio Conquistado" << " Forca Total: " << forca << " Resistencia: " << mundo.encontraTerritorio(nome)->getResistencia() << endl;
			} else {
				cout << "Territorio nao conquistado\n " << " Forca Total: " << forca << " Resistencia: "<< mundo.encontraTerritorio(nome)->getResistencia() <<endl;
				imperio_jogador.decreaseForcaMilitar();
			}
			return true;
		}
		else {
			cout << "Territorio ja conquistado" << endl;
			return false;
		}
	}
	else 
	{
		cout << "Territorio nao existe" << endl;
		return false;
	}
}

bool Logica::maisOuroProdutosMilitar(char op)
{
	if (op == 'o') {
		if (imperio_jogador.getTecnologia()->isBolsaDeValores()) {
			if (getImperioJogador()->getNumOuro() < getImperioJogador()->getLimiteAtualOuro()) { //Verifica se ja nao chegou ao limite de Ouro
				if (getImperioJogador()->getProdutos() >= 2) {
					getImperioJogador()->decreaseNumProdutos(2);
					getImperioJogador()->increaseNumOuro(1);
					cout << "Foi adicionado 1 ao numero de ouro" << endl;
					return true;
				}
				cout << "Nao possui produtos sufientes, apenas tem " << getImperioJogador()->getProdutos() << " produtos e necessita de 2" << endl;
				return false; //Caso nao tenha Produtos suficentes
			}
			cout << "Ja atingiu o limite atual de ouro" << endl;
			return false; //Caso ja tenha chegado ao limite de ouro
		}
		else {
			cout << "Não possui a tecnologia Bolsa de Valores" << endl;
			return false; //Caso não possua a Bolsa de Valores
		}
	}
	else {
		if (op == 'p') { 
			if (imperio_jogador.getTecnologia()->isBolsaDeValores()) {
				if (getImperioJogador()->getProdutos() < getImperioJogador()->getLimiteAtualProdutos()) {//Verifica se ja nao chegou ao limite de Produtos
					if (getImperioJogador()->getNumOuro() >= 2) {
						getImperioJogador()->decreaseNumOuro(2);
						getImperioJogador()->increaseNumProdutos(1);
						cout << "Foi adicionado 1 aos produtos" << endl;
						return true;
					}
					cout << "Nao possui ouro sufiente, apenas tem " << getImperioJogador()->getNumOuro() << " de ouro e necessita de 2" << endl;
					return false; //Caso nao tenha Ouro suficente
				}
				cout << "Ja atingiu o limite atual de produtos" << endl;
				return false; //Caso ja tenha chegado ao limite de produtos
			}
			else {
				cout << "Não possui a tecnologia Bolsa de Valores" << endl;
				return false; //Caso não possua a Bolsa de Valores
			}
		}
		else {
			if (op == 'm') {
				if (getImperioJogador()->getForcaMilitar() < getImperioJogador()->getLimiteAtualMilitar()) {//Verifica se ja nao chegou ao limite de Militares
					if (getImperioJogador()->getNumOuro() >= 1 && getImperioJogador()->getProdutos() >= 1) {
						getImperioJogador()->decreaseNumOuro(1);
						getImperioJogador()->decreaseNumProdutos(1);
						getImperioJogador()->increaseForcaMilitar();
						cout << "Foi adicionado 1 a forca militar" << endl;
						return true;
					}
					cout << "Nao possui ouro/produtos suficientes, apenas tem " << getImperioJogador()->getNumOuro() << " de ouro "<< getImperioJogador()->getProdutos() << " de produto e necessita de 1 de ambos" << endl;
					return false; //Caso nao tenha Ouro e Produtos suficente
				}
				cout << "Ja atingiu o limite atual de produtos" << endl;
				return false; //Caso ja tenha chegado ao limite de Militares
			}
		}
	}
	return false;
}

bool Logica::geraEventoRandom()
{
	string evento;
	evento = eventos.getEventoRandom();
	if (evento == "recurso") {
		recursoAbandonado();
		return true;
	}
	else {
		if (evento == "invasao") {
			invasao();
			return true;
		}
		else {
			if (evento == "alianca") {
				aliancaDiplomatica();
				return true;
			}
			else {
				if (evento == "sem") {
					semEvento();
					return true;
				}
				else {
					cout << "O evento inserido não existe!" << endl;
					return false;
				}
			}
		}
	}
}

bool Logica::geraEventoEspecifico(string evento)
{
	if (evento == "recurso") {
		recursoAbandonado();
		return true;
	}
	else {
		if (evento == "invasao") {
			invasao();
			return true;
		}
		else {
			if (evento == "alianca") {
				aliancaDiplomatica();
				return true;
			}
			else {
				if (evento == "sem") {
					semEvento();
					return true;
				}
				else {
					cout << "O evento inserido não existe!" << endl;
					return false;
				}
			}
		}
	}
}

void Logica::recursoAbandonado()
{
	if (ano == 2) {
		imperio_jogador.increaseNumOuro(1);
		cout << "Encontrou um Recurso de Ouro Abandonado" << endl;
	}
	else {
		imperio_jogador.increaseNumProdutos(1);
		cout << "Encontrou um Recurso de Produtos Abandonado" << endl;
	}
}

void Logica::invasao()
{
	int sorte;
	int forca_invasao;
	int forca_conjunta;
	bool defesas;
	int resistencia = 0;

	srand(time(nullptr));
	sorte = (rand() % 6) + 1;

	if (ano == 1) {
		forca_invasao = 2;
	}
	else {
		forca_invasao = 3;
	}

	forca_conjunta = forca_invasao + sorte;
	defesas = imperio_jogador.getTecnologia()->isDefesasTerritoriais();

	if (defesas) { resistencia = 1; }
	
	resistencia = resistencia + imperio_jogador.getResistenciaTerritorio((imperio_jogador.getTamTerritorios() - 1));

	if (resistencia < forca_conjunta) 
	{
		cout << "Sofreu uma Invasão e perdeu o Territorio" << imperio_jogador.getNomeTerritorio((imperio_jogador.getTamTerritorios() - 1)) << "!" <<endl;
		cout << "\tResistencia: " << resistencia << "ForcaInvasao" << forca_conjunta << endl;

		if (imperio_jogador.getTamTerritorios() == 1) {
			cout << "Perdeu o jogo por perder todos os Territorios!" << endl;
			exit(0);
		}
		imperio_jogador.apagaUltimoTerritorioConquistado();
	}
	else 
	{
		cout << "Sofreu uma tentativa falhada de Invasão ao Territorio" << imperio_jogador.getNomeTerritorio((imperio_jogador.getTamTerritorios() - 1)) << endl;
	}


}

void Logica::aliancaDiplomatica()
{
	cout << "Assinou uma Aliança Diplomatica! Aumentou a sua força militar!" << endl;
	imperio_jogador.increaseForcaMilitar();
}

void Logica::semEvento()
{
	cout << "Nenhum evento ocorreu!" << endl;
}

void Logica::tomaTerritorioOuTecnologia(string tipo, string nome)
{
	if (tipo == "territorio") {
		if (mundo.verificaExistenciaTerritorio(nome) == true)
		{
			adicionaNovoTerritorioAoImperio(nome);
		}
		else
		{
			cout << "Territorio nao existe" << endl;
			return;
		}
	}
	else {
		if (tipo == "tecnologia") {
			if (nome == "drone") {
				if ( imperio_jogador.getTecnologia()->isDronesMilitares() == false) {
					imperio_jogador.getTecnologia()->setDronesMilitares(true);
				}
				else {
					cout << "Já possui esta tecnologia" << endl;
					return; //Caso já tenha a tecnologia
				}
			}
			else {
				if (nome == "missil") {
					if (imperio_jogador.getTecnologia()->isMisseis() == false) {
						imperio_jogador.getTecnologia()->setMisseis(true);
					}
					else {
						cout << "Já possui esta tecnologia" << endl;
						return; //Caso já tenha a tecnologia
					}
				}
				else {
					if (nome == "defesas") {
						if (imperio_jogador.getTecnologia()->isDefesasTerritoriais() == false) {
							imperio_jogador.getTecnologia()->setDefesasTerritoriais(true);
						}
						else {
							cout << "Já possui esta tecnologia" << endl;
							return; //Caso já tenha a tecnologia
						}
					}
					else {
						if (nome == "bolsa") {
							if (imperio_jogador.getTecnologia()->isBolsaDeValores() == false) {
								imperio_jogador.getTecnologia()->setBolsaDeValores(true);
							}
							else {
								cout << "Já possui esta tecnologia" << endl;
								return; //Caso já tenha a tecnologia
							}
						}
						else {
							if (nome == "banco") {
								if (imperio_jogador.getTecnologia()->isBancoCentral() == false) {
									imperio_jogador.getTecnologia()->setBancoCentral(true);
								}
								else {
									cout << "Já possui esta tecnologia" << endl;
									return; //Caso já tenha a tecnologia
								}
							}
							else {
								cout << "A tecnologia inserida não existe!" << endl;
								return; //Caso já tenha a tecnologia
							}
						}
					}
				}
			}
		}
		}
	}
}
