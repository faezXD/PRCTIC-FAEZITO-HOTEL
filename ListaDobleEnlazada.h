#ifndef LISTADOBLEENLAZADA_H
#define LISTADOBLEENLAZADA_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Huesped {
    string nombre;
    int num_habitacion;
};

class ListaDobleEnlazada {
private:
    struct Nodo {
        Huesped dato;
        Nodo* sgte;
        Nodo* previo;
    };

    Nodo* cabeza;
    Nodo* cola;

public:
    ListaDobleEnlazada();
    ~ListaDobleEnlazada();
    void insertar(Huesped nuevo_huesped);
    void cargar_desde_archivo(string nombre_archivo);
    void escribir_en_archivo(string nombre_archivo);
    void mostrar();
    void buscar(string busqueda);
    void mostrar_ordenado();
};

#endif