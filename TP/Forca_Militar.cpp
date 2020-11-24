#include "Forca_Militar.h"

int Forca_Militar::getLimite_Max()
{
    return limite_max;
}

int Forca_Militar::getLimite_Atual()
{
    return limite_atual;
}

int Forca_Militar::getForca()
{
    return forca;
}

void Forca_Militar::setLimite_Atual()
{
    limite_atual = limite_max;
}

void Forca_Militar::setForca(int force)
{
    forca = force;
}
