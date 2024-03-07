//
// Created by rudyo on 7/03/2024.
//

#ifndef SOLITARIO_LISTADOBLEENLAZADA_H
#define SOLITARIO_LISTADOBLEENLAZADA_H

#include "Carta.h"

struct Lista {
    Carta carta;
    Lista* izq;
    Lista* der;
};


#endif //SOLITARIO_LISTADOBLEENLAZADA_H
