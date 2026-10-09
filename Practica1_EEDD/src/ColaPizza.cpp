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
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
        cout<<"Cola sin pedidos"<<endl;
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
    }
    else{
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
        cout<<"Datos de la Cola de pedidos: "<<endl;
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
        while(aux){
            Pedido pedidoact=aux->elementoPedido;
            cout<<"ID DEL PEDIDO :"<<pedidoact.id_pedido<<"\t"<<"ID DEL CLIENTE: "<<to_string(pedidoact.id_cliente)<<"\t"<<"TIPO: "<<pedidoact.tipo_pizza<<endl;
            cout<<"TAMANO DE LA PIZZA:"<<pedidoact.tamano<<"\t"<<"ZONA DE REPARTO: "<<pedidoact.zona_reparto<<"\t"<<"PERSONALIZADA: "<<pedidoact.personalizada<<endl;
            cout<<"ESTADO: "<<pedidoact.estado<<endl;
            cout<<"----------------------------------------------------------------------------------------------------"<<endl;
            aux=aux->siguiente;
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
