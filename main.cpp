#include <iostream>
#include "RellenarMazo.h"
#include "ColaCartas.h"
using namespace std;



int main() {
    Carta* mazo [52];
    ColaCartas cola;
    RellenarMazo rellenar;
    rellenar.rellenarMazoCartas(mazo);

    ColaCartas * mazoFrente1 = nullptr;
    ColaCartas * mazoFin1 = nullptr;


    //cola.insertarCarta(mazoFrente1,mazoFin1,*mazo[0]);
    //cola.insertarCarta(mazoFrente1,mazoFin1,*mazo[1]);
    //cola.insertarCarta(mazoFrente1,mazoFin1,*mazo[2]);

    while (mazoFrente1!= nullptr){

        cout<<"Carta: "<<mazoFrente1->getCarta().getFigura()<<endl;
        //cola.sacarCarta(mazoFrente1,mazoFin1);

    }

    /*for(int i=0; i<52; i++){
        cout<<i <<" Carta: "<<mazo[i]->getFigura()<<endl;
    }*/



    return 0;
}
