#include "PilaPizza.h"
#include<Pedido.h>
#include<string>

using namespace std;

PilaPizza::PilaPizza()
{
    cima = NULL;
    capacidadActual = 0;
    enviados = 0;
    retirados = 0;
}

void PilaPizza::reiniciar(){
    while (cima != NULL) {
            NodoPilaPizza *aux = cima;
            cima = cima->siguiente;
            delete aux;
        }
    capacidadActual = 0;
}

PilaPizza::PilaPizza(int cap)
{
    cima = NULL;
    capacidadActual = cap;
    enviados = 0;
    retirados = 0;
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
    NodoPilaPizza *aux= cima;
    if(esVacia()){
     /*   cout<<"----------------------------------------------------------------------------------------------------"<<endl;
        cout<<"Cola sin pedidos"<<endl;
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;*/
    }
    else{
        bool interfazAux = true;
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
        cout<<"Datos del Sistema: "<<endl;
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
        while(aux){
            Pedido pedidoact=aux->elementoPedido;
            if(interfazAux){
                cout<<pedidoact.estado<<":"<<endl;
                cout<<"----------------------------------------------------------------------------------------------------"<<endl;
                interfazAux = false;
            }
            cout<<"ID DEL PEDIDO :"<<pedidoact.id_pedido<<"\t"<<"ID DEL CLIENTE: "<<to_string(pedidoact.id_cliente)<<"\t"<<"TIPO: "<<pedidoact.tipo_pizza<<endl;
            cout<<"TAMANO DE LA PIZZA:"<<pedidoact.tamano<<"\t"<<"ZONA DE REPARTO: "<<pedidoact.zona_reparto<<"\t"<<"PERSONALIZADA: "<<pedidoact.personalizada<<endl;
            cout<<"ESTADO: "<<pedidoact.estado<<endl;
            cout<<"----------------------------------------------------------------------------------------------------"<<endl;
            aux=aux->siguiente;
        }
    }

}
