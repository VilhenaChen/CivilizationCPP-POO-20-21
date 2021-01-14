#pragma once
#include "Ilha.h"
class Pescaria : public Ilha
{
	int resistencia;
	int num_produtos_criados;
	int num_ouro_criado;
	int ano_conquistado;
	int turno_conquistado;
public:
	Pescaria(string name) : Ilha(name), resistencia(9), num_produtos_criados(2), num_ouro_criado(0), ano_conquistado(0), turno_conquistado(0) {}

	//gets
	int getResistencia();
	int getProdutos();
	int getOuro();
	int getAnoConquistado();
	int getTurnoConquistado();

	//sets
	void setAnoConquistado(int ano);
	void setTurnoConquistado(int turno);

	//update
	void atualizaProdutosEOuro(int ano, int turno);
};

