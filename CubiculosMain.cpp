#include "CubiculosMain.h"
#include "GestorVentanas.h"
#include "functions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <cstdlib>

using namespace std;

void escoger_color(int valor){
  if(valor==1){
    change_color(244);
  } else {
    change_color(240);
  }
}

void pintar_cubiculo(int cubiculo[], int x, int y){
  escoger_color(cubiculo[0]);
  gotoxy(x, y);
  cout<<"08am-10am";

  escoger_color(cubiculo[1]);
  cout<<"  10am-12pm";

  escoger_color(cubiculo[2]);
  cout<<"  12pm-02pm";

  escoger_color(cubiculo[3]);
  gotoxy(x, y+1);
  cout<<"02pm-04pm";

  escoger_color(cubiculo[4]);
  cout<<"  04pm-06pm";

  escoger_color(cubiculo[5]);
  cout<<"  06pm-08pm";

  change_color(240);
}

void CubiculosMain::mostrar() {
  change_color(112);
  system("cls");

  change_color(240);
  rectangle(46, 19, 37, 3);

  change_color(244);
  gotoxy(53,4);
  cout<<"MENU DE CUBICULOS";

  change_color(240);
  gotoxy(38, 5);
  cout<<"--------------------------------------------";
  gotoxy(48, 7);
  cout<<"Escoja que desea realizar:";

  change_color(241);
  gotoxy(40, 20);
  cout<<"UTILIZE LAS FLECHAS PARA SELECCIONAR LAS";
  gotoxy(48, 21);
  cout<<"OPCIONES (ARRIBA Y ABAJO)";
}

void CubiculosMain::listar_cubiculos() {
  
  //$ OBTENCION DE LAS RESERVAS DE CUBICULOS
  ifstream archivo("cubiculos.txt");
  string linea;
  int aux;
  int codigo_cubiculo;

  int cubiculo101[6]={0,0,0,0,0,0};
  int cubiculo102[6]={0,0,0,0,0,0};
  int cubiculo103[6]={0,0,0,0,0,0};
  int cubiculo104[6]={0,0,0,0,0,0};
  int cubiculo201[6]={0,0,0,0,0,0};
  int cubiculo202[6]={0,0,0,0,0,0};
  int cubiculo203[6]={0,0,0,0,0,0};
  int cubiculo204[6]={0,0,0,0,0,0};

  while(getline(archivo, linea)){
    if(linea.find("101") != string::npos){
      istringstream ss(linea);
      ss >> codigo_cubiculo;
      ss.ignore();
      ss >> aux;
      cubiculo101[aux]=1;
    }
    if(linea.find("102") != string::npos){
      istringstream ss(linea);
      ss >> codigo_cubiculo;
      ss.ignore();
      ss >> aux;
      cubiculo102[aux]=1;
    }
    if(linea.find("103") != string::npos){
      istringstream ss(linea);
      ss >> codigo_cubiculo;
      ss.ignore();
      ss >> aux;
      cubiculo103[aux]=1;
    }
    if(linea.find("104") != string::npos){
      istringstream ss(linea);
      ss >> codigo_cubiculo;
      ss.ignore();
      ss >> aux;
      cubiculo104[aux]=1;
    }

    if(linea.find("201") != string::npos){
      istringstream ss(linea);
      ss >> codigo_cubiculo;
      ss.ignore();
      ss >> aux;
      cubiculo201[aux]=1;
    }
    if(linea.find("202") != string::npos){
      istringstream ss(linea);
      ss >> codigo_cubiculo;
      ss.ignore();
      ss >> aux;
      cubiculo202[aux]=1;
    }
    if(linea.find("203") != string::npos){
      istringstream ss(linea);
      ss >> codigo_cubiculo;
      ss.ignore();
      ss >> aux;
      cubiculo203[aux]=1;
    }
    if(linea.find("204") != string::npos){
      istringstream ss(linea);
      ss >> codigo_cubiculo;
      ss.ignore();
      ss >> aux;
      cubiculo204[aux]=1;
    }
  }


  //$ PINTADO DE CONSOLA
  change_color(112);
  system("cls");
  cout<<cubiculo101[0]<<endl;
  cout<<cubiculo101[1]<<endl;
  cout<<cubiculo101[2]<<endl;
  cout<<cubiculo101[3]<<endl;
  cout<<cubiculo101[4]<<endl;
  cout<<cubiculo101[5]<<endl;
  change_color(240);
  rectangle(90, 25, 15, 2);

  change_color(244);
  gotoxy(50,4);
  cout<<"LISTADO DE CUBICULOS";
  change_color(241);
  gotoxy(35,6);
  cout<<"Utilize las flechas (<- , ->) para cambiar de piso";

  gotoxy(40,26);
  cout<<"LOS HORARIOS EN ROJO YA ESTAN RESERVADOS";
  gotoxy(46,27);
  cout<<"Presione ENTER para salir...";

  change_color(240);
  rectangle(35, 4, 22, 12);
  rectangle(35, 4, 63, 12);
  rectangle(35, 4, 22, 19);
  rectangle(35, 4, 63, 19);

  //$ CAMBIO DE PISO
  int opc=1, tecla=75;
  while(tecla!=13){
    switch(tecla){
			case 75:
        change_color(241);
				gotoxy(37, 8);
        cout<<"+------------+";
        gotoxy(35, 9);
        cout<<"->|   PISO 1   |";
        gotoxy(37, 10);
        cout<<"+------------+";
        change_color(240);

        gotoxy(69, 8);
        cout<<"+------------+";
        gotoxy(67, 9);
        cout<<"  |   PISO 2   |";
        gotoxy(69, 10);
        cout<<"+------------+";

				opc=0;
				break;
			case 77:
				gotoxy(37, 8);
        cout<<"+------------+";
        gotoxy(35, 9);
        cout<<"  |   PISO 1   |";
        gotoxy(37, 10);
        cout<<"+------------+";

        change_color(241);
        gotoxy(69, 8);
        cout<<"+------------+";
        gotoxy(67, 9);
        cout<<"->|   PISO 2   |";
        gotoxy(69, 10);
        cout<<"+------------+";
        change_color(240);
				
				opc=1;
				break;
		}
		
    switch(opc){
      case 0:
        gotoxy(33,13);
        cout<<"CUBICULO #101";
        pintar_cubiculo(cubiculo101, 24, 15);
        gotoxy(74,13);
        cout<<"CUBICULO #102";
        pintar_cubiculo(cubiculo102, 65, 15);
        gotoxy(33,20);
        cout<<"CUBICULO #103";
        pintar_cubiculo(cubiculo103, 24, 22);
        gotoxy(74,20);
        cout<<"CUBICULO #104";
        pintar_cubiculo(cubiculo104, 65, 22);
        break;
      case 1:
        gotoxy(33,13);
        cout<<"CUBICULO #201";
        pintar_cubiculo(cubiculo201, 24, 15);
        gotoxy(74,13);
        cout<<"CUBICULO #202";
        pintar_cubiculo(cubiculo202, 65, 15);
        gotoxy(33,20);
        cout<<"CUBICULO #203";
        pintar_cubiculo(cubiculo203, 24, 22);
        gotoxy(74,20);
        cout<<"CUBICULO #204";
        pintar_cubiculo(cubiculo204, 65, 22);
        break;
    }
		tecla = _getch();
  }
  
  getch();
}

