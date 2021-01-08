#pragma once
#include "Continente.h"
class Mina : public Continente
{
	int resistencia;
	int num_produtos_criados;
	int num_ouro_criado;
public:
	Mina(string name) : Continente(name), resistencia(5), num_produtos_criados(0), num_ouro_criado(1) {}

	//gets
	int getResistencia();
	int getProdutos();
	int getOuro();
};

