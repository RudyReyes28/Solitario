#include <iostream>
#include "RellenarMazo.h"
#include "Cola.h"
#include "BarajarMazo.h"
#include "ImprimirCartas.h"
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
int main() {
    Carta* mazo [52];
    RellenarMazo rellenar;
    rellenar.rellenarMazoCartas(mazo);

    barajarMazo(mazo,52);

    Cola * mazoFrente1 = nullptr;
    Cola * mazoFin1 = nullptr;

    repartirCartas(mazo,52,mazoFrente1,mazoFin1);

    while (mazoFrente1!= nullptr){
        imprimirColas(obtenerTamanoCola(mazoFrente1),mazoFrente1->carta.getFigura());
        cout<<endl;
        cout<<endl;
        mazoFrente1 = mazoFrente1->siguiente;
    }




    return 0;
}
