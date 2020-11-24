#include "Armazem.h"

int Armazem::getCapacidade_Max()
{
    return capacidade_max;
}

int Armazem::getCapacidade_Atual()
{
    return capacidade_atual;
}

int Armazem::getNum_produtos()
{
    return num_produtos;
}

void Armazem::setCapacidade_Atual()
{
    if ((capacidade_atual + 2) <= capacidade_max) {
        capacidade_atual = capacidade_atual + 2;
    }
}

void Armazem::setNum_produtos(int produtos)
{
    num_produtos = produtos;
}
