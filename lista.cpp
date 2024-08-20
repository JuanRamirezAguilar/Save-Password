#include "lista.hpp"

template <class DATA>
Lista<DATA>::Lista(const Lista & l) : Lista() {
    *this = l;
}

template <class DATA>
Lista<DATA>::Lista(std::initializer_list<DATA> elementos) : Lista() {
    for (const DATA & elemento : elementos) {
        push_back(elemento);
    }
}

template <class DATA>
inline Nodo<DATA> *Lista<DATA>::front() {
    return lista;
}   

template <class DATA>
inline Nodo<DATA> *Lista<DATA>::back() {
    return back_pos;
}

template <class DATA>
Nodo<DATA> *Lista<DATA>::ant(Nodo<DATA> *pos) {
    Nodo<DATA> * aux = lista;
    while (aux->sig != pos) {
        aux = aux->sig;
    }

    return aux;
}

template <class DATA>
void Lista<DATA>::push(Nodo<DATA> *pos, DATA & data) {
    Nodo<DATA> * new_nodo = nullptr;

    /* Este try catch se encarga de asignar memoria para el nuevo nodo,
       y en caso de que por algun motivo no se pueda asignar; lanza un error.
    */
    try {
        new_nodo = new Nodo<DATA>;
        new_nodo->elem = data;
    } catch (const std::bad_alloc & e) {
        std::cerr << "Error: No se pudo asignar memoria para un nuevo nodo. " << e.what() << std::endl;
        return;
    }

    if (empty()) {
        lista = new_nodo;
        back_pos = new_nodo;
        size_of_list++;
        return;
    }

    /*
        Si la lista esta vacia, se establece lista como el nuevo y ultimo nodo
        de la lista.

        |----------------|       |----------------|
        |                |       |                |
        |     lista      |   =   |   new_nodo     |
        |                |       |                |
        |----------------|       |----------------|

                                        ^
                                        |

                                |----------------|
                                |                |
                                |    back_pos    |
                                |                |
                                |----------------|

    
    */

    if (pos == back_pos) {
        back_pos->sig = new_nodo;
        back_pos = new_nodo;
        size_of_list++;

    /*
        Cuando la posicion es la ultima de la lista, se apunta sig al nuevo nodo
        y se actualiza la ultima posicion al nuevo nodo.

        |-----------|---|       |----------------|
        |           |   |       |                |
        |  back_pos |sig|   =   |   new_nodo     |
        |           |   |       |                |
        |-----------|---|       |----------------|

                                        ^
                                        |

                                |----------------|
                                |                |
                                |    back_pos    |
                                |                |
                                |----------------|

    
    */    


    } else if (pos == lista) {
        new_nodo->sig = lista;
        lista = new_nodo;
        size_of_list++;

    /*
        Cuando la posicion es el primer(lista) nodo de la lista, entonces se apunta sig
        de nuevo nodo a la lista y lista pasa a ser el nuevo nodo.

        |-----------|---|       |----------------|
        |           |   |       |                |
        |  new_nodo |sig|   =   |   lista        |
        |           |   |       |                |
        |-----------|---|       |----------------|

                                        
                ^                       
                |
                |               |-----------------|
                |               |                 |
                -----------     |    lista        |
                                |                 |
                                |---------------- |

    
    */

    } else {
        Nodo<DATA> * nodo_ant = nullptr;

        try {
            nodo_ant = ant(pos);
        } catch (...) {
            delete new_nodo;
            throw;
        }

        nodo_ant->sig = new_nodo;
        new_nodo->sig = pos;
        size_of_list++;
    }

    /*
        Cuando la posicion se encuentra en medio  de la lista, se busca el sig de la posicion del nodo
        y se apunta al nuevo nodo. Mientras el sig de nuevo nodo apunta a la posicion.

        |-----------|---|       |----------------|
        |           |   |       |                |
        |  ant(pos) |sig|   =   |   new_nodo     |
        |           |   |       |                |
        |-----------|---|       |----------------|

                                        
        |-----------|---|      |----------------|
        |           |   |      |                |
        | back_pos  |sig|  =   |     pos        |
        |           |   |      |                |
        |-----------|---|      |----------------|

    
    */
}

template <class DATA>
Nodo<DATA> *Lista<DATA>::find_ptr(DATA elem) {
    Nodo<DATA> * aux = lista;
    while (aux->elem != elem) {
        aux = aux->sig;
    }
    return aux;
}

template <class DATA>
Lista<DATA>::~Lista() {
    if (empty()) {
        return;
    }

    while (!empty()) {
        pop_back();
    }
    size_of_list = 0;
}

template <class DATA>
bool Lista<DATA>::operator == (const Lista<DATA> & list) const {
    if (size() != list.size()) { return false; }

    Nodo<DATA> * aux1 = lista;
    Nodo<DATA> * aux2 = list.lista;

    while (aux1 != nullptr && aux2 != nullptr) {
        if (aux1->elem != aux2->elem) {
            return false;  // Elementos diferentes
        }
        aux1 = aux1->sig;
        aux2 = aux2->sig;
    }

    // Ambas listas deben terminar al mismo tiempo para ser iguales
    return aux1 == nullptr && aux2 == nullptr;
}

template <class DATA>
bool Lista<DATA>::operator!=(const Lista<DATA> &list) const {
    return !(*this == &list);
}

