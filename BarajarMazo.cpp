//
// Created by rudyo on 26/02/2024.
//

#include <ctime>
#include "BarajarMazo.h"

void barajarMazo(Carta* mazo[], int tamano) {
    srand(time(nullptr));  // Inicializar la semilla del generador de números aleatorios

    for (int i = tamano - 1; i > 0; --i) {
        // Generar un índice aleatorio entre 0 e i
        int j = rand() % (i + 1);

        // Intercambiar las cartas en las posiciones i y j
        Carta* temp = mazo[i];
        mazo[i] = mazo[j];
        mazo[j] = temp;
    }
}

void repartirCartas(Carta* mazo[], int tamano,Cola *& frente,Cola*& fin) {
    for(int i=0; i<24; i++){
        insertarCarta(frente,fin,*mazo[i]);
    }

}
