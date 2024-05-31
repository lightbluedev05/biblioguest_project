#ifndef USERMAIN_H
#define USERMAIN_H
#include "GestorVentanas.h"

class GestorVentanas;

class UserMain{
  public:
    void mostrar(GestorVentanas& gestor);
    void mostrar_reservas(GestorVentanas& gestor);
    void cancelar_reserva(GestorVentanas& gestor);
    void seleccionar_opcion(GestorVentanas& gestor);

    void main(GestorVentanas& gestor);
};


#endif