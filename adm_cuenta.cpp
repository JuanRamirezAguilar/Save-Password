#include "adm_cuenta.hpp"

// Crear el directorio si no existe
    /*if (_mkdir("data") == -1 && errno != EEXIST) {
        throw runtime_error("Error al crear el directorio.");
    }

    ofstream file_trial;
    file_trial.open("data\\trial.txt", ios_base::out | ios_base::trunc);

    if (!file_trial.is_open()) {
        throw ios_base::failure("Error al abrir el archivo.");
    }

    file_trial << "Texto de prueba...";

    file_trial.close();*/

// La estructura de los archivos deberia ser users/"name user"/data.txt
// En data.txt se guarda todas las cuentas.

void Administrador::make_file(std::string dir) {
    try {
        std::string total_dir = "//account//" + dir + ".txt";
        if (!std::ifstream(total_dir)) {
            std::ofstream create(total_dir);
            create.close();
        }
    }   catch(const std::exception& e) {
        throw std::ios_base::failure("Error, direccion o archivo no validos.");
    }
}

void Administrador::set_lista(const Lista<Cuenta> other_list) {
    recover_list = other_list;
}

Lista<Cuenta> Administrador::get_list() {
    return recover_list;
}

void Administrador::up_list(std::string dir) {

}

void Administrador::down_list(std::string dir) {

}
