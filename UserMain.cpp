#include "GestorVentanas.h"
#include "UserMain.h"
#include "functions.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

void UserMain::mostrar(GestorVentanas& gestor){
  change_color(112);
  system("cls");
  hide_cursor();

  change_color(240);
  rectangle(50, 24, 35, 2);

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
  gotoxy(40, 25);
  cout<<"UTILIZE LAS FLECHAS PARA SELECCIONAR LAS";
  gotoxy(48, 26);
  cout<<"OPCIONES (ARRIBA Y ABAJO)";
}

void UserMain::mostrar_reservas(GestorVentanas& gestor){
  string codigo_cubiculo="", horario_cubiculo="", codigo_alumno="";
  string codigo_laptop="", horario_laptop="";

  //* CONSEGUIR DATA DE RESERVAS
  vector<vector<string>> data;
  string linea;
  ifstream file("reservas_data.csv");

  while(getline(file, linea)){
    vector<string> horarios={};
    string horario="";
    stringstream ss(linea);

    while(getline(ss, horario, ',')){
      horarios.push_back(horario);
    }
    data.push_back(horarios);
  }
  file.close();

  //* BUSCAR Y ASIGNAR RESERVA DEL DIA DE HOY
  for(int i=0; i<data.size(); i++){
    if(data[i][2]==gestor.codigo){
      codigo_alumno = data[i][2];
      if(data[i][0][1]=='A'){
        codigo_cubiculo = data[i][0];
        horario_cubiculo = data[i][1];
      } else {
        codigo_laptop = data[i][0];
        horario_laptop = data[i][1];
      }
    }
  }

  //* PINTADO DE LA PANTALLA
  system("cls");

  if(codigo_alumno==""){
    gotoxy(31, 10);
    cout<<"--------NO TIENES NINGUNA RESERVA EL DIA DE HOY--------";
    change_color(241);
    gotoxy(42,11);
    cout<<"PUEDES INTENTAR EJECUTAR ALGUNA RESERVA";
  } else {
    gotoxy(31, 10);
    cout<<"------------ESTAS SON TUS RESERVAS DE HOY------------";
    change_color(241);
    gotoxy(36,12);
    cout<<"CUBICULOS";
    gotoxy(65, 12);
    cout<<"LAPTOPS";
    change_color(240);

    if(codigo_cubiculo!=""){
      switch(stoi(horario_cubiculo)){
        case 1:
          horario_cubiculo = "08am-10am";
          break;
        case 2:
          horario_cubiculo = "10am-12pm";
          break;
        case 3:
          horario_cubiculo = "12pm-02pm";
          break;
        case 4:
          horario_cubiculo = "02pm-04pm";
          break;
        case 5:
          horario_cubiculo = "04pm-06pm";
          break;
        case 6:
          horario_cubiculo = "06pm-08pm";
          break;
      }
      gotoxy(36,14);
      cout<<"Cubiculo: "<<codigo_cubiculo;
      gotoxy(36,15);
      cout<<"Horario: "<<horario_cubiculo;
      gotoxy(36,16);
      cout<<"Alumno: "<<codigo_alumno;
    }

    if(codigo_laptop!=""){
      switch(stoi(horario_laptop)){
        case 1:
          horario_laptop = "08am-10am";
          break;
        case 2:
          horario_laptop = "10am-12pm";
          break;
        case 3:
          horario_laptop = "12pm-02pm";
          break;
        case 4:
          horario_laptop = "02pm-04pm";
          break;
        case 5:
          horario_laptop = "04pm-06pm";
          break;
        case 6:
          horario_laptop = "06pm-08pm";
          break;
      }
      gotoxy(65,14);
      cout<<"Cubiculo: "<<codigo_laptop;
      gotoxy(65,15);
      cout<<"Horario: "<<horario_laptop;
      gotoxy(65,16);
      cout<<"Alumno: "<<codigo_alumno;
    }
  }
  
  getch();
}

void UserMain::cancelar_reserva(GestorVentanas& gestor){
  //* CONSEGUIR DATA DE RESERVAS
  vector<vector<string>> data;
  string linea;
  ifstream file("reservas_data.csv");

  while(getline(file, linea)){
    vector<string> horarios={};
    string horario="";
    stringstream ss(linea);

    while(getline(ss, horario, ',')){
      horarios.push_back(horario);
    }
    data.push_back(horarios);
  }
  file.close();

  //* PINTADO DE OPCIONES
  system("cls");
  gotoxy(45, 8);
  cout<<"¿QUE RESERVA DESEA CANCELAR?";
  int tecla=75, opc=0;
  while(tecla!=13){  
    switch(tecla){
      case 75:
        change_color(241);
        button(25, 1, 36, 10, "CUBICULO");
        change_color(240);
        button(25, 1, 66, 10, "LAPTOP");
        opc=0;
        break;
      case 77:
        button(25, 1, 36, 10, "CUBICULO");
        change_color(241);
        button(25, 1, 66, 10, "LAPTOP");
        change_color(240);
        opc=1;
        break;
    }
    tecla=_getch();
  }

  //* ELIMINACION DE RESERVA
  bool encontrado=false;
  switch(opc){
    //$ ELIMINACION DE RESERVA DE CUBICULO
    case 0:
      for(int i=0; i<data.size(); i++){
        if(data[i][2]==gestor.codigo && data[i][0][1]=='A'){
          ofstream archivo("reservas_data.csv");
          for(int j=0; j<data.size(); j++){
            if(j!=i){
              for(int k=0; k<data[j].size(); k++){
                archivo<<data[j][k];
                if(k<data[j].size()-1){
                  archivo<<",";
                }
              }
              archivo<<"\n";
            }
          }
          archivo.close();
          encontrado=true;
          break;
        }
      }
      
      system("cls");

      if(!encontrado){
        gotoxy(50, 10);
        cout<<"NO TIENES RESERVA DE CUBICULO";
      } else {
        gotoxy(50, 10);
        cout<<"RESERVA CANCELADA CON EXITO :)";
      }
      break;

    //$ ELIMINACION DE RESERVA DE LAPTOP
    case 1:
      for(int i=0; i<data.size(); i++){
        if(data[i][2]==gestor.codigo && data[i][0][1]=='B'){
          ofstream archivo("reservas_data.csv");
          for(int j=0; j<data.size(); j++){
            if(j!=i){
              for(int k=0; k<data[j].size(); k++){
                archivo<<data[j][k];
                if(k<data[j].size()-1){
                  archivo<<",";
                }
              }
            }
            if(j<(data.size())-1 && j!=i){
              archivo<<"\n";
            }
          }
          archivo.close();
          encontrado=true;
          break;
        }
      }

      system("cls");

      if(!encontrado){
        gotoxy(50, 10);
        cout<<"NO TIENES RESERVA DE CUBICULO";
      } else {
        gotoxy(50, 10);
        cout<<"RESERVA CANCELADA CON EXITO :)";
      }
      break;
  }
  getch();
}