void CubiculosMain::seleccionar_opcion(GestorVentanas& gestor) {
  int opc=1, tecla=72;
  while(tecla!=13){

    if(tecla==72 && opc>1){
      opc--;
    }
    if(tecla==80 && opc<3){
      opc++;
    }

    switch(opc){
      //$ LISTADO
			case 1: 
				change_color(241);
				gotoxy(48, 9);
        cout<<"+-----------------------+";
        gotoxy(46, 10);
        cout<<"->|    Listar Cubiculos   |";
        gotoxy(48, 11);
        cout<<"+-----------------------+";
        change_color(240);

        gotoxy(48, 12);
        cout<<"+-----------------------+";
        gotoxy(46, 13);
        cout<<"  |        Reservar       |";
				gotoxy(48, 14);
        cout<<"+-----------------------+";

        gotoxy(48, 15);
        cout<<"+-----------------------+";
        gotoxy(46, 16);
        cout<<"  |         Atras         |";
				gotoxy(48, 17);
        cout<<"+-----------------------+";

				break;

      //$ RESERVAR
			case 2:
				gotoxy(48, 9);
        cout<<"+-----------------------+";
        gotoxy(46, 10);
        cout<<"  |    Listar Cubiculos   |";
        gotoxy(48, 11);
        cout<<"+-----------------------+";

        change_color(241);
        gotoxy(48, 12);
        cout<<"+-----------------------+";
        gotoxy(46, 13);
        cout<<"->|        Reservar       |";
				gotoxy(48, 14);
        cout<<"+-----------------------+";
        change_color(240);

        gotoxy(48, 15);
        cout<<"+-----------------------+";
        gotoxy(46, 16);
        cout<<"  |         Atras         |";
				gotoxy(48, 17);
        cout<<"+-----------------------+";

				break;

      //$ ATRAS
      case 3:
				gotoxy(48, 9);
        cout<<"+-----------------------+";
        gotoxy(46, 10);
        cout<<"  |    Listar Cubiculos   |";
        gotoxy(48, 11);
        cout<<"+-----------------------+";

        gotoxy(48, 12);
        cout<<"+-----------------------+";
        gotoxy(46, 13);
        cout<<"  |        Reservar       |";
				gotoxy(48, 14);
        cout<<"+-----------------------+";

        change_color(241);
        gotoxy(48, 15);
        cout<<"+-----------------------+";
        gotoxy(46, 16);
        cout<<"->|         Atras         |";
				gotoxy(48, 17);
        cout<<"+-----------------------+";
        change_color(240);

				break;
		}
		
		tecla = _getch();
  }

  switch(opc){
    case 1:
      CubiculosMain::listar_cubiculos();
      break;
    case 2:
      //gestor.cambiar_ventana(Ventanas::CUBICULOSRESERVA);
      break;
    case 3:
      gestor.cambiar_ventana(Ventanas::USERMAIN);
      break;
  }
}

void CubiculosMain::main(GestorVentanas& gestor) {
  CubiculosMain::mostrar();
  CubiculosMain::seleccionar_opcion(gestor);
}