#include <iostream>

#include <ctime>

#include "Estructuras de Datos/ArbolConsultas.h"

#include "Clases Principales/Candidato.h"

using namespace std;

struct NodoCiudad {
    string nombre;
    ArbolConsultas * arbol;
};

class OpcionesConsultas {
private: Lista < NodoCiudad > * listaArboles = new Lista < NodoCiudad > ;

public: OpcionesConsultas(Lista < Ciudad > * ciudades, Lista < Partido > * partidos, Lista < Candidato > * candidatos) {
        // Se agregan las ciudades a la lista
        for (int i = 0; i < ciudades -> getTam(); i++) {
            NodoCiudad * nuevo = new NodoCiudad;
            nuevo -> arbol = new ArbolConsultas;
            nuevo -> nombre = ciudades -> buscar(i).getNombre();
            listaArboles -> insertar( * nuevo);
        }

        // para cada ciudad se agregan los partidos
        for (int i = 0; i < listaArboles -> getTam(); i++) {
            listaArboles -> buscar(i).arbol -> cambiarNombre(listaArboles -> buscar(i).nombre);
            for (int j = 0; j < partidos -> getTam(); j++) {
                listaArboles -> buscar(i).arbol -> agregarPartido(partidos -> buscar(j));
            }
        }

        // Se agregan los candidatos a la ciudad y partido correspondiente
        for (int i = 0; i < candidatos -> getTam(); i++) {
            Candidato auxCandidato = candidatos -> buscar(i);
            for (int j = 0; j < listaArboles -> getTam(); j++) {
                NodoCiudad auxCiudad = listaArboles -> buscar(j);
                if (auxCiudad.nombre == auxCandidato.getCiudadResidencia().getNombre()) {
                    listaArboles -> buscar(j).arbol -> agregarCandidato(auxCandidato);
                    break;
                }
            }
        }
    }

    Lista < NodoCiudad > * getLista() {
        return listaArboles;
    };

    // Funcion que calcula la edad
    int calcularEdad(Candidato auxCandidato) {

        // Se calcular la edad partiendo en sub string con las posiciones necesarias para obtener dia, mes, anio
        int diaNacimiento = stoi(auxCandidato.getFechaNacimiento().substr(0, 2));
        int mesNacimiento = stoi(auxCandidato.getFechaNacimiento().substr(3, 2));
        int anioNacimiento = stoi(auxCandidato.getFechaNacimiento().substr(6, 4));
        // Obtener la fecha actual
        time_t tiempoActual = time(nullptr);
        tm * fechaActual = localtime( & tiempoActual);

        int diaActual = fechaActual -> tm_mday;
        int mesActual = fechaActual -> tm_mon + 1; // tm_mon está basado en 0
        int anioActual = fechaActual -> tm_year + 1900; // tm_year cuenta los años desde 1900

        // Calcular la edad
        int edad = anioActual - anioNacimiento;
        if (mesActual < mesNacimiento || (mesActual == mesNacimiento && diaActual < diaNacimiento)) {
            // No se ha cumplido el cumpleaños este año
            edad--;
        }

        return edad;
    }
    void consulta1(string partido, string ciudad);
    void consulta4(string ciudad);
    void consulta5(string ciudad);
    void consulta6(string ciudad);
    void consulta7(Lista < Ciudad > ciudades);
};

// Cosulta 1. Dado un partido y una ciudad, mostrar la lista de sus candidatos al Concejo y el candidato a la alcaldía (nombre, edad, sexo).
void OpcionesConsultas::consulta1(string partido, string ciudad) {
    for (int i = 0; i < listaArboles -> getTam(); i++) {
        NodoCiudad auxCiudad = listaArboles -> buscar(i);

        if (auxCiudad.nombre == ciudad) {
            int cAldalde = 0;
            Queue < Candidato > * auxPartido = auxCiudad.arbol -> getPartido(partido).candidatos;

            Candidato auxCandidato = auxPartido -> retornarElemento(0, 'I');
            if (auxCandidato.getPuesto() == "Alcaldia") {
                cAldalde++;
                int edad = calcularEdad(auxCandidato);
                cout << "Candidato alcaldia:" << endl;
                cout << auxCandidato.getNombre() << " edad: " << edad << " sexo: " << auxCandidato.getSexo() << endl;
            }
            cout << "Candidatos consejo:" << endl;

            for (int j = 0 + cAldalde; j < auxPartido -> getTam(); j++) {
                auxCandidato = auxPartido -> retornarElemento(j, 'I');

                int edad = calcularEdad(auxCandidato);

                cout << auxCandidato.getNombre() << " edad: " << edad << " sexo: " << auxCandidato.getSexo() << endl;
            }
        }
    }
    system("pause");
    return;
}

