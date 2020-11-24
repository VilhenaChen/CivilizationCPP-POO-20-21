#pragma once
#include <string>
#include <sstream>

using namespace std;

class Territorios
{
	string nome;
	int resistencia;
	int num_produtos_criados;
	int num_ouro_criado;
	int pontos_vitoria;


public:
	Territorios(string name, int resist, int prod, int ouro, int pontos)
	{
		nome = name;
		resistencia = resist;
		num_produtos_criados = prod;
		num_ouro_criado = ouro;
		pontos_vitoria = pontos;
	}

	//GETS
	string getNome();
	int getResistencia();
	int getProdutos();
	int getOuro();
	int getPontos();
};

