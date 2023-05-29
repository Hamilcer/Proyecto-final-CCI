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
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, nombre);
    cout << "Ingrese el departamento de la ciudad" << endl;
    getline(std::cin, departamento);
    cout << "Ingrese el tama�o del concejo" << endl;
    tamConcejo = leerEntrada(7,21);
    cout << "Ingrese el tama�o el censo electoral" << endl;
    censoElectoral = leerEntrada(1,5000000);

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

        cout << "De los siguientes partidos constituidos ,� cual de ellos pertenece el candidato ?" << endl;
        opcionLista.mostrarPartidos(partidos);
        OpcionPartido = leerEntrada(0,partidos->getTam()-1);

        // Buscar la ciudad de nacimiento y residencia de la lista de ciudades y guardarla en los objetos propios

        cout << "De las siguientes ciudades, �Cual de ella naci� el candidato?" << endl;
        opcionLista.mostrarCiudades(ciudades);
        OpcionNacimiento = leerEntrada(0,ciudades->getTam()-1);

        cout << "De las siguientes ciudades, �Cual de ellas reside el candidato?" << endl;
        opcionLista.mostrarCiudades(ciudades);
        OpcionResidencia = leerEntrada(0,ciudades->getTam()-1);

        // A�adir los dem�s datos del candidato

        cout << "Ingrese el nombre de candidato" << endl;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(std::cin, nombre);

        cout << "Ingrese el apellido del candidato" << endl;
        getline(std::cin, apellido);

        cout << "ingrese el puesto al que el candidato quiere postularse 1.Alcaldia - 2.Concejo " << endl;
        int opcion = leerEntrada(1,2);
        puesto = (opcion==1)?"Alcaldia":"Concejo";

        if(puesto == "Alcaldia")
            for(int i = 0; i < candidatos->getTam(); i++)
                if(candidatos->buscar(i).getCiudadResidencia().getNombre() == ciudades->buscar(OpcionResidencia).getNombre() &&
                    candidatos->buscar(i).getPartido().getNombre() == partidos->buscar(OpcionPartido).getNombre()
                )
                {
                    cout << "Ya existe un candadto a la alcaldia para esa ciudad y partido" << endl;
                    cout << "1. Postular a Concejo - 2. calcelar insercion" << endl;
                    int existe = leerEntrada(1,2);
                    if(existe == 1)
                    {
                        puesto = "Concejo";
                        break;
                    }
                    else
                        return Candidato();
                }



        cout << "Ingrese el documento de identidad del candidato" << endl;
        numIdentificacion = to_string(leerEntrada(0, 9999999999));

        cout << "ingrese el estado civil del candidato 1.Casado 2.Soltero 3.Union libre 4.Divorciado" << endl;
        opcion = leerEntrada(1,4);
        if(opcion == 1)
        {
            estadoCivil = "Casado";
        }
        else if (opcion == 2)
        {
            estadoCivil = "Soltero";
        }
        else if (opcion == 3)
        {
            estadoCivil = "Union libre";
        }
        else if (opcion == 4)
        {
            estadoCivil = "Divorciado";
        }

        cout << "Ingrese la fecha de nacimiento de candidato " << endl;
        cout << "Dia: " << endl;
        int dia = leerEntrada(1,31);
        cout << "Mes: " << endl;
        int mes = leerEntrada(1,12);
        cout << "Año: " << endl;
        int anio = leerEntrada(1950, 2005);
        string sdia = (dia>9)? to_string(dia):"0"+to_string(dia);
        string smes = (mes>9)? to_string(mes):"0"+to_string(mes);
        string sanio = to_string(anio);
        fechaNacimiento = sdia+"/"+smes+"/"+sanio;

        cout << "Ingrese el sexo del candidato 1.F 2.M " << endl;
        int genero = leerEntrada(1, 2);
        if (genero == 1) {
            sexo = 'F';
        } else {
            sexo = 'M';
        }

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
