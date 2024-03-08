#include <string>
#ifndef CARTA_H // Si no está definido el macro CARTA_H
#define CARTA_H // Definir el macro CARTA_H
using namespace std;


class Carta{
private:
    int valor;
    string figura;
    string palo;
    string color;
    bool levantado;

public:
    Carta();
    Carta(int , string, string, string);
    int getValor();
    string getFigura();
    string getPalo();
    string getColor();
    bool getLevantado();
    void setLevantado(bool valor);

};

#endif // CARTA_H // Terminar el bloque del #ifndef




