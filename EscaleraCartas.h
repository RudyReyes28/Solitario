//
// Created by rudyo on 7/03/2024.
//

#ifndef SOLITARIO_ESCALERACARTAS_H
#define SOLITARIO_ESCALERACARTAS_H

#include "ListaDobleEnlazada.h"

class EscaleraCartas{
    private:
        Lista* inicio;
        Lista* fin;

    public:
        EscaleraCartas();
        void agregar(Carta carta);
        void mostrarInicioFin();
        void mostrarFinInicio();
        void mostrarInicio();
        void mostrarFin();
        void borrarValor(Carta carta);
};

#endif //SOLITARIO_ESCALERACARTAS_H