void UserMain::seleccionar_opcion(GestorVentanas& gestor){
  int opc=1, tecla=72;
  while(tecla!=13){

    if(tecla==72 && opc>1){
      opc--;
    }
    if(tecla==80 && opc<5){
      opc++;
    }

    switch(opc){
      //$ LAPTOPS
			case 1: 
				change_color(241);
        gotoxy(46, 10);
        cout<<"->";
        button(25, 1, 48, 9, "Laptops");
        change_color(240);

        gotoxy(46, 13);
        cout<<"  ";
        button(25, 1, 48, 12, "Cubiculos");

        gotoxy(46, 16);
        cout<<"  ";
        button(25, 1, 48, 15, "Reservas Hechas");

        gotoxy(46, 19);
        cout<<"  ";
        button(25, 1, 48, 18, "Cancelar Reserva");

        gotoxy(46, 22);
        cout<<"  ";
        button(25, 1, 48, 21, "Volver");
				break;

      //$ CUBICULOS
			case 2:
        gotoxy(46, 10);
        cout<<"  ";
        button(25, 1, 48, 9, "Laptops");

        change_color(241);
        gotoxy(46, 13);
        cout<<"->";
        button(25, 1, 48, 12, "Cubiculos");
        change_color(240);

        gotoxy(46, 16);
        cout<<"  ";
        button(25, 1, 48, 15, "Reservas Hechas");

        gotoxy(46, 19);
        cout<<"  ";
        button(25, 1, 48, 18, "Cancelar Reserva");

        gotoxy(46, 22);
        cout<<"  ";
        button(25, 1, 48, 21, "Volver");
				break;

      //$ RESERVAS HECHAS
      case 3:
        gotoxy(46, 10);
        cout<<"  ";
        button(25, 1, 48, 9, "Laptops");

        gotoxy(46, 13);
        cout<<"  ";
        button(25, 1, 48, 12, "Cubiculos");

        change_color(241);
        gotoxy(46, 16);
        cout<<"->";
        button(25, 1, 48, 15, "Reservas Hechas");
        change_color(240);

        gotoxy(46, 19);
        cout<<"  ";
        button(25, 1, 48, 18, "Cancelar Reserva");

        gotoxy(46, 22);
        cout<<"  ";
        button(25, 1, 48, 21, "Volver");
				break;

      //$ CANCELAR RESERVAS
      case 4:
        gotoxy(46, 10);
        cout<<"  ";
        button(25, 1, 48, 9, "Laptops");

        gotoxy(46, 13);
        cout<<"  ";
        button(25, 1, 48, 12, "Cubiculos");

        gotoxy(46, 16);
        cout<<"  ";
        button(25, 1, 48, 15, "Reservas Hechas");

        change_color(241);
        gotoxy(46, 19);
        cout<<"->";
        button(25, 1, 48, 18, "Cancelar Reserva");
        change_color(240);

        gotoxy(46, 22);
        cout<<"  ";
        button(25, 1, 48, 21, "Volver");
				break;

      //$ SALIR
      case 5:
        gotoxy(46, 10);
        cout<<"  ";
        button(25, 1, 48, 9, "Laptops");

        gotoxy(46, 13);
        cout<<"  ";
        button(25, 1, 48, 12, "Cubiculos");

        gotoxy(46, 16);
        cout<<"  ";
        button(25, 1, 48, 15, "Reservas Hechas");

        gotoxy(46, 19);
        cout<<"  ";
        button(25, 1, 48, 18, "Cancelar Reserva");

        change_color(241);
        gotoxy(46, 22);
        cout<<"->";
        button(25, 1, 48, 21, "Volver");
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
      UserMain::cancelar_reserva(gestor);
      break;
    case 5:
      gestor.cambiar_ventana(Ventanas::MAINWINDOW);
      break;
  }
}

void UserMain::main(GestorVentanas& gestor){
  UserMain::mostrar(gestor);
  UserMain::seleccionar_opcion(gestor);
}