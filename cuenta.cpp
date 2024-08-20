#include "cuenta.hpp"

Cuenta::Cuenta() : id(0), name_service(""), password("") {}

Cuenta::Cuenta(const std::string & name_aux, const std::string & pass_aux) : id(0) {
    name_service = name_aux;
    password = pass_aux;
}

Cuenta::Cuenta(const int & id_aux, const std::string & name_aux, const std::string & pass_aux) {
    id = id_aux;
    name_service = name_aux;
    password = pass_aux;
}

Cuenta::Cuenta(const Cuenta & copia) : id(copia.id), name_service(copia.name_service), password(copia.password) {}

void Cuenta::set_id(const int & id_aux) {
    id = id_aux;
}

void Cuenta::set_name_service(const std::string & name_aux) {
    name_service = name_aux;
}

void Cuenta::set_password(const std::string & pass_aux) {
    // Crear logica de encriptado del password
    password = pass_aux;
}

int Cuenta::get_id() const {
    return id;
}

std::string Cuenta::get_name_service() const {
    return name_service;
}

std::string Cuenta::get_password() const {
    return password;
}

Cuenta & Cuenta::operator = (const Cuenta &copia) {
    if (copia == *this)
        return *this;

    id = copia.id;
    name_service = copia.name_service;
    password = copia.password;

    return *this;
}


bool Cuenta::operator == (const Cuenta & comparado) const {
    return id == comparado.id;
}

bool Cuenta::operator != (const Cuenta & comparado) const {
    return !(comparado == *this);
}

bool Cuenta::operator < (const Cuenta & comparado) const {
    return id < comparado.id;
}

bool Cuenta::operator <= (const Cuenta & comparado) const {
    return id <= comparado.id;
}

bool Cuenta::operator > (const Cuenta & comparado) const {
    return !(id < comparado.id);
}

bool Cuenta::operator >= (const Cuenta & comparado) const {
    return id >= comparado.id;
}

std::ostream & operator << (std::ostream & out, const Cuenta & objSalida) {
    out << "Nombre: " << objSalida.name_service;
    out << "\tContrasena: " << objSalida.password;
    return out;
}

std::istream & operator >> (std::istream & in, Cuenta & objEntrada) {
    return in;
}
