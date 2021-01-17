#pragma once
#include "Forca_Militar.h"
#include "Cofre.h"
#include "Armazem.h"
#include "Territorio.h"
#include "Tecnologia.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>



using namespace std;

class Imperio_Jogador
{
	int fator_sorte;
	int producao_ouro;
	int producao_produtos;
	Forca_Militar forca_militar;
	Cofre cofre;
	Armazem armazem;
	Tecnologia tecnologia;
	vector<Territorio*> territorios;

public:
	
	Imperio_Jogador() : fator_sorte(0), producao_ouro(0), producao_produtos(0) {}

	//gets
	int getFatorSorte();
	int getForcaMilitar();
	int getLimiteMaxMilitar();
	int getLimiteAtualMilitar();
	int getProdutos();
	int getLimiteMaxProdutos();
	int getLimiteAtualProdutos();
	int getNumOuro();
	int getLimiteMaxOuro();
	int getLimiteAtualOuro();
	int getTamTerritorios();
	string getNomeTerritorio(int posicao);
	int getResistenciaTerritorio(int posicao);
	int getOuroTerritorio(int posicao);
	int getProdutosTerritorio(int posicao);
	int getPontosVitoriaTerritorio(int posicao);
	int getProducaoOuro();
	int getProducaoProdutos();
	Tecnologia* getTecnologia();

	//sets
	void setOuro(int quantidade);
	void setProdutos(int quantidade);

	//gera
	void geraFatorSorte();

	//increases
	void increaseForcaMilitar();
	void increaseLimiteAtualMilitar();
	void increaseNumProdutos(int inc);
	void increaseLimiteAtualProdutos();
	void increaseNumOuro(int inc);
	void increaseLimiteAtualOuro();

	//decreases
	void decreaseForcaMilitar();
	void decreaseNumProdutos(int dec);
	void decreaseNumOuro(int dec);

	//add
	void addTerritorio(Territorio* territory);

	//verify
	bool verificaSeVetorTerritoriosEstaVazio();
	bool verificaSeTerritorioEstaConquistado(string nome);

	//Update
	void atualizaProducaoOuro();
	void atualizaProducaoProdutos();
	void atualizaProdutosEOutroTerritorios(int ano, int turno);

	//find
	Territorio* encontraTerritorio(string nome);

	//buy
	void compraTecnologia(string nome);

	//delete
	void apagaUltimoTerritorioConquistado();

	~Imperio_Jogador() 
	{
		for (auto it = territorios.begin(); it < territorios.end(); it++)
		{
			delete* it;
		}
	}
	
};

