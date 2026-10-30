#include "ColaPizza.h"
#include<Pedido.h>
#include <iomanip>
#include<string>

using namespace std;

ColaPizza::ColaPizza()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
    //ctor
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



void ColaPizza::mostrarCola(){

    NodoColaPizza *aux=primero;
    if(es_vacia()){
     /*   cout<<"----------------------------------------------------------------------------------------------------"<<endl;
        cout<<"Cola sin pedidos"<<endl;
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;*/
    }
    else{
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
        cout<<"Datos del Sistema: "<<endl;
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
        if(primero->elementoPedido.estado=="RETIRADO" || primero->elementoPedido.estado=="ENVIADO"){
        cout<<"=== FINALIZADOS ==="<<":"<<endl;
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;}
        else{
        cout<<"=== "<<primero->elementoPedido.estado<<" ==="<<endl;
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
        }
        cout <<left<<setw(10)<<"PEDIDO"<<setw(2)<<'|'<<setw(12)<<"CLIENTE"<<setw(2)<<'|'<<setw(15)<<"PIZZA"<<setw(2)<<'|'<<setw(15)<<"TAMANO"
        <<setw(2)<<'|'<<setw(15)<<"ZONA"<<setw(2)<<'|'<<setw(8)<<"PERS"<<setw(2)<<'|'<<setw(12)<<"ESTADO"<<setw(2)<<'|'<<endl;
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
        while(aux){
            Pedido pedidoact=aux->elementoPedido;
            cout << left<<setw(10)<<pedidoact.id_pedido<<setw(2)<<'|'<<setw(12)<<pedidoact.id_cliente<<setw(2)<<'|'<<setw(15)<<pedidoact.tipo_pizza
            <<setw(2)<<'|'<<setw(15)<<pedidoact.tamano<<setw(2)<<'|'<<setw(15)<<pedidoact.zona_reparto<<setw(2)<<'|'<<setw(8)<<pedidoact.personalizada
            <<setw(2)<<'|'<<setw(12)<<pedidoact.estado<<setw(2)<<'|'<<endl;
            aux=aux->siguiente;
        }
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
    }
}

void ColaPizza::mostrarColaF(){
    if(es_vacia()){
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
        cout<<"Cola sin pedidos"<<endl;
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
    }
    else{
        NodoColaPizza *aux=primero;
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
        cout<<"=== FINALIZADOS ==="<<endl;
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
        cout <<left<<setw(10)<<"PEDIDO"<<setw(2)<<'|'<<setw(12)<<"CLIENTE"<<setw(2)<<'|'<<setw(15)<<"PIZZA"<<setw(2)<<'|'<<setw(15)<<"TAMANO"
        <<setw(2)<<'|'<<setw(15)<<"ZONA"<<setw(2)<<'|'<<setw(8)<<"PERS"<<setw(2)<<'|'<<setw(12)<<"ESTADO"<<setw(2)<<'|'<<endl;
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
        while(aux){
            Pedido pedidoact=aux->elementoPedido;
             cout << left<<setw(10)<<pedidoact.id_pedido<<setw(2)<<'|'<<setw(12)<<pedidoact.id_cliente<<setw(2)<<'|'<<setw(15)<<pedidoact.tipo_pizza
            <<setw(2)<<'|'<<setw(15)<<pedidoact.tamano<<setw(2)<<'|'<<setw(15)<<pedidoact.zona_reparto<<setw(2)<<'|'<<setw(8)<<pedidoact.personalizada
            <<setw(2)<<'|'<<setw(12)<<pedidoact.estado<<setw(2)<<'|'<<endl;
            aux=aux->siguiente;
        }
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;

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
