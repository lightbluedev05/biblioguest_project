#ifndef CUBICULOSRESERVA_H
#define CUBICULOSRESERVA_H
#include "GestorVentanas.h"

class GestorVentanas;

class CubiculosReserva {
  public:
    //METODOS
    void mostrar();
    void ejecutar_reserva();
    
    void main(GestorVentanas& gestor);
};


#endif