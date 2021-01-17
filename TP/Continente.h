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
	virtual int getAnoConquistado() = 0;
	virtual int getTurnoConquistado() = 0;
	virtual string getMeuTipo() = 0;

	//sets
	virtual void setAnoConquistado(int ano) = 0;
	virtual void setTurnoConquistado(int turno) = 0;

	//update
	virtual void atualizaProdutosEOuro(int ano, int turno) = 0;



};

