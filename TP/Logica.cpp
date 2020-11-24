#include "Logica.h"

void Logica::fillTipos_Territorios()
{
	tipos_territorios.push_back("Planicie");
	tipos_territorios.push_back("Montanha");
	tipos_territorios.push_back("Fortaleza");
	tipos_territorios.push_back("Mina");
	tipos_territorios.push_back("Duna");
	tipos_territorios.push_back("Castelo");
	tipos_territorios.push_back("Refugio dos Piratas");
	tipos_territorios.push_back("Pescaria");
}

bool Logica::verificaTipo_Territorio(string nome)
{
	for (int i = 0; i < tipos_territorios.size(); i++) 
	{
		if (tipos_territorios[i] == nome) 
		{
			return true;
		}
	}
	return false;
}
