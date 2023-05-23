#include "Archivos.h"
#include "iostream"
#include <string>
#include <random>

class OpcionesSimulacion{
	private:
        Lista<Candidato>* candidatos;
        Lista<Ciudad>* ciudades;
        Lista<Partido>* partidos;

	public:
        OpcionesListas opcionLista;
    OpcionesSimulacion (Lista<Ciudad> *ciudades, Lista<Partido> *partidos, Lista<Candidato> *candidatos) {
       this->ciudades = ciudades;
       this->candidatos = candidatos;
       this->partidos = partidos;
    }

        void simularVotos(){
            int Opcion;
            opcionLista.mostrarCiudades(ciudades);
            cout<<"Ingrese la ciudad a la cual desea simular"<<endl;
            cin>>Opcion;
            Ciudad ciudadEleccion = ciudades->buscar(Opcion);
            cout<<"Ingrese el tipo de eleccion: 1.Alcaldia 2.Concejo"<<endl;
            cin>>Opcion;
            Lista<Candidato> listaCandidatos;
            int totalVotos = ciudadEleccion.getCensoElectoral();
            int votosBlanco, votosNulos, abstencion, votosRestantes;
            int sumaVotos=0;

            if (Opcion == 1){
                listaCandidatos = candidatosPorCiudadPuesto(ciudadEleccion.getNombre(), candidatos, "Alcaldia");
            }else if(Opcion == 2){
                listaCandidatos = candidatosPorCiudadPuesto(ciudadEleccion.getNombre(), candidatos, "Consejo");
            }

            votosRestantes=totalVotos;
            cout<<votosRestantes<<endl;

            for (int i = 0; i < listaCandidatos.getTam(); i++){
                int votos = numeroAleatorio(votosRestantes/2);
                //PENDIENTE guardar voto en la lista candidato para estadisticas
                Candidato candidato = listaCandidatos.buscar(i);
                candidato.setVotos(votos);
                votosRestantes -= votos;
                sumaVotos += votos;
                cout << candidato.getNombre()<< "   "<< candidato.getVotos()<< endl;
            }

            votosBlanco = numeroAleatorio(votosRestantes/2);
            cout<<"Votos blancos: "<<votosBlanco<<endl;
            votosNulos = numeroAleatorio(votosRestantes-votosBlanco);
            cout<<"Votos nulos: "<<votosNulos<<endl;
            abstencion = votosRestantes-votosBlanco-votosNulos;
            cout<<"Votos abstencion: "<<abstencion<<endl;
            cout<<"Total de votos(censo ciudad): "<<totalVotos<<endl;
            cout<<"Total de votos(suma): "<<sumaVotos+votosBlanco+votosNulos+abstencion<<endl;
            system("Pause");

    }


        Lista <Candidato> candidatosPorCiudadPuesto(string ciudad, Lista<Candidato> *candidatos, string puesto){
            Lista<Candidato> listaFiltrada;
            for (int i = 0; i < candidatos->getTam(); i++) {
                Candidato candidato = candidatos->buscar(i);
                if(candidato.getCiudadResidencia().getNombre() == ciudad && candidato.getPuesto() == puesto){
                    listaFiltrada.insertar(candidato);
                }
            }
            return listaFiltrada;
        }

        int numeroAleatorio(int total){
            std::random_device rd;
            std::mt19937 eng(rd());
            std::uniform_int_distribution <> rango(0, total);
        return rango(eng);
    }
};
