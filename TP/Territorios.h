#pragma once
#include <string>
#include <sstream>

using namespace std;

class Territorios
{
	string nome;
	int resistencia;
	int cria_produtos;
	int cria_ouro;
	int pontos_vitoria;


public:
	Territorios(string name, int resit, int prod, int ouro, int pontos) {}

	//GETS
	string getNome();
	int getResistencia();
	int getProdutos();
	int getOuro();
	int getPontos();

	//SETS
	void setNome(string name);
	void setResistencia(int resist);
	void setProdutos(int prod);
	void setOuro(int ouro);
	void setPontos(int pontos);
};

