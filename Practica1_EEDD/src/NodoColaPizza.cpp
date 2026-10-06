#include "NodoColaPizza.h"

NodoColaPizza::NodoColaPizza()
{
    elementoPedido= NULL;
    siguiente=NULL;
    //ctor
}

NodoColaPizza::NodoColaPizza(Pedido p, NodoColaPizza *sig)
{
    elementoPedido = p;
    suiguiente = sig;
    //ctor
}

NodoColaPizza::~NodoColaPizza()
{
    //dtor
}
