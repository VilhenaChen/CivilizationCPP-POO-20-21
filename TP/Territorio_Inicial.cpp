#include "Territorio_Inicial.h"


int Territorio_Inicial::getResistencia()
{
	return resistencia;
}

int Territorio_Inicial::getProdutos()
{
	return num_produtos_criados;
}

int Territorio_Inicial::getOuro()
{
	return num_ouro_criado;
}
int Territorio_Inicial::getPontos()
{
	return pontos_vitoria;
}

int Territorio_Inicial::getAnoConquistado()
{
	return ano_conquistado;
}

int Territorio_Inicial::getTurnoConquistado()
{
	return turno_conquistado;
}

void Territorio_Inicial::setAnoConquistado(int ano)
{
	ano_conquistado = ano;
}

void Territorio_Inicial::setTurnoConquistado(int turno)
{
	turno_conquistado = turno;
}

void Territorio_Inicial::atualizaProdutosEOuro(int ano, int turno){}
