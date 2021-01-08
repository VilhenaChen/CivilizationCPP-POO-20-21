#include "Mundo.h"
int Mundo::getTamTerritorios()
{
	return territorios.size();
}

string Mundo::getNomeTerritorio(int posicao)
{
	string name = territorios[posicao]->getNome();
	return name;
}

int Mundo::getResistenciaTerritorio(int posicao)
{
	int resist = territorios[posicao]->getResistencia();
	return resist;
}


void Mundo::fillTipos_Territorios()
{
	tipos_territorios.push_back("Planicie");
	tipos_territorios.push_back("Montanha");
	tipos_territorios.push_back("Fortaleza");
	tipos_territorios.push_back("Mina");
	tipos_territorios.push_back("Duna");
	tipos_territorios.push_back("Castelo");
	tipos_territorios.push_back("RefugioDosPiratas");
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

bool Mundo::verificaSeExistemTerritorios()
{
	if (territorios.size() == 0) 
	{
		return false;
	}
	return true;
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
		nome_gerado = nome;
		nome_gerado = nome_gerado.append(num_str);
		existe = false;

		for (int i = 0; i < territorios.size(); i++) 
		{
			if (nome_gerado == territorios[i]->getNome())
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

	if (nome == "Planicie") {
		territorios.push_back(new Planicie(nome_concat));
	}
	else {
		if (nome == "Montanha") {
			territorios.push_back(new Montanha(nome_concat));
		}
		else {
			if (nome == "Fortaleza") {
				territorios.push_back(new Fortaleza(nome_concat));
			}
			else {
				if (nome == "Mina") {
					territorios.push_back(new Mina(nome_concat));
				}
				else {
					if (nome == "Duna") {
						territorios.push_back(new Duna(nome_concat));
					}
					else {
						if (nome == "Castelo") {
							territorios.push_back(new Castelo(nome_concat));
						}
						else {
							if (nome == "Pescaria") {
								territorios.push_back(new Pescaria(nome_concat));
							}
							else {
								territorios.push_back(new Refugio_Piratas(nome_concat));
							}
						}
					}
				}
			}
		}
	}
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
