#include "Tecnologia.h"

bool Tecnologia::isDronesMilitares()
{
    return drones_militares;
}

bool Tecnologia::isMisseis()
{
    return misseis;
}

bool Tecnologia::isDefesasTerritoriais()
{
    return defesas_territoriais;
}

bool Tecnologia::isBolsaDeValores()
{
    return bolsa_de_valores;
}

bool Tecnologia::isBancoCentral()
{
    return banco_central;
}

void Tecnologia::setDronesMilitares(bool valor)
{
    drones_militares = valor;
}

void Tecnologia::setMisseis(bool valor)
{
    misseis = valor;
}

void Tecnologia::setDefesasTerritoriais(bool valor)
{
    defesas_territoriais = valor;
}

void Tecnologia::setBolsaDeValores(bool valor)
{
    bolsa_de_valores = valor;
}

void Tecnologia::setBancoCentral(bool valor)
{
    banco_central = valor;
}
