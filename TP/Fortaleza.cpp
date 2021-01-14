#include "Fortaleza.h"

int Fortaleza::getResistencia()
{
	return resistencia;
}

int Fortaleza::getProdutos()
{
	return num_produtos_criados;
}

int Fortaleza::getOuro()
{
	return num_ouro_criado;
}

int Fortaleza::getAnoConquistado()
{
	return ano_conquistado;
}

int Fortaleza::getTurnoConquistado()
{
	return turno_conquistado;
}

void Fortaleza::setAnoConquistado(int ano)
{
	ano_conquistado = ano;
}

void Fortaleza::setTurnoConquistado(int turno)
{
	turno_conquistado = turno;
}

void Fortaleza::atualizaProdutosEOuro(int ano, int turno){}
