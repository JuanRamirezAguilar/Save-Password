#ifndef MENUREGISTRAR_HPP
#define MENUREGISTRAR_HPP

enum OPCIONES_CON {REGISTRAR_CON = 1, SALIR_CON};

class Menu_Res {

    private:
        void menu_principal();

    public:
        void menu();
        void imprimir_menu();
        void flechas_seleccion(int x1_pos, int x2_pos, int y_pos);
        void borrar_flechas(int x1_pos, int x2_pos, int y_pos);
        void limpiar_pantalla();

};

#endif // MENUREGISTRAR_HPP