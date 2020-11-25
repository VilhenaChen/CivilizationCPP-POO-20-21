#include "Logica.h"

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

vector<string> Logica::spitComando(string comando)
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
