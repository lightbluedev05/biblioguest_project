#include "ReservasHechas.h"
#include "GestorVentanas.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

void ReservasHechas::mostrar() {
  system("cls");
  cout<<"AQUI ESTAN TUS RESERVAS"<<endl;
  getch();
}

void ReservasHechas::main(GestorVentanas& gestor) {
  ReservasHechas::mostrar();
}