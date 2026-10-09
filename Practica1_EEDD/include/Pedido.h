#ifndef PEDIDO_H
#define PEDIDO_H
#include<string>

using namespace std;

struct Pedido
{

    string id_pedido;
    int id_cliente;
    string tipo_pizza;
    string tamano;
    string zona_reparto;
    bool personalizada;
    string estado;
};

#endif // PEDIDO_H
