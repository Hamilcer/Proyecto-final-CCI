#include "Archivos.h"

#include "iostream"

#include <string>

#include <random>
#include <stack>

class OpcionesSimulacion {

private:
    Lista < Candidato > * candidatos;
    Lista < Ciudad > * ciudades;
    Lista < Partido > * partidos;
    Lista <int> *otrosVotos;

    Lista <Candidato> listaCandidatosFiltrada;
    Lista <int> posiciones;

public: OpcionesListas opcionLista;

    OpcionesSimulacion(Lista < Ciudad > * ciudades, Lista < Partido > * partidos, Lista < Candidato > * candidatos, Lista<int> *otrosVotos) {
        this -> ciudades = ciudades;
        this -> candidatos = candidatos;
        this -> partidos = partidos;
        this -> otrosVotos = otrosVotos;
    }

    void simularVotos() {
        int Opcion;
        opcionLista.mostrarCiudades(ciudades);
        cout << "Ingrese el id de la ciudad a la cual desea simular" << endl;
        cin >> Opcion;
        Ciudad ciudadEleccion = ciudades -> buscar(Opcion);
        cout << "Ingrese el tipo de eleccion: 1.Alcaldia 2.Concejo" << endl;
        cin >> Opcion;
        //Lista < Candidato > listaCandidatos;
        int totalVotos = ciudadEleccion.getCensoElectoral();
        int votosBlanco, votosNulos, abstencion, votosRestantes;
        int sumaVotos = 0;

        if (Opcion == 1) {
            candidatosPorCiudadPuesto(ciudadEleccion.getNombre(), "Alcaldia");
        } else if (Opcion == 2) {
            candidatosPorCiudadPuesto(ciudadEleccion.getNombre(), "Consejo");
        }

        votosRestantes = totalVotos;
        cout << votosRestantes << endl;

        for (int i = 0; i < listaCandidatosFiltrada.getTam(); i++) {
            int votos = numeroAleatorio(votosRestantes / 2);
            //PENDIENTE guardar voto en la lista candidato para estadisticas
            int posicionActual = posiciones.buscar(i);
            Candidato candidato = listaCandidatosFiltrada.buscar(i);
            candidato.setVotos(votos);
            candidatos -> modificar(candidato, posicionActual);
            votosRestantes -= votos;
            sumaVotos += votos;
            cout << candidato.getNombre() << "   " << candidato.getVotos() << endl;
        }

        votosBlanco = numeroAleatorio(votosRestantes / 2);
        otrosVotos -> insertar(votosBlanco);
        cout << "Votos blancos: " << votosBlanco << endl;

        votosNulos = numeroAleatorio(votosRestantes - votosBlanco);
        otrosVotos ->insertar(votosNulos);
        cout << "Votos nulos: " << votosNulos << endl;

        abstencion = votosRestantes - votosBlanco - votosNulos;
        otrosVotos ->insertar(abstencion);
        cout << "Votos abstencion: " << abstencion << endl;

        cout << "Total de votos(censo ciudad): " << totalVotos << endl;
        cout << "Total de votos(suma): " << sumaVotos + votosBlanco + votosNulos + abstencion << endl;

        system("Pause");

    }

    void candidatosPorCiudadPuesto(string ciudad, string puesto) {

        for (int i = 0; i < candidatos -> getTam(); i++) {
            Candidato candidato = candidatos -> buscar(i);
            if (candidato.getCiudadResidencia().getNombre() == ciudad && candidato.getPuesto() == puesto) {
                listaCandidatosFiltrada.insertar(candidato);
                // Mauesquerraamienta misteriosa que nos ayudará más adelante.
                posiciones.insertar(i);
            }
        }
    }

    int numeroAleatorio(int total) {
        std::random_device rd;
        std::mt19937 eng(rd());
        std::uniform_int_distribution < > rango(0, total);
        return rango(eng);
    }


};