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

bool Tecnologia::verificaSePossuiTodasAsTecnologias()
{
    if (drones_militares && misseis && defesas_territoriais && bolsa_de_valores && banco_central) {
        return true;
    }
    else {
        return false;
    }
}

int Tecnologia::getPrecoDrones()
{
    return preco_drones;
}

int Tecnologia::getPrecoMisseis()
{
    return preco_misseis;
}

int Tecnologia::getPrecoDefesas()
{
    return defesas_territoriais;
}

int Tecnologia::getPrecoBolsa()
{
    return bolsa_de_valores;
}

int Tecnologia::getPrecoBanco()
{
    return preco_banco;
}

int Tecnologia::getNumeroTecnologias()
{
    int cont = 0;
    if (drones_militares) { cont++; }
    if (misseis) { cont++; }
    if (defesas_territoriais) { cont++; }
    if (banco_central) { cont++; }
    if (bolsa_de_valores) { cont++; }

    return cont;
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
