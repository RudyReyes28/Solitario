//
// Created by rudyo on 26/02/2024.
//

#ifndef SOLITARIO_BARAJARMAZO_H
#define SOLITARIO_BARAJARMAZO_H

#include "Carta.h"
#include "Cola.h"
#include "EscaleraCartas.h"

void barajarMazo(Carta* mazo[], int tamano);
void repartirCartas(Carta* mazo[],Cola *& frente,Cola*& fin);
void repartirCartasEscalera(Carta* mazo[], EscaleraCartas& escaleraA,EscaleraCartas& escaleraB,EscaleraCartas& escaleraC,EscaleraCartas& escaleraD,EscaleraCartas& escaleraE,EscaleraCartas& escaleraF,EscaleraCartas& escaleraG);

#endif //SOLITARIO_BARAJARMAZO_H
