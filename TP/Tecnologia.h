#pragma once
class Tecnologia
{
	bool drones_militares;
	bool misseis;
	bool defesas_territoriais;
	bool bolsa_de_valores;
	bool banco_central;

	Tecnologia() 
	{
		drones_militares = false;
		misseis = false;
		defesas_territoriais = false;
		bolsa_de_valores = false;
		banco_central = false;
	}

	//verify
	bool isDronesMilitares();
	bool isMisseis();
	bool isDefesasTerritoriais();
	bool isBolsaDeValores();
	bool isBancoCentral();

	//sets
	void setDronesMilitares(bool valor);
	void setMisseis(bool valor);
	void setDefesasTerritoriais(bool valor);
	void setBolsaDeValores(bool valor);
	void setBancoCentral(bool valor);
	

};

