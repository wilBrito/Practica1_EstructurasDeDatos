#include <iostream>
#include<ColaPizza.h>
#include<NodoColaPizza.h>
#include<Pedido.h>
#include<Pizzeria.h>

using namespace std;

int menu(){
    int result;
    cout<<" -------------------------------------------------------------------------------"<<endl;
    cout<<"|Opcion                                   |Funcion                              |"<<endl;
    cout<<" -------------------------------------------------------------------------------"<<endl;
    cout<<"| 1                                       |Generar N pedidos                    |"<<endl;
    cout<<" -------------------------------------------------------------------------------"<<endl;
    cout<<"| 2                                       |Mostrar pedidos recibidos            |"<<endl;
    cout<<" -------------------------------------------------------------------------------"<<endl;
    cout<<"| 0                                       |Salir                                |"<<endl;
    cout<<" -------------------------------------------------------------------------------"<<endl;
    cout<<"Selecciona: "<<endl;
    cin>>result;
    return result;
}
void mostrarPedidosRecibidos(ColaPizza colaP){
    cout<<" ---------------------------------------------------------------------------------------------"<<endl;
    cout<<"|Pedido      |Cliente        |Pizza          |Tamano      |Zona     |Pers       |Estado       |"<<endl;
    cout<<" ---------------------------------------------------------------------------------------------"<<endl;

    ColaPizza colaAux = colaP;
    while(!colaAux.es_vacia()){

        cout<<" ---------------------------------------------------------------------------------------------"<<endl;
        cout<<"|"<<colaAux.inicio().id_pedido<<"      |Cliente        |Pizza          |Tamano      |Zona     |Pers       |Estado       |"<<endl;
        cout<<" ---------------------------------------------------------------------------------------------"<<endl;

        colaAux.desencolar();
    }
}

int main()
{

    //Prueba

    //Generar pedido
    Pedido ped;

    ColaPizza cola;
/*
    cout<< cola.es_vacia()<<endl;
    cola.mostrarCola();


*/
    cola.encolar(ped);
    cola.encolar(ped);
/*
    cout<< cola.es_vacia()<<endl;

    cola.mostrarCola();
*/
    cout<<"Pizzeria Lugi"<<endl;
    int n;
    do{
        n = menu();
    }while(n<0||n>2);

    switch(n){
        case 1:
            //generar N pedidos
            break;
        case 2:
            mostrarPedidosRecibidos(cola);
            break;
        case 0:
            //salir
            break;
    }

    return 0;
}
