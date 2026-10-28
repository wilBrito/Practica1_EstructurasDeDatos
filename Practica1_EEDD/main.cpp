#include <iostream>
#include<ColaPizza.h>
#include<NodoColaPizza.h>
#include<Pedido.h>
#include<Pizzeria.h>
#include <stdlib.h>

using namespace std;

int menu(){
    int result;
    cout<<" -------------------------------------------------------------------------------"<<endl;
    cout<<"|Opcion                                   |Funcion                              |"<<endl;
    cout<<" -------------------------------------------------------------------------------"<<endl;
    cout<<"| 1                                       |Generar N pedidos                    |"<<endl;
    cout<<" -------------------------------------------------------------------------------"<<endl;
    cout<<"| 2                                       |Ejecutar un paso de simulación       |"<<endl;
    cout<<" -------------------------------------------------------------------------------"<<endl;
    cout<<"| 3                                       |Mostrar el estado del sistema        |"<<endl;
    cout<<" -------------------------------------------------------------------------------"<<endl;
    cout<<"| 4                                       |Ver la caja activa de una zona       |"<<endl;
    cout<<" -------------------------------------------------------------------------------"<<endl;
    cout<<"| 5                                       |Retirar un pedido de una caja activa |"<<endl;
    cout<<" -------------------------------------------------------------------------------"<<endl;
    cout<<"| 6                                       |Mostrar la cola de finalizados       |"<<endl;
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
            int pasos;
            cout<<"----------------------------------------------------------------------------------------------------"<<endl;
            cout<<"DANDO 10 PASOS EN CADA COLA"<<endl;
            cout<<"----------------------------------------------------------------------------------------------------"<<endl;
            pizzeriaLuigi.N_Pedidos_Paso();
            break;
        case 3:
            pizzeriaLuigi.mostrar_pedidos();
            break;
        case 4:
            bool zona;
            char busq;
            zona=false;
            while(!zona){
            cout<<"----------------------------------------------------------------------------------------------------"<<endl;
            cout<<"INTRODUCE LA ZONA QUE QUIERES REVISAR"<<endl;
            cout<<"N=NORTE , S=SUR , E=ESTE , O=OESTE"<<endl;
            cout<<"----------------------------------------------------------------------------------------------------"<<endl;
            cin>>busq;
            if(busq=='N'||busq=='S'||busq=='E'||busq=='O'){
                zona=true;
            }
            else{
                cout<<"----------------------------------------------------------------------------------------------------"<<endl;
                cout<<"ZONA NO VALIDA"<<endl;
                cout<<"----------------------------------------------------------------------------------------------------"<<endl;
            }}
            pizzeriaLuigi.mostrarPila(busq);
            break;
        case 5:{
            bool zona2;
            char busq2;
            string id;
            zona2=false;
            while(!zona2){
            cout<<"----------------------------------------------------------------------------------------------------"<<endl;
            cout<<"INTRODUCE LA ZONA QUE QUIERES REVISAR"<<endl;
            cout<<"N=NORTE , S=SUR , E=ESTE , O=OESTE"<<endl;
            cout<<"----------------------------------------------------------------------------------------------------"<<endl;
            cin>>busq2;
            if(busq2=='N'||busq2=='S'||busq2=='E'||busq2=='O'){
                zona2=true;
            }
            else{
                cout<<"----------------------------------------------------------------------------------------------------"<<endl;
                cout<<"ZONA NO VÁLIDA"<<endl;
                cout<<"----------------------------------------------------------------------------------------------------"<<endl;
            }}
            bool idCorrecto=false;
            while(!idCorrecto){
            cout<<"----------------------------------------------------------------------------------------------------"<<endl;
            cout<<"INTRODUCE EL ID A RETIRAR CON FORMATO P+5 cifras:"<<endl;
            cout<<"----------------------------------------------------------------------------------------------------"<<endl;
            cin>>id;
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
            else if(!isdigit(id[1])||!isdigit(id[2])||!isdigit(id[3])||!isdigit(id[4])||!isdigit(id[5])){
            cout<<"----------------------------------------------------------------------------------------------------"<<endl;
            cout<<"LOS 5 CARACTERES SIGUIENDO A 'P' DEBEN SER CIFRAS NUMERICAS"<<endl;
            cout<<"----------------------------------------------------------------------------------------------------"<<endl;
            }
            else{
                idCorrecto=true;
            }}
                pizzeriaLuigi.retirarelemento(busq2,id);}
            break;
        case 6:
            pizzeriaLuigi.mostrarColaFinalizados();
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
