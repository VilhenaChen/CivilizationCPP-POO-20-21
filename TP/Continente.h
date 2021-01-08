#pragma once
#include "Territorio.h"

class Continente : public Territorio
{
	int pontos_vitoria;
public:
	Continente(string name) :Territorio(name), pontos_vitoria(1) {}
	
	//gets
	int getPontos();
	virtual int getResistencia() = 0;
	virtual int getProdutos() = 0;
	virtual int getOuro() = 0;



};

