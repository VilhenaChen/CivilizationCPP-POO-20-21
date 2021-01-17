#include "Duna.h"

int Duna::getResistencia()
{
	return resistencia;
}

int Duna::getProdutos()
{
	return num_produtos_criados;
}

int Duna::getOuro()
{
	return num_ouro_criado;
}

int Duna::getAnoConquistado()
{
	return ano_conquistado;
}

int Duna::getTurnoConquistado()
{
	return turno_conquistado;
}

string Duna::getMeuTipo()
{
	return "Duna";
}

void Duna::setAnoConquistado(int ano)
{
	ano_conquistado = ano;
}

void Duna::setTurnoConquistado(int turno)
{
	turno_conquistado = turno;
}

void Duna::atualizaProdutosEOuro(int ano, int turno){}
