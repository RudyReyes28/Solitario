//
// Created by rudyo on 7/03/2024.
//

#ifndef SOLITARIO_MOVIMIENTOESCALERAS_H
#define SOLITARIO_MOVIMIENTOESCALERAS_H

#include "EscaleraCartas.h"
#include "Cola.h"
#include "Pila.h"

void moverEntreEscaleras(EscaleraCartas& escaleraA, EscaleraCartas& escaleraB, EscaleraCartas& escaleraC, EscaleraCartas& escaleraD, EscaleraCartas& escaleraE, EscaleraCartas& escaleraF, EscaleraCartas& escaleraG);

EscaleraCartas& obtenerEscalera(char columna, EscaleraCartas& escaleraA, EscaleraCartas& escaleraB, EscaleraCartas& escaleraC, EscaleraCartas& escaleraD, EscaleraCartas& escaleraE, EscaleraCartas& escaleraF, EscaleraCartas& escaleraG);

void moverStackEscaleras(Cola*& mazoFrente2, Cola*& mazoFin2,EscaleraCartas& escaleraA, EscaleraCartas& escaleraB, EscaleraCartas& escaleraC, EscaleraCartas& escaleraD, EscaleraCartas& escaleraE, EscaleraCartas& escaleraF, EscaleraCartas& escaleraG);

void moverStackBase(Cola*& mazoFrente2, Cola*& mazoFin2, Pila*& corazones, Pila*& diamantes,Pila*& treboles, Pila*& picas);

void identificarPaloCartas(Cola*& mazoFrente2, Cola*& mazoFin2, Pila*& palo);
#endif //SOLITARIO_MOVIMIENTOESCALERAS_H
