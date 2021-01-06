#include <iostream>
#include "Interface.h"
#include "Logica.h"

int main()
{
    Logica* logica = new Logica();
    Interface* interface = new Interface(logica);
    interface->Lanca_Menu_Inicial();
    return 0;
}

