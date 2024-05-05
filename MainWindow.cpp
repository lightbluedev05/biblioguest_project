#include "MainWindow.h"
#include "GestorVentanas.h"
#include "functions.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void MainWindow::mostrar(){
  system("cls");
  rectangle(45, 14, 33, 5);
  gotoxy(39,7);
  cout<<"Bienvenido al Sistema de Gestion";
  gotoxy(36,8);
  cout<<"de reserva de la Biblioteca de la UNMSM";
  gotoxy(30,0);
  cout<<"    ____  _ __    ___       ______                __ "<<endl;
  gotoxy(30,1);
  cout<<"   / __ )(_) /_  / (_)___  / ____/_  _____  _____/ /_"<<endl;
  gotoxy(30,2);
  cout<<"  / __  / / __ |/ / / __ |/ / __/ / / / _ |/ ___/ __/"<<endl;
  gotoxy(30,3);
  cout<<" / /_/ / / /_/ / / / /_/ / /_/ / /_/ /  __(__  ) /_  "<<endl;
  gotoxy(30,4);
  cout<<"/_____/_/_____/_/_/|____/|____/|____/|___/____/|__/  "<<endl;
  gotoxy(30,5);

}

void MainWindow::seleccionar_ventana(GestorVentanas& gestor){
  int opc=1, tecla=72;
  while(tecla!=13){
    switch(tecla){
			case 72: 
				change_color(15,22);
				gotoxy(43, 10);
        cout<<"+-----------------------+";
        gotoxy(43, 11);
        cout<<"|     Ingresar como     |";
        gotoxy(43, 12);
        cout<<"|       un Alumno       |";
        gotoxy(43, 13);
        cout<<"+-----------------------+";

        change_color(15,0);
        gotoxy(43, 15);
        cout<<"+-----------------------+";
        gotoxy(43, 16);
        cout<<"|     Ingresar como     |";
        gotoxy(43, 17);
        cout<<"|     Administrador     |";
				gotoxy(43, 18);
        cout<<"+-----------------------+";

				opc=1;
				break;
			case 80:
				change_color(15,0);
				gotoxy(43, 10);
        cout<<"+-----------------------+";
        gotoxy(43, 11);
        cout<<"|     Ingresar como     |";
        gotoxy(43, 12);
        cout<<"|       un Alumno       |";
        gotoxy(43, 13);
        cout<<"+-----------------------+";

        change_color(15,22);
        gotoxy(43, 15);
        cout<<"+-----------------------+";
        gotoxy(43, 16);
        cout<<"|     Ingresar como     |";
        gotoxy(43, 17);
        cout<<"|     Administrador     |";
				gotoxy(43, 18);
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