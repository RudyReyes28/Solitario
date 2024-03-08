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

void repartirCartas(Carta* mazo[],Cola *& frente,Cola*& fin) {
    for(int i=0; i<24; i++){

        insertarCarta(frente,fin,*mazo[i]);
    }

}

void repartirCartasEscalera(Carta* mazo[], EscaleraCartas& escaleraA,EscaleraCartas& escaleraB,EscaleraCartas& escaleraC,EscaleraCartas& escaleraD,EscaleraCartas& escaleraE,EscaleraCartas& escaleraF,EscaleraCartas& escaleraG){
    for(int i=24; i<52; i++){
        if(i==24){
            Carta carta = *mazo[i];
            carta.setLevantado(true);
            escaleraA.agregar(carta);

        }else if(i== 25 || i==26){
            Carta carta = *mazo[i];
            if(i==26){carta.setLevantado(true);}
            escaleraB.agregar(carta);
        }else if(i>26 && i<30){
            Carta carta = *mazo[i];
            if(i==29){carta.setLevantado(true);}
            escaleraC.agregar(carta);
        }else if(i>=30 && i<=33){
            Carta carta = *mazo[i];
            if(i==33){carta.setLevantado(true);}
            escaleraD.agregar(carta);
        }else if(i>=34 && i<=38){
            Carta carta = *mazo[i];
            if(i==38){carta.setLevantado(true);}
            escaleraE.agregar(carta);
        }else if(i>=39 && i<=44){
            Carta carta = *mazo[i];
            if(i==44){carta.setLevantado(true);}
            escaleraF.agregar(carta);
        }else if(i>=45){
            Carta carta = *mazo[i];
            if(i==51){carta.setLevantado(true);}
            escaleraG.agregar(carta);
        }

    }
}
