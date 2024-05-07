#include "MainWindow.h"
#include "GestorVentanas.h"
#include "functions.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void MainWindow::mostrar(){
  change_color(116);
  system("cls");

  change_color(112);
  rectangle(45, 14, 33, 7);
  gotoxy(39,7);
  cout<<"Bienvenido al Sistema de Gestion";
  gotoxy(36,8);
  cout<<"de reserva de la Biblioteca de la UNMSM";

  change_color(113);
  gotoxy(30, 24);
  cout<<"UTILIZE LAS FLECHAS PARA SELECCIONAR LAS OPCIONES 🡹 🡻";

  change_color(116);
  gotoxy(33,1);
  cout<<" ____  _ __    ___       ______                __ "<<endl;
  change_color(124);
  gotoxy(32,2);
  cout<<" / __ )(_) /_  / (_)___  / ____/_  _____  _____/ /_"<<endl;
  change_color(116);
  gotoxy(31,3);
  cout<<" / __  / / __ |/ / / __ |/ / __/ / / / _ |/ ___/ __/"<<endl;
  change_color(124);
  gotoxy(30,4);
  cout<<" / /_/ / / /_/ / / / /_/ / /_/ / /_/ /  __(__  ) /_ "<<endl;
  change_color(116);
  gotoxy(30,5);
  cout<<"/_____/_/_____/_/_/|____/|____/|____/|___/____/|__/"<<endl;

}

void MainWindow::seleccionar_ventana(GestorVentanas& gestor){
  int opc=1, tecla=72;
  while(tecla!=13){
    switch(tecla){
			case 72: 
				change_color(113);
				gotoxy(43, 12);
        cout<<"+-----------------------+";
        gotoxy(41, 13);
        cout<<"🡺 |     Ingresar como     |";
        gotoxy(43, 14);
        cout<<"|       un Alumno       |";
        gotoxy(43, 15);
        cout<<"+-----------------------+";

        change_color(112);
        gotoxy(43, 17);
        cout<<"+-----------------------+";
        gotoxy(41, 18);
        cout<<"  |     Ingresar como     |";
        gotoxy(43, 19);
        cout<<"|     Administrador     |";
				gotoxy(43, 20);
        cout<<"+-----------------------+";

				opc=1;
				break;
			case 80:
				change_color(112);
				gotoxy(43, 12);
        cout<<"+-----------------------+";
        gotoxy(41, 13);
        cout<<"  |     Ingresar como     |";
        gotoxy(43, 14);
        cout<<"|       un Alumno       |";
        gotoxy(43, 15);
        cout<<"+-----------------------+";

        change_color(113);
        gotoxy(43, 17);
        cout<<"+-----------------------+";
        gotoxy(41, 18);
        cout<<"🡺 |     Ingresar como     |";
        gotoxy(43, 19);
        cout<<"|     Administrador     |";
				gotoxy(43, 20);
        cout<<"+-----------------------+";
				
				opc=0;
				break;
		}
		
		tecla = _getch();
  }

  switch(opc){
    case 1:
      gestor.cambiar_ventana(Ventanas::USERLOGIN);
      break;
    case 0:
      gestor.terminar_programa();
      break;
  }

}

void MainWindow::main(GestorVentanas& gestor){
  MainWindow::mostrar();
  MainWindow::seleccionar_ventana(gestor);
}