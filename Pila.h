//
// Created by rudyo on 4/03/2024.
//

#ifndef SOLITARIO_PILA_H
#define SOLITARIO_PILA_H

#include "Carta.h"

struct Pila{
    Carta carta;
    Pila *siguiente;
};

void insertarCartaAPila(Pila* &pila, Carta carta);
int obtenerTamanoPila(Pila* pila);

#endif //SOLITARIO_PILA_H
