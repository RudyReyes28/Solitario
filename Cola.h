
#ifndef COLA_H
#define COLA_H

#include "Carta.h"

struct Cola {
    Carta carta;
    Cola* siguiente;
};

void insertarCarta(Cola*& frente, Cola*& fin, Carta carta);
void sacarCarta(Cola*& frente, Cola*& fin);

#endif