
#include "Colas.h"/*
void Colas::insertarCarta(ColaCartas *& frente, ColaCartas *& fin, Carta carta) {
    ColaCartas *nuevo_nodo = new ColaCartas();
    nuevo_nodo->getCarta() = carta;
    nuevo_nodo->getSiguiente() = nullptr;

    if(frente == nullptr){
        frente = nuevo_nodo;
    }else{
        fin->siguienteCarta=nuevo_nodo;
    }

    fin = nuevo_nodo;
}

void Colas::sacarCarta(ColaCartas *& frente, ColaCartas *& fin) {
    ColaCartas *aux = frente;

    if(frente == fin){
        frente = nullptr;
        fin = nullptr;
    }else{
        frente = frente->siguienteCarta;
    }

    delete aux;
}*/