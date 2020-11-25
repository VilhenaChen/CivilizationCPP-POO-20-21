#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Interface
{
	Logica logica;

public:
	Interface(Logica logic) : logica(logic) {}

	bool Menu_Inicial();
	bool Menu_Jogo();

	void Lanca_Menu_Inicial();

	void Lanca_Menu_Jogo();
};

