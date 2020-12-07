#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Logica.h"

using namespace std;

class Interface
{
	Logica logica;

public:
	Interface(Logica logic) : logica(logic) {}

	//Menus
	bool Menu_Inicial();
	bool Menu_Primeira_Fase();
	bool Menu_Segunda_Fase();
	bool Menu_Terceira_Fase();
	bool Menu_Quarta_Fase();

	//Lanca Menus
	void Lanca_Menu_Inicial();
	void Lanca_Menu_Jogo();

	//Listas
	void listaInicial();
	void lista();
};

