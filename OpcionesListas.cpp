#include "Archivos.h"
#include <string>

class OpcionesListas{
	private:
		Lista<Ciudad>* ciudades;
		Lista<Partido>* partidos;
		Lista<Candidato>* candidatos;
		
	public:
		
		void leerArchivos(){
			Archivos Ciudades("Ciudades");
			Archivos Partidos("Partidos");
			Archivos Candidatos("Candidatos");
			
			ciudades = Ciudades.leerCiudades();
			partidos = Partidos.leerPartidos();
			candidatos = Candidatos.leerCandidatos();
		}
		
		//1. Ciudades para las cuales se realizará el proceso electoral.
		void mostrarCiudades(){
			
			for (int i = 0; i < ciudades->getTam(); i++) {
				cout << ciudades->buscar(i).getNombre() << endl;
			}
						        
			system("Pause"); // Pausa el programa y espera a que se presione una tecla
		}
		
		//2. Partidos legalmente reconocidos.
		void mostrarPartidos(){
			for (int i = 0; i < partidos->getTam(); i++) {
				cout << partidos->buscar(i).getNombre() << endl;
			}
						        
			system("Pause"); // Pausa el programa y espera a que se presione una tecla
		}
		
		//3. Todos los candidatos al concejo de una ciudad.
		
		void candidatosConcejo(string ciudad){
			int cantidad = 0;
			for (int i = 0; i < candidatos->getTam(); i++) {
				if(candidatos->buscar(i).getCiudadResidencia().getNombre() == ciudad && candidatos->buscar(i).getPuesto() == "Consejo"){
				  cout << candidatos->buscar(i).getNombre()<< endl;
				  cantidad++;	
				}
			}
			
			if(cantidad == 0){
				cout<<"Esta ciudad no tiene candidatos para esta categoria, verifique el ingreso"<<endl;
			}
						        
			system("Pause"); // Pausa el programa y espera a que se presione una tecla
		}
		
		//4. Todos los candidatos a la alcaldía de una ciudad.
		
		void candidatosAlcaldia(string ciudad){
			int cantidad = 0;
			for (int i = 0; i < candidatos->getTam(); i++) {
				if(candidatos->buscar(i).getCiudadResidencia().getNombre() == ciudad && candidatos->buscar(i).getPuesto() == "Alcaldia" ){
				  cout << candidatos->buscar(i).getNombre() << endl;
				  cantidad++;	
				}
			}
			
			if(cantidad == 0){
				cout<<"Esta ciudad no tiene candidatos para esta categoria, verifique el ingreso"<<endl;
			}
						        
			system("Pause"); // Pausa el programa y espera a que se presione una tecla
		}
		
		//5. Candidatos a cada una de las alcaldías, por partido.
		//6. Candidatos a cada uno de los concejos, por partido.
		
		void candidatosAlcaldiaConsejoPartido(string partido, string puesto){
			int cantidad = 0;
			for (int i = 0; i < candidatos->getTam(); i++) {
				if(candidatos->buscar(i).getPartido().getNombre() == partido &&  candidatos->buscar(i).getPuesto() == puesto ){
				  cout << candidatos->buscar(i).getNombre() << endl;
				  cantidad++;	
				}
			}
			
			if(cantidad == 0){
				cout<<"Este partido no tiene candidatos para esta categoria, verifique el ingreso"<<endl;
			}
						        
			system("Pause"); // Pausa el programa y espera a que se presione una tecla
		}
		
		//7. Por cada partido, la lista de candidatos a los consejos.
		//8. Por cada partido, la lista de candidatos a las alcaldías.
		void candidatosAlcaldiaConsejoPartidoLista(string cargo){
			for(int j = 0 ; j < 2; j++){
				cout<<"Lista de nombres de candidatos del partido "+ partidos->buscar(j).getNombre()+" para el cargo "+cargo<<endl;
				for (int i = 0; i < candidatos->getTam(); i++) {
					if(candidatos->buscar(i).getPartido().getNombre() == partidos->buscar(j).getNombre() &&  candidatos->buscar(i).getPuesto() == cargo ){
					  cout << candidatos->buscar(i).getNombre() << endl;
					}
			  	}	
			}
			system("Pause"); // Pausa el programa y espera a que se presione una tecla
		}
		
		
};
