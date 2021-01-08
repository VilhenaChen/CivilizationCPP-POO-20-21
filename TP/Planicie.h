#pragma once
#include "Continente.h"
class Planicie : public Continente
{
	int resistencia;
	int num_produtos_criados;
	int num_ouro_criado;
public:
	Planicie(string name) : Continente(name), resistencia(5), num_produtos_criados(1), num_ouro_criado(1){}

	//gets
	int getResistencia();
	int getProdutos();
	int getOuro();

};

