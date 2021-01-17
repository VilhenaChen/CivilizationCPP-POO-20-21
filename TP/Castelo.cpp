#include "Castelo.h"

int Castelo::getResistencia()
{
	return resistencia;
}

int Castelo::getProdutos()
{
	return num_produtos_criados;
}

int Castelo::getOuro()
{
	return num_ouro_criado;
}

int Castelo::getAnoConquistado()
{
	return ano_conquistado;
}

int Castelo::getTurnoConquistado()
{
	return turno_conquistado;
}

string Castelo::getMeuTipo()
{
	return "Castelo";
}

void Castelo::setAnoConquistado(int ano)
{
	ano_conquistado = ano;
}

void Castelo::setTurnoConquistado(int turno)
{
	turno_conquistado = turno;
}

void Castelo::atualizaProdutosEOuro(int ano, int turno)
{
	if (turno <= 2){
		num_produtos_criados = 3;
	}
	else {
		num_produtos_criados = 0;
	}
}
