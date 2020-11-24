#pragma once
#include <vector>
#include <string>
using namespace std;
class Logica
{
	vector<string> tipos_territorios;
public:
	Logica() 
	{
		fillTipos_Territorios();
	}
	
	//fill
	void fillTipos_Territorios();

	//verify
	bool verificaTipo_Territorio(string nome);
};

