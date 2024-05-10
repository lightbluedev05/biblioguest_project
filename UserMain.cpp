#include "GestorVentanas.h"
#include "UserMain.h"
#include "functions.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>

void UserMain::mostrar(GestorVentanas& gestor){
  change_color(112);
  system("cls");
  hide_cursor();

  change_color(240);
  rectangle(50, 22, 35, 2);

  change_color(244);
  gotoxy(53, 3);
  cout<<"MENU DE USUARIO";

  change_color(240);
  gotoxy(36, 4);
  cout<<"------------------------------------------------";
  gotoxy(37, 5);
  cout<<"BIENVENIDO "<<gestor.nombre;
  gotoxy(47, 7);
  cout<<"ESCOGE QUE DESEAS REALIZAR:";

  change_color(241);
  gotoxy(40, 23);
  cout<<"UTILIZE LAS FLECHAS PARA SELECCIONAR LAS";
  gotoxy(48, 24);
  cout<<"OPCIONES (ARRIBA Y ABAJO)";
}

void UserMain::seleccionar_opcion(GestorVentanas& gestor){
  int opc=1, tecla=72;
  while(tecla!=13){

    if(tecla==72 && opc>1){
      opc--;
    }
    if(tecla==80 && opc<4){
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

        gotoxy(48, 15);
        cout<<"+-----------------------+";
        gotoxy(46, 16);
        cout<<"  |    Reservas Hechas    |";
				gotoxy(48, 17);
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

        gotoxy(48, 15);
        cout<<"+-----------------------+";
        gotoxy(46, 16);
        cout<<"  |    Reservas Hechas    |";
				gotoxy(48, 17);
        cout<<"+-----------------------+";

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
        gotoxy(48, 15);
        cout<<"+-----------------------+";
        gotoxy(46, 16);
        cout<<"->|    Reservas Hechas    |";
				gotoxy(48, 17);
        cout<<"+-----------------------+";
        change_color(240);

        gotoxy(48, 18);
        cout<<"+-----------------------+";
        gotoxy(46, 19);
        cout<<"  |         Salir         |";
				gotoxy(48, 20);
        cout<<"+-----------------------+";
				break;

      //$ SALIR
      case 4:
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

        gotoxy(48, 15);
        cout<<"+-----------------------+";
        gotoxy(46, 16);
        cout<<"  |    Reservas Hechas    |";
				gotoxy(48, 17);
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
      gestor.cambiar_ventana(Ventanas::LAPTOPMAIN);
      break;
    case 2:
      
      break;
    case 3:
      gestor.cambiar_ventana(Ventanas::RESERVASHECHAS);
      break;
    case 4:
      gestor.cambiar_ventana(Ventanas::MAINWINDOW);
      break;
  }
}

void UserMain::main(GestorVentanas& gestor){
  UserMain::mostrar(gestor);
  UserMain::seleccionar_opcion(gestor);
}