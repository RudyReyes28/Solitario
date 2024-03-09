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

    if(filaInicial<=escaleraInicial.obtenerTamano() && escaleraInicial.obtenerTamano()>0){
        Carta cartaSacar = escaleraInicial.obtenerCartaEnPosicion(filaInicial-1);

        int auxiliarFila = filaInicial;
        int tamanoPrimeraEscalera = escaleraInicial.obtenerTamano();


        if(cartaSacar.getLevantado()){
            while(auxiliarFila <= tamanoPrimeraEscalera) {
                int pCartaUltima = escaleraFinal.obtenerTamano();
                cartaSacar = escaleraInicial.obtenerCartaEnPosicion(filaInicial-1);


                if (pCartaUltima == 0) {
                    if (cartaSacar.getValor() == 13) {
                        //HACEMOS EL MOVIMIENTO
                        escaleraInicial.borrarValor(cartaSacar);
                        escaleraFinal.agregar(cartaSacar);
                    } else {
                        cout << "No se mover esta carta, tiene que ser del tipo KING" << endl;
                    }
                } else {
                    Carta cartaUltima = escaleraFinal.mostrarFin();

                    if (cartaSacar.getValor() == (cartaUltima.getValor() - 1) &&
                        cartaSacar.getColor() != cartaUltima.getColor()) {
                        //CONFIGURAR EL IF

                        cout << "valor inicial:" << cartaSacar.getValor();
                        cout << " valor ultima:" << cartaUltima.getValor() << endl;
                        escaleraInicial.borrarValor(cartaSacar);
                        escaleraFinal.agregar(cartaSacar);
                    }else {
                        cout << "No se puede sacar esta carta" << endl;
                    }
                }

                auxiliarFila++;
            }

        }else{
            cout<<"No se puede sacar esta carta"<<endl;
        }

    }else{
        cout<<"No se puede sacar esta carta"<<endl;
    }
}

void moverStackEscaleras(Cola*& mazoFrente2, Cola*& mazoFin2,EscaleraCartas& escaleraA, EscaleraCartas& escaleraB, EscaleraCartas& escaleraC, EscaleraCartas& escaleraD, EscaleraCartas& escaleraE, EscaleraCartas& escaleraF, EscaleraCartas& escaleraG){
    if(obtenerTamanoCola(mazoFrente2) >0){

        if(mazoFin2 != nullptr){
            char columnaFinal;
            Carta cartaSacar = mazoFin2->carta;
            cout<<"Ingresa la columna final (A/B/C/D/F/G):";
            cin >> columnaFinal;
            EscaleraCartas& escaleraFinal = obtenerEscalera(columnaFinal,escaleraA, escaleraB,escaleraC, escaleraD,escaleraE, escaleraF, escaleraG);
            int pCartaUltima = escaleraFinal.obtenerTamano();

                if(pCartaUltima == 0){
                    if(cartaSacar.getValor() == 13){
                        //HACEMOS EL MOVIMIENTO
                        sacarUltimaCarta(mazoFrente2,mazoFin2);
                        cartaSacar.setLevantado(true);
                        escaleraFinal.agregar(cartaSacar);
                    }else{
                        cout<<"No se mover esta carta, tiene que ser del tipo KING"<<endl;
                    }
                }else{
                    Carta cartaUltima = escaleraFinal.mostrarFin();
                    if(cartaSacar.getValor()==cartaUltima.getValor()-1 && cartaSacar.getColor()!=cartaUltima.getColor()){
                        //CONFIGURAR EL IF
                        cout<<"valor inicial:"<< cartaSacar.getValor();
                        cout<<" valor ultima:"<< cartaUltima.getValor() <<endl;
                        sacarUltimaCarta(mazoFrente2,mazoFin2);
                        cartaSacar.setLevantado(true);
                        escaleraFinal.agregar(cartaSacar);
                    }else{
                        cout<<"No se puede sacar esta carta"<<endl;
                    }
                }
        }
    }else{
        cout<<"No hay carta por sacer" <<endl;
    }

}

