#pragma once
#include <vector>
#include <string>
#include "Mundo.h"
#include "Imperio_Jogador.h"
#include "Territorio.h"

using namespace std;

class Logica
{
	const int max_turnos = 12;
	int turno;
	Mundo mundo;
	Imperio_Jogador imperio_jogador;

public:
	Logica(): turno(0) {}

	//add
	void adicionaNovoTerritorioAoImperio(string nome);
};

