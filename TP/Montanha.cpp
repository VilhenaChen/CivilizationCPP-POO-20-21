#include "Montanha.h"

int Montanha::getResistencia()
{
	return resistencia;
}

int Montanha::getProdutos()
{
	return num_produtos_criados;
}

int Montanha::getOuro()
{
	return num_ouro_criado;
}

int Montanha::getAnoConquistado()
{
	return ano_conquistado;
}

int Montanha::getTurnoConquistado()
{
	return turno_conquistado;
}

void Montanha::setAnoConquistado(int ano)
{
	ano_conquistado = ano;
}

void Montanha::setTurnoConquistado(int turno)
{
	turno_conquistado = turno;
}

void Montanha::atualizaProdutosEOuro(int ano, int turno)
{
	if (turno_conquistado < 4) {
		if (turno > (turno_conquistado + 2)) {
			num_produtos_criados = 1;
		}
	}
	else {
		if (ano_conquistado == 1) {
			if (turno_conquistado == 4) {
				if (ano == 2) {
					num_produtos_criados = 1;
				}
			}
			else {
				if (turno_conquistado == 5) {
					if (turno > 1 && ano == 2) {
						num_produtos_criados = 1;
					}
				}
				else {
					if (turno_conquistado == 6) {
						if (turno > 2 && ano == 2) {
							num_produtos_criados = 1;
						}
					}
				}
			}
		}
	}
}
