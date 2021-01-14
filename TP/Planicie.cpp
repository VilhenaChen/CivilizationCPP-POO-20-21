#include "Planicie.h"

int Planicie::getResistencia()
{
	return resistencia;
}

int Planicie::getProdutos()
{
	return num_produtos_criados;
}

int Planicie::getOuro()
{
	return num_ouro_criado;
}

int Planicie::getAnoConquistado()
{
	return ano_conquistado;
}

int Planicie::getTurnoConquistado()
{
	return turno_conquistado;
}

void Planicie::setAnoConquistado(int ano)
{
	ano_conquistado = ano;
}

void Planicie::setTurnoConquistado(int turno)
{
	turno_conquistado = turno;
}

void Planicie::atualizaProdutosEOuro(int ano, int turno)
{
	if (ano == 2){
		num_produtos_criados = 2;
	}
}
