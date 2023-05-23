#include <stdlib.h>  //Libreria para limpiar pantalla
#include "Clases Principales/Inicializar.cpp"

class Simulacion{
	private:
		Lista<Ciudad>* ciudades;
		Lista<Partido>* partidos;
		Lista<Candidato>* candidatos;
		
		Inicializar inicializar;
	public:
		
		int Opcion;
		
		//Muestra de Menus
		void MostrarMenu();
		void SubMenuListas();
		void SubMenuConsultas();
		void SubMenuEstadisticas();
		void SubMenuInsercion();
		void EleccionSubMenuInsercion();
		
		//Bloque de ejecución
		void Menu();
		
		//Leer Archivos e inicializar Listas
		void leerArchivos(){
			
			Archivos Ciudades("Ciudades");
			Archivos Partidos("Partidos");
			Archivos Candidatos("Candidatos");
			
			ciudades = Ciudades.leerCiudades();
			partidos = Partidos.leerPartidos();
			candidatos = Candidatos.leerCandidatos();
			
		}
};

void Simulacion::Menu(){
	bool programa = true;
	
	OpcionesListas opcionLista; // Inicializa el objeto de la clase Opciones Listas
	leerArchivos();
	
	while(programa){ // Bucle infinito del programa
		system("cls");
		MostrarMenu();
		cin>>Opcion;
		
		switch(Opcion){
			case 1:
				{	
					system("cls"); // Limpia pantalla
					SubMenuListas(); // Muestra menú
					cin>>Opcion;
					switch(Opcion){
						case 1:{
							opcionLista.mostrarCiudades(ciudades); 
							break;
						}
						case 2:{
							opcionLista.mostrarPartidos(partidos);
							break;
						}
						case 3:{
							string ciudad;
							cout<<"Ingrese la ciudad en la que desea buscar candidatos al consejo"<<endl;
							cin>>ciudad;
							opcionLista.candidatosConcejo(ciudad,candidatos);
							
							break;
						}
						case 4:{
							string ciudad;
							cout<<"Ingrese la ciudad en la que desea buscar candidatos a la alcaldia"<<endl;
							cin>>ciudad;
							opcionLista.candidatosAlcaldia(ciudad,candidatos);
							break;
						}
						case 5:{
							string partido;
							cout<<"Ingrese el partido en la que desea buscar candidatos a la alcaldia"<<endl;
							cin>>partido;
							opcionLista.candidatosAlcaldiaConsejoPartido(partido, "Alcaldia",candidatos);
							break;
						}
						case 6:{
							string partido;
							cout<<"Ingrese el partido en la que desea buscar candidatos al Consejo"<<endl;
							cin>>partido;
							opcionLista.candidatosAlcaldiaConsejoPartido(partido, "Consejo",candidatos);
							
							break;
						}
						case 7:{
							opcionLista.candidatosAlcaldiaConsejoPartidoLista("Consejo",candidatos,partidos);
							break;
						}
						case 8:{
							opcionLista.candidatosAlcaldiaConsejoPartidoLista("Alcaldia",candidatos,partidos);
							break;
						}
					}
					break;
				}
			case 2:
				{
					system("cls");
					SubMenuConsultas();
					cin>>Opcion;
					switch(Opcion){
						case 1:{
								
								break;
							}
						case 2:{
							
							break;
						}
						case 3:{
							
							break;
						}
						case 4:{
							
							break;
						}
						case 5:{
							
							break;
						}
						case 6:{
							
							break;
						}
						case 7:{
							
							break;
						}
					break;
					}
				}
			case 3:
				{
					system("cls");
					SubMenuEstadisticas();
					cin>>Opcion;
					switch(Opcion){
						case 1:{
								
								break;
							}
						case 2:{
							
							break;
						}
						case 3:{
							
							break;
						}
					break;	
					}
				}
			case 4:
				{
					system("cls");
					//REALIZAR SIMULACION 1. SIMULAR 2. TODOS LOS VOTOS DE LA SIMULACION SE REINICIAN
					break;
				}
			case 5:
				{
					system("cls");
					SubMenuInsercion();
					cin>>Opcion;
					
					string caso;
					
					switch(Opcion){
						case 1:
						{ //Opciones para insertar
							EleccionSubMenuInsercion();
							cin>>Opcion;
							switch(Opcion){
								case 1:
								{  
									//Creación del Objeto partido
									Partido NuevoPartido = inicializar.inicializarPartido();
									//Inserción en la lista de partidos
									partidos->insertar(NuevoPartido);
									
									Opcion = 0;
									break;
								}
								case 2:
								{ // Insertar Candidato (Se necesita validación de puesto, fecha nacimiento, estado civil)
								
									//Creacion del objeto candidato para añadirlo en la lista
									
									Candidato nuevoCandidato = inicializar.inicializarCandidato(partidos,ciudades);
									//Inserción en la lista de candidatos
									candidatos->insertar(nuevoCandidato);
									break;
								}
								case 3:
								{
									//Se ingresan los datos de la nueva ciudad (Se necesita validación cuando la ciudad ya existe)
									//Creación del Objeto Ciudad
									Ciudad NuevaCiudad = inicializar.inicializarCiudad();
									//Insercion en la lista de ciudades
									ciudades->insertar(NuevaCiudad);
									break;
								}
							}
						  break;
						}
						case 2:
						{ //Opciones para Modificar
							EleccionSubMenuInsercion();
							cin>>Opcion;
							switch(Opcion){
								case 1:{ 
									//Encontrar el partido a modificar
									string NombrePartido, RepresentanteLegal;
									cout<<"¿Que partido deseas modificar?"<<endl;
									opcionLista.mostrarPartidos(partidos);
									cin>>Opcion;
									//Inicializar Partido
									Partido NuevoPartido = inicializar.inicializarPartido();
									
									partidos->modificar(NuevoPartido,Opcion);
									
									break;
								}
								case 2:{ //Modificar Candidato
									
									// Encontrar el candidato a modificar
									int Opcion;
									
									cout << "Selecciona el candidato que deseas modificar" << endl;
									opcionLista.mostrarCandidatos(candidatos);
									cin >> Opcion;
									
									// Creación del objeto candidato para añadirlo en la lista
									Candidato nuevoCandidato = inicializar.inicializarCandidato(partidos, ciudades);
									
									// Inserción en la lista de candidatos
									candidatos->modificar(nuevoCandidato, Opcion);
									break;
								}
								case 3:{ //Modificar Ciudad
								
									//Enconntrar la ciudad a modificar (Se necesita validación cuando la ciudad ya existe)
									string nombre, departamento;
									int tamConcejo, censoElectoral, ciudad;
									cout<<"Selecciona la ciudad que desea modificar"<<endl;
									opcionLista.mostrarCiudades(ciudades);
									cin>>ciudad;
									
									//Creación del Objeto Ciudad
									Ciudad NuevaCiudad = inicializar.inicializarCiudad();
									//Insercion en la lista de ciudades
									ciudades->modificar(NuevaCiudad,ciudad);
									break;
								}
							}
							break;
						}
						case 3:
						{ //Opciones para Eliminar
							EleccionSubMenuInsercion();
							cin>>Opcion;
							switch(Opcion){
								case 1:{//Eliminar Partido
									int Eleccion;
									cout<<"¿Que partido deseas Eliminar?"<<endl;
									opcionLista.mostrarPartidos(partidos);
									cin>>Eleccion;
									
									partidos->borrar(Eleccion);
									break;
								}
								case 2:{//Eliminar Candidato
									
									cout<<"¿Que candidato deseas Eliminar?"<<endl;
									opcionLista.mostrarCandidatos(candidatos);
									cin>>Opcion;
									
									candidatos->borrar(Opcion);
									
									break;
								}
								case 3:{ // Eliminar Ciudades
									
									cout<<"¿Que ciudades deseas Eliminar?"<<endl;
									opcionLista.mostrarCiudades(ciudades);
									cin>>Opcion;
									
									ciudades->borrar(Opcion);
									
									break;
								}
							}
							break;
						}
					}
				  Opcion = 0;
				  break;	
				}
			case 6:
				{
					system("cls");
					//FINALIZAR Y GUARDAR EN LOS ARCHIVOS PLANOS
					
					//Escribir en el archivo plano los partidos de la lista
					Archivos Partidos("Partidos");
					string textoPartidos;
					
					for (int i = 0; i < partidos->getTam(); i++){
						Partido partido = partidos->buscar(i); // Declaración del partido de la lista para añadir su información al texto plano
						textoPartidos += partido.getNombre()+","+partido.getRepresentanteLegal()+"\n";
					}
					
					Partidos.escribir(textoPartidos);
					
					//Escribir en el archivo plano las ciudades de la lista
					
					Archivos Ciudades("Ciudades");
					string textoCiudades;
					
					for (int i = 0; i < ciudades->getTam(); i++){
						Ciudad ciudad = ciudades->buscar(i);
						textoCiudades += ciudad.getNombre()+","+ciudad.getDepartamento()+","+to_string(ciudad.getTamConcejo())+","+to_string(ciudad.getCensoElectoral())+"\n";
					}
					
					Ciudades.escribir(textoCiudades);
					
					//Escribir en el archivo plano los candidatos de la lista
					
					programa = false;
					break;
				}
		}
	}
}
void Simulacion::MostrarMenu(){
	cout<<"Registraduria Nacional del Estado Civil"<<endl;
	cout<<"Menu Principal"<<endl;
	cout<<"--------------------------------------------------"<<endl;
	cout<<"1. Buscar listas por categoria"<<endl;
	cout<<"2. Realizar consultas"<<endl;
	cout<<"3. Obtener Estadisticas"<<endl;
	cout<<"4. Simular Proceso electoral"<<endl;
	cout<<"5. Insertar, Modificar y Eliminar"<<endl;
	cout<<"6. Salir"<<endl;
}

