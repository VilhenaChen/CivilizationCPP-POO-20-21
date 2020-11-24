#include "Mundo.h"

bool Mundo::verificaValidadeTipo(string nome)
{

	return false;
}

string Mundo::geraNomeConcat(string nome)
{
	string nome_gerado;
	return nome_gerado;
}

bool Mundo::addTerritorio(string nome)
{
	string nome_concat;

	if (logica->verificaTipo_Territorio(nome) == false) 
	{
		return false;
	}
	//geraNomeConcat
	//getResistencaRespetiva
	//getNumProdutosRespetivo
	//getNumOuroRespetivo
	//getPontosRespetivos

	territorios.push_back(new Territorio(nome_concat, 5, 1, 1, 1));
	return true;
}
