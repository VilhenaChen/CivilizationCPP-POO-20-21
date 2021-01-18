#pragma once
#include "Territorio.h"

using namespace std;

class Territorio_Inicial : public Territorio
{
	int pontos_vitoria;
	int resistencia;
	int num_produtos_criados;
	int num_ouro_criado;
	int ano_conquistado;
	int turno_conquistado;

public:
	Territorio_Inicial(string name) :Territorio(name), pontos_vitoria(1), resistencia(9), num_produtos_criados(1), num_ouro_criado(1), ano_conquistado(0), turno_conquistado(0) {}

	//gets
	int getResistencia();
	int getProdutos();
	int getOuro();
	int getPontos();
	int getAnoConquistado();
	int getTurnoConquistado();
	string getMeuTipo();

	//sets
	void setAnoConquistado(int ano);
	void setTurnoConquistado(int turno);

	//update
	void atualizaProdutosEOuro(int ano, int turno);

	~Territorio_Inicial() {}
};

