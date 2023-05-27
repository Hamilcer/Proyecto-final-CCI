#include "../Archivos.h"

#include "../OpcionesListas.cpp"
#include "../OpcionesConsultas.cpp"
#include "../OpcionesSimulacion.cpp"
#include "../OpcionesEstadisticas.cpp"

class Inicializar {
private: OpcionesListas opcionLista;
public:
    //Metodos para inicializar los partidos , ciudades y candidatos
    //Con el fin de obtener los datos a la hora de insertar o modificar sin necesidad de repetir codigo
    Partido inicializarPartido(Lista < Partido > * partidos);
    Ciudad inicializarCiudad();
    Candidato inicializarCandidato(Lista < Partido > * partidos, Lista < Ciudad > * ciudades, Lista < Candidato > * candidatos);
};

Partido Inicializar::inicializarPartido(Lista < Partido > * partidos) {
    //Insertar Partido
    string NombrePartido, RepresentanteLegal;

    bool partidoValido = false;
    int i = 0;

    while (!partidoValido) {
        cout << "Ingrese el nombre del Partido" << endl;
        cin >> NombrePartido;
        cout << "Ingrese el nombre del Representante legal" << endl;
        cin >> RepresentanteLegal;

        for (i = 0; i < partidos -> getTam(); i++) {
            Partido partidoAuxiliar = partidos -> buscar(i);
            if (partidoAuxiliar.getNombre() == NombrePartido || partidoAuxiliar.getRepresentanteLegal() == RepresentanteLegal) {
                cout << "El Nombre del partido ya existe o ya hay un representante legal en un partido" << endl;
                break;
            }
        }

        // Si el bucle for se completó sin encontrar coincidencias, el partido es válido
        if (i == partidos -> getTam()) {
            partidoValido = true;
        }
    }
    Partido partido(NombrePartido, RepresentanteLegal);

    return partido;
}

Ciudad Inicializar::inicializarCiudad() {
    //Se ingresan los datos de la nueva ciudad (Se necesita validación cuando la ciudad ya existe)
    string nombre, departamento;
    int tamConcejo, censoElectoral;
    cout << "Ingrese el nombre de la ciudad" << endl;
    cin >> nombre;
    cout << "Ingrese el departamento de la ciudad" << endl;
    cin >> departamento;
    cout << "Ingrese el tamaño del concejo" << endl;
    cin >> tamConcejo;
    cout << "Ingrese el tamaño el censo electoral" << endl;
    cin >> censoElectoral;

    Ciudad ciudad(nombre, departamento, tamConcejo, censoElectoral);

    return ciudad;
}

Candidato Inicializar::inicializarCandidato(Lista < Partido > * partidos, Lista < Ciudad > * ciudades, Lista < Candidato > * candidatos) {
    // Insertar Candidato (Se necesita validación de puesto, fecha nacimiento, estado civil)

    int OpcionPartido, OpcionNacimiento, OpcionResidencia;
    string nombre, apellido, puesto, numIdentificacion, estadoCivil, fechaNacimiento;
    char sexo;

    bool candidatoValido = false;
    int i = 0;

    while (!candidatoValido) {

        //Buscar el partido perteneciente de la lista de partidos y guardarla en el objeto partido

        cout << "De los siguientes partidos constituidos ,¿ cual de ellos pertenece el candidato ?";
        opcionLista.mostrarPartidos(partidos);
        cin >> OpcionPartido;

        // Buscar la ciudad de nacimiento y residencia de la lista de ciudades y guardarla en los objetos propios

        cout << "De las siguientes ciudades, ¿Cual de ella nació el candidato?" << endl;
        opcionLista.mostrarCiudades(ciudades);
        cin >> OpcionNacimiento;

        cout << "De las siguientes ciudades, ¿Cual de ellas reside el candidato?" << endl;
        opcionLista.mostrarCiudades(ciudades);
        cin >> OpcionResidencia;

        // Añadir los demás datos del candidato

        cout << "Ingrese el nombre de candidato" << endl;
        cin >> nombre;

        cout << "Ingrese el apellido del candidato" << endl;
        cin >> apellido;

        cout << "ingrese el puesto al que el candidato quiere postularse" << endl;
        cin >> puesto;

        cout << "Ingrese el documento de identidad del candidato" << endl;
        cin >> numIdentificacion;

        cout << "ingrese el estado civil del candidato" << endl;
        cin >> estadoCivil;

        cout << "Ingrese la fecha de nacimiento de candidato (Ejemplo : 02/01/1980 dia,mes,año)" << endl;
        cin >> fechaNacimiento;

        for (int i = 0; i < candidatos -> getTam(); i++) {
            Candidato candidatoAuxiliar = candidatos -> buscar(i);
            if (candidatoAuxiliar.getNumIdentificacion() == numIdentificacion) {
                cout << "Ya hay un candidato con este numero de identificación" << endl;
                break;
            }
        }

        // Si el bucle for se completó sin encontrar coincidencias, el partido es válido
        if (i == candidatos -> getTam()) {
            candidatoValido = true;
        }

    }

    //Creacion del objeto candidato para añadirlo en la lista
    Partido partido = partidos -> buscar(OpcionPartido);
    int votos = 0;

    Ciudad ciudadNacimiento = ciudades -> buscar(OpcionNacimiento);
    Ciudad ciudadResidencia = ciudades -> buscar(OpcionResidencia);

    Candidato candidato(nombre, apellido, puesto, numIdentificacion, sexo, estadoCivil, fechaNacimiento, ciudadNacimiento, ciudadResidencia, partido, votos);

    return candidato;
}