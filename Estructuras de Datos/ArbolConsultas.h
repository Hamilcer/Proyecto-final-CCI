#ifndef ARBOLCONSULTAS_H
#define ARBOLCONSULTAS_H

#include <iostream>

#include "Lista.h"

#include "Queue.h"

#include "../Clases Principales/Candidato.h"

using namespace std;

struct NodoConsulta
{
    string nombre;
    Queue<Candidato> *candidatos; // Cola doble
};

struct NodoRaiz
{
    string nombre;
    Lista<NodoConsulta> listaConsulta;
};

template <class T>
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
    NodoConsulta *crearNodoConsulta(string nombre);
    void agregarNodoConsulta(T objeto);
    void agregarCandidato(Candidato *candidato, string nodoObjetivo);
    NodoConsulta getPartido(string partido);
};

template <class T>
NodoConsulta *ArbolConsultas<T>::crearNodoConsulta(string nombre)
{
    NodoConsulta *nuevo = new NodoConsulta;
    nuevo->candidatos = new Queue<Candidato>;
    nuevo->nombre = nombre;
    return nuevo;
}

template <class T>
void ArbolConsultas<T>::agregarNodoConsulta(T objeto)
{
    // Verifica que el objeto no exista
    for (int i = 0; i < raiz->listaConsulta.getTam(); i++)
    {
        if (raiz->listaConsulta.buscar(i).nombre == objeto.getNombre())
        {
            return;
        }
    }

    raiz->listaConsulta.insertar(*crearNodoConsulta(objeto.getNombre()));
}


template <class T>
void ArbolConsultas<T>::agregarCandidato(Candidato *candidato, string nodoObjetivo)
{
    for (int i = 0; i < raiz->listaConsulta.getTam(); i++)
    {
        NodoConsulta aux = raiz->listaConsulta.buscar(i);
        if (aux.nombre == nodoObjetivo)
        {
            if (candidato->getPuesto() == "Consejo")
                raiz->listaConsulta.buscar(i).candidatos->Enqueue(candidato, 'I');
            else
                raiz->listaConsulta.buscar(i).candidatos->Enqueue(candidato, 'F');

            return;
        }
    }
}

template <class T>
NodoConsulta ArbolConsultas<T>::getPartido(string partido)
{
    for (int i = 0; i < raiz->listaConsulta.getTam(); i++)
    {
        if (raiz->listaConsulta.buscar(i).nombre == partido)
        {
            return raiz->listaConsulta.buscar(i);
        }
    }
    return raiz->listaConsulta.buscar(0);
}

#endif