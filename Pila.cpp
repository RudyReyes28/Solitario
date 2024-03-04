//
// Created by rudyo on 4/03/2024.
//

#include "Pila.h"

void insertarCartaAPila(Pila* &pila, Carta carta){
    Pila *nuevaPila = new Pila();
    nuevaPila->carta = carta;
    nuevaPila->siguiente = pila;
    pila = nuevaPila;
}