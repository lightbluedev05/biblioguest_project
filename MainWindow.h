#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "GestorVentanas.h"

using namespace std;
class GestorVentanas;

class MainWindow {
  public:
    //METODOS
    void mostrar();
    void seleccionar_ventana(GestorVentanas& gestor);

    void main(GestorVentanas& gestor);
};


#endif