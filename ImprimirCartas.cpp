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
    cout<<"corazones   diamantes   treboles   picas"<<endl;
    cout<<"|||||||||   "<<"|||||||||   "<<"|||||||||   "<<"|||||||||"<<endl;
    cout<<"|       |   "<<"|       |   "<<"|       |   "<<"|       |"<<endl;
    cout<<"| "<< figuraCorazones << "  |   "<<"| "<<  figuraDiamantes  <<"  |   "<<"| "<< figuraTreboles << "  |   "<<"| "<<  figuraPicas  <<"  |"<<endl;
    cout<<"|       |   "<<"|       |   "<<"|       |   "<<"|       |"<<endl;
    cout<<"|||||||||   "<<"|||||||||   "<<"|||||||||   "<<"|||||||||"<<endl;

}