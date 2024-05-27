#ifndef CUBICULOSRESERVA_H
#define CUBICULOSRESERVA_H
#include "GestorVentanas.h"

class GestorVentanas;

class CubiculosReserva {
  public:
    static std::string codigo_cubiculo;
    static std::string horario_cubiculo;

    //METODOS
    void mostrar();
    void ingresar_datos(GestorVentanas& gestor);
    void comprobacion_de_datos(GestorVentanas& gestor);
    void ejecutar_reserva(GestorVentanas& gestor);
    
    void main(GestorVentanas& gestor);
};

#endif