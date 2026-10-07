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

int main()
{
/*
    //Prueba

    //Generar pedido
    Pedido ped;

    ColaPizza cola;

    cout<< cola.es_vacia()<<endl;
    cola.mostrarCola();

    cola.encolar(ped);
    cout<< cola.es_vacia()<<endl;

    cola.mostrarCola();
*/
    cout<<"Pizzeria Lugi"<<endl;
    int n;
    do{
        n = menu();
    }while(n<0||n>2);



    return 0;
}
