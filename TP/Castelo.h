#pragma once
#include "Continente.h"
class Castelo : public Continente
{
	int resistencia;
	int num_produtos_criados;
	int num_ouro_criado;
public:
	Castelo(string name) : Continente(name), resistencia(7), num_produtos_criados(3), num_ouro_criado(1) {}

	//gets
	int getResistencia();
	int getProdutos();
	int getOuro();
};

