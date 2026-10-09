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
}