void Simulacion::SubMenuListas(){
	cout<<"Buscar Listas por categoria"<<endl;
	cout<<"1. Ciudades para las cuales se realizará el proceso electoral."<<endl;
	cout<<"2. Partidos legalmente reconocidos."<<endl;
	cout<<"3. Todos los candidatos al concejo de una ciudad."<<endl;
	cout<<"4. Todos los candidatos a la alcaldía de una ciudad."<<endl;
	cout<<"5. Candidatos a cada una de las alcaldías, por partido."<<endl;
	cout<<"6. Candidatos a cada uno de los concejos, por partido."<<endl;
	cout<<"7. Por cada partido, la lista de candidatos a los consejos."<<endl;
	cout<<"8. Por cada partido, la lista de candidatos a las alcaldías."<<endl;
	
}
void Simulacion::SubMenuConsultas(){
	cout<<"Realizar una consulta"<<endl;
	cout<<"1. Dado un partido y una ciudad, mostrar la lista de sus candidatos al Concejo y el candidato a la alcaldía."<<endl;
	cout<<"2. Dado un partido mostrar la lista de candidatos a alcaldías de cada una de las diferentes ciudades."<<endl;
	cout<<"3. Dado un partido mostrar las listas de candidatos a cada uno de los diferentes concejos."<<endl;
	cout<<"4. Dada una ciudad, mostrar por cada partido, el candidato a la alcaldía y los candidatos al concejo"<<endl;
	cout<<"5. Dada una ciudad, mostrar el tarjetón de candidatos a la alcaldía."<<endl;
	cout<<"6. Dada una ciudad, mostrar el tarjetón de candidatos al concejo."<<endl;
	cout<<"7. Censo electoral. Por cada ciudad, mostrar la cantidad de personas habilitadas para votar."<<endl;
}

void Simulacion::SubMenuEstadisticas(){
	cout<<"Estadisticas"<<endl;
	cout<<"1. Ver el reporte por ciudad"<<endl;
	cout<<"2. Ver el reporte por consejo"<<endl;
	cout<<"3. Ver el reporte total nacional"<<endl;
}

void Simulacion::SubMenuInsercion(){
	cout<<"1. Insertar"<<endl;
	cout<<"2. Modificar"<<endl;
	cout<<"3. Eliminar"<<endl;
}

void Simulacion::EleccionSubMenuInsercion(){
	cout<<"1. Partido"<<endl;
	cout<<"2. Candidato"<<endl;
	cout<<"3. Ciudad"<<endl;
}
