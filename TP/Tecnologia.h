#pragma once
class Tecnologia
{
	bool drones_militares;
	bool misseis;
	bool defesas_territoriais;
	bool bolsa_de_valores;
	bool banco_central;
	int preco_drones;
	int preco_misseis;
	int preco_defesas;
	int preco_bolsa;
	int preco_banco;

public:
	Tecnologia() : drones_militares(false),misseis(false),defesas_territoriais(false),bolsa_de_valores(false),banco_central(false),
		preco_drones(3),preco_misseis(4),preco_defesas(4),preco_bolsa(2),preco_banco(3){}

	//verify
	bool isDronesMilitares();
	bool isMisseis();
	bool isDefesasTerritoriais();
	bool isBolsaDeValores();
	bool isBancoCentral();
	bool verificaSePossuiTodasAsTecnologias();

	//gets
	int getPrecoDrones();
	int getPrecoMisseis();
	int getPrecoDefesas();
	int getPrecoBolsa();
	int getPrecoBanco();
	int getNumeroTecnologias();

	//sets
	void setDronesMilitares(bool valor);
	void setMisseis(bool valor);
	void setDefesasTerritoriais(bool valor);
	void setBolsaDeValores(bool valor);
	void setBancoCentral(bool valor);
	

};

