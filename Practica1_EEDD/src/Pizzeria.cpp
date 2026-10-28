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


    cout<<"=== CAJAS TERMICAS ==="<<endl;
    cout<<"Zona Este -> ";
    cajaEste.mostrarPilaSimple();
    cout<<"Zona Oeste -> ";
    cajaOeste.mostrarPilaSimple();
    cout<<"Zona Norte -> ";
    cajaNorte.mostrarPilaSimple();
    cout<<"Zona Sur -> ";
    cajaSur.mostrarPilaSimple();
    cout<<"Total de cajas enviadas: "<<cajaEste.enviados+cajaOeste.enviados+cajaSur.enviados+cajaNorte.enviados<<endl;
    cout<<"Total de pedidos enviados o retirados: "<<cajaEste.enviados*cajaEste.capacidadActual+cajaOeste.enviados*cajaOeste.capacidadActual+cajaSur.enviados*cajaSur.capacidadActual+cajaNorte.enviados*cajaNorte.capacidadActual+cajaEste.retirados+cajaOeste.retirados+cajaSur.retirados+cajaNorte.retirados<<endl;

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
void Pizzeria::deExpEste_a_cajaEste(){
    Pedido aMover=colaExpEste.inicio();
    aMover.estado="CAJA ESTE";
    cajaEste.apilar(aMover,finalizados);
    colaExpEste.desencolar();}
void Pizzeria::deExpOeste_a_cajaOeste(){
    Pedido aMover=colaExpOeste.inicio();
    aMover.estado="CAJA OESTE";
    cajaOeste.apilar(aMover,finalizados);
    colaExpOeste.desencolar();}
void Pizzeria::deExpNorte_a_cajaNorte(){
    Pedido aMover=colaExpNorte.inicio();
    aMover.estado="CAJA NORTE";
    cajaNorte.apilar(aMover,finalizados);
    colaExpNorte.desencolar();}
void Pizzeria::deExpSur_a_cajaSur(){
    Pedido aMover=colaExpSur.inicio();
    aMover.estado="CAJA SUR";
    cajaSur.apilar(aMover,finalizados);
    colaExpSur.desencolar();}

void Pizzeria::N_Pedidos_Paso(){
        int i=0;
        int pasos=10;
        //Se introdu. en cajas
        while(!colaExpNorte.es_vacia() && i<pasos){
            deExpNorte_a_cajaNorte();
        }
        i=0;
        while(!colaExpEste.es_vacia() && i<pasos){
            deExpEste_a_cajaEste();
        }
        i=0;
        while(!colaExpSur.es_vacia() && i<pasos){
            deExpSur_a_cajaSur();
        }
        i=0;
        while(!colaExpOeste.es_vacia() && i<pasos){
            deExpOeste_a_cajaOeste();
        }
        i=0;

        //Colas pizzeria
        while(!colaCocina.es_vacia()&&i<pasos){
            de_cocina_a_Exp();
        }
        i=0;
        while(!colaPedidosEspeciales.es_vacia()&&i<pasos){
            de_prepEsp_a_cocina();
        }
        i=0;
        while(!colaPedidos.es_vacia()&&i<pasos){
            de_recibido_a_cocina_o_prepEsp();
    }
    cout<<"----------------------------------------------------------------------------------------------------"<<endl;
    cout<<"PASOS EN CADA COLA DADOS CORRECTAMENTE"<<endl;
    cout<<"----------------------------------------------------------------------------------------------------"<<endl;
    }
void Pizzeria::mostrarPila(char zona){
    if(zona=='N'){
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
        cout<<"CAJA NORTE"<<endl;
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
        cajaNorte.mostrarPila();
    }
    else if(zona=='S'){
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
        cout<<"CAJA SUR"<<endl;
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
        cajaSur.mostrarPila();
    }
    else if(zona=='E'){
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
        cout<<"CAJA ESTE"<<endl;
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
        cajaEste.mostrarPila();
    }
    else if(zona=='O'){
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
        cout<<"CAJA OESTE"<<endl;
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
        cajaOeste.mostrarPila();
}}
void Pizzeria::retirarelemento(char zona,string id){
if(zona=='N'){
    cout<<"----------------------------------------------------------------------------------------------------"<<endl;
    cout<<"RETIRANDO EN ZONA NORTE"<<endl;
    cout<<"----------------------------------------------------------------------------------------------------"<<endl;
    cajaOeste.retirarelemento(id,finalizados);
}
else if(zona=='S'){
    cout<<"----------------------------------------------------------------------------------------------------"<<endl;
    cout<<"RETIRANDO EN ZONA SUR"<<endl;
    cout<<"----------------------------------------------------------------------------------------------------"<<endl;
    cajaSur.retirarelemento(id,finalizados);
}
else if(zona=='E'){
    cout<<"----------------------------------------------------------------------------------------------------"<<endl;
    cout<<"RETIRANDO EN ZONA ESTE"<<endl;
    cout<<"----------------------------------------------------------------------------------------------------"<<endl;
    cajaEste.retirarelemento(id,finalizados);
}
else if(zona=='O'){
    cout<<"----------------------------------------------------------------------------------------------------"<<endl;
    cout<<"RETIRANDO EN ZONA OESTE"<<endl;
    cout<<"----------------------------------------------------------------------------------------------------"<<endl;
    cajaOeste.retirarelemento(id,finalizados);
}}
void Pizzeria::mostrarColaFinalizados(){
finalizados.mostrarCola();}


