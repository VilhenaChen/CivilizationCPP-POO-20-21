#pragma once
#include <string>
#include <sstream>

using namespace std;

class Territorio
{

	string nome;


public:
	Territorio(string name) :nome(name){}

	//GETS
	string getNome();
	virtual int getPontos() = 0;
	virtual int getResistencia() = 0;
	virtual int getProdutos() = 0;
	virtual int getOuro() = 0;

	~Territorio() {}
};

