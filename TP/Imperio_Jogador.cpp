#include "Imperio_Jogador.h"

int Imperio_Jogador::getForcaMilitar()
{
	return forca_militar.getForca();
}

int Imperio_Jogador::getLimiteMaxMilitar()
{
	return forca_militar.getLimite_Max();
}

int Imperio_Jogador::getLimiteAtualMilitar()
{
	return forca_militar.getLimite_Atual();
}

int Imperio_Jogador::getProdutos()
{
	return armazem.getNum_produtos();
}

int Imperio_Jogador::getLimiteMaxProdutos()
{
	return armazem.getCapacidade_Max();
}

int Imperio_Jogador::getLimiteAtualProdutos()
{
	return armazem.getCapacidade_Atual();
}

int Imperio_Jogador::getNumOuro()
{
	return cofre.getNum_ouro();
}

int Imperio_Jogador::getLimiteMaxOuro()
{
	return cofre.getCapacidade_Max();
}

int Imperio_Jogador::getLimiteAtualOuro()
{
	return cofre.getCapacidade_Atual();
}

void Imperio_Jogador::increaseForcaMilitar()
{
	int forca_atual = forca_militar.getForca();
	int lim_forca = forca_militar.getLimite_Atual();
	if ((forca_atual + 1) <= lim_forca)
	{
		forca_atual = forca_atual + 1;
	}
	forca_militar.setForca(forca_atual);
}

void Imperio_Jogador::increaseLimiteAtualMilitar()
{
	forca_militar.setLimite_Atual();
}

void Imperio_Jogador::increaseNumProdutos(int inc)
{
	int produto_atual = armazem.getNum_produtos();
	int capacidade = armazem.getCapacidade_Atual();
	if ((produto_atual + inc) <= capacidade)
	{
		produto_atual = produto_atual + inc;
	}
	else
	{
		produto_atual = capacidade;
	}
	forca_militar.setForca(produto_atual);
}

void Imperio_Jogador::increaseLimiteAtualProdutos()
{
	armazem.setCapacidade_Atual();
}

void Imperio_Jogador::increaseNumOuro(int inc)
{
	int ouro_atual = cofre.getNum_ouro();
	int capacidade = cofre.getCapacidade_Atual();
	if ((ouro_atual + inc) <= capacidade)
	{
		ouro_atual = ouro_atual + inc;
	}
	else
	{
		ouro_atual = capacidade;
	}
	forca_militar.setForca(ouro_atual);
}

void Imperio_Jogador::increaseLimiteAtualOuro()
{
	cofre.setCapacidade_Atual();
}

void Imperio_Jogador::decreaseForcaMilitar()
{
	int forca_atual = forca_militar.getForca();
	if ((forca_atual - 1) >= 0)
	{
		forca_atual = forca_atual - 1;
	}
	forca_militar.setForca(forca_atual);
}

void Imperio_Jogador::decreaseNumProdutos(int dec)
{
	int produto_atual = armazem.getNum_produtos();
	if ((produto_atual - dec) >= 0)
	{
		produto_atual = produto_atual - dec;
	}
	else
	{
		produto_atual = 0;
	}
	forca_militar.setForca(produto_atual);
}

void Imperio_Jogador::decreaseNumOuro(int dec)
{
	int ouro_atual = cofre.getNum_ouro();
	if ((ouro_atual - dec) >= 0)
	{
		ouro_atual = ouro_atual - dec;
	}
	else
	{
		ouro_atual = 0;
	}
	forca_militar.setForca(ouro_atual);
}

void Imperio_Jogador::addTerritorio(Territorio* territory)
{
	territorios.push_back(territory);
}
