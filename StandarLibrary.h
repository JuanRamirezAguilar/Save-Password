#ifndef STANDARLIBRARY_H_INCLUDED
#define STANDARLIBRARY_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "Colores.h"

class StandarLibrary {
    public:
        void pausa();
        //void timeStop(int Milsec);
        void limpiaBuffer();
        void limpiarpantalla();
        void gotoxy(int x, int y);
        void setborder(int startX, int startY, int width, int height);
        void AltEnter();
        void ocultar_cursor();
        void mostrar_cursor();

};

#endif // STANDARLIBRARY_H_INCLUDED