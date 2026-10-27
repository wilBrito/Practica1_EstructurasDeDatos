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

void PilaPizza::reiniciar(){
    while (cima != NULL) {
            desapilar();
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

void PilaPizza::apilar(Pedido ped){
    NodoPilaPizza *nuevo_nodo = new NodoPilaPizza(ped, cima);

    cima = nuevo_nodo;
    encaja++;
    if(encaja==capacidadActual){
        enviados++;
        reiniciar();
    }
}

void PilaPizza::desapilar(){
    NodoPilaPizza *nodo;
    if(cima){
        nodo = cima;
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

    while (aux) {
        cout << aux->elementoPedido.id_pedido << endl;
        aux = aux->siguiente;
    }

    cout << "cajas enviadas: " << enviados
         << " pedidos retirados: " << retirados << endl;
}
void PilaPizza::retirarelemento(string id){
    if(id.length() != 6){
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
        cout<<"ID CON LONGITUD INVÁLIDA"<<endl;
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
    }
    else if(id[0] != 'P'){
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
        cout<<"PEDIDOS DEBEN EMPEZAR CON 'P'"<<endl;
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;

}
else{
    bool encontrado=false;
    NodoPilaPizza *aux = cima;
    NodoPilaPizza *aborrar;
    if(aux->elementoPedido.id_pedido==id){
        cima=aux->siguiente;
        encaja--;
        delete aux;
        encontrado=true;
    }
    while(aux && !encontrado){
        if(aux->siguiente->elementoPedido.id_pedido==id){
            aborrar=aux->siguiente;
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
    }}
}

