#include "../Archivos.h"
#include "../OpcionesListas.cpp"

class Inicializar{
	private:
		OpcionesListas opcionLista;
	public:
		//Metodos para inicializar los partidos , ciudades y candidatos
		//Con el fin de obtener los datos a la hora de insertar o modificar sin necesidad de repetir codigo
		Partido inicializarPartido();
		Ciudad inicializarCiudad();
		Candidato inicializarCandidato(Lista<Partido>* partidos, Lista<Ciudad>* ciudades);
};


Partido Inicializar::inicializarPartido(){
	//Insertar Partido
	string NombrePartido, RepresentanteLegal;
	cout<<"Ingrese el nombre del Partido"<<endl;
	cin>>NombrePartido;
	cout<<"Ingrese el nombre del Representante legal"<<endl;
	cin>>RepresentanteLegal;
	
	Partido partido(NombrePartido,RepresentanteLegal);
	
	return partido;	
}

Ciudad Inicializar::inicializarCiudad(){
	//Se ingresan los datos de la nueva ciudad (Se necesita validación cuando la ciudad ya existe)
	string nombre, departamento;
	int tamConcejo, censoElectoral;
	cout<<"Ingrese el nombre de la ciudad"<<endl;
	cin>>nombre;
	cout<<"Ingrese el departamento de la ciudad"<<endl;
	cin>>departamento;
	cout<<"Ingrese el tamaño del concejo"<<endl;
	cin>>tamConcejo;
	cout<<"Ingrese el tamaño el censo electoral"<<endl;
	cin>>censoElectoral;
	
	Ciudad ciudad(nombre,departamento,tamConcejo,censoElectoral);
	
	return ciudad;
}

Candidato Inicializar::inicializarCandidato(Lista<Partido>* partidos, Lista<Ciudad>* ciudades){
	// Insertar Candidato (Se necesita validación de puesto, fecha nacimiento, estado civil)
									
	int Opcion;
	string nombre, apellido, puesto, numIdentificacion, estadoCivil, fechaNacimiento;
	char sexo;
	
	//Buscar el partido perteneciente de la lista de partidos y guardarla en el objeto partido
	
	cout<<"De los siguientes partidos constituidos ,¿ cual de ellos pertenece el candidato ?";
	opcionLista.mostrarPartidos(partidos);
	cin>>Opcion;
	
	Partido partido = partidos->buscar(Opcion);
	
	// Buscar la ciudad de nacimiento y residencia de la lista de ciudades y guardarla en los objetos propios
	
	cout<<"De las siguientes ciudades, ¿Cual de ella nació el candidato?"<<endl;
	opcionLista.mostrarCiudades(ciudades);
	cin>>Opcion;
	
	Ciudad ciudadNacimiento = ciudades->buscar(Opcion);
	
	cout <<"De las siguientes ciudades, ¿Cual de ellas reside el candidato?"<<endl;
	opcionLista.mostrarCiudades(ciudades);
	cin>>Opcion;
	
	Ciudad ciudadResidencia = ciudades->buscar(Opcion);
	
	// Añadir los demás datos del candidato
	
	cout<<"Ingrese el nombre de candidato"<<endl;
	cin>>nombre;
	
	cout<<"Ingrese el apellido del candidato"<<endl;
	cin>>apellido;
	
	cout<<"ingrese el puesto al que el candidato quiere postularse"<<endl;
	cin>>puesto;
	
	cout<<"Ingrese el documento de identidad del candidato"<<endl;
	cin>>numIdentificacion;
	
	cout<<"ingrese el estado civil del candidato"<<endl;
	cin>>estadoCivil;
	
	cout<<"Ingrese la fecha de nacimiento de candidato (Ejemplo : 02/01/1980 dia,mes,año)"<<endl;
	cin>>fechaNacimiento;
	
	//Creacion del objeto candidato para añadirlo en la lista
	
	Candidato candidato(nombre,apellido,puesto,numIdentificacion,sexo,estadoCivil,fechaNacimiento,ciudadNacimiento,ciudadResidencia,partido);
	
	return candidato;
}
