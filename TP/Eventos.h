#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Eventos
{
	vector<string> eventos;
public:
	Eventos() {
		eventos.push_back("recurso");
		eventos.push_back("invasao");
		eventos.push_back("alianca");
		eventos.push_back("sem");
	}

	//Evento Random
	string getEventoRandom();

	~Eventos() {}
};

