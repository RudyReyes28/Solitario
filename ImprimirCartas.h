//
// Created by rudyo on 26/02/2024.
//

#ifndef SOLITARIO_IMPRIMIRCARTAS_H
#define SOLITARIO_IMPRIMIRCARTAS_H

#include "Cola.h"
#include "Pila.h"
#include "EscaleraCartas.h"

void imprimirColas(int numero, string figura);

void imprimirPilas(Pila* corazones, Pila* diamantes,Pila* treboles,Pila* picas);

void imprimirEscaleras(EscaleraCartas escaleraA,EscaleraCartas escaleraB,EscaleraCartas escaleraC,EscaleraCartas escaleraD,EscaleraCartas escaleraE,EscaleraCartas escaleraF,EscaleraCartas escaleraG);
void imprimirCartaDeEscalera(EscaleraCartas escalera, int i);
#endif //SOLITARIO_IMPRIMIRCARTAS_H
