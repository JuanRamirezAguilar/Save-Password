#include "menuRegistrar.hpp"

#include <iostream>
#include <conio.h>

#include "StandarLibrary.h"
#include "Colores.h"

void Menu_Res::menu_principal() {
    limpiar_pantalla();
    imprimir_menu();

    INT16 opc = REGISTRAR_CON;
    bool bucle_del_menu = true;
    int x1, y, x2;

    while (bucle_del_menu) {

        // El switch sirve para dibujar las flechas de seleccion.
        switch (opc) {
            case REGISTRAR_CON:
                x1 = 12; x2 = 36; y = 5;
                flechas_seleccion(x1, x2, y);
                break;

            case SALIR_CON:
                x1 = 12; x2 = 24; y = 7;
                flechas_seleccion(x1, x2, y);
                break;

                default:
                    break;
        }

        char car = char(getch());
        if (car == char(224)) { // Código especial para teclas de flecha
            car = char(getch());
            switch (car) {
                case 72: // Flecha arriba
                    if (opc > REGISTRAR_CON) { // Lista es igual a 1
                        borrar_flechas(x1, x2, y);
                        opc--;
                    } 
                    break;
                case 80: // Flecha abajo
                    if (opc < SALIR_CON) { // Salir es igual a 2
                        borrar_flechas(x1, x2, y);
                        opc++;
                    } 
                    break;
                default:
                    break;
            }
        
        } else if (car == '\r') {
            switch (opc) {
                case REGISTRAR_CON:
                    break;

                case SALIR_CON:
                    bucle_del_menu = false;
                    break;

                    default:
                        break;
            }
        }
    }
}

void Menu_Res::menu() {
    menu_principal();
}

void Menu_Res::imprimir_menu()
{
    StandarLibrary utilidades;

    std::cout << ARB;
    utilidades.gotoxy(15, 2);
    std::cout << "ReLink --Tus contraseñas seguras--";
    
    std::cout << AQB;
    utilidades.gotoxy(23, 3);
    std::cout << "--Registrar--";
    std::cout << RTNC;


    utilidades.gotoxy(15, 5);
    std::cout << "Registrar Contraseña" <<std::endl;

    utilidades.gotoxy(15, 7);
    std::cout << "Regresar" <<std::endl;

    utilidades.gotoxy(10, 25);
    std::cout << "Seleccionar [";
    std::cout << VF;
    std::cout << "ENTER";
    std::cout << RTNC;
    std::cout <<"]";
    utilidades.gotoxy(40, 25);
    std::cout << "Mover [";
    std::cout << VF;
    std::cout << "⬆, ⬇";
    std::cout << RTNC;
    std::cout << "]";
}

void Menu_Res::flechas_seleccion(int x1_pos, int x2_pos, int y_pos) {
    StandarLibrary utilidades;
    
    std::cout << AF;
    utilidades.gotoxy(x1_pos, y_pos);
    std::cout << ">>" <<std::endl;
    utilidades.gotoxy(x2_pos, y_pos);
    std::cout << "<<" <<std::endl;
    std::cout << RTNC;
}

void Menu_Res::borrar_flechas(int x1_pos, int x2_pos, int y_pos) {
    StandarLibrary utilidades;
    
    utilidades.gotoxy(x1_pos, y_pos);
    std::cout << "  " <<std::endl;
    utilidades.gotoxy(x2_pos, y_pos);
    std::cout << "  " <<std::endl;
}

void Menu_Res::limpiar_pantalla() {
    StandarLibrary utilidades;

    // Metodo menos eficiente
    /*const int height = 30, width = 60, init = 2;
    for (int i = init; i < width; i++) {
        for (int j = init; j < height; j++) {
            utilidades.gotoxy(i, j);
            std::cout << " ";
        }
    }*/

   const int height = 30, init = 2;
   for (int i = init; i < height; i++) {
        utilidades.gotoxy(init, i);
        std::cout << "                                                        ";
   }
}
