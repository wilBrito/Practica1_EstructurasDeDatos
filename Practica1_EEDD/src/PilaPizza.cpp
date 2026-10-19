#include "PilaPizza.h"
#include<Pedido.h>
#include<string>

using namespace std;

PilaPizza::PilaPizza()
{
    cima = NULL;
}

bool PilaPizza::esVacia(){
    return cima == NULL;
}

void PilaPizza::apilar(Pedido ped){
    NodoPilaPizza *nuevo_nodo = new NodoPilaPizza(ped, cima);

    cima = nuevo_nodo;
}

void PilaPizza::desapilar(){
    NodoPilaPizza *nodo;
    if(cima){
        nodo = cima;
        cima = nodo->siguiente;
        delete nodo;

    }
}

Pedido PilaPizza::mostrarCima(){
    if(!esVacia()){
        return cima->elementoPedido;
    }
    return Pedido(); //CUIDADO definir pedido fantasma vacio

}

void PilaPizza::mostrarPila(){


}
