
#include "Archivos.h"

#include "Clases Principales/Candidato.h"
#include "Estructuras de Datos/PilaDinamica.h"
#include "Estructuras de Datos/Multilista.h"


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
	Ciudad Bogota("Bogota","Cundinamarca",15,20);
	Ciudad Villavicencio("Villavicencio","Meta",15,30);
	
	//Creaci�n de Partidos
	Partido Conservador("Conservador","Juan Carrillo");
	Partido Liberal("Liberal","Maria Fernanda");

	//Creacion candidatos
	Candidato Manuel("Manuel", "Rodriguez", "Alcalde", "1", 'M', "Casado", "15/06/2013", Bogota, Bogota, Liberal);
	Candidato Johan("Johan", "Rodriguez", "Consejo", "2", 'M', "Casado", "15/06/2013", Bogota, Villavicencio, Liberal);
	Candidato Marino("Marino", "Rodriguez", "Consejo", "3", 'M', "Casado", "15/06/2013", Bogota, Bogota, Conservador);
	Candidato Benigno("Benigno", "Rodriguez", "Consejo", "4", 'M', "Casado", "15/06/2013", Bogota, Villavicencio, Conservador);
	Candidato Fuensanta("Fuensanta", "Rodriguez", "Consejo", "5", 'M', "Casado", "15/06/2013", Bogota, Bogota, Liberal);
	Candidato Jesica("Jesica", "Rodriguez", "Consejo", "6", 'M', "Casado", "15/06/2013", Bogota, Villavicencio, Liberal);
	Candidato Amanda("Amanda", "Rodriguez", "Consejo", "7", 'M', "Casado", "15/06/2013", Bogota, Bogota, Conservador);
	Candidato Eloisa("Eloisa", "Rodriguez", "Alcalde", "8", 'M', "Casado", "15/06/2013", Bogota, Villavicencio, Conservador);
	Candidato Iker("Iker", "Rodriguez", "Consejo", "9", 'M', "Casado", "15/06/2013", Bogota, Bogota, Liberal);
	Candidato Consuelo("Consuelo", "Rodriguez", "Consejo", "10", 'M', "Casado", "15/06/2013", Bogota, Villavicencio, Liberal);
	
	//A�adir las ciudades y partidos en las listas
	
	listaCiudades.meter(Bogota);
	listaCiudades.meter(Villavicencio);
	
	listaPartidos.meter(Conservador);
	listaPartidos.meter(Liberal);
	
	while(listaCiudades.estaVacia() != true){
		Ciudades.escribir(listaCiudades.sacar().toString());
	}

	//cout << ("2">"a");
	
	Multilista1 ml(10, 10);

	ml.insertar(Manuel);
    ml.insertar(Johan);
    ml.insertar(Marino);
    ml.insertar(Benigno);
    ml.insertar(Fuensanta);
    ml.insertar(Jesica);
    ml.insertar(Amanda); 
    ml.insertar(Eloisa);
    ml.insertar(Iker);
    ml.insertar(Consuelo);

	ml.imprimir("Alcalde");

	
	
	return 0;
}
