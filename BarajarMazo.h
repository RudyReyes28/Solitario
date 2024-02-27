//
// Created by rudyo on 26/02/2024.
//

#ifndef SOLITARIO_BARAJARMAZO_H
#define SOLITARIO_BARAJARMAZO_H

#include "Carta.h"
#include "Cola.h"

void barajarMazo(Carta* mazo[], int tamano);
void repartirCartas(Carta* mazo[], int tamano,Cola *& frente,Cola*& fin);


#endif //SOLITARIO_BARAJARMAZO_H
