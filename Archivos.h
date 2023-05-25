#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <fstream>

#include <sstream>


#include "Estructuras de Datos/Lista.h"

#include "Clases Principales/Candidato.h"

#include "Clases Principales/Elecciones.h"

class Archivos {
private: string nombreArchivo;
    string rutaArchivo;

    //Lista leidas de la memoria secundaria

    Lista < Candidato > * candidatos;
    Lista < Ciudad > * ciudades;
    Lista < Partido > * partidos;

public: Archivos(string nombre) {
        nombreArchivo = nombre + ".txt";
        rutaArchivo = "Memoria Secundaria/" + nombreArchivo;
    }

    void escribir(string texto) {
        ofstream archivo(rutaArchivo, ios::trunc);
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

    //Del archivo Ciudades, lee las ciudades, crea los objetos de las ciudades, los a�ade a la lista y retorna la lista
    Lista < Ciudad > * leerCiudades() {
        ciudades = new Lista < Ciudad > ();

        ifstream archivo(rutaArchivo);
        if (!archivo) {
            cout << "Error al abrir el archivo." << std::endl;
            return ciudades;
        }

        string linea;
        while (getline(archivo, linea)) {
            std::stringstream ss(linea);
            std::string nombre, departamento, tamConcejoStr, censoElectoralStr;

            if (std::getline(ss, nombre, ',') && std::getline(ss, departamento, ',') &&
                std::getline(ss, tamConcejoStr, ',') && std::getline(ss, censoElectoralStr)) {
                if (!nombre.empty() && !departamento.empty() && !tamConcejoStr.empty() && !censoElectoralStr.empty()) {
                    int tamConcejo = std::stoi(tamConcejoStr);
                    int censoElectoral = std::stoi(censoElectoralStr);

                    Ciudad ciudad(nombre, departamento, tamConcejo, censoElectoral);
                    ciudades -> insertar(ciudad);
                }
            }
        }

        archivo.close();
        return ciudades;
    }
    //Del archivo Partidos, lee los partidos, crea los objetos de los partidos, los a�ade a la lista y retorna la lista
    Lista < Partido > * leerPartidos() {
        partidos = new Lista < Partido > ();

        ifstream archivo(rutaArchivo);
        if (!archivo) {
            cout << "Error al abrir el archivo." << std::endl;
            return partidos;
        }

        string linea;
        while (getline(archivo, linea)) {
            std::stringstream ss(linea);
            std::string nombre, representanteLegal;

            if (std::getline(ss, nombre, ',') && std::getline(ss, representanteLegal)) {
                if (!nombre.empty() && !representanteLegal.empty()) {

                    Partido partido(nombre, representanteLegal);
                    partidos -> insertar(partido);
                }
            }
        }

        archivo.close();
        return partidos;
    }

    //Del archivo Candidatos, lee los candidatos, crea los objetos de los candidatos, los a�ade a la lista y retorna la lista

    Lista < Candidato > * leerCandidatos() {
        candidatos = new Lista < Candidato > ();

        ifstream archivo(rutaArchivo);
        if (!archivo) {
            cout << "Error al abrir el archivo." << std::endl;
            return candidatos;
        }

        string linea;
        while (getline(archivo, linea)) {
            std::stringstream ss(linea);
            std::string nombre, apellido, puesto, numIdentificacion, sexoStr, estadoCivil, fechaNacimiento, ciudadNacimientoNombre, ciudadNacimientoDepartamento, ciudadResidenciaNombre, ciudadResidenciaDepartamento, partidoNombre, votos;

            if (std::getline(ss, nombre, ',') && std::getline(ss, apellido, ',') &&
                std::getline(ss, puesto, ',') && std::getline(ss, numIdentificacion, ',') &&
                std::getline(ss, sexoStr, ',') && std::getline(ss, estadoCivil, ',') &&
                std::getline(ss, fechaNacimiento, ',') && std::getline(ss, ciudadNacimientoNombre, ',') &&
                std::getline(ss, ciudadResidenciaNombre, ',') && std::getline(ss, partidoNombre, ',') &&
                std::getline(ss, votos)) {
                if (!nombre.empty() && !apellido.empty() && !puesto.empty() && !numIdentificacion.empty() &&
                    !sexoStr.empty() && !estadoCivil.empty() && !fechaNacimiento.empty() &&
                    !ciudadNacimientoNombre.empty() && !ciudadResidenciaNombre.empty() && !partidoNombre.empty() && !votos.empty()) {

                    char sexo = sexoStr[0];
                    Ciudad ciudadNacimiento(ciudadNacimientoNombre, " ", 0, 0);
                    Ciudad ciudadResidencia(ciudadResidenciaNombre, " ", 0, 0);
                    Partido partido(partidoNombre, " ");

                    int cantVotos = stoi(votos); //lo vuelve entero
                    /*
                              //Si no existen las ciudades, las escribimos en el archivo de ciudades sin representante legal
                              if(!ciudades->existe(ciudadNacimiento)){
                                  ciudades->insertar(ciudadNacimiento);
                              }

                              if(!partidos->existe(partido)){
                                  partidos->insertar(partido);
                              }
                              */

                    //inicializa el candidato y lo a�ade en la lista
                    Candidato candidato(nombre, apellido, puesto, numIdentificacion, sexo, estadoCivil,
                                        fechaNacimiento, ciudadNacimiento, ciudadResidencia, partido, cantVotos);

                    candidatos -> insertar(candidato);
                }
            }
        }

        archivo.close();
        return candidatos;
    }

};
#endif