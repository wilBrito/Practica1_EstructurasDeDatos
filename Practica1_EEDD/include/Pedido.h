#ifndef PEDIDO_H
#define PEDIDO_H
#include<string>

using namespace std;

struct Pedido
{

    int id_pedido;
    //Alberto, necesito un constructor pedido vacio y otro normal con las caracteristicas del trabajo
    Pedido();

    string mostrarPedido();



};

#endif // PEDIDO_H
