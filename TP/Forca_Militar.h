#pragma once
#include <cstdlib>
#include <ctime>

class Forca_Militar
{
	const int limite_max=5;
	int limite_atual;
	int forca;

public:
	Forca_Militar() : limite_atual(3) 
	{
		srand(time(nullptr));
		forca = rand() % 4;
	}

	//Gets
	int getLimite_Max();
	int getLimite_Atual();
	int getForca();

	//Sets
	void setLimite_Atual();
	void setForca(int force);
};

