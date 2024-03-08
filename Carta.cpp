#include "Carta.h"

Carta::Carta(int _valor, string _figura, string _palo, string _color) {
    valor = _valor;
    figura = _figura;
    palo = _palo;
    color = _color;
    levantado = false;

}

Carta::Carta() {}

int Carta::getValor() {return valor;}
string Carta::getFigura() {return figura;}
string Carta::getPalo() {return palo;}
string Carta::getColor() {return color;}
bool Carta::getLevantado() {return levantado;}
void Carta::setLevantado(bool valor) { levantado = valor;}
