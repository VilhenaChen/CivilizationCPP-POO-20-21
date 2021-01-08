#pragma once
#include "Ilha.h"
class Pescaria : public Ilha
{
	int resistencia;
	int num_produtos_criados;
	int num_ouro_criado;
public:
	Pescaria(string name) : Ilha(name), resistencia(9), num_produtos_criados(2), num_ouro_criado(0) {}

	//gets
	int getResistencia();
	int getProdutos();
	int getOuro();
};

