#include "Cola.h"

void insertarCarta(Cola*& frente, Cola*& fin, Carta carta) {
    Cola* nuevo_nodo = new Cola();
    nuevo_nodo->carta = carta;
    nuevo_nodo->siguiente = nullptr;

    if (frente == nullptr) {
        frente = nuevo_nodo;
    } else {
        fin->siguiente = nuevo_nodo;
    }

    fin = nuevo_nodo;
}

void sacarCarta(Cola*& frente, Cola*& fin) {
    Cola* aux = frente;

    if (frente == fin) {
        frente = nullptr;
        fin = nullptr;
    } else {
        frente = frente->siguiente;
    }

    delete aux;
}