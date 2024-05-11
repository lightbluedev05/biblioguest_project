#include "GestorVentanas.h"
#include "CubiculosReserva.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "functions.h"

using namespace std;

void CubiculosReserva::mostrar(){
  rectangle(15, 1, 10, 2);
  rectangle(15, 1, 10, 5);
  rectangle(15, 1, 10, 8);
}

void ejecutar_reserva(){
  int codigo_cubiculo;
  int horario;
  int codigo_alumno;

  gotoxy(11,3);
  cin>>codigo_cubiculo;

  gotoxy(11,6);
  cin>>horario;

  gotoxy(11,9);
  cin>>codigo_alumno;
  

}

void CubiculosReserva::main(GestorVentanas& gestor){
  CubiculosReserva::mostrar();
  CubiculosReserva::ejecutar_reserva();
}