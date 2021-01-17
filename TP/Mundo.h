#pragma once
#include <vector>
#include "Territorio.h"
#include <string>
#include "Continente.h"
#include "Ilha.h"
#include "Territorio_Inicial.h"
#include "Planicie.h"
#include "Montanha.h"
#include "Fortaleza.h"
#include "Mina.h"
#include "Duna.h"
#include "Castelo.h"
#include "Refugio_Piratas.h"
#include "Pescaria.h"
using namespace std;
class Mundo
{
	vector<Territorio*> territorios;
	vector<string> tipos_territorios;

public:
	Mundo()
	{
		fillTipos_Territorios();
		territorios.push_back(new Territorio_Inicial("TerritorioInicial"));
	}

	//get
	int getTamTerritorios();
	string getNomeTerritorio(int posicao);
	int getResistenciaTerritorio(int posicao);


	//fill
	void fillTipos_Territorios();

	//verify
	bool verificaTipo_Territorio(string nome);
	bool verificaExistenciaTerritorio(string nome);
	bool verificaSeExistemTerritorios();

	//generate
	string geraNomeConcat(string nome);

	//add
	bool addTerritorio(string nome);

	//find
	Territorio* encontraTerritorio(string nome);


	~Mundo() 
	{
		for (auto it = territorios.begin(); it < territorios.end(); it++) 
		{
			delete* it;
		}
	}
};

