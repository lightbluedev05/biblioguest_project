#include "AdminLogin.h"
#include "GestorVentanas.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

void AdminLogin::mostrar() {
  cout<<"hola mundo";
  getch();
}

void AdminLogin::main(GestorVentanas& gestor) {
  system("cls");
  AdminLogin::mostrar();
}