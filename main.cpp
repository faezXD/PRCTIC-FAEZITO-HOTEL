        #include <iostream>
        #include <fstream>
        #include <string>
        #include "ListaDobleEnlazada.h"

        using namespace std;

        int main() {
            ListaDobleEnlazada lista;

            // Cargar la información del archivo de texto en la lista
            lista.cargar_desde_archivo("hotel.txt");

            int opcion;
            do {
                cout << "Hotel Abdala Airlines:" << endl;
                cout << "------------------------------------------:" << endl;
                cout << "1. Ingresar un nuevo Tripulante " << endl;
                cout << "2. Mostrar la lista de Tripulantes" << endl;
                cout << "3. Buscar huesped por nombre o numero de habitacion" << endl;
                cout << "4. Mostrar lista en orden" << endl;
                cout << "0. Salir" << endl;
                cout << "------------------------------------------:" << endl;
                cin >> opcion;

                switch (opcion) {
                    case 1: {
                        string nombre;
                        int num_habitacion;

                        cout << "Ingrese el nombre del huesped: ";
                        cin >> nombre;
                        cout << "Ingrese el numero de habitacion: ";
                        cin >> num_habitacion;

                        Huesped nuevo_huesped = {nombre, num_habitacion};
                        lista.insertar(nuevo_huesped);

                        // Guardar la información actualizada en el archivo de texto
                        lista.escribir_en_archivo("hotel.txt");
                        break;
                    }
                    case 2: {
                        lista.mostrar();
                        break;
                    }
                    case 3: {
                        string busqueda;
                        cout << "Ingrese el nombre o numero de habitacion del huesped a buscar: ";
                        cin >> busqueda;

                        lista.buscar(busqueda);
                        break;
                    }
                    case 4: {
                        lista.mostrar_ordenado();
                        break;

                    }
                    case 0:
                        cout << "Saliendo del programa." << endl;
                        break;
                    default:
                        cout << "Opcion invalida. Intente de nuevo." << endl;
                }
            } while (opcion != 0);

            return 0;
        }