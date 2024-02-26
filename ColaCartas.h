
#include "Carta.h"

class ColaCartas{
private:
    Carta carta;
    ColaCartas * siguienteCarta;

public:
    ColaCartas();
    Carta getCarta();
    ColaCartas * getSiguiente();
};