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
	virtual int getAnoConquistado() = 0;
	virtual int getTurnoConquistado() = 0;

	//sets
	virtual void setAnoConquistado(int ano) = 0;
	virtual void setTurnoConquistado(int turno) = 0;

	//update
	virtual void atualizaProdutosEOuro(int ano, int turno) = 0;

	~Territorio() {}
};

