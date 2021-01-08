#pragma once
#include "Continente.h"
class Duna : public Continente
{
	int resistencia;
	int num_produtos_criados;
	int num_ouro_criado;
public:
	Duna(string name) : Continente(name), resistencia(4), num_produtos_criados(1), num_ouro_criado(0) {}

	//gets
	int getResistencia();
	int getProdutos();
	int getOuro();
};

