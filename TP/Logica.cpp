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
	if (nome == "Refugio")
	{
		nome = "Refugio dos Piratas";
	}
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
	for (int i = 0; i < imperio_jogador.getTamTerritorios(); i++) 
	{
		pontuacao_final = (pontuacao_final + imperio_jogador.getPontosVitoriaTerritorio(i));
	}
	if (verificaSeTodosOsTerritoriosEstaoConquistados() == true) 
	{
		pontuacao_final = (pontuacao_final + 3);
	}
}

bool Logica::conquista(string nome) {
	int forca = 0;
	imperio_jogador.geraFatorSorte();
	if (mundo.verificaExistenciaTerritorio(nome) == true)
	{
		if (imperio_jogador.verificaSeTerritorioEstaConquistado(nome) == false) {
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
