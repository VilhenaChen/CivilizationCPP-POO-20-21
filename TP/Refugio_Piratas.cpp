#include "Refugio_Piratas.h"

int Refugio_Piratas::getResistencia()
{
	return resistencia;
}

int Refugio_Piratas::getProdutos()
{
	return num_produtos_criados;
}

int Refugio_Piratas::getOuro()
{
	return num_ouro_criado;
}

int Refugio_Piratas::getAnoConquistado()
{
	return ano_conquistado;
}

int Refugio_Piratas::getTurnoConquistado()
{
	return turno_conquistado;
}

string Refugio_Piratas::getMeuTipo()
{
	return "RefugioDosPiratas";
}

void Refugio_Piratas::setAnoConquistado(int ano)
{
	ano_conquistado = ano;
}

void Refugio_Piratas::setTurnoConquistado(int turno)
{
	turno_conquistado = turno;
}

void Refugio_Piratas::atualizaProdutosEOuro(int ano, int turno){}
