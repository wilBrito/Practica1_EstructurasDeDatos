#include "ColaPizza.h"
#include<Pedido.h>

#include<string>

using namespace std;

ColaPizza::ColaPizza()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
    //ctor
}

ColaPizza::~ColaPizza()
{
    //dtor
}

void ColaPizza::encolar(Pedido ped){
    NodoColaPizza *nuevo_nodo = new NodoColaPizza(ped);
    if(es_vacia()){
        primero = nuevo_nodo;
        ultimo = nuevo_nodo;
    }
    else{
        ultimo->siguiente = nuevo_nodo;
        ultimo = nuevo_nodo;
    }
    longitud++;
}

void ColaPizza::desencolar(){
    if(!es_vacia()){
        NodoColaPizza *aux = primero;

        if((primero == ultimo) && (primero->siguiente == NULL)){
            primero = NULL;
            ultimo = NULL;
            aux->siguiente = NULL;
            delete(aux);
        }
        else{
            primero = primero->siguiente;
            aux->siguiente = NULL;
            delete(aux);
        }
        longitud--;

    }
}

Pedido ColaPizza::inicio(){
    if(!es_vacia()){
        return primero->elementoPedido;
    }
    return Pedido(); //CUIDADO definir pedido fantasma vacio
}


Pedido ColaPizza::fin(){
    if(!es_vacia()){
        return ultimo->elementoPedido;
    }
    return Pedido(); //CUIDADO definir pedido fantasma vacio
}

bool ColaPizza::es_vacia(){
    return((primero ==NULL)&&(ultimo==NULL));
}


//No es correcto
void ColaPizza::mostrarCola(){
    NodoColaPizza *aux=primero;
    if(es_vacia()){
        cout<<"Cola Vacía"<<endl;
    }
    else{
        cout<<"Datos de la Cola: "<<endl;
        while(aux){
            aux->elementoPedido.mostrarPedido();
            cout<<aux->elementoPedido.mostrarPedido()<<endl;
            aux = aux->siguiente;
        }
    }
}

int ColaPizza::length(){
    NodoColaPizza *aux = primero;
    int cont = 0;

    if(es_vacia()){
    }
    else{
        while(aux){
            aux = aux ->siguiente;
            cont++;
        }
    }
    return cont;
}
