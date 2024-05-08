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

  change_color(240);
  rectangle(59, 23, 27, 1);
  gotoxy(40,8);
  cout<<"Bienvenido al Sistema de Gestion";
  gotoxy(37,9);
  cout<<"de reserva de la Biblioteca de la UNMSM";

  gotoxy(30, 24);
  cout<<"UTILIZE LAS FLECHAS PARA SELECCIONAR LAS OPCIONES 🡹 🡻";

  change_color(244);
  gotoxy(33,2);
  cout<<" ____  _ __    ___       ______                __ "<<endl;
  
  gotoxy(32,3);
  cout<<" / __ )(_) /_  / (_)___  / ____/_  _____  _____/ /_"<<endl;
  
  gotoxy(31,4);
  cout<<" / __  / / __ |/ / / __ |/ / __/ / / / _ |/ ___/ __/"<<endl;
  
  gotoxy(30,5);
  cout<<" / /_/ / / /_/ / / / /_/ / /_/ / /_/ /  __(__  ) /_ "<<endl;
  
  gotoxy(30,6);
  cout<<"/_____/_/_____/_/_/|____/|____/|____/|___/____/|__/"<<endl;

}

void MainWindow::seleccionar_ventana(GestorVentanas& gestor){
  int opc=1, tecla=72;
  while(tecla!=13){
    switch(tecla){
			case 72: 
				change_color(241);
				gotoxy(44, 12);
        cout<<"+-----------------------+";
        gotoxy(42, 13);
        cout<<"🡺 |     Ingresar como     |";
        gotoxy(44, 14);
        cout<<"|       un Alumno       |";
        gotoxy(44, 15);
        cout<<"+-----------------------+";

        change_color(240);
        gotoxy(44, 17);
        cout<<"+-----------------------+";
        gotoxy(42, 18);
        cout<<"  |     Ingresar como     |";
        gotoxy(44, 19);
        cout<<"|     Administrador     |";
				gotoxy(44, 20);
        cout<<"+-----------------------+";

				opc=1;
				break;
			case 80:
				change_color(240);
				gotoxy(44, 12);
        cout<<"+-----------------------+";
        gotoxy(42, 13);
        cout<<"  |     Ingresar como     |";
        gotoxy(44, 14);
        cout<<"|       un Alumno       |";
        gotoxy(44, 15);
        cout<<"+-----------------------+";

        change_color(241);
        gotoxy(44, 17);
        cout<<"+-----------------------+";
        gotoxy(42, 18);
        cout<<"🡺 |     Ingresar como     |";
        gotoxy(44, 19);
        cout<<"|     Administrador     |";
				gotoxy(44, 20);
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