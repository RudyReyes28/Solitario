#include <iostream>
#include "RellenarMazo.h"
using namespace std;



int main() {
    Carta* mazo [52];
    RellenarMazo rellenar;
    rellenar.rellenarMazoCartas(mazo);


    for(int i=0; i<52; i++){
        cout<<i <<" Carta: "<<mazo[i]->getFigura()<<endl;
    }



    return 0;
}
