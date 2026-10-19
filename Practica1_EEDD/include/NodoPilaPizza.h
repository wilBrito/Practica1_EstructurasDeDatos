#ifndef NODOPILAPIZZA_H
#define NODOPILAPIZZA_H

#include "NodoPilaPizza.h"
#include<iostream>
#include<Pedido.h>

class NodoPilaPizza
{
    friend class PilaPizza;
    private:
        Pedido elementoPedido;
        NodoPilaPizza *siguiente;

    public:
        NodoPilaPizza();
        NodoPilaPizza(Pedido ped, NodoPilaPizza *sig = NULL);

};

#endif // NODOPILAPIZZA_H
