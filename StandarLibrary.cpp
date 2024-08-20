#include "StandarLibrary.h"

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

void StandarLibrary::pausa () {
    std::cin.clear();
    std::cin.sync();
    std::cin.ignore();
}

/*void StandarLibrary::timeStop(int Milsec) {
    Sleep(Milsec);
}*/

void StandarLibrary::limpiaBuffer (void) {
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void StandarLibrary::limpiarpantalla() {
    system(CLEAR);
}

void StandarLibrary::gotoxy (int x,int y) {
    printf("%c[%d;%df",0x1B,y,x);
}

void StandarLibrary::setborder(int startX, int startY, int width, int height) {
    int columnaX, FilaY;

    for (columnaX = startX; columnaX < startX + width; columnaX++) {
        gotoxy(columnaX, startY);
        putchar('=');
        gotoxy(columnaX, startY + height - 1);
        putchar('=');
    }

    for (FilaY = startY + 1; FilaY < startY + height - 2; FilaY++) {
        gotoxy(startX, FilaY);
        putchar('|');
        gotoxy(startX + width - 1, FilaY);
        putchar('|');
    }
}

void StandarLibrary::AltEnter() {
    keybd_event(VK_MENU,
                0x38,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                KEYEVENTF_KEYUP,
                0);
    keybd_event(VK_MENU,
                0x38,
                KEYEVENTF_KEYUP,
                0);
    return;
}

void StandarLibrary::ocultar_cursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void StandarLibrary::mostrar_cursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = TRUE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}