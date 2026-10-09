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
    Pizzeria pizzeriaLuigi;
    cout<<"Pizzeria Lugi"<<endl;
    int n;
    do{
        n = menu();

    switch(n){
        case 1:
            int num;
            cout<<"----------------------------------------------------------------------------------------------------"<<endl;
            cout<<"Cuantos pedidos desea generar?"<<endl;
            cout<<"----------------------------------------------------------------------------------------------------"<<endl;
            cin>>num;
            cout<<"----------------------------------------------------------------------------------------------------"<<endl;
            pizzeriaLuigi.crear_N_pedidos(num);
            cout<<"PEDIDOS CREADOS CORRECTAMENTE"<<endl;
            cout<<"----------------------------------------------------------------------------------------------------"<<endl;
            break;
        case 2:
            pizzeriaLuigi.mostrar_pedidos();
            break;
        case 0:
            //salir
            break;
        default:
            cout<<"----------------------------------------------------------------------------------------------------"<<endl;
            cout<<"Opcion no valida, vuelva a seleccionar"<<endl;
            cout<<"----------------------------------------------------------------------------------------------------"<<endl;
            break;
    }

    }while(n!=0);

    return 0;
}
