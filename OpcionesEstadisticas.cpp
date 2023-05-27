#include "Archivos.h"

#include "iostream"

#include <string>

#include <random>

#include <stack>

#include <map>

struct PartidoVotos {
  string partido;
  int votos;
};

class OpcionesEstadisticas {

  private:

    Lista < Candidato > * candidatos;
  Lista < Ciudad > * ciudades;
  Lista < Partido > * partidos;
  Lista < Elecciones > * totalElecciones;

  Lista < Candidato > listaCandidatosFiltrada;
  Lista < int > posiciones;
  Lista < PartidoVotos > listaPartidoVotos;

  public: OpcionesListas opcionLista;

  OpcionesEstadisticas(Lista < Ciudad > * ciudades, Lista < Partido > * partidos, Lista < Candidato > * candidatos, Lista < Elecciones > * totalElecciones) {

    this -> ciudades = ciudades;
    this -> candidatos = candidatos;
    this -> partidos = partidos;
    this -> totalElecciones = totalElecciones;

    // Crea lista de partidos con votos en 0
    for (int i = 0; i < partidos -> getTam(); i++) {
      Partido partido = partidos -> buscar(i);
      PartidoVotos pv = {
        partido.getNombre(),
        0
      };
      listaPartidoVotos.insertar(pv);
    }
  }