void moverStackBase(Cola*& mazoFrente2, Cola*& mazoFin2, Pila*& corazones, Pila*& diamantes,Pila*& treboles, Pila*& picas){
    if(obtenerTamanoCola(mazoFrente2) >0){
        if(mazoFin2 != nullptr){
            Carta cartaSacar = mazoFin2->carta;

            if(cartaSacar.getPalo() == "CORAZONES"){
                identificarPaloCartas(mazoFrente2, mazoFin2, corazones);
            }else if(cartaSacar.getPalo() == "DIAMANTES"){
                identificarPaloCartas(mazoFrente2, mazoFin2, diamantes);
            }else if(cartaSacar.getPalo() == "TREBOLES"){
                identificarPaloCartas(mazoFrente2, mazoFin2, treboles);
            }else if(cartaSacar.getPalo() == "PICAS"){
                identificarPaloCartas(mazoFrente2, mazoFin2, picas);
            }
        }
    }else{
        cout<<"No hay carta por sacer" <<endl;
    }
}

void moverEscaleraBase(EscaleraCartas& escaleraA, EscaleraCartas& escaleraB, EscaleraCartas& escaleraC, EscaleraCartas& escaleraD, EscaleraCartas& escaleraE, EscaleraCartas& escaleraF, EscaleraCartas& escaleraG,  Pila*& corazones, Pila*& diamantes,Pila*& treboles, Pila*& picas){
    char columnaInicial;
    cout<<"Ingresa la columna inicial (A/B/C/D/F/G):";
    cin >> columnaInicial;
    cin.ignore();

    EscaleraCartas& escaleraInicial = obtenerEscalera(columnaInicial, escaleraA, escaleraB,escaleraC, escaleraD,escaleraE, escaleraF, escaleraG);

    if(escaleraInicial.obtenerTamano()>0){
        Carta cartaUltima = escaleraInicial.mostrarFin();

        if(cartaUltima.getPalo() == "CORAZONES"){
            identificarPaloEscaleras(corazones,escaleraInicial, cartaUltima);
        }else if(cartaUltima.getPalo() == "DIAMANTES"){
            identificarPaloEscaleras(diamantes,escaleraInicial, cartaUltima);
        }else if(cartaUltima.getPalo() == "TREBOLES"){
            identificarPaloEscaleras(treboles,escaleraInicial, cartaUltima);
        }else if(cartaUltima.getPalo() == "PICAS"){
            identificarPaloEscaleras(picas,escaleraInicial, cartaUltima);
        }
    }else{
        cout<<"No hay cartas por mover"<<endl;

    }

}

void identificarPaloCartas(Cola*& mazoFrente2, Cola*& mazoFin2, Pila*& palo){
    Carta cartaSacar = mazoFin2->carta;

        if(palo == nullptr ){
            if(cartaSacar.getValor() == 1) {
                sacarUltimaCarta(mazoFrente2, mazoFin2);
                cartaSacar.setLevantado(true);
                insertarCartaAPila(palo, cartaSacar);
            }else{
                cout<<"No se puede agregar la carta"<<endl;
            }
        }else if(palo->carta.getValor() == cartaSacar.getValor()-1){
            sacarUltimaCarta(mazoFrente2, mazoFin2);
            cartaSacar.setLevantado(true);
            insertarCartaAPila(palo, cartaSacar);
        }else{
            cout<<"No se puede agregar la carta"<<endl;
        }


}

void identificarPaloEscaleras(Pila*& palo, EscaleraCartas& escalera, Carta cartaSacar){
    if(palo == nullptr ){
        if(cartaSacar.getValor() == 1) {
            escalera.borrarValor(cartaSacar);
            cartaSacar.setLevantado(true);
            insertarCartaAPila(palo, cartaSacar);
        }else{
            cout<<"No se puede agregar la carta"<<endl;
        }
    }else if(palo->carta.getValor() == cartaSacar.getValor()-1){
        escalera.borrarValor(cartaSacar);
        cartaSacar.setLevantado(true);
        insertarCartaAPila(palo, cartaSacar);
    }else{
        cout<<"No se puede agregar la carta"<<endl;
    }
}