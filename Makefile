CPP = g++
TARGET = solitario

# all
all: .all-post

.all-post: Carta.o Pila.o RellenarMazo.o Cola.o ListaDobleEnlazada.o EscaleraCartas.o BarajarMazo.o ImprimirCartas.o  MovimientoEscaleras.o main.o
	$(CPP) Carta.o Pila.o RellenarMazo.o Cola.o   ListaDobleEnlazada.o EscaleraCartas.o BarajarMazo.o ImprimirCartas.o  MovimientoEscaleras.o main.o -o $(TARGET)


Carta.o: Carta.cpp Carta.h
	$(CPP) -c Carta.cpp

Pila.o: Pila.cpp Pila.h
	$(CPP) -c Pila.cpp

RellenarMazo.o: RellenarMazo.cpp RellenarMazo.h
	$(CPP) -c RellenarMazo.cpp

Cola.o: Cola.cpp Cola.h
	$(CPP) -c Cola.cpp

ListaDobleEnlazada.o: ListaDobleEnlazada.cpp ListaDobleEnlazada.h
	$(CPP) -c ListaDobleEnlazada.cpp

EscaleraCartas.o: EscaleraCartas.cpp EscaleraCartas.h
	$(CPP) -c EscaleraCartas.cpp

BarajarMazo.o: BarajarMazo.cpp BarajarMazo.h
	$(CPP) -c BarajarMazo.cpp

ImprimirCartas.o: ImprimirCartas.cpp ImprimirCartas.h
	$(CPP) -c ImprimirCartas.cpp

MovimientoEscaleras.o: MovimientoEscaleras.cpp MovimientoEscaleras.h
	$(CPP) -c MovimientoEscaleras.cpp

main.o:
	$(CPP) -c main.cpp


# clean
clean:
	rm -f *.o $(TARGET)