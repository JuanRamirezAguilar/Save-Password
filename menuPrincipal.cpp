#include "menuPrincipal.hpp"

#include <iostream>
#include <conio.h>

#include "StandarLibrary.h"
#include "Colores.h"

#include "menuRegistrar.hpp"


Menu::Menu() {

}

void Menu::menu_principal() {
    StandarLibrary utilidades;
    utilidades.ocultar_cursor();

    utilidades.limpiarpantalla();
    utilidades.setborder(1, 1, 60, 40);

    imprimir_menu();

    INT16 opc = LISTA;
    bool bucle_del_menu = true;
    int x1, y, x2;

    while (bucle_del_menu) {

        // El switch sirve para dibujar las flechas de seleccion.
        switch (opc) {
            case LISTA:
                x1 = 12; x2 = 36; y = 5;
                flechas_seleccion(x1, x2, y);
                break;
                        
            case BUSCAR:
                x1 = 12; x2 = 37; y = 7;
                flechas_seleccion(x1, x2, y);
                break;

            case REGISTRAR:
                x1 = 12; x2 = 40; y = 9;
                flechas_seleccion(x1, x2, y);
                break;

            case ELIMINAR:
                x1 = 12; x2 = 39; y = 11;
                flechas_seleccion(x1, x2, y);
                break;

            case OPCIONES:
                x1 = 12; x2 = 24; y = 13;
                flechas_seleccion(x1, x2, y);
                break;

            case SALIR:
                x1 = 12; x2 = 21; y = 15;
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
                    if (opc > LISTA) { // Lista es igual a 1
                        borrar_flechas(x1, x2, y);
                        opc--;
                    } 
                    break;
                case 80: // Flecha abajo
                    if (opc < SALIR) { // Salir es igual a 6
                        borrar_flechas(x1, x2, y);
                        opc++;
                    } 
                    break;
                default:
                    break;
            }
        
        } else if (car == '\r') {
            switch (opc) {
                case LISTA:
                    break;
                            
                case BUSCAR:
                    break;

                case REGISTRAR: registrar(); break;

                case ELIMINAR:
                    break;

                case OPCIONES:
                    break;

                case SALIR:
                    bucle_del_menu = false;
                    break;

                    default:
                        break;
            }
        }
    }
}

void Menu::menu() {
    menu_principal();
}

void Menu::imprimir_menu() {
    StandarLibrary utilidades;

    std::cout << ARB;
    utilidades.gotoxy(15, 2);

    std::cout << "ReLink --Tus contraseñas seguras--" <<std::endl;
    std::cout << RTNC;
    
    utilidades.gotoxy(15, 5);
    std::cout << "Lista de contraseñas" <<std::endl;

    utilidades.gotoxy(15, 7);
    std::cout << "Buscar una contraseña" <<std::endl;

    utilidades.gotoxy(15, 9);
    std::cout << "Registrar una contraseña" <<std::endl;
    
    utilidades.gotoxy(15, 11);
    std::cout << "Eliminar una contraseña" <<std::endl;
    
    utilidades.gotoxy(15, 13);
    std::cout << "Opciones" <<std::endl;
    
    utilidades.gotoxy(15, 15);
    std::cout << "Salir" <<std::endl;

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

void Menu::flechas_seleccion(int x1_pos, int x2_pos, int y_pos) {
    StandarLibrary utilidades;
    
    std::cout << AF;
    utilidades.gotoxy(x1_pos, y_pos);
    std::cout << ">>" <<std::endl;
    utilidades.gotoxy(x2_pos, y_pos);
    std::cout << "<<" <<std::endl;
    std::cout << RTNC;
}

void Menu::borrar_flechas(int x1_pos, int x2_pos, int y_pos) {
    StandarLibrary utilidades;
    
    utilidades.gotoxy(x1_pos, y_pos);
    std::cout << "  " <<std::endl;
    utilidades.gotoxy(x2_pos, y_pos);
    std::cout << "  " <<std::endl;
}

void Menu::limpiar_pantalla() {
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

void Menu::reintegrar_menu() {
    limpiar_pantalla();
    imprimir_menu();
}

void Menu::registrar() {
    Menu_Res menu_registrar;
    menu_registrar.menu();
    reintegrar_menu();
}
