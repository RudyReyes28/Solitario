#include <iostream>
#include "RellenarMazo.h"
#include "Cola.h"
#include "BarajarMazo.h"
#include "ImprimirCartas.h"
#include "Pila.h"

using namespace std;

int obtenerTamanoCola(Cola* frente) {
    int tamano = 0;
    Cola* actual = frente;

    while (actual != nullptr) {
        ++tamano;
        actual = actual->siguiente;
    }

    return tamano;
}

string obtenerFigura(Cola* fin){
    string cartaFigura = "  # ";
    if(fin != nullptr){
        cartaFigura = fin->carta.getFigura();
    }

    return cartaFigura;
}
int main() {
    Carta* mazo [52];
    RellenarMazo rellenar;
    rellenar.rellenarMazoCartas(mazo);

    barajarMazo(mazo,52);

    Cola * mazoFrente1 = nullptr;
    Cola * mazoFin1 = nullptr;

    Cola* mazoFrente2 = nullptr;
    Cola * mazoFin2 = nullptr;

    //PILAS PARA LOS ULTIMOS 4 MAZOS
    Pila*  corazones = nullptr;
    Pila*  diamantes = nullptr;
    Pila*  treboles = nullptr;
    Pila*  picas = nullptr;

    repartirCartas(mazo,52,mazoFrente1,mazoFin1);
    string cartaFigura = "  # ";
    char opcion = 's';
    imprimirColas(obtenerTamanoCola(mazoFrente1),cartaFigura);
    cout<<endl;
    imprimirPilas(corazones,diamantes,treboles,picas);
    do{

        cout<<"Sacar carta: "<<endl;
        cin>>opcion;
        cin.ignore();
        Carta cartaSacada = sacarCarta(mazoFrente1,mazoFin1);
        insertarCarta(mazoFrente2,mazoFin2,cartaSacada);

        cartaFigura = obtenerFigura(mazoFin2);
        int cantidadCartas = obtenerTamanoCola(mazoFrente1);
        imprimirColas(cantidadCartas,cartaFigura);


        if(cantidadCartas == 0){
            while (mazoFrente2!= nullptr){
                Carta nuevaCarta = sacarCarta(mazoFrente2,mazoFin2);
                insertarCarta(mazoFrente1,mazoFin1,nuevaCarta);
            }
             cantidadCartas = obtenerTamanoCola(mazoFrente1);
            imprimirColas(cantidadCartas,"  # ");
        }
        char opcionMazo2;
        cout<<"Sacar carta del segundo mazo: (s/n) "<<endl;
        cin>>opcionMazo2;
        cin.ignore();
        if(opcionMazo2 == 's'){
            Carta ultimaCarta = sacarUltimaCarta(mazoFrente2, mazoFin2);
            if(mazoFin2 != nullptr){
                cartaFigura = mazoFin2->carta.getFigura();
                cantidadCartas = obtenerTamanoCola(mazoFrente1);
                imprimirColas(cantidadCartas,cartaFigura);
            }


        }


    } while (opcion =='s');





    return 0;
}
