#pragma once
#include <vector>
#include "Territorio.h"
#include <string>
using namespace std;
class Mundo
{
	vector<Territorio*> territorios;
	vector<string> tipos_territorios;

public:
	Mundo()
	{
		fillTipos_Territorios();
		territorios.push_back(new Territorio("Territorio Inicial1", 9, 1, 1, 0));
	}

	//fill
	void fillTipos_Territorios();

	//verify
	bool verificaTipo_Territorio(string nome);
	bool verificaExistenciaTerritorio(string nome);

	//generate
	string geraNomeConcat(string nome);

	//add
	bool addTerritorio(string nome);

	//find
	Territorio* encontraTerritorio(string nome);

};

