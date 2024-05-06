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
  system("cls");
  rectangle(46, 20, 30, 5);
  gotoxy(37,8);
  cout<<"ALUMNO, INGRESE SUS CREDENCIALES";
  gotoxy(37,11);
  cout<<"CODIGO:";
  gotoxy(37,12);
  cout<<"+------------------------------+";
  gotoxy(37,13);
  cout<<"|                              |";
  gotoxy(37,14);
  cout<<"+------------------------------+";

  gotoxy(37,16);
  cout<<"CONTRASENA:";
  gotoxy(37,17);
  cout<<"+------------------------------+";
  gotoxy(37,18);
  cout<<"|                              |";
  gotoxy(37,19);
  cout<<"+------------------------------+";

  gotoxy(35, 22);
  cout<<"+------------+";
  gotoxy(35, 23);
  cout<<"|  INGRESAR  |";
  gotoxy(35, 24);
  cout<<"+------------+";

  gotoxy(58, 22);
  cout<<"+-----------+";
  gotoxy(58, 23);
  cout<<"|   SALIR   |";
  gotoxy(58, 24);
  cout<<"+-----------+";

}

void UserLogin::ingresar_credenciales(GestorVentanas& gestor){
  gotoxy(38,13);
  cin>>gestor.codigo;
  gotoxy(38,18);
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
				change_color(15,22);
				gotoxy(35, 22);
        cout<<"+------------+";
        gotoxy(35, 23);
        cout<<"|  INGRESAR  |";
        gotoxy(35, 24);
        cout<<"+------------+";

        change_color(15,0);
        gotoxy(58, 22);
        cout<<"+-----------+";
        gotoxy(58, 23);
        cout<<"|   SALIR   |";
				gotoxy(58, 24);
        cout<<"+-----------+";

				opc=1;
				break;
			case 77:
				change_color(15,0);
				gotoxy(35, 22);
        cout<<"+------------+";
        gotoxy(35, 23);
        cout<<"|  INGRESAR  |";
        gotoxy(35, 24);
        cout<<"+------------+";

        change_color(15,22);
        gotoxy(58, 22);
        cout<<"+-----------+";
        gotoxy(58, 23);
        cout<<"|   SALIR   |";
				gotoxy(58, 24);
        cout<<"+-----------+";
        change_color(15,0);
				
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