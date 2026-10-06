#include "Pedido.h"
#include<iostream>
#include<string>

using namespace std;


Pedido::Pedido()
{
    id_pedido = 1111;
    //ctor
}

string Pedido::mostrarPedido(){
    return to_string(id_pedido);
}


