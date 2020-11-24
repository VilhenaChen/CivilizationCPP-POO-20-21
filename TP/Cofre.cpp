#include "Cofre.h"

int Cofre::getCapacidade_Max()
{
    return capacidade_max;
}

int Cofre::getCapacidade_Atual()
{
    return capacidade_atual;
}

int Cofre::getNum_ouro()
{
    return num_ouro;
}

void Cofre::setCapacidade_Atual()
{
    if ((capacidade_atual + 2) <= capacidade_max) {
        capacidade_atual = capacidade_atual + 2;
    }
}

void Cofre::setNum_ouro(int ouro)
{
    num_ouro = ouro;
}
