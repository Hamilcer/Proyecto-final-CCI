
#include <fstream>
#include <iostream>

using namespace std;

class Archivos {
    private:
        string nombreArchivo;
        string rutaArchivo;

    public:
        Archivos(string nombre) {
            nombreArchivo = nombre + ".txt";
            rutaArchivo = "Memoria Secundaria/" + nombreArchivo;
        }

        void escribir(string texto) {
            ofstream archivo(rutaArchivo, ios::app);
            archivo << texto << endl;
            archivo.close();
        }

        void anadir(string texto) {
            ofstream archivo(rutaArchivo, ios::app);
            archivo << texto;
            archivo.close();
        }

        void modificar(string textoAntiguo, string textoNuevo) {
            ifstream archivoAntiguo(rutaArchivo);
            ofstream archivoNuevo("temp.txt");

            string linea;
            while (getline(archivoAntiguo, linea)) {
                if (linea == textoAntiguo) {
                    archivoNuevo << textoNuevo << endl;
                } else {
                    archivoNuevo << linea << endl;
                }
            }

            archivoAntiguo.close();
            archivoNuevo.close();

            remove(rutaArchivo.c_str());
            rename("temp.txt", rutaArchivo.c_str());
        }

        void eliminar(string texto) {
            ifstream archivoAntiguo(rutaArchivo);
            ofstream archivoNuevo("temp.txt");

            string linea;
            while (getline(archivoAntiguo, linea)) {
                if (linea != texto) {
                    archivoNuevo << linea << endl;
                }
            }

            archivoAntiguo.close();
            archivoNuevo.close();

            remove(rutaArchivo.c_str());
            rename("temp.txt", rutaArchivo.c_str());
        }
};
