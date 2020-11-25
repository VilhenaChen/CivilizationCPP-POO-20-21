#include "Mundo.h"

void Mundo::fillTipos_Territorios()
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

bool Mundo::verificaTipo_Territorio(string nome)
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

bool Mundo::verificaExistenciaTerritorio(string nome)
{
	for (int i = 0; i < territorios.size(); i++)
	{
		if (territorios[i]->getNome() == nome)
		{
			return true;
		}
	}
	return false;
}

string Mundo::geraNomeConcat(string nome)
{
	string nome_gerado, num_str;
	int num = 0;
	bool existe=false;
	do 
	{
		num++;
		num_str = to_string(num);
		nome_gerado = nome.append(num_str);
		existe = false;

		for (int i = 0; i < tipos_territorios.size(); i++) 
		{
			if (nome_gerado == tipos_territorios[i])
			{
				existe = true;
			}
		}
	} while (existe == true);

	return nome_gerado;
}

bool Mundo::addTerritorio(string nome)
{
	string nome_concat;

	if (verificaTipo_Territorio(nome) == false) 
	{
		return false;
	}

	nome_concat = geraNomeConcat(nome);

	//getResistencaRespetiva
	//getNumProdutosRespetivo
	//getNumOuroRespetivo
	//getPontosRespetivos

	territorios.push_back(new Territorio(nome_concat, 5, 1, 1, 1));
	return true;
}

Territorio* Mundo::encontraTerritorio(string nome)
{
	if (verificaExistenciaTerritorio(nome) == true) 
	{
		for (int i = 0; i < territorios.size(); i++)
		{
			if (territorios[i]->getNome() == nome) 
			{
				return territorios[i];
			}
		}
	}
	return nullptr;
}
