//
// Created by rudyo on 7/03/2024.
//
#include <iostream>
#include "MovimientoEscaleras.h"
using namespace std;
EscaleraCartas& obtenerEscalera(char columna, EscaleraCartas& escaleraA, EscaleraCartas& escaleraB, EscaleraCartas& escaleraC, EscaleraCartas& escaleraD, EscaleraCartas& escaleraE, EscaleraCartas& escaleraF, EscaleraCartas& escaleraG) {
    switch (columna) {
        case 'A':
            return escaleraA;
        case 'B':
            return escaleraB;
        case 'C':
            return escaleraC;
        case 'D':
            return escaleraD;
        case 'E':
            return escaleraE;
        case 'F':
            return escaleraF;
        case 'G':
            return escaleraG;
        default:
            // Manejar el caso de una columna no válida según tus necesidades
            cerr << "Error: Columna no válida." << endl;
            // Devolver una referencia, podría ser cualquier referencia según tus necesidades
            return escaleraA;
    }
}

void moverEntreEscaleras(EscaleraCartas& escaleraA, EscaleraCartas& escaleraB, EscaleraCartas& escaleraC, EscaleraCartas& escaleraD, EscaleraCartas& escaleraE, EscaleraCartas& escaleraF, EscaleraCartas& escaleraG){

    char columnaInicial, columnaFinal;
    int filaInicial;

    cout<<"Ingresa la columna inicial (A/B/C/D/F/G):";
    cin >> columnaInicial;
    cout<<"Ingresa la fila inicial (1/2/3/4/5/6/7):";
    cin >> filaInicial;
    cout<<"Ingresa la columna final (A/B/C/D/F/G):";
    cin >> columnaFinal;
    cin.ignore();

    // Obtener las referencias de las escaleras correspondientes
    EscaleraCartas& escaleraInicial = obtenerEscalera(columnaInicial, escaleraA, escaleraB,escaleraC, escaleraD,escaleraE, escaleraF, escaleraG);
    EscaleraCartas& escaleraFinal = obtenerEscalera(columnaFinal,escaleraA, escaleraB,escaleraC, escaleraD,escaleraE, escaleraF, escaleraG);

    if(escaleraInicial.obtenerTamano()<=filaInicial && escaleraInicial.obtenerTamano()>0){
        Carta cartaSacar = escaleraInicial.obtenerCartaEnPosicion(filaInicial-1);
        int pCartaUltima = escaleraFinal.obtenerTamano();


        if(cartaSacar.getLevantado()){
            if(pCartaUltima == 0){
                if(cartaSacar.getValor() == 13){
                    //HACEMOS EL MOVIMIENTO
                    escaleraInicial.borrarValor(cartaSacar);
                    escaleraFinal.agregar(cartaSacar);
                }else{
                    cout<<"No se mover esta carta, tiene que ser del tipo KING"<<endl;
                }
            }else{
                Carta cartaUltima = escaleraFinal.mostrarFin();
                if(cartaSacar.getValor()<cartaUltima.getValor() && cartaSacar.getColor()!=cartaUltima.getColor()){
                    escaleraInicial.borrarValor(cartaSacar);
                    escaleraFinal.agregar(cartaSacar);
                }else{
                    cout<<"No se puede sacar esta carta"<<endl;
                }
            }

        }else{
            cout<<"No se puede sacar esta carta"<<endl;
        }

    }


}
