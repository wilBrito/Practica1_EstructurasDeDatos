#include "NodoPilaPizza.h"

NodoPilaPizza::NodoPilaPizza()
{
    elementoPedido= Pedido(); //CUIDADO mete un pedido no vacio del todo PROVISIONAL
    siguiente=NULL;
    //ctor
}

NodoPilaPizza::NodoPilaPizza(Pedido p, NodoPilaPizza *sig)
{
    elementoPedido = p;
    siguiente = sig;
    //ctor
}


