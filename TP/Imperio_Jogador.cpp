#include "Imperio_Jogador.h"

int Imperio_Jogador::getFatorSorte()
{
	return fator_sorte;
}

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

int Imperio_Jogador::getTamTerritorios()
{
	return territorios.size();
}

string Imperio_Jogador::getNomeTerritorio(int posicao)
{
	string nome = territorios[posicao]->getNome();
	return nome;
}

int Imperio_Jogador::getResistenciaTerritorio(int posicao)
{
	int resist = territorios[posicao]->getResistencia();
	return resist;
}

int Imperio_Jogador::getOuroTerritorio(int posicao)
{
	int gold = territorios[posicao]->getOuro();
	return gold;
}

int Imperio_Jogador::getProdutosTerritorio(int posicao)
{
	int products = territorios[posicao]->getProdutos();
	return products;
}

int Imperio_Jogador::getPontosVitoriaTerritorio(int posicao)
{
	int points = territorios[posicao]->getPontos();
	return points;

}

int Imperio_Jogador::getProducaoOuro()
{
	return producao_ouro;
}

int Imperio_Jogador::getProducaoProdutos()
{
	return producao_produtos;
}


void Imperio_Jogador::geraFatorSorte() {
	srand(time(nullptr));
	fator_sorte = rand() % 7;
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
	armazem.setNum_produtos(produto_atual);
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
	cofre.setNum_ouro(ouro_atual);
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

bool Imperio_Jogador::verificaSeVetorTerritoriosEstaVazio()
{
	if (territorios.size() == 0) 
	{
		return true;
	}
	return false;
}

bool Imperio_Jogador::verificaSeTerritorioEstaConquistado(string nome)
{
	for (int i = 0; i < territorios.size(); i++) 
	{
		if (territorios[i]->getNome() == nome) 
		{
			return true;
		}
	}
	return false;
}

void Imperio_Jogador::atualizaProducaoOuro()
{
	int ouro = 0;
	for(int i = 0; i < territorios.size(); i++) {
		ouro = ouro + getOuroTerritorio(i);
	}
	producao_ouro = ouro;
}

void Imperio_Jogador::atualizaProducaoProdutos()
{
	int produtos = 0;
	for(int i = 0; i < territorios.size(); i++) {
		produtos = produtos + getProdutosTerritorio(i);
	}
	producao_produtos = produtos;
}

Territorio* Imperio_Jogador::encontraTerritorio(string nome)
{
	for (int i = 0; i < territorios.size(); i++)
	{
		if (territorios[i]->getNome() == nome)
		{
			return territorios[i];
		}
	}
	return nullptr;
}

