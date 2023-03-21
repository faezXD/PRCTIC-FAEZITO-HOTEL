#include "ListaDobleEnlazada.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



ListaDobleEnlazada::~ListaDobleEnlazada() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* siguiente = actual->sgte;
        delete actual;
        actual = siguiente;
    }
}
ListaDobleEnlazada::ListaDobleEnlazada() {
    cabeza = nullptr;
    cola = nullptr;

}

void ListaDobleEnlazada::insertar(Huesped nuevo_huesped) {
    Nodo* nuevo_nodo = new Nodo;
    nuevo_nodo->dato = nuevo_huesped;
    nuevo_nodo->sgte = nullptr;

    if (cabeza == nullptr) {
        nuevo_nodo->previo = nullptr;
        cabeza = nuevo_nodo;
        cola = nuevo_nodo;
    }
    else {
        nuevo_nodo->previo = cola;
        cola->sgte = nuevo_nodo;
        cola = nuevo_nodo;
    }
}

void ListaDobleEnlazada::mostrar() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        std::cout << "Nombre: " << actual->dato.nombre << ", Habitacion: " << actual->dato.num_habitacion << std::endl;
        actual = actual->sgte;
    }
}

void ListaDobleEnlazada::escribir_en_archivo(std::string nombre_archivo) {
    std::ofstream archivo(nombre_archivo);

    Nodo* actual = cabeza;
    while (actual != nullptr) {
        archivo << actual->dato.nombre << "," << actual->dato.num_habitacion << std::endl;
        actual = actual->sgte;
    }

    archivo.close();
}
void ListaDobleEnlazada::buscar(string busqueda) {
    Nodo* actual = cabeza;
    bool encontrado = false;

    while (actual != nullptr) {
        if (actual->dato.nombre == busqueda || to_string(actual->dato.num_habitacion) == busqueda) {
            cout << "Nombre: " << actual->dato.nombre << ", Habitacion: " << actual->dato.num_habitacion << endl;
            encontrado = true;
        }
        actual = actual->sgte;
    }

    if (!encontrado) {
        cout << "Huesped no encontrado." << endl;
    }
}
void ListaDobleEnlazada::mostrar_ordenado() {
    // Crear un vector con los datos de la lista
    std::vector<Huesped> lista_huespedes;
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        lista_huespedes.push_back(actual->dato);
        actual = actual->sgte;
    }

    // Ordenar el vector alfabéticamente
    std::sort(lista_huespedes.begin(), lista_huespedes.end(),
              [](const Huesped& a, const Huesped& b) {
                  return a.nombre < b.nombre;
              });

    // Mostrar el contenido del vector ordenado
    for (const Huesped& huesped : lista_huespedes) {
        std::cout << "Nombre: " << huesped.nombre
                  << ", Habitación: " << huesped.num_habitacion
                  << std::endl;
    }
}

void ListaDobleEnlazada::cargar_desde_archivo(std::string nombre_archivo) {
    std::ifstream archivo(nombre_archivo);

    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            size_t pos = linea.find(",");
            if (pos != std::string::npos) {
                std::string nombre = linea.substr(0, pos);
                int num_habitacion = std::stoi(linea.substr(pos + 1));
                Huesped huesped = { nombre, num_habitacion };
                insertar(huesped);
            }
        }

        archivo.close();
    }
}
