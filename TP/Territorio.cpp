#include "Territorio.h"

string Territorio::getNome()
{
	return nome;
}

int Territorio::getResistencia()
{
	return resistencia;
}

int Territorio::getProdutos()
{
	return num_produtos_criados;
}

int Territorio::getOuro()
{
	return num_ouro_criado;
}

int Territorio::getPontos()
{
	return pontos_vitoria;
}
