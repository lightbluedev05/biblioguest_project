#include "GestorVentanas.h"
#include "CubiculosReserva.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "functions.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;

//$ INICIALIZACION
string CubiculosReserva::codigo_cubiculo;
string CubiculosReserva::horario;

bool cubiculo_valido(const string& codigo) {
  set<string> codigos_validos = {"1A01", "1A02", "1A03", "1A04", "2A01", "2A02", "2A03", "2A04"};

  return find(codigos_validos.begin(), codigos_validos.end(), codigo) != codigos_validos.end();
}


void CubiculosReserva::mostrar(){
  change_color(112);
  system("cls");
  show_cursor();

  change_color(240);
  rectangle(67, 19, 27, 3);

  change_color(244);
  gotoxy(52, 4);
  cout<<"RESERVA DE CUBICULOS";

  change_color(240);
  gotoxy(44, 7);
  cout<<"Codigo del cubiculo: #";
  rectangle(15, 1, 66, 6);

  rectangle(15, 1, 33, 10);
  gotoxy(36,11);
  cout<<"08am-10am";

  rectangle(15, 1, 53, 10);
  gotoxy(56,11);
  cout<<"10am-12pm";

  rectangle(15, 1, 73, 10);
  gotoxy(76,11);
  cout<<"12pm-02pm";

  rectangle(15, 1, 33, 15);
  gotoxy(36,16);
  cout<<"02pm-04pm";

  rectangle(15, 1, 53, 15);
  gotoxy(56,16);
  cout<<"04pm-06pm";

  rectangle(15, 1, 73, 15);
  gotoxy(76,16);
  cout<<"06pm-08pm";

  rectangle(14, 1, 44, 19);
  gotoxy(47,20);
  cout<<"RESERVAR";

  rectangle(15, 1, 63, 19);
  gotoxy(68,20);
  cout<<"ATRAS";

}

void CubiculosReserva::ingresar_datos(GestorVentanas& gestor){
  int controlador=0;
  do{
    controlador++;
    if(controlador>4){
      gotoxy(98, 6);
      cout<<"REVISA BIEN EL CODIGO";
      gotoxy(98,7);
      cout<<"DEL CUBICULO :)";
      gotoxy(98,8);
      cout<<"PRESIONA ENTER";
      getch();
      gestor.cambiar_ventana(Ventanas::CUBICULOSMAIN);
      return;
    }
    gotoxy(67,7);
    cout<<"             ";
    gotoxy(67,7);
    cin>>CubiculosReserva::codigo_cubiculo;
  } while(!cubiculo_valido(CubiculosReserva::codigo_cubiculo));

  //$ SELECCION DE HORARIO
  int aux_x=0, aux_y=0, tecla=75;

  while(tecla!=13){
    switch (tecla){
      case 75:
        if(aux_x>0){
          aux_x--;
        }
        break;

      case 77:
        if(aux_x<2){
          aux_x++;
        }
        break;

      case 72:
        if(aux_y>0){
          aux_y--;
        }
        break;

      case 80:
        if(aux_y<1){
          aux_y++;
        }
        break;
    }

    if(aux_x==0 && aux_y==0){change_color(113); CubiculosReserva::horario = "0";}
    rectangle(15, 1, 33, 10);
    gotoxy(36,11);
    cout<<"08am-10am";
    change_color(240);

    if(aux_x==1 && aux_y==0){change_color(113); CubiculosReserva::horario = "1";}
    rectangle(15, 1, 53, 10);
    gotoxy(56,11);
    cout<<"10am-12pm";
    change_color(240);

    if(aux_x==2 && aux_y==0){change_color(113); CubiculosReserva::horario = "2";}
    rectangle(15, 1, 73, 10);
    gotoxy(76,11);
    cout<<"12pm-02pm";
    change_color(240);

    if(aux_x==0 && aux_y==1){change_color(113); CubiculosReserva::horario = "3";}
    rectangle(15, 1, 33, 15);
    gotoxy(36,16);
    cout<<"02pm-04pm";
    change_color(240);

    if(aux_x==1 && aux_y==1){change_color(113); CubiculosReserva::horario = "4";}
    rectangle(15, 1, 53, 15);
    gotoxy(56,16);
    cout<<"04pm-06pm";
    change_color(240);

    if(aux_x==2 && aux_y==1){change_color(113); CubiculosReserva::horario = "5";}
    rectangle(15, 1, 73, 15);
    gotoxy(76,16);
    cout<<"06pm-08pm";
    change_color(240);

		tecla = _getch();
  }
  
  int opc=0;
  tecla=75;
  //$ SELECCION DE OPCION
  while(tecla!=13){
    switch(tecla){
      case 75:
        change_color(241);
        rectangle(14, 1, 44, 19);
        gotoxy(46,20);
        cout<<"*RESERVAR";
        change_color(240);

        rectangle(15, 1, 63, 19);
        gotoxy(68,20);
        cout<<"ATRAS";
        opc=0;
        break;

      case 77:
        rectangle(14, 1, 44, 19);
        gotoxy(47,20);
        cout<<"RESERVAR";

        change_color(241);
        rectangle(15, 1, 63, 19);
        gotoxy(67,20);
        cout<<"*ATRAS";
        change_color(240);
        opc=1;
        break;
    }
    tecla = _getch();
  }

  switch(opc){
    case 0:
      CubiculosReserva::comprobacion_de_datos(gestor);
      break;
    case 1:
      gestor.cambiar_ventana(Ventanas::CUBICULOSMAIN);
      break;
  }

}

