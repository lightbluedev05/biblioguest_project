#include "GestorVentanas.h"
#include "AdminMain.h"
#include "functions.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>

void AdminMain::mostrar(GestorVentanas& gestor){
  change_color(112);
  system("cls");
  hide_cursor();

  change_color(240);
  rectangle(50, 22, 35, 2);

  change_color(244);
  gotoxy(53, 3);
  cout<<"MENU DE ADMIN";

  change_color(240);
  gotoxy(36, 4);
  cout<<"------------------------------------------------";
  gotoxy(37, 5);
  cout<<"BIENVENIDO ADMIN";
  gotoxy(40, 7);
  cout<<"ESCOGE LA ACTIVIDAD QUE DESEA VERIFICAR:";

  change_color(241);
  gotoxy(40, 23);
  cout<<"UTILIZE LAS FLECHAS PARA SELECCIONAR LAS";
  gotoxy(48, 24);
  cout<<"OPCIONES (ARRIBA Y ABAJO)";
}

void AdminMain::seleccionar_opcion(GestorVentanas& gestor){
  int opc=1, tecla=72;
  while(tecla!=13){

    if(tecla==72 && opc>1){
      opc--;
    }
    if(tecla==80 && opc<3){
      opc++;
    }

    switch(opc){
      //$ LAPTOPS
			case 1: 
				change_color(241);
				gotoxy(48, 9);
        cout<<"+-----------------------+";
        gotoxy(46, 10);
        cout<<"->|        Laptops        |";
        gotoxy(48, 11);
        cout<<"+-----------------------+";
        change_color(240);

        gotoxy(48, 12);
        cout<<"+-----------------------+";
        gotoxy(46, 13);
        cout<<"  |       Cubiculos       |";
				gotoxy(48, 14);
        cout<<"+-----------------------+";

        gotoxy(48, 18);
        cout<<"+-----------------------+";
        gotoxy(46, 19);
        cout<<"  |         Salir         |";
				gotoxy(48, 20);
        cout<<"+-----------------------+";
				break;

      //$ CUBICULOS
			case 2:
				gotoxy(48, 9);
        cout<<"+-----------------------+";
        gotoxy(46, 10);
        cout<<"  |        Laptops        |";
        gotoxy(48, 11);
        cout<<"+-----------------------+";

        change_color(241);
        gotoxy(48, 12);
        cout<<"+-----------------------+";
        gotoxy(46, 13);
        cout<<"->|       Cubiculos       |";
				gotoxy(48, 14);
        cout<<"+-----------------------+";
        change_color(240);

        gotoxy(48, 18);
        cout<<"+-----------------------+";
        gotoxy(46, 19);
        cout<<"  |         Salir         |";
				gotoxy(48, 20);
        cout<<"+-----------------------+";
				break;

      //$ RESERVAS HECHAS
      case 3:
				gotoxy(48, 9);
        cout<<"+-----------------------+";
        gotoxy(46, 10);
        cout<<"  |        Laptops        |";
        gotoxy(48, 11);
        cout<<"+-----------------------+";

        gotoxy(48, 12);
        cout<<"+-----------------------+";
        gotoxy(46, 13);
        cout<<"  |       Cubiculos       |";
				gotoxy(48, 14);
        cout<<"+-----------------------+";

        change_color(241);

        gotoxy(48, 18);
        cout<<"+-----------------------+";
        gotoxy(46, 19);
        cout<<"->|         Salir         |";
				gotoxy(48, 20);
        cout<<"+-----------------------+";
        change_color(240);
				break;
		}
		
		tecla = _getch();
  }

  switch(opc){
    case 1:
      //gestor.cambiar_ventana(Ventanas::LAPTOPMAIN);
      break;
    case 2:
      //gestor.cambiar_ventana(Ventanas::RESERVASHECHAS);
      break;
    case 3:
      gestor.cambiar_ventana(Ventanas::MAINWINDOW);
      break;
  }
}

void AdminMain::main(GestorVentanas& gestor){
  AdminMain::mostrar(gestor);
  AdminMain::seleccionar_opcion(gestor);
}