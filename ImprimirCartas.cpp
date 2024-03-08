//
// Created by rudyo on 26/02/2024.
//
#include <iostream>
#include "ImprimirCartas.h"
using namespace std;
void imprimirColas(int numero, string figura){
    cout<<"|||||||||   "<<"|||||||||"<<endl;
    cout<<"|       |   "<<"|       |"<<endl;
    cout<<"|  "<< numero << "   |   "<<"| "<<  figura  <<"  |"<<endl;
    cout<<"|       |   "<<"|       |"<<endl;
    cout<<"|||||||||   "<<"|||||||||"<<endl;

}

void imprimirPilas(Pila* corazones, Pila* diamantes,Pila* treboles,Pila* picas){
    string figuraCorazones = "  # ";
    string figuraDiamantes = "  # ";
    string figuraTreboles = "  # ";
    string figuraPicas = "  # ";

    if(corazones!= nullptr){
        figuraCorazones = corazones->carta.getFigura();
    }
    if(diamantes!= nullptr){
        figuraDiamantes = diamantes->carta.getFigura();
    }
    if(treboles!= nullptr){
        figuraTreboles = treboles->carta.getFigura();
    }
    if(picas!= nullptr){
        figuraPicas = picas->carta.getFigura();
    }
    cout<<"corazones   diamantes   treboles     picas"<<endl;
    cout<<"|||||||||   "<<"|||||||||   "<<"|||||||||   "<<"|||||||||"<<endl;
    cout<<"|       |   "<<"|       |   "<<"|       |   "<<"|       |"<<endl;
    cout<<"| "<< figuraCorazones << "  |   "<<"| "<<  figuraDiamantes  <<"  |   "<<"| "<< figuraTreboles << "  |   "<<"| "<<  figuraPicas  <<"  |"<<endl;
    cout<<"|       |   "<<"|       |   "<<"|       |   "<<"|       |"<<endl;
    cout<<"|||||||||   "<<"|||||||||   "<<"|||||||||   "<<"|||||||||"<<endl;

}

void imprimirEscaleras(EscaleraCartas escaleraA,EscaleraCartas escaleraB,EscaleraCartas escaleraC,EscaleraCartas escaleraD,EscaleraCartas escaleraE,EscaleraCartas escaleraF,EscaleraCartas escaleraG){
// Obtener la cantidad máxima de cartas en todas las escaleras
    int tamanios [] = {escaleraA.obtenerTamano(), escaleraB.obtenerTamano(), escaleraC.obtenerTamano(),
                         escaleraD.obtenerTamano(), escaleraE.obtenerTamano(), escaleraF.obtenerTamano(),
                         escaleraG.obtenerTamano()};

    int tamanoMayor = tamanios[0];
    for (int i = 1; i < 7; ++i) {
        if (tamanios[i] > tamanoMayor) {
            tamanoMayor = tamanios[i];
        }
    }

    // Imprimir cada fila
    cout<<"        A         B           C          D          E          F          G" <<endl;
    for (int i = 0; i < tamanoMayor; ++i) {
        // Imprimir la i-ésima carta de cada escalera
        cout << "  ";
        if (i < escaleraA.obtenerTamano()) {
            //cout << "||" << escaleraA.obtenerCartaEnPosicion(i).getFigura() << "||";
            cout << i+1<<" ";
            imprimirCartaDeEscalera(escaleraA,i);
        } else {
            cout << i+1<<" ";
            cout << "        ";
        }

        cout << "   ";

        if (i < escaleraB.obtenerTamano()) {
            //cout << "||" << escaleraB.obtenerCartaEnPosicion(i).getFigura() << "||";
            imprimirCartaDeEscalera(escaleraB,i);
        } else {
            cout << "        ";
        }

        cout << "   ";

        if (i < escaleraC.obtenerTamano()) {
            //cout << "||" << escaleraC.obtenerCartaEnPosicion(i).getFigura() << "||";
            imprimirCartaDeEscalera(escaleraC,i);
        } else {
            cout << "        ";
        }

        cout << "   ";

        if (i < escaleraD.obtenerTamano()) {
            //cout << "||" << escaleraD.obtenerCartaEnPosicion(i).getFigura() << "||";
            imprimirCartaDeEscalera(escaleraD,i);
        } else {
            cout << "        ";
        }

        cout << "   ";

        if (i < escaleraE.obtenerTamano()) {
            //cout << "||" << escaleraE.obtenerCartaEnPosicion(i).getFigura() << "||";
            imprimirCartaDeEscalera(escaleraE,i);
        } else {
            cout << "        ";
        }

        cout << "   ";

        if (i < escaleraF.obtenerTamano()) {
            //cout << "||" << escaleraF.obtenerCartaEnPosicion(i).getFigura() << "||";
            imprimirCartaDeEscalera(escaleraF,i);
        } else {
            cout << "        ";
        }
        cout << "   ";

        if (i < escaleraG.obtenerTamano()) {
            //cout << "||" << escaleraG.obtenerCartaEnPosicion(i).getFigura() << "||";
            imprimirCartaDeEscalera(escaleraG,i);
        } else {
            cout << "        ";
        }


        cout << endl;
    }
}

void imprimirCartaDeEscalera(EscaleraCartas escalera, int i){
    if(escalera.obtenerCartaEnPosicion(i).getLevantado()){
        cout << "||" << escalera.obtenerCartaEnPosicion(i).getFigura() << "||";
    }else{
        cout << "||" << "####" << "||";
    }

}