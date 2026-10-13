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
        ColaPizza colaPedidosEspeciales;
        ColaPizza colaCocina;
        ColaPizza colaExpNorte;
        ColaPizza colaExpSur;
        ColaPizza colaExpEste;
        ColaPizza colaExpOeste;
        int idcontado;
        void de_cocina_a_Exp();
        void de_prepEsp_a_cocina();
        void de_recibido_a_cocina_o_prepEsp();
    public:
        Pizzeria();
        ~Pizzeria();
        void crear_N_pedidos(int num);
        void mostrar_pedidos();
        void N_Pedidos_Paso();

    protected:
};

#endif // PIZZERIA_H
