#ifndef USERLOGIN_H
#define USERLOGIN_H
#include "GestorVentanas.h"

class GestorVentanas;

class UserLogin {
  public:
    //METODOS
    void mostrar();
    void ingresar_credenciales(GestorVentanas& gestor);
    void seleccionar_opcion(GestorVentanas& gestor);
    void validar_credenciales(GestorVentanas& gestor);
    
    void main(GestorVentanas& gestor);
};


#endif