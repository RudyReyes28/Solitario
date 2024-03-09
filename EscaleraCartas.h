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
        Carta mostrarFin();
        void borrarValor(Carta carta);
        int obtenerTamano();
        Carta obtenerCartaEnPosicion(int posicion);
        void siguienteAnterior(int posicion);
};

#endif //SOLITARIO_ESCALERACARTAS_H
