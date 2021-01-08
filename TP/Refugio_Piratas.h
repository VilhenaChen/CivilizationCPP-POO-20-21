#pragma once
#include "Ilha.h"
class Refugio_Piratas : public Ilha
{
	int resistencia;
	int num_produtos_criados;
	int num_ouro_criado;
public:
	Refugio_Piratas(string name) : Ilha(name), resistencia(9), num_produtos_criados(0), num_ouro_criado(1) {}

	//gets
	int getResistencia();
	int getProdutos();
	int getOuro();
};

