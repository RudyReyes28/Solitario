cmake_minimum_required(VERSION 3.27)
project(Solitario)

set(CMAKE_CXX_STANDARD 17)

add_executable(Solitario main.cpp
        Carta.h
        RellenarMazo.h
        Carta.cpp
        RellenarMazo.cpp
        Cola.h
        Cola.cpp
        BarajarMazo.h
        BarajarMazo.cpp
        ImprimirCartas.h
        ImprimirCartas.cpp
        Pila.cpp
        Pila.h
        ListaDobleEnlazada.cpp
        ListaDobleEnlazada.h
        EscaleraCartas.cpp
        EscaleraCartas.h
        MovimientoEscaleras.cpp
        MovimientoEscaleras.h)
