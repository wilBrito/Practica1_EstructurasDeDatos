#include "Pizzeria.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "ColaPizza.h"
#include "Pedido.h"
using namespace std;
Pizzeria::Pizzeria()
{
    idcontado=0;
}

Pizzeria::~Pizzeria()
{
    //dtor
}
void Pizzeria::crear_N_pedidos(int num){
    int i=0;
    srand(time(NULL));
    while(i<num){
        string tipo=tipo_pizza[rand()%6];//tam tipo_pizza
        string tamanopizza=tamano[rand()%2];//tam de tamano
        string zona=zona_reparto[rand()%4];//tam de zona_reparto
        int cond=rand()%10;
        bool personalizada=(cond==0||cond==1);
        int idcligen=rand()%900+100;//id clientes (0-899)+100
        string num_a_string=to_string(idcontado);
        while(num_a_string.size()<5){
            num_a_string="0"+num_a_string;
        }
        string idgen="P"+num_a_string;
        Pedido pedidogen={idgen,idcligen,tipo,tamanopizza,zona,personalizada,"RECIBIDO"};
        colaPedidos.encolar(pedidogen);
        if(idcontado==99999){
            idcontado=0;
        }
        else{
            idcontado++;
        }
        i++;
    }
}
void Pizzeria::mostrar_pedidos(){
    colaPedidos.mostrarCola();
    colaCocina.mostrarCola();
    colaPedidosEspeciales.mostrarCola();
    colaExpNorte.mostrarCola();
    colaExpSur.mostrarCola();
    colaExpEste.mostrarCola();
    colaExpOeste.mostrarCola();
}
void Pizzeria::de_cocina_a_Exp(){
    Pedido aMover=colaCocina.inicio();
    if(aMover.zona_reparto=="NORTE"){
            aMover.estado = "EXP NORTE";
            colaExpNorte.encolar(aMover);}
    else if(aMover.zona_reparto=="SUR"){
            aMover.estado = "EXP SUR";
            colaExpSur.encolar(aMover);}
    else if(aMover.zona_reparto=="ESTE"){
            aMover.estado = "EXP ESTE";
            colaExpEste.encolar(aMover);}
    else if(aMover.zona_reparto=="OESTE"){
            aMover.estado = "EXP OESTE";
            colaExpOeste.encolar(aMover);}
    colaCocina.desencolar();
}

void Pizzeria::de_prepEsp_a_cocina(){
    Pedido aMover=colaPedidosEspeciales.inicio();
    aMover.estado = "COCINA";
    colaCocina.encolar(aMover);
    colaPedidosEspeciales.desencolar();
}

void Pizzeria::de_recibido_a_cocina_o_prepEsp(){
    Pedido aMover=colaPedidos.inicio();
    if(aMover.personalizada){
        aMover.estado = "PED ESP";
        colaPedidosEspeciales.encolar(aMover);
    }
    else{
        aMover.estado = "COCINA";
        colaCocina.encolar(aMover);
    }
    colaPedidos.desencolar();
}

void Pizzeria::N_Pedidos_Paso(int pasos){
    if(pasos<0){
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
        cout<< "NO SE PUEDEN DAR PASOS NEGATIVOS"<<endl;
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
    }
    else{
    int i=0;
    while(!colaCocina.es_vacia()&&i<pasos){
        de_cocina_a_Exp();
        i++;
    }
    while(!colaPedidosEspeciales.es_vacia()&&i<pasos){
        de_prepEsp_a_cocina();
        i++;
    }
    while(!colaPedidos.es_vacia()&&i<pasos){
        de_recibido_a_cocina_o_prepEsp();
        i++;
    }
    if(i<pasos){
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
        cout<<"NO SE HA PODIDO REALIZAR "<<pasos<<" PASOS, SE HAN REALIZADO "<< i <<" PASOS EN TOTAL"<<endl;
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;}
    else{
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
        cout<<"TODOS LOS PASOS REALIZADOS"<<endl;
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
    }
    }}

