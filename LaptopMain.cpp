#include "LaptopMain.h"
#include "GestorVentanas.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

void LaptopMain::mostrar() {
  system("cls");
  cout<<"BIENVENIDO AL LAPTOP MAIN"<<endl;
  getch();
}

void LaptopMain::main(GestorVentanas& gestor) {
  LaptopMain::mostrar();
}