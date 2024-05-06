#include "GestorVentanas.h"
#include "UserMain.h"
#include "functions.h"
#include <iostream>
#include <conio.h>

void UserMain::mostrar(GestorVentanas& gestor){
  hide_cursor();
  rectangle(60, 20, 20, 5);
  gotoxy(22, 6);
  cout<<"BIENVENIDO "<<gestor.codigo;
  gotoxy(36, 8);
  cout<<"ESCOGE QUE DESEAS REALIZAR:";
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
			case 1: 
				change_color(15,22);
				gotoxy(37, 10);
        cout<<"+-----------------------+";
        gotoxy(37, 11);
        cout<<"|        Laptops        |";
        gotoxy(37, 12);
        cout<<"+-----------------------+";
        change_color(15,0);

        gotoxy(37, 14);
        cout<<"+-----------------------+";
        gotoxy(37, 15);
        cout<<"|       Cubiculos       |";
				gotoxy(37, 16);
        cout<<"+-----------------------+";

        gotoxy(37, 18);
        cout<<"+-----------------------+";
        gotoxy(37, 19);
        cout<<"|    Reservas Hechas    |";
				gotoxy(37, 20);
        cout<<"+-----------------------+";

        gotoxy(37, 22);
        cout<<"+-----------------------+";
        gotoxy(37, 23);
        cout<<"|         Salir         |";
				gotoxy(37, 24);
        cout<<"+-----------------------+";
				break;

			case 2:
				gotoxy(37, 10);
        cout<<"+-----------------------+";
        gotoxy(37, 11);
        cout<<"|        Laptops        |";
        gotoxy(37, 12);
        cout<<"+-----------------------+";
        
        change_color(15,22);
        gotoxy(37, 14);
        cout<<"+-----------------------+";
        gotoxy(37, 15);
        cout<<"|       Cubiculos       |";
				gotoxy(37, 16);
        cout<<"+-----------------------+";
        change_color(15,0);

        gotoxy(37, 18);
        cout<<"+-----------------------+";
        gotoxy(37, 19);
        cout<<"|    Reservas Hechas    |";
				gotoxy(37, 20);
        cout<<"+-----------------------+";

        gotoxy(37, 22);
        cout<<"+-----------------------+";
        gotoxy(37, 23);
        cout<<"|         Salir         |";
				gotoxy(37, 24);
        cout<<"+-----------------------+";
				break;

      case 3:
				gotoxy(37, 10);
        cout<<"+-----------------------+";
        gotoxy(37, 11);
        cout<<"|        Laptops        |";
        gotoxy(37, 12);
        cout<<"+-----------------------+";
        
        gotoxy(37, 14);
        cout<<"+-----------------------+";
        gotoxy(37, 15);
        cout<<"|       Cubiculos       |";
				gotoxy(37, 16);
        cout<<"+-----------------------+";

        change_color(15,22);
        gotoxy(37, 18);
        cout<<"+-----------------------+";
        gotoxy(37, 19);
        cout<<"|    Reservas Hechas    |";
				gotoxy(37, 20);
        cout<<"+-----------------------+";
        change_color(15,0);

        gotoxy(37, 22);
        cout<<"+-----------------------+";
        gotoxy(37, 23);
        cout<<"|         Salir         |";
				gotoxy(37, 24);
        cout<<"+-----------------------+";
				break;

      case 4:
				gotoxy(37, 10);
        cout<<"+-----------------------+";
        gotoxy(37, 11);
        cout<<"|        Laptops        |";
        gotoxy(37, 12);
        cout<<"+-----------------------+";
        
        gotoxy(37, 14);
        cout<<"+-----------------------+";
        gotoxy(37, 15);
        cout<<"|       Cubiculos       |";
				gotoxy(37, 16);
        cout<<"+-----------------------+";

        gotoxy(37, 18);
        cout<<"+-----------------------+";
        gotoxy(37, 19);
        cout<<"|    Reservas Hechas    |";
				gotoxy(37, 20);
        cout<<"+-----------------------+";

        change_color(15,22);
        gotoxy(37, 22);
        cout<<"+-----------------------+";
        gotoxy(37, 23);
        cout<<"|         Salir         |";
				gotoxy(37, 24);
        cout<<"+-----------------------+";
        change_color(15,0);
				break;
		}
		
		tecla = _getch();
  }

  switch(opc){
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      gestor.terminar_programa();
      break;
  }
}

void UserMain::main(GestorVentanas& gestor){
  UserMain::mostrar(gestor);
  UserMain::seleccionar_opcion(gestor);
}