#ifndef PIZZERIA_H
#define PIZZERIA_H
#include "ColaPizza.h"
#include "Pedido.h"
const string tipo_pizza[]={"MARGARITA","BARBACOA","VEGETAL","HAWAIANA","ROMANA","CUATROQUESOS"};
const string tamano[]={"MEDIANA","GRANDE"};
const string zona_reparto[]={"NORTE","SUR","ESTE","OESTE"};
class Pizzeria
{
    private:
        ColaPizza colaPedidos;
        int idcontado;
    public:
        Pizzeria();
        ~Pizzeria();
        void crear_N_pedidos(int num);
        void mostrar_pedidos();

    protected:
};

#endif // PIZZERIA_H
