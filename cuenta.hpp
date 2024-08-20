#ifndef CUENTA_HPP
#define CUENTA_HPP

#include <iostream>

class Cuenta {

    private:
        int id;
        std::string name_service;
        std::string password;

    public:
        Cuenta();
        Cuenta(const std::string &, const std::string &);
        Cuenta(const int &, const std::string &, const std::string &);
        Cuenta(const Cuenta &);
        
        void set_id(const int &);
        void set_name_service(const std::string &);
        void set_password(const std::string &);

        int get_id() const;
        std::string get_name_service() const;
        std::string get_password() const;

        Cuenta & operator = (const Cuenta & copia);
        bool operator == (const Cuenta& comparado) const;
        bool operator != (const Cuenta& comparado) const;
        bool operator < (const Cuenta& comparado) const;
        bool operator <= (const Cuenta& comparado) const;
        bool operator > (const Cuenta& comparado) const;
        bool operator >= (const Cuenta& comparado) const;
        friend std::ostream& operator << (std::ostream& out, const Cuenta& objSalida);
        friend std::istream& operator >> (std::istream& in, Cuenta& objEntrada);
};


#endif // CUENTA_HPP