#ifndef ELECCIONES_H
#define ELECCIONES_H

#include <string>

#include "Candidato.h"

class Elecciones {
private: int numEleccion;
    Candidato candidato;
    int votos;

public: Elecciones() {
        numEleccion = 0;
        votos = 0;
    }

    Elecciones(int numEleccion, Candidato candidato, int votos) {
        this -> numEleccion = numEleccion;
        this -> candidato = candidato;
        this -> votos = votos;
    }


    int getNumEleccion() {
        return numEleccion;
    }
    Candidato getCandidatos() {
        return candidato;
    }
    int getVotos() {
        return votos;
    }

    void setNumEleccion(int numEleccion) {
        Elecciones::numEleccion = numEleccion;
    }
    void setCandidato(const Candidato & candidato) {
        Elecciones::candidato = candidato;
    }
    void setVotos(int votos) {
        Elecciones::votos = votos;
    }

};

#endif