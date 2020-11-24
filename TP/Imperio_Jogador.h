#pragma once
#include "Forca_Militar.h"
#include "Cofre.h"
#include "Armazem.h"

class Imperio_Jogador
{
	Forca_Militar forca_militar;
	Cofre cofre;
	Armazem armazem;

public:
	
	//gets
	int getForcaMilitar();
	int getLimiteMaxMilitar();
	int getLimiteAtualMilitar();
	int getProdutos();
	int getLimiteMaxProdutos();
	int getLimiteAtualProdutos();
	int getNumOuro();
	int getLimiteMaxOuro();
	int getLimiteAtualOuro();

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


	
};

