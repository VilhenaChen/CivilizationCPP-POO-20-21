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
	virtual int getAnoConquistado() = 0;
	virtual int getTurnoConquistado() = 0;

	//sets
	virtual void setAnoConquistado(int ano) = 0;
	virtual void setTurnoConquistado(int turno) = 0;

	//update
	virtual void atualizaProdutosEOuro(int ano, int turno) = 0;
};

