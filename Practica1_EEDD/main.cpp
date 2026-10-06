#include <iostream>
#include<ColaPizza.h>
#include<NodoColaPizza.h>
#include<Pedido.h>
#include<Pizzeria.h>

using namespace std;

int main()
{
    //Prueba

    //Generar pedido
    Pedido ped;

    ColaPizza cola;

    cout<< cola.es_vacia()<<endl;
    cola.mostrarCola();

    cola.encolar(ped);
    cout<< cola.es_vacia()<<endl;

    cola.mostrarCola();




    return 0;
}
