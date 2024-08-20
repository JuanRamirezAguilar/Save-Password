#ifndef ADM_CUENTA_HPP
#define ADM_CUENTA_HPP

#include "cuenta.hpp"
#include "lista.hpp"

#include <fstream>
#include <iostream>
#include <direct.h> // Para _mkdir en Windows
#include <stdexcept> // Para std::runtime_error

class Administrador {
    private:
        Lista<Cuenta> recover_list;
        std::ostream out_stream;
        std::fstream in_stream;

        void make_file(std::string dir);

    private:
        void set_lista(const Lista<Cuenta> other_list);
        Lista<Cuenta> get_list();

        

        void up_list(std::string dir);
        void down_list(std::string dir);
};

#endif // ADM_CUENTA_HPP