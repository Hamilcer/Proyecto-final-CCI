#include "Archivos.h"

#include "iostream"

#include <string>

#include <random>

class OpcionesSimulacion {

private: Lista < Candidato > * candidatos;
    Lista < Ciudad > * ciudades;
    Lista < Partido > * partidos;
    Lista < Elecciones > * totalElecciones;

    Lista < Candidato > listaCandidatosFiltrada;
    Lista < int > posiciones;
    int ganador[2] = {
            -1,
            0
    };

public: OpcionesListas opcionLista;

    OpcionesSimulacion(Lista < Ciudad > * ciudades, Lista < Partido > * partidos, Lista < Candidato > * candidatos, Lista < Elecciones > * totalElecciones) {
        this -> ciudades = ciudades;
        this -> candidatos = candidatos;
        this -> partidos = partidos;
        this -> totalElecciones = totalElecciones;
    }

    void simularVotos() {

        int Opcion;

        opcionLista.mostrarCiudades(ciudades);
        cout << "Ingrese el id de la ciudad a la cual desea simular" << endl;
        cin >> Opcion;

        Ciudad ciudadEleccion = ciudades -> buscar(Opcion);

        cout << "Ingrese el tipo de eleccion: 1.Alcaldia 2.Concejo" << endl;
        cin >> Opcion;

        int totalVotos = ciudadEleccion.getCensoElectoral();
        int votosBlanco, votosNulos, abstencion, votosRestantes;
        int sumaVotos = 0;
        string tipoEleccion = "";
        votosRestantes = totalVotos;

        if (Opcion == 1) {
            candidatosPorCiudadPuesto(ciudadEleccion.getNombre(), "Alcaldia");
            tipoEleccion = "Alcaldia";
        } else if (Opcion == 2) {
            candidatosPorCiudadPuesto(ciudadEleccion.getNombre(), "Concejo");
            tipoEleccion = "Concejo";
        }

        cout << "Elecciones a " << tipoEleccion << " para " << ciudadEleccion.getNombre() << endl;
        cout << "---------------------------------------------------------------------------------------" << endl;
        asignacionVotos(votosRestantes, votosBlanco, votosNulos, abstencion, sumaVotos, totalVotos, ciudadEleccion, tipoEleccion);
        //cout << votosRestantes << endl;
        system("Pause");

    }

    void candidatosPorCiudadPuesto(string ciudad, string puesto) {

        for (int i = 0; i < candidatos -> getTam(); i++) {
            Candidato candidato = candidatos -> buscar(i);
            if (candidato.getCiudadResidencia().getNombre() == ciudad && candidato.getPuesto() == puesto) {
                listaCandidatosFiltrada.insertar(candidato);
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

    double porcentaje(double dato, double total) {
        return (dato / total) * 100.0;
    }

    void asignacionVotos(int votosRestantes, int votosBlanco, int votosNulos, int abstencion, int sumaVotos, int totalVotos, Ciudad ciudadEleccion, string tipoEleccion) {

        for (int i = 0; i < listaCandidatosFiltrada.getTam(); i++) {

            int votos = numeroAleatorio(votosRestantes / (listaCandidatosFiltrada.getTam() / 2));
            int posicionActual = posiciones.buscar(i);
            Candidato candidato = listaCandidatosFiltrada.buscar(i);
            candidato.setVotos(votos);
            if (votos > ganador[1]) {
                ganador[1] = votos; //Guarda la cantidad de votos.
                ganador[0] = i; //Pos en la lista filtrada.
            }
            candidatos -> modificar(candidato, posicionActual);
            votosRestantes -= votos;
            sumaVotos += votos;
            cout << candidato.getPartido().getNombre() << "  | " << candidato.getNombre() + "  " + candidato.getApellido() << "  | " << candidato.getVotos() << " | " << porcentaje(candidato.getVotos(), ciudadEleccion.getCensoElectoral()) << " %" << endl;
        }

        if (tipoEleccion == "Alcaldia") {
            Candidato canGanador = listaCandidatosFiltrada.buscar(ganador[0]);
            cout << "---------*****---------" << endl;
            cout << "EL GANADOR ES " << canGanador.getNombre() + " " + canGanador.getApellido() << endl;
            cout << "---------*****---------" << endl;
        }

        //Limpiar lista
        int tamano = listaCandidatosFiltrada.getTam(); //revisar porque queda tam -1
        for (tamano; tamano > 0; tamano--) {
            listaCandidatosFiltrada.borrar(tamano - 1);
            posiciones.borrar(tamano - 1);
        }

        cout << "Total entre candidatos: " << sumaVotos << endl;
        votosBlanco = numeroAleatorio(votosRestantes / 2);
        cout << "Votos blancos: " << votosBlanco << "  | " << porcentaje(votosBlanco, ciudadEleccion.getCensoElectoral()) << " %" << endl;

        votosNulos = numeroAleatorio(votosRestantes - votosBlanco);
        cout << "Votos nulos: " << votosNulos << "  | " << porcentaje(votosNulos, ciudadEleccion.getCensoElectoral()) << " %" << endl;

        abstencion = votosRestantes - votosBlanco - votosNulos;
        cout << "Votos abstencion: " << abstencion << "  | " << porcentaje(abstencion, ciudadEleccion.getCensoElectoral()) << " %" << endl;

        cout << "Total de votos(censo ciudad): " << totalVotos << endl;
        cout << "Total de votos(suma): " << sumaVotos + votosBlanco + votosNulos + abstencion << "  | " << porcentaje(sumaVotos + votosBlanco + votosNulos + abstencion, ciudadEleccion.getCensoElectoral()) << " %" << endl;
        cout << "---------------------------------------------------------------------------------------" << endl;

        Elecciones eleccion(ciudadEleccion.getNombre(), tipoEleccion, sumaVotos, votosBlanco, votosNulos, abstencion, "12/3/42");
        totalElecciones -> insertar(eleccion);
    }

};