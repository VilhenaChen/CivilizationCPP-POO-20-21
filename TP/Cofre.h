#pragma once
class Cofre
{
	const int capacidade_max = 5;
	int capacidade_atual;
	int num_ouro;

public:
	Cofre() 
	{ 
		capacidade_atual = 3; 
		num_ouro = 0;
	}

	//Gets
	int getCapacidade_Max();
	int getCapacidade_Atual();
	int getNum_ouro();

	//Sets
	void setCapacidade_Atual();
	void setNum_ouro(int ouro);
};

