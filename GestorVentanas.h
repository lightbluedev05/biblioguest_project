#ifndef GESTORVENTANAS_H
#define GESTORVENTANAS_H

#include <string>
//INCLUIR .H DE CADA VENTANA
#include "MainWindow.h"
#include "UserLogin.h"
#include "UserMain.h"
#include "LaptopMain.h"
#include "CubiculosMain.h"
#include "ReservasHechas.h"
#include "AdminLogin.h"
#include "AdminMain.h"
#include "CubiculosReserva.h"


//LLAMAR A CADA CLASE DE VENTANA AÑADIDA
class MainWindow;
class UserLogin;
class UserMain;
class LaptopMain;
class CubiculosMain;
class ReservasHechas;
class AdminLogin;
class AdminMain;
class CubiculosReserva;

//AGREGAR LA VENTANA EN EL ENUM
enum class Ventanas{
  MAINWINDOW,
  USERLOGIN,
  USERMAIN,
  LAPTOPMAIN,
  CUBICULOSMAIN,
  RESERVASHECHAS,
  ADMINLOGIN,
  ADMINMAIN,
  CUBICULOSRESERVA
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
    Ventanas ventana_actual=Ventanas::CUBICULOSMAIN;

    //CREAR UN OBJETO DE CADA VENTANA
    MainWindow* main_window;
    UserLogin* user_login;
    UserMain* user_main;
    LaptopMain* laptop_main;
    CubiculosMain* cubiculos_main;
    ReservasHechas* reservas_hechas;
    AdminLogin* admin_login;
    AdminMain* admin_main;
    CubiculosReserva* cubiculos_reserva;
};

#endif