// Consulta 4. Dada una ciudad, mostrar por cada partido, el candidato a la alcaldía y los candidatos al concejo.
void OpcionesConsultas::consulta4(string ciudad) {
    for (int i = 0; i < listaArboles -> getTam(); i++) // Buscar la ciudad
    {
        NodoCiudad auxCiudad = listaArboles -> buscar(i);

        if (auxCiudad.nombre == ciudad) {
            Lista < NodoPartido > auxPartidos = auxCiudad.arbol -> getRaiz() -> partidos;
            for (int i = 0; i < auxPartidos.getTam(); i++) // Mirar cada partido
            {
                cout << endl <<
                     auxPartidos.buscar(i).nombre << endl;
                Queue < Candidato > * auxCandidatos = auxPartidos.buscar(i).candidatos;
                int cAldalde = 0;
                if (auxCandidatos -> retornarElemento(0, 'I').getPuesto() == "Alcaldia") {
                    cAldalde++;
                    cout << "   Candidato alcaldia:" << endl;
                    cout << "       - " << auxCandidatos -> retornarElemento(0, 'I').getNombre() << endl;
                }

                cout << "   Candidatos consejo:" << endl;

                for (int j = 0 + cAldalde; j < auxCandidatos -> getTam(); j++) {
                    cout << "       - " << auxCandidatos -> retornarElemento(j, 'I').getNombre() << endl;
                }
            }
        }
    }
    system("pause");
    return;
}

// Consulta 5. Dada una ciudad, mostrar el tarjetón de candidatos a la alcaldía. Incluye voto en blanco. (0.voto en blanco, 1. Candidato uno, 2. Candidato dos,…..)
void OpcionesConsultas::consulta5(string ciudad) {
    cout << endl <<
         ciudad << endl;
    cout << "   0. voto en blanco" << endl;
    for (int i = 0; i < listaArboles -> getTam(); i++) // Buscar la ciudad
    {
        NodoCiudad auxCiudad = listaArboles -> buscar(i);

        if (auxCiudad.nombre == ciudad) {
            Lista < NodoPartido > auxPartidos = auxCiudad.arbol -> getRaiz() -> partidos;
            for (int i = 0; i < auxPartidos.getTam(); i++) // Mirar cada partido
            {
                Queue < Candidato > * auxCandidatos = auxPartidos.buscar(i).candidatos;
                if (auxCandidatos -> retornarElemento(0, 'I').getPuesto() == "Alcaldia") {
                    Candidato c = auxCandidatos -> retornarElemento(0, 'I');
                    cout << "   " << i + 1 << ". " << c.getNombre() << " - partido: " << c.getPartido().getNombre() << endl;
                }
            }
        }
    }
    system("pause");
    return;
}

// Consulta 6. Dada una ciudad, mostrar el tarjetón de candidatos al concejo, incluye voto en blanco. Suponga que todas las listas aplican voto preferente. (0.voto en blanco, 1. Partido 1, 1.1. Candidato 1 del partido 1, etc. 2. Partido 2, 2.1 candidato 1 del partido 2, 2.2. candidato 2 del partido 2 , 3. Partido 3 …).
void OpcionesConsultas::consulta6(string ciudad) {
    cout << endl <<
         ciudad << endl;
    cout << "   0. voto en blanco" << endl;

    for (int i = 0; i < listaArboles -> getTam(); i++) // Buscar la ciudad
    {
        NodoCiudad auxCiudad = listaArboles -> buscar(i);

        if (auxCiudad.nombre == ciudad) {
            Lista < NodoPartido > auxPartidos = auxCiudad.arbol -> getRaiz() -> partidos;
            for (int i = 0; i < auxPartidos.getTam(); i++) // Mirar cada partido
            {
                cout << "   " << i + 1 << ". " <<
                     auxPartidos.buscar(i).nombre << endl;
                Queue < Candidato > * auxCandidatos = auxPartidos.buscar(i).candidatos;

                for (int j = 1; j < auxCandidatos -> getTam(); j++) {
                    cout << "       " << i + 1 << "." << j << " " << auxCandidatos -> retornarElemento(j, 'I').getNombre() << endl;
                }
            }
        }
    }
    system("pause");
    return;
}

// Consulta 7. Censo electoral. Por cada ciudad, mostrar la cantidad de personas habilitadas para votar.
void OpcionesConsultas::consulta7(Lista < Ciudad > ciudades) {
    for (int i = 0; i < ciudades.getTam(); i++) {
        Ciudad ciudad = ciudades.buscar(i);
        cout << ciudad.getNombre() << ": " << ciudad.getCensoElectoral() << endl;
    }
    system("pause");
    return;
}