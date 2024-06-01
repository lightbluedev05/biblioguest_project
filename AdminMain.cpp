#include "GestorVentanas.h"
#include "AdminMain.h"
#include "functions.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <iostream>

void AdminMain::mostrar(GestorVentanas& gestor) {
    system("cls");
    hide_cursor();

    change_color(240);
    rectangle(50, 22, 35, 2);

    change_color(244);
    gotoxy(53, 3);
    std::cout << "MENU DE ADMIN";

    change_color(240);
    gotoxy(36, 4);
    std::cout << "------------------------------------------------";
    gotoxy(37, 5);
    std::cout << "BIENVENIDO ADMIN";
    gotoxy(40, 7);
    std::cout << "ESCOGE LA ACTIVIDAD QUE DESEA VERIFICAR:";

    change_color(241);
    gotoxy(40, 23);
    std::cout << "UTILIZE LAS FLECHAS PARA SELECCIONAR LAS";
    gotoxy(48, 24);
    std::cout << "OPCIONES (ARRIBA Y ABAJO)";
}

void AdminMain::seleccionar_opcion(GestorVentanas& gestor) {
    int opc = 1, tecla = 72;
    while (tecla != 13) {

        if (tecla == 72 && opc > 1) {
            opc--;
        }
        if (tecla == 80 && opc < 4) {
            opc++;
        }

        switch (opc) {
            //$ LAPTOPS
            case 1:
                change_color(241);
                gotoxy(48, 9);
                std::cout << "+-----------------------+";
                gotoxy(46, 10);
                std::cout << "->|       Verificar       |";
                gotoxy(48, 11);
                std::cout << "+-----------------------+";
                change_color(240);

                gotoxy(48, 12);
                std::cout << "+-----------------------+";
                gotoxy(46, 13);
                std::cout << "  |       XXXXXXXXX       |";
                gotoxy(48, 14);
                std::cout << "+-----------------------+";

                gotoxy(48, 15);
                std::cout << "+-----------------------+";
                gotoxy(46, 16);
                std::cout << "  |      Estadisticas     |";
                gotoxy(48, 17);
                std::cout << "+-----------------------+";

                gotoxy(48, 18);
                std::cout << "+-----------------------+";
                gotoxy(46, 19);
                std::cout << "  |         Salir         |";
                gotoxy(48, 20);
                std::cout << "+-----------------------+";
                break;

            //$ CUBICULOS
            case 2:
                gotoxy(48, 9);
                std::cout << "+-----------------------+";
                gotoxy(46, 10);
                std::cout << "  |       Verificar       |";
                gotoxy(48, 11);
                std::cout << "+-----------------------+";

                change_color(241);
                gotoxy(48, 12);
                std::cout << "+-----------------------+";
                gotoxy(46, 13);
                std::cout << "->|       XXXXXXXXX       |";
                gotoxy(48, 14);
                std::cout << "+-----------------------+";
                change_color(240);

                gotoxy(48, 15);
                std::cout << "+-----------------------+";
                gotoxy(46, 16);
                std::cout << "  |      Estadisticas     |";
                gotoxy(48, 17);
                std::cout << "+-----------------------+";

                gotoxy(48, 18);
                std::cout << "+-----------------------+";
                gotoxy(46, 19);
                std::cout << "  |         Salir         |";
                gotoxy(48, 20);
                std::cout << "+-----------------------+";
                break;

            //$ RESERVAS HECHAS
            case 3:
                gotoxy(48, 9);
                std::cout << "+-----------------------+";
                gotoxy(46, 10);
                std::cout << "  |       Verificar       |";
                gotoxy(48, 11);
                std::cout << "+-----------------------+";

                gotoxy(48, 12);
                std::cout << "+-----------------------+";
                gotoxy(46, 13);
                std::cout << "  |       XXXXXXXXX       |";
                gotoxy(48, 14);
                std::cout << "+-----------------------+";

                change_color(241);

                gotoxy(48, 15);
                std::cout << "+-----------------------+";
                gotoxy(46, 16);
                std::cout << "->|      Estadisticas     |";
                gotoxy(48, 17);
                std::cout << "+-----------------------+";

                change_color(240);
                gotoxy(48, 18);
                std::cout << "+-----------------------+";
                gotoxy(46, 19);
                std::cout << "  |         Salir         |";
                gotoxy(48, 20);
                std::cout << "+-----------------------+";
                break;

            case 4:
                gotoxy(48, 9);
                std::cout << "+-----------------------+";
                gotoxy(46, 10);
                std::cout << "  |       Verificar       |";
                gotoxy(48, 11);
                std::cout << "+-----------------------+";

                gotoxy(48, 12);
                std::cout << "+-----------------------+";
                gotoxy(46, 13);
                std::cout << "  |       XXXXXXXXX       |";
                gotoxy(48, 14);
                std::cout << "+-----------------------+";

                gotoxy(48, 15);
                std::cout << "+-----------------------+";
                gotoxy(46, 16);
                std::cout << "  |      Estadisticas     |";
                gotoxy(48, 17);
                std::cout << "+-----------------------+";

                change_color(241);
                gotoxy(48, 18);
                std::cout << "+-----------------------+";
                gotoxy(46, 19);
                std::cout << "->|         Salir         |";
                gotoxy(48, 20);
                std::cout << "+-----------------------+";
                change_color(240);
                break;
        }

        tecla = _getch();
    }

    // Declarar variables antes del switch
    std::string filePath;
    std::string command;
    int result;

    switch (opc) {
        case 1:
            gestor.cambiar_ventana(Ventanas::ADMINVERIFICAR);
            break;
        case 2:
            //gestor.cambiar_ventana(Ventanas::ADMINSTATIC);
            break;
        case 3:
            //gestor.cambiar_ventana(Ventanas::ADMINSTATIC);
            filePath = "Laptops.xlsx";

            // Comando para abrir Excel con el archivo especificado
            command = "start excel \"" + filePath + "\"";

            // Ejecutar el comando
            result = std::system(command.c_str());
            break;
        case 4:
            gestor.cambiar_ventana(Ventanas::MAINWINDOW);
            break;
    }
}

void AdminMain::main(GestorVentanas& gestor) {
    AdminMain::mostrar(gestor);
    AdminMain::seleccionar_opcion(gestor);
}