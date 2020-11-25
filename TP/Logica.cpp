#include "Logica.h"

void Logica::adicionaNovoTerritorioAoImperio(string nome)
{
	Territorio* terr;
	terr = mundo.encontraTerritorio(nome);
	imperio_jogador.addTerritorio(terr);
}
