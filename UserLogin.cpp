#include "GestorVentanas.h"
#include "UserLogin.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "functions.h"
#include "VerificarUsuario.h"

using namespace std;

void UserLogin::mostrar(){
  show_cursor();

  change_color(112);
  system("cls");
  //rectangle(48,22,37,4);
  change_color(240);
  rectangle(46, 20, 38, 5);

  gotoxy(45,8);
  cout<<"ALUMNO, INGRESE SUS CREDENCIALES";

  gotoxy(45,11);
  cout<<"CODIGO:";
  gotoxy(45,12);
  cout<<"+------------------------------+";
  gotoxy(45,13);
  cout<<"|                              |";
  gotoxy(45,14);
  cout<<"+------------------------------+";

  gotoxy(45,16);
  cout<<"CONTRASENA:";
  gotoxy(45,17);
  cout<<"+------------------------------+";
  gotoxy(45,18);
  cout<<"|                              |";
  gotoxy(45,19);
  cout<<"+------------------------------+";

  gotoxy(43, 22);
  cout<<"+------------+";
  gotoxy(43, 23);
  cout<<"|  INGRESAR  |";
  gotoxy(43, 24);
  cout<<"+------------+";

  gotoxy(66, 22);
  cout<<"+-----------+";
  gotoxy(66, 23);
  cout<<"|   SALIR   |";
  gotoxy(66, 24);
  cout<<"+-----------+";

}

void UserLogin::ingresar_credenciales(GestorVentanas& gestor){
  gotoxy(46,13);
  cin>>gestor.codigo;
  gotoxy(46,18);
  cin>>gestor.contrasena;
}

void UserLogin::validar_credenciales(GestorVentanas& gestor){
  system("cls");
  int verificacion = VerificarUsuario(gestor.codigo, gestor.contrasena, gestor);
  switch (verificacion){
    case 1:
      gestor.cambiar_ventana(Ventanas::USERMAIN);
      break;
    case 0:
      cout<<"error";
      break;
  }
}

void UserLogin::seleccionar_opcion(GestorVentanas& gestor){
  int opc=1, tecla=75;
  while(tecla!=13){
    switch(tecla){
			case 75:
        change_color(31);
				gotoxy(43, 22);
        cout<<"+------------+";
        gotoxy(43, 23);
        cout<<"|  INGRESAR  |";
        gotoxy(43, 24);
        cout<<"+------------+";
        change_color(240);

        gotoxy(66, 22);
        cout<<"+-----------+";
        gotoxy(66, 23);
        cout<<"|   SALIR   |";
        gotoxy(66, 24);
        cout<<"+-----------+";

				opc=1;
				break;
			case 77:
				gotoxy(43, 22);
        cout<<"+------------+";
        gotoxy(43, 23);
        cout<<"|  INGRESAR  |";
        gotoxy(43, 24);
        cout<<"+------------+";

        change_color(31);
        gotoxy(66, 22);
        cout<<"+-----------+";
        gotoxy(66, 23);
        cout<<"|   SALIR   |";
        gotoxy(66, 24);
        cout<<"+-----------+";
        change_color(240);
				
				opc=0;
				break;
		}
		
		tecla = _getch();
  }

  switch(opc){
    case 1:
      UserLogin::validar_credenciales(gestor);
      break;
    case 0:
      gestor.cambiar_ventana(Ventanas::MAINWINDOW);
      break;
  }
}

void UserLogin::main(GestorVentanas& gestor){
  UserLogin::mostrar();
  UserLogin::ingresar_credenciales(gestor);
  UserLogin::seleccionar_opcion(gestor);
}