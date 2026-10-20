#ifndef PILAPIZZA_H
#define PILAPIZZA_H

#include "NodoPilaPizza.h"
#include<iostream>
#include<Pedido.h>


#define CAP_CAJA 6
class PilaPizza
{
    friend class Pizzeria;
    private:
        NodoPilaPizza *cima;

        int capacidadActual;
        int enviados;
        int retirados;
    public:
        PilaPizza();
        PilaPizza(int capacidad);

        bool esVacia();
        void apilar(Pedido ped);
        void desapilar();
        Pedido mostrarCima();
        void mostrarPila();

        void reiniciar();
};

#endif // PILAPIZZA_H
