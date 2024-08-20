#include "menuPrincipal.hpp"
#include <windows.h>
#include <fstream>
#include <direct.h> // Para _mkdir en Windows
#include <stdexcept> // Para std::runtime_error
#include <iostream>

using namespace std;

int main () {
    SetConsoleOutputCP(CP_UTF8);
    Menu mi_menu;

    std::cout << sizeof(mi_menu);
    std::cin.clear();
    std::cin.sync();
    std::cin.ignore();

    mi_menu.menu();

    

    return 0;
}
