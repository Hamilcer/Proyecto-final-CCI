#include <iostream>

#include <ctime>

#include "Estructuras de Datos/ArbolConsultas.h"

#include "Clases Principales/Candidato.h"

#include "Estructuras de Datos/ArbolRojiNegro.h"

using namespace std;

class OpcionesConsultas
{
private:
    // Lista<NodoCiudad> *listaArboles = new Lista<NodoCiudad>;            // Cada ciudad tiene un arbol
    ArbolRojiNegro<string, ArbolConsultas> *arbolCiudades = new ArbolRojiNegro<string, ArbolConsultas>; // Cada ciudad tiene un arbol

public:
    OpcionesConsultas(Lista<Ciudad> *ciudades, Lista<Partido> *partidos, Lista<Candidato> *candidatos);

    // Funcion que calcula la edad
    int calcularEdad(Candidato *auxCandidato);
    void agregarDatosArbolRN();

    void consulta1(string partido, string ciudad);
    void consulta4(string ciudad);
    void consulta5(string ciudad);
    void consulta6(string ciudad);
    void consulta7(Lista<Ciudad> ciudades);
};

// Constrctor
OpcionesConsultas::OpcionesConsultas(Lista<Ciudad> *ciudades, Lista<Partido> *partidos, Lista<Candidato> *candidatos)
{
    // Se agregan las ciudades al arbolRN
    for (int i = 0; i < ciudades->getTam(); i++)
    {
        arbolCiudades->insertarNodo(ciudades->buscar(i).getNombre());
    }

    // Se crea un arbol Consulta para cada ciudad
    Cola<NodoArbol<string, ArbolConsultas> *> CInOrden = arbolCiudades->obtenerInOrden(arbolCiudades->obtenerRaiz());

    Lista<NodoArbol<string, ArbolConsultas> *> ciudadesArbolRN;

    NodoArbol<string, ArbolConsultas> *nodoAux; // Nodo auxiliar para insertar arbol
    while (!CInOrden.isVacia())
    {
        nodoAux = CInOrden.dequeue();
        ciudadesArbolRN.insertar(nodoAux);
    }

    for (int i = 0; i < ciudadesArbolRN.getTam(); i++) // Se crean arboles 
    {
        nodoAux = ciudadesArbolRN.buscar(i);
        nodoAux->data = new ArbolConsultas;
        ;
        nodoAux->data->cambiarNombre(nodoAux->clave);
        for (int i = 0; i < partidos->getTam(); i++) // agrega partido
        {
            nodoAux->data->agregarPartido(partidos->buscar(i));
        }
    }

    // Se agregan los candidatos a la ciudad y partido correspondiente
    for (int i = 0; i < candidatos->getTam(); i++)
    {
        Candidato *auxCandidato = candidatos->buscarApuntador(i);
        nodoAux = arbolCiudades->buscar(auxCandidato->getCiudadResidencia().getNombre()); // busca la ciudad la cual debe agregar el cadidato
        nodoAux->data->agregarCandidato(auxCandidato);
    }
}

int OpcionesConsultas::calcularEdad(Candidato *auxCandidato)
{

    // Se calcular la edad partiendo en sub string con las posiciones necesarias para obtener dia, mes, anio
    int diaNacimiento = stoi(auxCandidato->getFechaNacimiento().substr(0, 2));
    int mesNacimiento = stoi(auxCandidato->getFechaNacimiento().substr(3, 2));
    int anioNacimiento = stoi(auxCandidato->getFechaNacimiento().substr(6, 4));
    // Obtener la fecha actual
    time_t tiempoActual = time(nullptr);
    tm *fechaActual = localtime(&tiempoActual);

    int diaActual = fechaActual->tm_mday;
    int mesActual = fechaActual->tm_mon + 1;      // tm_mon está basado en 0
    int anioActual = fechaActual->tm_year + 1900; // tm_year cuenta los años desde 1900

    // Calcular la edad
    int edad = anioActual - anioNacimiento;
    if (mesActual < mesNacimiento || (mesActual == mesNacimiento && diaActual < diaNacimiento))
    {
        // No se ha cumplido el cumpleaños este año
        edad--;
    }

    return edad;
}

// Cosulta 1. Dado un partido y una ciudad, mostrar la lista de sus candidatos al Concejo y el candidato a la alcaldía (nombre, edad, sexo).
void OpcionesConsultas::consulta1(string partido, string ciudad)
{
    NodoArbol<string, ArbolConsultas> *nodoAux = arbolCiudades->buscar(ciudad);

    int cAldalde = 0; // esto es para saber si se imprimió un alcalde, se usa en el for de abajo

    Queue<Candidato> *auxPartido = nodoAux->data->getPartido(partido).candidatos;

    if (auxPartido->getTam() > 0)
    {
        Candidato *auxCandidato = auxPartido->retornarElemento(0, 'I');

        string auxz = auxCandidato->getPuesto();
        if (auxz == "Alcaldia")
        {
            cAldalde++;
            int edad = calcularEdad(auxCandidato);
            cout << "Candidato alcaldia:" << endl;
            cout << auxCandidato->getNombre() << " edad: " << edad << " sexo: " << auxCandidato->getSexo() << " - " << auxCandidato->getNumIdentificacion() << endl;
        }

        if (auxPartido->getTam() > 1)
        {
            cout << "Candidatos consejo:" << endl;

            for (int j = 0 + cAldalde; j < auxPartido->getTam(); j++)
            {
                auxCandidato = auxPartido->retornarElemento(j, 'I');

                int edad = calcularEdad(auxCandidato);

                cout << auxCandidato->getNombre() << " edad: " << edad << " sexo: " << auxCandidato->getSexo() << " - " << auxCandidato->getNumIdentificacion() << endl;
            }
        }
    }
    system("pause");
    return;
}

