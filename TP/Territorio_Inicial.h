#pragma once
#include "Territorio.h"

class Territorio_Inicial : public Territorio
{
	int pontos_vitoria;
	int resistencia;
	int num_produtos_criados;
	int num_ouro_criado;

public:
	Territorio_Inicial(string name) :Territorio(name), pontos_vitoria(1), resistencia(9), num_produtos_criados(1), num_ouro_criado(1) {}

	//gets
	int getResistencia();
	int getProdutos();
	int getOuro();
	int getPontos();
};

