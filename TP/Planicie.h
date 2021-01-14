#pragma once
#include "Continente.h"
class Planicie : public Continente
{
	int resistencia;
	int num_produtos_criados;
	int num_ouro_criado;
	int ano_conquistado;
	int turno_conquistado;
public:
	Planicie(string name) : Continente(name), resistencia(5), num_produtos_criados(1), num_ouro_criado(1), ano_conquistado(0), turno_conquistado(0){}

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

