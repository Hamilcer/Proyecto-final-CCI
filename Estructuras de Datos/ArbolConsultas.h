#ifndef ARBOLCONSULTAS_H
#define ARBOLCONSULTAS_H

#include <iostream>

#include "Lista.h"

#include "Queue.h"

#include "../Clases Principales/Candidato.h"

using namespace std;

struct NodoPartido
{
    string nombre;
    Queue<Candidato> *candidatos; // Cola doble
};

struct NodoRaiz
{
    string nombre;
    Lista<NodoPartido> partidos;
};

class ArbolConsultas
{
    NodoRaiz *raiz;

public:
    ArbolConsultas()
    {
        raiz = new NodoRaiz;
        raiz->nombre = "nombre";
    }
    void cambiarNombre(string nombre)
    {
        raiz->nombre = nombre;
    };
    NodoRaiz *getRaiz()
    {
        return raiz;
    };
    NodoPartido *crearNodoPartido(string nombre);
    void agregarPartido(Partido partido);
    void agregarCandidato(Candidato *candidato);
    NodoPartido getPartido(string partido);
};

NodoPartido *ArbolConsultas::crearNodoPartido(string nombre)
{
    NodoPartido *nuevo = new NodoPartido;
    nuevo->candidatos = new Queue<Candidato>;
    nuevo->nombre = nombre;
    return nuevo;
}

void ArbolConsultas::agregarPartido(Partido partido)
{
    // Verifica que el partido no exista
    for (int i = 0; i < raiz->partidos.getTam(); i++)
    {
        if (raiz->partidos.buscar(i).nombre == partido.getNombre())
        {
            return;
        }
    }

    raiz->partidos.insertar(*crearNodoPartido(partido.getNombre()));
}

void ArbolConsultas::agregarCandidato(Candidato *candidato)
{
    for (int i = 0; i < raiz->partidos.getTam(); i++)
    {
        NodoPartido aux = raiz->partidos.buscar(i);
        if (aux.nombre == candidato->getPartido().getNombre())
        {
            if (candidato->getPuesto() == "Consejo")
                raiz->partidos.buscar(i).candidatos->Enqueue(candidato, 'I');
            else
                raiz->partidos.buscar(i).candidatos->Enqueue(candidato, 'F');

            return;
        }
    }
}

NodoPartido ArbolConsultas::getPartido(string partido)
{
    for (int i = 0; i < raiz->partidos.getTam(); i++)
    {
        if (raiz->partidos.buscar(i).nombre == partido)
        {
            return raiz->partidos.buscar(i);
        }
    }
    return raiz->partidos.buscar(0);
}

#endif