#include "NodoColaPizza.h"
#include<Pedido.h>

using namespace std;

NodoColaPizza::NodoColaPizza()
{
    elementoPedido= Pedido(); //CUIDADO mete un pedido no vacio del todo PROVISIONAL
    siguiente=NULL;
    //ctor
}

NodoColaPizza::NodoColaPizza(Pedido p, NodoColaPizza *sig)
{
    elementoPedido = p;
    siguiente = sig;
    //ctor
}

NodoColaPizza::~NodoColaPizza()
{
    //dtor
}
