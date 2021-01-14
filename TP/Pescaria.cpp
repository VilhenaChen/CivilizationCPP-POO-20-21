#include "Pescaria.h"

int Pescaria::getResistencia()
{
	return resistencia;
}

int Pescaria::getProdutos()
{
	return num_produtos_criados;
}

int Pescaria::getOuro()
{
	return num_ouro_criado;
}

int Pescaria::getAnoConquistado()
{
	return ano_conquistado;
}

int Pescaria::getTurnoConquistado()
{
	return turno_conquistado;
}

void Pescaria::setAnoConquistado(int ano)
{
	ano_conquistado = ano;
}

void Pescaria::setTurnoConquistado(int turno)
{
	turno_conquistado = turno;
}

void Pescaria::atualizaProdutosEOuro(int ano, int turno)
{
	if (ano == 1) {
		num_produtos_criados = 2;
	}
	else {
		num_produtos_criados = 4;
	}
}
