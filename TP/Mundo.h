#pragma once
#include <vector>
#include "Territorio.h"
#include "Logica.h"
using namespace std;
class Mundo
{
	vector<Territorio*> territorios;
	Logica* logica;

public:
	Mundo(Logica* logic) : logica(logic)
	{
		territorios.push_back(new Territorio("Territorio Inicial1", 9, 1, 1, 0));
	}

	//verificaValidadeTipo
	bool verificaValidadeTipo(string nome);

	//geraNomeConcat
	string geraNomeConcat(string nome);

	//add
	bool addTerritorio(string nome);

};

