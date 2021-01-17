#include "Eventos.h"

string Eventos::getEventoRandom()
{
    int random;
    srand(time(nullptr));
    random = rand() % 4;
    return eventos[random];
}

