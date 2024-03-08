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

Carta sacarCarta(Cola*& frente, Cola*& fin) {
    Cola* aux = frente;
    Carta cartaSacada = aux->carta;

    if (frente == fin) {
        frente = nullptr;
        fin = nullptr;
    } else {
        frente = frente->siguiente;
    }

    delete aux;

    return cartaSacada;
}


Carta sacarUltimaCarta(Cola*& frente, Cola*& fin) {

    Carta cartaSacada = fin->carta;

    if (frente == fin) {
        delete frente;
        frente = nullptr;
        fin = nullptr;
    } else {
        Cola* aux = frente;
        while (aux->siguiente != fin) {
            aux = aux->siguiente;
        }
        delete fin;
        fin = aux;
        fin->siguiente = nullptr;
    }

    return cartaSacada;
}

int obtenerTamanoCola(Cola* frente) {
    int tamano = 0;
    Cola* actual = frente;

    while (actual != nullptr) {
        ++tamano;
        actual = actual->siguiente;
    }

    return tamano;
}
