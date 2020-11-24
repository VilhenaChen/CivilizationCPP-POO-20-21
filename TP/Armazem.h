#pragma once
class Armazem
{
	const int capacidade_max = 5;
	int capacidade_atual;
	int num_produtos;

public:
	Armazem() : capacidade_atual(3), num_produtos(0) {}

	//Gets
	int getCapacidade_Max();
	int getCapacidade_Atual();
	int getNum_produtos();

	//Sets
	void setCapacidade_Atual();
	void setNum_produtos(int produtos);
};

