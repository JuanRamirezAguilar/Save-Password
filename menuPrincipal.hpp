#ifndef MENUPRINCIPAL_HPP
#define MENUPRINCIPAL_HPP

enum OPCIONES {LISTA = 1, BUSCAR, REGISTRAR, ELIMINAR, OPCIONES, SALIR};

class Menu {

    private:
        void menu_principal();

    public:
        Menu();
        void menu();
        void imprimir_menu();
        void flechas_seleccion(int x1_pos, int x2_pos, int y_pos);
        void borrar_flechas(int x1_pos, int x2_pos, int y_pos);
        void limpiar_pantalla();
        void reintegrar_menu();

        void registrar();
};

#endif // MENUPRINCIPAL_HPP