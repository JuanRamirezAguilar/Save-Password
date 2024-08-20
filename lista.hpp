#ifndef LISTA_HPP
#define LISTA_HPP

#include <iostream>

template <class DATA>
class Lista;
template <class DATA>
class Nodo;

template <class DATA>
class Nodo {
    private:
        DATA elem;
        Nodo<DATA> * sig;

    public:
        Nodo() : sig(nullptr){}
        friend class Lista<DATA>;
};

template <class DATA>
class Lista {
    private:
        Nodo<DATA> * lista;
        Nodo<DATA> * back_pos;
        int size_of_list;
        
        Nodo<DATA> * front();
        Nodo<DATA> * back();
        Nodo<DATA> * ant(Nodo<DATA> * pos);
        void push(Nodo<DATA> * pos, DATA & data);
        Nodo<DATA> * find_ptr(DATA elem);

    public:
        Lista() : lista(nullptr), back_pos(lista), size_of_list(0) {}
        Lista(const Lista & l);
        Lista(std::initializer_list<DATA> elementos);
        ~Lista();

        // Operadores de la lista
        bool operator == (const Lista<DATA> & list) const;
        bool operator != (const Lista<DATA> & list) const;
        bool operator < (const Lista<DATA> & list) const;
        bool operator <= (const Lista<DATA> & list) const;
        bool operator > (const Lista<DATA> & list) const;
        bool operator >= (const Lista<DATA> & list) const;
        Lista<DATA> & operator = (const Lista<DATA> & list);

        // Miembros de la lista
        bool empty() const;
        int size() const;
        void anular();
        void push_back(DATA data);
        void push_front(DATA data);
        bool exist(DATA elem);
        void print();
        // Remove last element from the list
        void pop_back();
        // Remove first element from the list
        void pop_front();
        void index() const;
        // Index range go from 0 to size() - 1
        void remove_by_index(int index);
        void remove_by_element(DATA element);

        DATA & operator[](int indice);
        

        // Inicio de la clase Iterator para el uso de for-range
        class Iterator {
            private:
                Nodo<DATA> * current;

            public:
                Iterator(Nodo<DATA> * start) : current(start) {}
                DATA& operator * () const { return current->elem; }
                Iterator& operator++() { 
                    current = current->sig; 
                    return *this; 
                }
                bool operator!=(const Iterator& other) const { 
                    return current != other.current; 
                }
                bool operator==(const Iterator& other) const { 
                    return current == other.current; 
                }

        };
        // Fin de la clase Iterator para el uso de for-range
        // Funciones para el iterador
        Iterator begin() { return Iterator(lista); }
        Iterator end() { return Iterator(nullptr); }
};

#endif // LISTA_HPP