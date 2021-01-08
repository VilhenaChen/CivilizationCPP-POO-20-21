#pragma once
#include "Territorio.h"
class Ilha : public Territorio
{
	int pontos_vitoria;
public:
	Ilha(string name) :Territorio(name), pontos_vitoria(2) {}

	//gets
	int getPontos();
	virtual int getResistencia() = 0;
	virtual int getProdutos() = 0;
	virtual int getOuro() = 0;
};

