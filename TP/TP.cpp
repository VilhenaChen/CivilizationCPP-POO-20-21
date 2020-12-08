#include <iostream>
#include "Interface.h"
#include "Logica.h"

int main()
{
    /*Territorios todos iguais, ou seja maybe todos iniciais
    * Resistencia = 9
    * pontos Vitoria = 0
    * Produacao = 1 prod 1 ouro
    */
    Logica* logica = new Logica();
    Interface* interface = new Interface(logica);
    interface->Lanca_Menu_Inicial();
    return 0;
}

