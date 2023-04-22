
#include "Archivos.h"

#include "Clases Principales/Candidato.h"
#include "Estructuras de Datos/PilaDinamica.h"


int main(){
	
	cout<<"Inicializando .."<<endl;
	
	//Creaci�n de las listas
	
	Pila<Ciudad> listaCiudades;
	Pila<Partido> listaPartidos;
	Pila<Candidato> listaCandidatos;
	
	//Creaci�n de los archivos
	
	Archivos Ciudades("Ciudades");
	Archivos Partidos("Partidos");
	Archivos Candidatos("Candidatos");
	
	//Creaci�n de Ciudades
	Ciudad Bogota("Bogot�","Cundinamarca",15,20);
	Ciudad Villavicencio("Villavicencio","Meta",15,30);
	
	//Creaci�n de Partidos
	Partido Conservador("Convervador","Juan Carrillo");
	Partido Liberal("Liberal","Maria Fernanda");
	
	//A�adir las ciudades y partidos en las listas
	
	listaCiudades.meter(Bogota);
	listaCiudades.meter(Villavicencio);
	
	listaPartidos.meter(Conservador);
	listaPartidos.meter(Liberal);
	
	while(listaCiudades.estaVacia() != true){
		Ciudades.escribir(listaCiudades.sacar().toString());
	}
	
	
	
	
	return 0;
}
