#ifndef NODOCOLAPIZZA_H
#define NODOCOLAPIZZA_H

#include<iostream>

class NodoColaPizza
{
    friend class Cola;
    private:
        NodoColaPizza *siguiente;
        Pedido elementoPedido; // Pertenece a Pizzeria
    public:
        NodoColaPizza();
        NodoColaPizza(Pedido p, NodoColaPizza *sig = NULL); //Pendiente pedido
        ~NodoColaPizza();


};

#endif // NODOCOLAPIZZA_H
