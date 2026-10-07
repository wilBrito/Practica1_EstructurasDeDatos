#ifndef COLAPIZZA_H
#define COLAPIZZA_H
#include "NodoColaPizza.h"
#include<iostream>
#include<Pedido.h>

class ColaPizza
{
    private:
        NodoColaPizza *primero;
        NodoColaPizza *ultimo;
        int longitud;

    public:
        ColaPizza();
        ~ColaPizza();

        void encolar(Pedido ped);
        Pedido inicio();
        Pedido fin();
        void desencolar();
        bool es_vacia();

        void mostrarCola(); //No es correcto
        int length();




};

#endif // COLAPIZZA_H
