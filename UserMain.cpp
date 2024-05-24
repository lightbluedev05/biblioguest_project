#include "GestorVentanas.h"
#include "UserMain.h"
#include "functions.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;

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
  cout<<"BIENVENIDO"<<gestor.nombre;
  gotoxy(47, 7);
  cout<<"ESCOGE QUE DESEAS REALIZAR:";

  change_color(241);
  gotoxy(40, 23);
  cout<<"UTILIZE LAS FLECHAS PARA SELECCIONAR LAS";
  gotoxy(48, 24);
  cout<<"OPCIONES (ARRIBA Y ABAJO)";
}

void UserMain::mostrar_reservas(GestorVentanas& gestor){
  ifstream archivo("cubiculos.txt");
  string linea;
  string aux_codigo_cubiculo="", aux_horario="", aux_codigo_alumno="";

  while(getline(archivo, linea)){
    if(linea.find(gestor.codigo) != string::npos){
      //OBTENER LO QUE ESTA ESCRITO EN LA LINEA DONDE SE ENCONTRO EL CODIGO
      istringstream ss(linea);
      ss >> aux_codigo_cubiculo;
      ss.ignore();
      ss >> aux_horario;
      ss.ignore();
      ss >> aux_codigo_alumno;
      break;
    }
  }

  archivo.close();

  system("cls");

  if(aux_codigo_alumno==""){
    gotoxy(31, 10);
    cout<<"--------NO TIENES NINGUNA RESERVA EL DIA DE HOY--------";
    change_color(241);
    gotoxy(42,11);
    cout<<"PUEDES INTENTAR EJECUTAR ALGUNA RESERVA";
  } else {
    switch(stoi(aux_horario)){
      case 0:
        aux_horario = "08am-10am";
        break;
      case 1:
        aux_horario = "10am-12pm";
        break;
      case 2:
        aux_horario = "12pm-02pm";
        break;
      case 3:
        aux_horario = "02pm-04pm";
        break;
      case 4:
        aux_horario = "04pm-06pm";
        break;
      case 5:
        aux_horario = "06pm-08pm";
        break;
    }
    gotoxy(31, 10);
    cout<<"------------ESTAS SON TUS RESERVAS DE HOY------------";
    change_color(241);
    gotoxy(36,12);
    cout<<"CUBICULOS";
    change_color(240);
    gotoxy(36,14);
    cout<<"Cubiculo: "<<aux_codigo_cubiculo;
    gotoxy(36,15);
    cout<<"Horario: "<<aux_horario;
    gotoxy(36,16);
    cout<<"Alumno: "<<aux_codigo_alumno;

    change_color(241);
    gotoxy(65, 12);
    cout<<"LAPTOPS";
    change_color(240);

  }
  
  getch();
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
      gestor.cambiar_ventana(Ventanas::CUBICULOSMAIN);
      break;
    case 3:
      UserMain::mostrar_reservas(gestor);
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