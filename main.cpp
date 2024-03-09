#include <iostream>
#include "RellenarMazo.h"
#include "Cola.h"
#include "BarajarMazo.h"
#include "ImprimirCartas.h"
#include "Pila.h"
#include "EscaleraCartas.h"
#include "MovimientoEscaleras.h"

using namespace std;


string obtenerFigura(Cola* fin){
    string cartaFigura = "  # ";
    if(fin != nullptr){
        cartaFigura = fin->carta.getFigura();
    }

    return cartaFigura;
}

bool verificarGanador(Pila*  corazones,Pila*  diamantes, Pila*  treboles,Pila*  picas){


    int cantCorazones = obtenerTamanoPila(corazones);
    int cantDiamantes = obtenerTamanoPila(diamantes);
    int cantTreboles = obtenerTamanoPila(treboles);
    int cantPicas = obtenerTamanoPila(picas);

    if(cantCorazones==13 && cantDiamantes==13 && cantTreboles == 13 && cantPicas == 13){
        return true;
    }else{
        return false;
    }


}

int main() {
    Carta* mazo [52];
    RellenarMazo rellenar;
    rellenar.rellenarMazoCartas(mazo);

    barajarMazo(mazo,52);

    //COLAS PARA LOS PRIMEROS DOS MAZOS
    Cola * mazoFrente1 = nullptr;
    Cola * mazoFin1 = nullptr;

    Cola* mazoFrente2 = nullptr;
    Cola * mazoFin2 = nullptr;


    //PILAS PARA LOS ULTIMOS 4 MAZOS
    Pila*  corazones = nullptr;
    Pila*  diamantes = nullptr;
    Pila*  treboles = nullptr;
    Pila*  picas = nullptr;

    //LISTAS ENLAZADAS PARA LAS ESCALERAS
    EscaleraCartas escaleraA;
    EscaleraCartas escaleraB;
    EscaleraCartas escaleraC;
    EscaleraCartas escaleraD;
    EscaleraCartas escaleraE;
    EscaleraCartas escaleraF;
    EscaleraCartas escaleraG;

    repartirCartas(mazo,mazoFrente1,mazoFin1);
    repartirCartasEscalera(mazo,escaleraA,escaleraB,escaleraC,escaleraD,escaleraE,escaleraF,escaleraG);

    int opcion=0;
    string cartaFigura = "  # ";
    do {
        cartaFigura = obtenerFigura(mazoFin2);
        int cantidadCartas = obtenerTamanoCola(mazoFrente1);
        imprimirColas(cantidadCartas,cartaFigura);
        imprimirEscaleras(escaleraA, escaleraB, escaleraC, escaleraD, escaleraE, escaleraF, escaleraG);
        imprimirPilas(corazones,diamantes,treboles,picas);
        cout << endl;
        cout<<"--------- SOLITARIO ------------"<<endl;
        cout<<"1. Levantar cartas del stock"<<endl;
        cout<<"2. Mover carta del stock a la escalera"<<endl;
        cout<<"3. Mover cartas entre escaleras"<<endl;
        cout<<"4. Mover del stock a base (4 pilas)"<<endl;
        cout<<"5. Mover de la escalera a base (4 pilas)"<<endl;
        cout<<"6. Ver el siguiente y anterior"<<endl;
        cout<<"7. Salir del juego"<<endl;
        cout<<"Ingrese la opcion:";
        cin >> opcion;
        cin.ignore();
        if(opcion == 1){
             cantidadCartas = obtenerTamanoCola(mazoFrente1);
            if(cantidadCartas>0){
                Carta cartaSacada = sacarCarta(mazoFrente1,mazoFin1);
                insertarCarta(mazoFrente2,mazoFin2,cartaSacada);
            }else{
                cout<<"Reinicie el stock"<<endl;
            }

            if(cantidadCartas == 0){
                char reiniciarStack;
                cout<<"1. Reiniciar Stack (S/N): "<<endl;
                cin >> reiniciarStack;
                cin.ignore();
                cout<<endl;

                if(reiniciarStack == 'S') {
                    while (mazoFrente2 != nullptr) {
                        Carta nuevaCarta = sacarCarta(mazoFrente2, mazoFin2);
                        insertarCarta(mazoFrente1, mazoFin1, nuevaCarta);
                    }
                }
            }
        }else if(opcion == 2){
            moverStackEscaleras(mazoFrente2,mazoFin2,escaleraA, escaleraB, escaleraC, escaleraD, escaleraE, escaleraF, escaleraG);

        }else if(opcion == 3) {
            moverEntreEscaleras(escaleraA, escaleraB, escaleraC, escaleraD, escaleraE, escaleraF, escaleraG);


        }else if(opcion == 4){
            moverStackBase(mazoFrente2, mazoFin2,corazones,diamantes,treboles,picas);

        }else if(opcion == 5){
            moverEscaleraBase(escaleraA, escaleraB, escaleraC, escaleraD, escaleraE, escaleraF, escaleraG,corazones,diamantes,treboles,picas);
        }else if(opcion == 6){
            verSiguienteYAnterior(escaleraA,escaleraB,escaleraC,escaleraD,escaleraE,escaleraF,escaleraG);
        }

        if(verificarGanador(corazones,diamantes,treboles,picas)){
            cout<<"HA GANADO"<<endl;
            opcion = 7;
        }


    }while(opcion != 7);



    return 0;
}
