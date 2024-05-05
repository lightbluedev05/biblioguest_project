#ifndef GESTORVENTANAS_H
#define GESTORVENTANAS_H

#include <string>
//INCLUIR .H DE CADA VENTANA
#include "MainWindow.h"
#include "UserLogin.h"
#include "UserMain.h"


//LLAMAR A CADA CLASE DE VENTANA AÑADIDA
class MainWindow;
class UserLogin;
class UserMain;

//AGREGAR LA VENTANA EN EL ENUM
enum class Ventanas{
  MAINWINDOW,
  USERLOGIN,
  USERMAIN
};

class GestorVentanas {
  public:
    std::string codigo;
    std::string contrasena;
    std::string nombre;
    bool exit=false;

    void iniciar();
    void cambiar_ventana(Ventanas nueva_ventana);
    void terminar_programa();
  private:
    Ventanas ventana_actual=Ventanas::MAINWINDOW;

    //CREAR UN OBJETO DE CADA VENTANA
    MainWindow* main_window;
    UserLogin* user_login;
    UserMain* user_main;
};

#endif