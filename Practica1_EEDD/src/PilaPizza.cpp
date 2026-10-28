#include "PilaPizza.h"
#include<Pedido.h>
#include<string>
#include <ColaPizza.h>

using namespace std;

PilaPizza::PilaPizza()
{
    cima = NULL;
    capacidadActual = 6;
    enviados = 0;
    retirados = 0;
    encaja=0;
}

void PilaPizza::reiniciar(ColaPizza& cola){
    while (cima != NULL) {
            desapilar(cola);
        }
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

void PilaPizza::apilar(Pedido ped,ColaPizza& cola){
    NodoPilaPizza *nuevo_nodo = new NodoPilaPizza(ped, cima);

    cima = nuevo_nodo;
    encaja++;

    if(encaja==capacidadActual){
        enviados++;
        reiniciar(cola);
    }
}

void PilaPizza::desapilar(ColaPizza& cola){
    NodoPilaPizza *nodo;
    if(cima){
        nodo = cima;
        Pedido aFin=nodo->elementoPedido;
        aFin.estado="ENVIADO";
        cola.encolar(aFin);
        cima = nodo->siguiente;
        delete nodo;
        encaja--;

    }
}

Pedido PilaPizza::mostrarCima(){
    if(!esVacia()){
        return cima->elementoPedido;
    }
    return Pedido(); //CUIDADO definir pedido fantasma vacio

}
void PilaPizza::mostrarPila() {
    cout << "pedidos: " << encaja << "/" << capacidadActual << endl;

    NodoPilaPizza *aux = cima;
    if(encaja!=0){
    cout<<"CIMA"<<endl;}
    while (aux) {
        cout << aux->elementoPedido.id_pedido << endl;
        aux = aux->siguiente;
    }
    if(encaja!=0){
    cout<<"FONDO"<<endl;}

    cout << "cajas enviadas: " << enviados
         << " pedidos retirados: " << retirados << endl;
}
void PilaPizza::mostrarPilaSimple(){
    cout << "pedidos: " << encaja << "/" << capacidadActual <<"\t" <<"cajas enviadas: " << enviados<<endl;

}
void PilaPizza::retirarelemento(string id, ColaPizza& cola){
    bool encontrado=false;
    NodoPilaPizza *aux = cima;
    NodoPilaPizza *aborrar;
    if(aux->elementoPedido.id_pedido==id){
        cima=aux->siguiente;
        encaja--;
        retirados++;
        Pedido aFin=aux->elementoPedido;
        aFin.estado="RETIRADO";
        cola.encolar(aFin);
        delete aux;
        encontrado=true;
    }
    while(aux && !encontrado){
        if(aux->siguiente->elementoPedido.id_pedido==id){
            aborrar=aux->siguiente;
            Pedido aFin=aborrar->elementoPedido;
            aFin.estado="RETIRADO";
            cola.encolar(aFin);
            aux->siguiente=aux->siguiente->siguiente;
            delete aborrar;
            encaja--;
            encontrado=true;
        }
        else{
            aux=aux->siguiente;
        }
    }
    if(encontrado){
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
        cout<<"PEDIDO RETIRADO CORRECTAMENTE"<<endl;
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
    }
    else{
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
        cout<<"ELEMENTO NO ENCONTRADO"<<endl;
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
    }
}

