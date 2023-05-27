#ifndef ELECCIONES_H
#define ELECCIONES_H

#include <string>

#include "Candidato.h"

class Elecciones {
private:
    string nomCiudad;
    string tipoEleccion;
    int votosTotales;
    int votosBlancos;
    int votosNulos;
    int votosAbstencion;
    string fecha;

public: Elecciones() {
        nomCiudad = "";
        string tipoEleccion;
        votosTotales = 0;
        votosBlancos = 0;
        votosNulos = 0;
        votosAbstencion = 0;
        fecha = "";
    }

    Elecciones(string nomCiudad,string tipoEleccion, int votosTotales, int votosBlancos, int votosNulos, int votosAbstencion, string fecha) {
        this -> nomCiudad = nomCiudad;
        this -> tipoEleccion = tipoEleccion;
        this -> votosTotales = votosTotales;
        this -> votosBlancos = votosBlancos;
        this -> votosNulos = votosNulos;
        this -> votosAbstencion = votosAbstencion;
        this -> fecha = fecha;
    }


    const string &getNomCiudad() const {
        return nomCiudad;
    }

    void setNomCiudad(const string &nomCiudad) {
        Elecciones::nomCiudad = nomCiudad;
    }

    const string &getTipoEleccion() const {
        return tipoEleccion;
    }

    void setTipoEleccion(const string &tipoEleccion) {
        Elecciones::tipoEleccion = tipoEleccion;
    }

    int getVotosTotales() const {
        return votosTotales;
    }

    void setVotosTotales(int votosTotales) {
        Elecciones::votosTotales = votosTotales;
    }

    int getVotosBlancos() const {
        return votosBlancos;
    }

    void setVotosBlancos(int votosBlancos) {
        Elecciones::votosBlancos = votosBlancos;
    }

    int getVotosNulos() const {
        return votosNulos;
    }

    void setVotosNulos(int votosNulos) {
        Elecciones::votosNulos = votosNulos;
    }

    int getVotosAbstencion() const {
        return votosAbstencion;
    }

    void setVotosAbstencion(int votosAbstencion) {
        Elecciones::votosAbstencion = votosAbstencion;
    }

    const string &getFecha() const {
        return fecha;
    }

    void setFecha(const string &fecha) {
        Elecciones::fecha = fecha;
    }


};

#endif