// Consulta 4. Dada una ciudad, mostrar por cada partido, el candidato a la alcaldía y los candidatos al concejo.
void OpcionesConsultas::consulta4(string ciudad)
{

    NodoArbol<string, ArbolConsultas> *nodoAux = arbolCiudades->buscar(ciudad);

    Lista<NodoPartido> auxPartidos = nodoAux->data->getRaiz()->partidos;
    for (int i = 0; i < auxPartidos.getTam(); i++) // Mirar cada partido
    {
        if (auxPartidos.getTam() > 0)
        {
            cout << endl
                 << auxPartidos.buscar(i).nombre << endl;
            Queue<Candidato> *auxCandidatos = auxPartidos.buscar(i).candidatos;
            int cAldalde = 0;
            if (auxCandidatos->retornarElemento(0, 'I')->getPuesto() == "Alcaldia")
            {
                cAldalde++;
                cout << "   Candidato alcaldia:" << endl;
                cout << "       - " << auxCandidatos->retornarElemento(0, 'I')->getNombre() << endl;
            }
            if (auxPartidos.getTam() > 0)
            {
                cout << "   Candidatos consejo:" << endl;

                for (int j = 0 + cAldalde; j < auxCandidatos->getTam(); j++)
                {
                    cout << "       - " << auxCandidatos->retornarElemento(j, 'I')->getNombre() << endl;
                }
            }
        }
    }

    system("pause");
    return;
}

// Consulta 5. Dada una ciudad, mostrar el tarjetón de candidatos a la alcaldía. Incluye voto en blanco. (0.voto en blanco, 1. Candidato uno, 2. Candidato dos,…..)
void OpcionesConsultas::consulta5(string ciudad)
{
    cout << endl
         << ciudad << endl;
    cout << "   0. voto en blanco" << endl;

    NodoArbol<string, ArbolConsultas> *nodoAux = arbolCiudades->buscar(ciudad);

    Lista<NodoPartido> auxPartidos = nodoAux->data->getRaiz()->partidos;
    for (int i = 0; i < auxPartidos.getTam(); i++) // Mirar cada partido
    {
        Queue<Candidato> *auxCandidatos = auxPartidos.buscar(i).candidatos;
        if (auxCandidatos->retornarElemento(0, 'I')->getPuesto() == "Alcaldia")
        {
            Candidato *c = auxCandidatos->retornarElemento(0, 'I');
            cout << "   " << i + 1 << ". " << c->getNombre() << " - partido: " << c->getPartido().getNombre() << endl;
        }
    }

    system("pause");
    return;
}

// Consulta 6. Dada una ciudad, mostrar el tarjetón de candidatos al concejo, incluye voto en blanco. Suponga que todas las listas aplican voto preferente. (0.voto en blanco, 1. Partido 1, 1.1. Candidato 1 del partido 1, etc. 2. Partido 2, 2.1 candidato 1 del partido 2, 2.2. candidato 2 del partido 2 , 3. Partido 3 …).
void OpcionesConsultas::consulta6(string ciudad)
{
    cout << endl
         << ciudad << endl;
    cout << "   0. voto en blanco" << endl;

    NodoArbol<string, ArbolConsultas> *nodoAux = arbolCiudades->buscar(ciudad);

    Lista<NodoPartido> auxPartidos = nodoAux->data->getRaiz()->partidos;
    for (int i = 0; i < auxPartidos.getTam(); i++) // Mirar cada partido
    {
        cout << "   " << i + 1 << ". " << auxPartidos.buscar(i).nombre << endl;
        Queue<Candidato> *auxCandidatos = auxPartidos.buscar(i).candidatos;

        for (int j = 1; j < auxCandidatos->getTam(); j++)
        {
            cout << "       " << i + 1 << "." << j << " " << auxCandidatos->retornarElemento(j, 'I')->getNombre() << endl;
        }
    }

    system("pause");
    return;
}

// Consulta 7. Censo electoral. Por cada ciudad, mostrar la cantidad de personas habilitadas para votar.
void OpcionesConsultas::consulta7(Lista<Ciudad> ciudades)
{
    for (int i = 0; i < ciudades.getTam(); i++)
    {
        Ciudad ciudad = ciudades.buscar(i);
        cout << ciudad.getNombre() << ": " << ciudad.getCensoElectoral() << endl;
    }
    system("pause");
    return;
}