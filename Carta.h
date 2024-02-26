#include <string>

using namespace std;


class Carta{
private:
    int valor;
    string figura;
    string palo;
    string color;

public:
    Carta(int , string, string, string);
    int getValor();
    string getFigura();
    string getPalo();
    string getColor();

};






