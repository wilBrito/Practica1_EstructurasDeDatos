#ifndef PILAPIZZA_H
#define PILAPIZZA_H

#include "NodoPilaPizza.h"
#include<iostream>
#include<Pedido.h>

class PilaPizza
{
    private:
        NodoPilaPizza *cima;
    public:
        PilaPizza();

        bool esVacia();
        void apilar(Pedido ped);
        void desapilar();
        Pedido mostrarCima();
        void mostrarPila();
};

#endif // PILAPIZZA_H