void CubiculosReserva::comprobacion_de_datos(GestorVentanas& gestor){
  ifstream archivo("cubiculos.txt");
  string linea;
  string aux_codigo_cubiculo;
  string aux_horario;
  bool encontrado = false;

  while(getline(archivo, linea)){
    if(linea.find(gestor.codigo) != string::npos){
      //$ ALUMNO YA RESERVO CUBICULO
      change_color(240);
      system("cls");
      gotoxy(31, 10);
      cout<<"--------YA HAS RESERVADO UN CUBICULO EL DIA DE HOY--------";
      change_color(241);
      gotoxy(39,11);
      cout<<"PUEDES CONSULTARLO EN TUS RESERVAS HECHAS";
      getch();
      encontrado=true;
      gestor.cambiar_ventana(Ventanas::CUBICULOSMAIN);
      break;
    }
  }
  
  if(encontrado==false){
    while(getline(archivo, linea)){
      istringstream ss(linea);
      ss >> aux_codigo_cubiculo;
      ss.ignore();
      ss >> aux_horario;
      if(CubiculosReserva::horario == aux_horario && CubiculosReserva::codigo_cubiculo == aux_codigo_cubiculo){
        //$ HORARIO OCUPADO
        change_color(240);
        system("cls");
        gotoxy(25, 10);
        cout<<"--------EL HORARIO SELECCIONADO EN ESTE CUBICULO YA ESTA RESERVADO--------";
        change_color(241);
        gotoxy(34,11);
        cout<<"REVISA LOS HORARIOS DISPONIBLES EN LA LISTA DE CUBICULOS";
        getch();
        gestor.cambiar_ventana(Ventanas::CUBICULOSMAIN);
        break;
      }
    }
  }

  if(encontrado==false){
    CubiculosReserva::ejecutar_reserva(gestor);
  }

  archivo.close();
  /*while(getline(archivo, linea)){
    if(linea.find("1A01 1 23200328") != string::npos){
      //$ ALUMNO YA RESERVO CUBICULO
      change_color(240);
      system("cls");
      gotoxy(31, 10);
      cout<<"--------YA HAS RESERVADO UN CUBICULO EL DIA DE HOY--------";
      change_color(241);
      gotoxy(39,11);
      cout<<"PUEDES CONSULTARLO EN TUS RESERVAS HECHAS";
      getch();
      break;

    } else {
      istringstream ss(linea);
      ss >> aux_codigo_cubiculo;
      ss.ignore();
      ss >> aux_horario;

      if(!(CubiculosReserva::horario == aux_horario && CubiculosReserva::codigo_cubiculo == aux_codigo_cubiculo)){
        //$ EJECUTA LA RESERVA
        CubiculosReserva::ejecutar_reserva(gestor);
        break;

      } else {
        //$ HORARIO OCUPADO
        change_color(240);
        system("cls");
        gotoxy(25, 10);
        cout<<"--------EL HORARIO SELECCIONADO EN ESTE CUBICULO YA ESTA RESERVADO--------";
        change_color(241);
        gotoxy(34,11);
        cout<<"REVISA LOS HORARIOS DISPONIBLES EN LA LISTA DE CUBICULOS";
        getch();
        break;
      }
    }
  }*/
}

void CubiculosReserva::ejecutar_reserva(GestorVentanas& gestor){

  string reserva;

  reserva=CubiculosReserva::codigo_cubiculo+" "+CubiculosReserva::horario+" "+gestor.codigo;

  ofstream archivo("cubiculos.txt", ios::app);
  archivo<<reserva<<endl;
  archivo.close();

  system("cls");
  cout<<"RESERVA EJECUTADA";
  getch();
  gestor.cambiar_ventana(Ventanas::CUBICULOSMAIN);
}

void CubiculosReserva::main(GestorVentanas& gestor){
  CubiculosReserva::mostrar();
  CubiculosReserva::ingresar_datos(gestor);
}