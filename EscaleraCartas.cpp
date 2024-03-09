//
// Created by rudyo on 7/03/2024.
//

#include <iostream>
#include "EscaleraCartas.h"
using namespace std;
EscaleraCartas::EscaleraCartas() {
    inicio = nullptr;
    fin = nullptr;
}

void EscaleraCartas::agregar(Carta carta)
{
    Lista* nuevo = new Lista();
    nuevo->carta = carta;
    if (inicio == nullptr) {
        inicio = nuevo;
        fin = nuevo;
        nuevo->izq = nullptr;
        nuevo->der = nullptr;
    }
    else {
        nuevo->izq = fin;
        fin->der = nuevo;
        fin = fin->der;
        //FIN = nuevo
        fin->der = nullptr;
    }
}

void EscaleraCartas::mostrarInicioFin()
{
    Lista* reco = inicio;
    while (reco!= nullptr)
    {
        cout << reco->carta.getFigura() << endl;
        reco=reco->der;
    }
}

void EscaleraCartas::mostrarFinInicio()
{
    Lista* reco = fin;
    while (reco != nullptr)
    {
        cout << reco->carta.getFigura() << endl;
        reco = reco->izq;
    }
}

void EscaleraCartas::mostrarInicio()
{
    cout << "Primer elemento: " << inicio->carta.getFigura() << endl;
}

Carta EscaleraCartas::mostrarFin()
{
    return fin->carta;
}

void EscaleraCartas::borrarValor(Carta carta)
{
    if (inicio == nullptr) {
        cout << "No se puede borrar el elemento " << carta.getFigura() << " porque la lista esta vacia!" << endl;
    }else if (inicio->carta.getFigura() == carta.getFigura()) {
        Lista* borrarInicio = inicio;
        inicio = inicio->der;
        //inicio->izq = nullptr;
        if (inicio != nullptr) {
            inicio->izq = nullptr;
        }
        delete borrarInicio;

    }else if (fin->carta.getFigura() == carta.getFigura()) {
        Lista* borrarFin = fin;
        fin = fin->izq;
        fin->carta.setLevantado(true);
        fin->der = nullptr;
        delete borrarFin;
    }else {
        Lista* reco = inicio->der;
        Lista* anterior;
        Lista* siguiente;
        Lista* borrar;
        while (reco->der != nullptr)
        {
            if (reco->carta.getFigura() == carta.getFigura()) {
                anterior = reco->izq;
                siguiente = reco->der;
                borrar = reco;
                anterior->der = siguiente;
                siguiente->izq = anterior;
                delete borrar;
                break;
            }
            reco=reco->der;
        }
    }
}

int EscaleraCartas::obtenerTamano() {
    int tamano = 0;
    Lista* actual = inicio;

    while (actual != nullptr) {
        tamano++;
        actual = actual->der;  // Avanza al siguiente nodo
    }

    return tamano;

}

Carta EscaleraCartas::obtenerCartaEnPosicion(int posicion) {
    int tamano=0;
    Carta carta;
    Lista* actual = inicio;

    while (actual != nullptr) {
        if(tamano == posicion){
            return actual->carta;
        }
        tamano++;
        actual = actual->der;  // Avanza al siguiente nodo
    }

    return carta;
}

void EscaleraCartas::siguienteAnterior(int posicion){
        int tamano = 0;
        Lista* actual = inicio;

        while (actual != nullptr) {
            if (tamano == posicion) {
                // Verificar y modificar la carta del nodo anterior
                if (actual->izq != nullptr) {
                    actual->izq->carta.setLevantado(true);
                }

                // Verificar y modificar la carta del nodo siguiente
                if (actual->der != nullptr) {
                    actual->der->carta.setLevantado(true);
                }

                // Romper el bucle ya que hemos realizado las modificaciones
                break;
            }

            tamano++;
            actual = actual->der;  // Avanza al siguiente nodo
        }
}