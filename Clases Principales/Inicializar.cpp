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
	    cout << "Ingrese el nombre del Partido: ";
	    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	    getline(std::cin, NombrePartido);
	
	    cout << "Ingrese el nombre del Representante legal: ";
	    getline(std::cin, RepresentanteLegal);

        for (i = 0; i < partidos -> getTam(); i++) {
            Partido partidoAuxiliar = partidos -> buscar(i);
            if (partidoAuxiliar.getNombre() == NombrePartido || partidoAuxiliar.getRepresentanteLegal() == RepresentanteLegal) {
                cout << "El Nombre del partido ya existe o ya hay un representante legal en un partido" << endl;
                break;
            }
        }

        // Si el bucle for se complet� sin encontrar coincidencias, el partido es v�lido
        if (i == partidos -> getTam()) {
            partidoValido = true;
        }
    }
    Partido partido(NombrePartido, RepresentanteLegal);

    return partido;
}

Ciudad Inicializar::inicializarCiudad() {
    //Se ingresan los datos de la nueva ciudad (Se necesita validaci�n cuando la ciudad ya existe)
    string nombre, departamento;
    int tamConcejo, censoElectoral;
    cout << "Ingrese el nombre de la ciudad" << endl;
    cin >> nombre;
    cout << "Ingrese el departamento de la ciudad" << endl;
    cin >> departamento;
    cout << "Ingrese el tama�o del concejo" << endl;
    cin >> tamConcejo;
    cout << "Ingrese el tama�o el censo electoral" << endl;
    cin >> censoElectoral;

    Ciudad ciudad(nombre, departamento, tamConcejo, censoElectoral);

    return ciudad;
}

Candidato Inicializar::inicializarCandidato(Lista < Partido > * partidos, Lista < Ciudad > * ciudades, Lista < Candidato > * candidatos) {
    // Insertar Candidato (Se necesita validaci�n de puesto, fecha nacimiento, estado civil)

    int OpcionPartido, OpcionNacimiento, OpcionResidencia;
    string nombre, apellido, puesto, numIdentificacion, estadoCivil, fechaNacimiento;
    char sexo;

    bool candidatoValido = false;
    int i = 0;

    while (!candidatoValido) {
		bool encontrado = false;
        //Buscar el partido perteneciente de la lista de partidos y guardarla en el objeto partido

        cout << "De los siguientes partidos constituidos ,� cual de ellos pertenece el candidato ?";
        opcionLista.mostrarPartidos(partidos);
        cin >> OpcionPartido;

        // Buscar la ciudad de nacimiento y residencia de la lista de ciudades y guardarla en los objetos propios

        cout << "De las siguientes ciudades, �Cual de ella naci� el candidato?" << endl;
        opcionLista.mostrarCiudades(ciudades);
        cin >> OpcionNacimiento;

        cout << "De las siguientes ciudades, �Cual de ellas reside el candidato?" << endl;
        opcionLista.mostrarCiudades(ciudades);
        cin >> OpcionResidencia;

        // A�adir los dem�s datos del candidato

        cout << "Ingrese el nombre de candidato" << endl;
        getline(std::cin, nombre);

        cout << "Ingrese el apellido del candidato" << endl;
        getline(std::cin, apellido);

        cout << "ingrese el puesto al que el candidato quiere postularse 1.Alcaldia - 2.Concejo " << endl;
        int opcion = leerEntrada(1,2);
        puesto = (opcion==1)?"Alcaldia":"Concejo";

        cout << "Ingrese el documento de identidad del candidato" << endl;
        cin >> numIdentificacion;

        cout << "ingrese el estado civil del candidato" << endl;
        cin >> estadoCivil;

        cout << "Ingrese la fecha de nacimiento de candidato (Ejemplo : 02/01/1980 dia,mes,a�o)" << endl;
        cin >> fechaNacimiento;

        for (int i = 0; i < candidatos -> getTam(); i++) {
            Candidato candidatoAuxiliar = candidatos -> buscar(i);
            if (candidatoAuxiliar.getNumIdentificacion() == numIdentificacion) {
                cout << "Ya hay un candidato con este numero de identificaci�n" << endl;
                encontrado = true;
                break;
            }
        }

	    if (!encontrado) {
	        candidatoValido = true;
	    }
    }

    //Creacion del objeto candidato para a�adirlo en la lista
    Partido partido = partidos -> buscar(OpcionPartido);
    int votos = 0;

    Ciudad ciudadNacimiento = ciudades -> buscar(OpcionNacimiento);
    Ciudad ciudadResidencia = ciudades -> buscar(OpcionResidencia);

    Candidato candidato(nombre, apellido, puesto, numIdentificacion, sexo, estadoCivil, fechaNacimiento, ciudadNacimiento, ciudadResidencia, partido, votos);

    return candidato;
}
