#ifndef ADMINMAIN_H
#define ADMINMAIN_H
#include "GestorVentanas.h"

class GestorVentanas;

class AdminMain{
  public:
    void mostrar(GestorVentanas& gestor);
    void main(GestorVentanas& gestor);
    void seleccionar_opcion(GestorVentanas& gestor);
};


#endif