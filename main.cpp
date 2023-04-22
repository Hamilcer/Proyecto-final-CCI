
#include "Archivos.h"

#include "Clases Principales/Candidato.h"
#include "Estructuras de Datos/PilaDinamica.h"


int main(){
	
	cout<<"Inicializando .."<<endl;
	
	//Creación de las listas
	
	Pila<Ciudad> listaCiudades;
	Pila<Partido> listaPartidos;
	Pila<Candidato> listaCandidatos;
	
	//Creación de los archivos
	
	Archivos Ciudades("Ciudades");
	Archivos Partidos("Partidos");
	Archivos Candidatos("Candidatos");
	
	//Creación de Ciudades
	Ciudad Bogota("Bogotá","Cundinamarca",15,20);
	Ciudad Villavicencio("Villavicencio","Meta",15,30);
	
	//Creación de Partidos
	Partido Conservador("Convervador","Juan Carrillo");
	Partido Liberal("Liberal","Maria Fernanda");
	
	//Añadir las ciudades y partidos en las listas
	
	listaCiudades.meter(Bogota);
	listaCiudades.meter(Villavicencio);
	
	listaPartidos.meter(Conservador);
	listaPartidos.meter(Liberal);
	
	while(listaCiudades.estaVacia() != true){
		Ciudades.escribir(listaCiudades.sacar().toString());
	}
	
	
	
	
	return 0;
}
