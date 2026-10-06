#ifndef COLAPIZZA_H
#define COLAPIZZA_H
#include "NodoColaPizza.h"
#include<iostream>

class ColaPizza
{
    private:
        NodoColaPizza *primero;
        NodoColaPizza *ultimo;
        int longitud;

    public:
        ColaPizza();
        ~ColaPizza();

        void encolar(Pedido);
        Pedido inicio();
        Pedido fin();
        Pedido desencolar();
        bool es_vacia();

        void mostrarCola(); //No es correcto




};

#endif // COLAPIZZA_H
