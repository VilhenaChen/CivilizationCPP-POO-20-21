#include "Mina.h"

int Mina::getResistencia()
{
	return resistencia;
}

int Mina::getProdutos()
{
	return num_produtos_criados;
}

int Mina::getOuro()
{
	return num_ouro_criado;
}

int Mina::getAnoConquistado()
{
	return ano_conquistado;
}

int Mina::getTurnoConquistado()
{
	return turno_conquistado;
}

string Mina::getMeuTipo()
{
	return "Mina";
}

void Mina::setAnoConquistado(int ano)
{
	ano_conquistado = ano;
}

void Mina::setTurnoConquistado(int turno)
{
	turno_conquistado = turno;
}

void Mina::atualizaProdutosEOuro(int ano, int turno)
{
	if (turno <= 3) {
		num_ouro_criado = 1;
	}
	else {
		num_ouro_criado = 2;
	}
}
