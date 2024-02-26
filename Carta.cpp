#include "Carta.h"

Carta::Carta(int _valor, string _figura, string _palo, string _color) {
    valor = _valor;
    figura = _figura;
    palo = _palo;
    color = _color;

}

int Carta::getValor() {return valor;}
string Carta::getFigura() {return figura;}
string Carta::getPalo() {return palo;}
string Carta::getColor() {return color;}
