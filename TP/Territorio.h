#pragma once
#include <string>
#include <sstream>

using namespace std;

class Territorio
{

	string nome;
	int resistencia;
	int num_produtos_criados;
	int num_ouro_criado;
	int pontos_vitoria;


public:
	Territorio(string name, int resist, int prod, int gold, int points) :nome(name), resistencia(resist), num_produtos_criados(prod), num_ouro_criado(gold), pontos_vitoria(points) {}

	//GETS
	string getNome();
	int getResistencia();
	int getProdutos();
	int getOuro();
	int getPontos();
};