template <class DATA>
bool Lista<DATA>::operator<(const Lista<DATA> &list) const {
    return size() < list.size();
}

template <class DATA>
bool Lista<DATA>::operator<=(const Lista<DATA> &list) const {
    return size() <= list.size();
}

template <class DATA>
bool Lista<DATA>::operator>(const Lista<DATA> &list) const {
    return size() > list.size();
}

template <class DATA>
bool Lista<DATA>::operator>=(const Lista<DATA> &list) const {
    return size() >= list.size();
}

template <class DATA>
Lista<DATA> & Lista<DATA>::operator = (const Lista<DATA> & list) {
    if (this == &list) { return *this; }

    anular();
    Nodo<DATA> * aux = list.lista;

    while (aux != nullptr) {
        push_back(aux->elem);  // Copiar cada elemento de la lista
        aux = aux->sig;
    }
    return *this;
}

template <class DATA>
bool Lista<DATA>::empty() const {
    return lista == nullptr;
}

template <class DATA>
int Lista<DATA>::size() const {
    return size_of_list;
}

template <class DATA>
void Lista<DATA>::anular() {
    ~Lista();
}

template <class DATA>
void Lista<DATA>::push_back(DATA data) {
    push(back(), data);
}

template <class DATA>
void Lista<DATA>::push_front(DATA data) {
    push(front(), data);
}

template <class DATA>
bool Lista<DATA>::exist(DATA elem) {
    Nodo<DATA> * aux = lista;
    while (aux->elem != elem) {
        aux = aux->sig;
    }
    return aux != nullptr;
}

template <class DATA>
void Lista<DATA>::print() {
    if (empty()) {
        std::cout << "Empty list." <<std::endl;
    }
    
    Nodo<DATA> * aux = lista;
    while (aux != nullptr) {
        std::cout << aux->elem <<std::endl;
        aux = aux->sig;
    }
}

template <class DATA>
void Lista<DATA>::pop_back() {
    if (empty()) {
        throw std::out_of_range("Error: Intento de eliminar de una lista vacía.");
    }

    // En caso de que solo exista un nodo en la lista;
    if (lista == back_pos) {
        delete lista;
        lista = nullptr;
        back_pos = nullptr;
        size_of_list--;
    } else {
        Nodo<DATA> * aux = ant(back_pos);
        aux->sig = nullptr;
        delete back_pos;
        back_pos = aux;
        size_of_list--;
    }
}

template <class DATA>
void Lista<DATA>::pop_front() {
    if (empty()) {
        throw std::out_of_range("Error: Intento de eliminar de una lista vacía.");
    }

    Nodo<DATA> * aux = lista->sig; // Se le asigna el siguiente nodo a aux.
    delete lista;
    
    lista = aux; // Si lista era el unico nodo de la lista, cuando se asigne lista.sig a aux, se pasara a nullptr y contara como vacia.
    if (empty()) {
        back_pos = nullptr; // En caso de que este vacia la lista; se pasara a nullptr la ultima pos.
    }
    size_of_list--;
}

template <class DATA>
void Lista<DATA>::index() const {
    if (empty()) {
        std::cout << "Empty list." <<std::endl;
    }
    
    Nodo<DATA> * aux = lista;
    int index = 0;
    while (aux != nullptr) {
        std::cout << index++ << ") " << aux->elem <<std::endl;
        aux = aux->sig;
    }
}

template <class DATA>
void Lista<DATA>::remove_by_index(int index) {
    if (empty() || index < 0 || index >= size()) {  // Verificar si el índice es válido
        throw std::out_of_range("Error: Lista vacía o índice no válido.");
    }

    if (index == 0) {
        pop_front();
    } else if (index == size() - 1) {
        pop_back();
    } else {
        Nodo<DATA>* aux = lista;
        Nodo<DATA>* prev = nullptr;
        int count = 0;

        while (aux != nullptr && count != index) {
            prev = aux;
            aux = aux->sig;
            ++count;
        }

        if (aux == nullptr) {
            throw std::out_of_range("Error: Elemento no encontrado en la lista.");
        }
        // Actualizar el siguiente del nodo anterior y eliminar el nodo
        if (prev != nullptr) {
            prev->sig = aux->sig;
        }
        if (aux == back_pos) {
            back_pos = prev;
        }

        delete aux;
    }
}

template <class DATA>
void Lista<DATA>::remove_by_element(DATA element) {
    if (empty()) {  // Verificar si el índice es válido
        throw std::out_of_range("Error: Lista vacía.");
    }

    Nodo<DATA> * aux = lista;
    while (aux != nullptr) {
        if (aux->elem == element) {
            if (aux == lista) {
                pop_front();
            } else if (aux == back_pos) {
                pop_back();
            } else {
                Nodo<DATA> * pos_ant = ant(aux);
                pos_ant->sig = aux->sig;

                delete aux;
            }    
            return;
        }
        aux = aux->sig;
    }
    throw std::out_of_range("Error: Elemento no encontrado en la lista.");
}

template<class DATA>
DATA & Lista<DATA>::operator[](int indice) {
    if (indice > size() || indice < 0) {
        throw std::out_of_range("Índice fuera de rango");
    } else {
        int index = 0;
        Nodo<DATA>* aux = lista;
        while (index <= indice && aux != nullptr) {
            if (index == indice) {
                return aux->elem;
            }
            index++;
            aux = aux->sig;
        }
    }
    throw std::logic_error("Elemento no encontrado");
}