  void estadisticaPorCiudad() { //Imprime para alcaldia y ciudad si ambos existen

    int Opcion;
    opcionLista.mostrarCiudades(ciudades);
    cout << "Ingrese el id de la ciudad a mostrar la estadistica" << endl;
    cin >> Opcion;
    Ciudad ciudadEleccion = ciudades -> buscar(Opcion);
    system("cls");
    cout << "Reporte de votos de la ciudad " << ciudadEleccion.getNombre() << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < totalElecciones -> getTam(); i++) {
      Elecciones eleccion = totalElecciones -> buscar(i);
      if (eleccion.getNomCiudad() == ciudadEleccion.getNombre()) {

        cout << "Eleccion a  " << eleccion.getTipoEleccion() << endl;
        cout << "Total votos: " << eleccion.getVotosTotales() << " | " << porcentaje(eleccion.getVotosTotales(), ciudadEleccion.getCensoElectoral()) << "%" << endl;
        cout << "Votos blancos: " << eleccion.getVotosBlancos() << " | " << porcentaje(eleccion.getVotosBlancos(), ciudadEleccion.getCensoElectoral()) << "%" << endl;
        cout << "Votos nulos: " << eleccion.getVotosNulos() << " | " << porcentaje(eleccion.getVotosNulos(), ciudadEleccion.getCensoElectoral()) << "%" << endl;
        cout << "Votos abstencion: " << eleccion.getVotosAbstencion() << " | " << porcentaje(eleccion.getVotosAbstencion(), ciudadEleccion.getCensoElectoral()) << "%" << endl;
      }
    }
    cout << "---------------------------------------------------------------------------------------" << endl;
  }

  /*
  void estadisticaPorConsejoPartido() { //filtrado apartir de partido
      int Opcion;

      opcionLista.mostrarPartidos(partidos);
      cout << "Ingrese el id del partido a mostrar la estadistica" << endl;
      cin >> Opcion;
      Partido partidoEleccion = partidos -> buscar(Opcion);
      system("cls");
      cout << "Reporte de votos de Consejo para el partido " << partidoEleccion.getNombre() << endl;
      int totalVotos = 0;
      int mujer = 0;
      int hombre = 0;

      for (int i = 0; i < candidatos -> getTam(); i++) {
          Candidato candidato = candidatos -> buscar(i);
          if (candidato.getPartido().getNombre() == partidoEleccion.getNombre()) {
              totalVotos += candidato.getVotos();
              if (candidato.getSexo() == 'M'){
                  hombre += candidato.getVotos();
              } else {
                  mujer += candidato.getVotos();
              }
          }
      }

      cout << "Total votos: " << totalVotos << endl;
      cout << "Total Hombres: " << hombre << endl;
      cout << "Total Mujeres: " << mujer << endl;

      system("Pause");
  }
  */

  void estadisticaEleccion(string tipoEleccion) { //filtrado por ciudad
    int Opcion;

    opcionLista.mostrarCiudades(ciudades);
    cout << "Ingrese el id de la ciudad para la estadistica" << endl;
    cin >> Opcion;
    Ciudad ciudadEleccion = ciudades -> buscar(Opcion);
    system("cls");
    cout << "Reporte de votos para la ciudad " << ciudadEleccion.getNombre() << endl;

    int totalVotos = 0;
    int mujer = 0;
    int hombre = 0;

    for (int i = 0; i < candidatos -> getTam(); i++) {
      Candidato candidato = candidatos -> buscar(i);
      if (candidato.getCiudadResidencia().getNombre() == ciudadEleccion.getNombre() && candidato.getPuesto() == tipoEleccion) {
        string partido = candidato.getPartido().getNombre();
        int votos = candidato.getVotos();

        agregarVotosPartido(partido, votos);

        totalVotos += candidato.getVotos();
        if (candidato.getSexo() == 'M') {
          hombre += candidato.getVotos();
        } else {
          mujer += candidato.getVotos();
        }
      }
    }

    cout << "---------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < partidos -> getTam(); i++) {
      PartidoVotos pv = listaPartidoVotos.buscar(i);
      cout << "Total votos para el partido " << pv.partido << ": " << pv.votos << " | " << porcentaje(pv.votos, totalVotos) << "%" << endl;
    }

    cout << "Total Hombres: " << hombre << " | " << porcentaje(hombre, totalVotos) << "%" << endl;
    cout << "Total Mujeres: " << mujer << " | " << porcentaje(mujer, totalVotos) << "%" << endl;
    cout << "Total votos: " << totalVotos << " | " << porcentaje(totalVotos, totalVotos) << "%" << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < listaPartidoVotos.getTam(); i++) {
      PartidoVotos pv = listaPartidoVotos.buscar(i);
      pv.votos = 0;
      listaPartidoVotos.modificar(pv, i);
    }
  }

  void estadisticaNacional(string tipoEleccion) {

    system("cls");
    cout << "Reporte Nacional de votos --- " << tipoEleccion << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;

    int totalVotos = 0;
    int mujer = 0;
    int hombre = 0;

    for (int i = 0; i < candidatos -> getTam(); i++) {
      Candidato candidato = candidatos -> buscar(i);
      if (candidato.getPuesto() == tipoEleccion) {
        string partido = candidato.getPartido().getNombre();
        int votos = candidato.getVotos();

        agregarVotosPartido(partido, votos);

        totalVotos += candidato.getVotos();

        if (candidato.getSexo() == 'M') {
          hombre += candidato.getVotos();
        } else {
          mujer += candidato.getVotos();
        }
      }
    }

    for (int i = 0; i < listaPartidoVotos.getTam(); i++) {
      PartidoVotos pv = listaPartidoVotos.buscar(i);
      cout << "Total votos para el partido " << pv.partido << ": " << pv.votos << " | " << porcentaje(pv.votos, totalVotos) << "%" << endl;
    }

    cout << "Total Hombres: " << hombre << " | " << porcentaje(hombre, totalVotos) << "%" << endl;
    cout << "Total Mujeres: " << mujer << " | " << porcentaje(mujer, totalVotos) << "%" << endl;
    cout << "Total votos: " << totalVotos << " | " << porcentaje(totalVotos, totalVotos) << "%" << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < listaPartidoVotos.getTam(); i++) {
      PartidoVotos pv = listaPartidoVotos.buscar(i);
      pv.votos = 0;
      listaPartidoVotos.modificar(pv, i);
    }
  }

  double porcentaje(double dato, double total) {
    return (dato / total) * 100.0;
  }

  void agregarVotosPartido(string nombrePartido, int cantVotos) {
    for (int i = 0; i < listaPartidoVotos.getTam(); i++) {
      PartidoVotos pv = listaPartidoVotos.buscar(i);
      if (pv.partido == nombrePartido) {
        int aux = pv.votos + cantVotos;
        pv.votos = aux;
        listaPartidoVotos.modificar(pv, i);
      }
    }
  }

};