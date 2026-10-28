#ifndef PILAPIZZA_H
#define PILAPIZZA_H

#include "NodoPilaPizza.h"
#include<iostream>
#include<Pedido.h>
#include <ColaPizza.h>

#define CAP_CAJA 6
class PilaPizza
{
    friend class Pizzeria;
    private:
        NodoPilaPizza *cima;

        int capacidadActual;
        int enviados;
        int retirados;
        int encaja;
    public:
        PilaPizza();
        PilaPizza(int capacidad);

        bool esVacia();
        void apilar(Pedido ped);
        void desapilar();
        Pedido mostrarCima();
        void mostrarPila();
        void mostrarPilaSimple();

        void reiniciar();
        void retirarelemento(string id,ColaPizza& cola);
};

#endif // PILAPIZZA_H
