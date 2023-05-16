#include <stdlib.h>  //Libreria para limpiar pantalla
#include "OpcionesListas.cpp"
#include "OpcionesSimulacion.cpp"


class Simulacion{
	private:

	public:
		
		int Opcion;
		
		void MostrarMenu();
		void SubMenuListas();
		void SubMenuConsultas();
		void SubMenuEstadisticas();
        void SubMenuSimulacion();
        void SubMenuAgregarRegistro();
        void SubMenuEliminarRegistro();
        void SubMenuModificarRegistro();
		
		void Menu();
};

void Simulacion::Menu(){
	bool programa = true;
	
	while(programa){ // Bucle infinito del programa
		system("cls");
		MostrarMenu();
		cin>>Opcion;
		
		switch(Opcion){
			case 1:
				{	
					OpcionesListas opcionLista; // Inicializa el objeto de la clase Opciones Listas
					opcionLista.leerArchivos(); // Lee los archivos e inicializa las listas
					
					system("cls"); // Limpia pantalla
					SubMenuListas(); // Muestra men�
					cin>>Opcion;
					switch(Opcion){
						case 1:{
							opcionLista.mostrarCiudades(); 
							break;
						}
						case 2:{
							opcionLista.mostrarPartidos();
							break;
						}
						case 3:{
							string ciudad;
							cout<<"Ingrese la ciudad en la que desea buscar candidatos al consejo"<<endl;
							cin>>ciudad;
							opcionLista.candidatosConcejo(ciudad);
							
							break;
						}
						case 4:{
							string ciudad;
							cout<<"Ingrese la ciudad en la que desea buscar candidatos a la alcaldia"<<endl;
							cin>>ciudad;
							opcionLista.candidatosAlcaldia(ciudad);
							break;
						}
						case 5:{
							string partido;
							cout<<"Ingrese el partido en la que desea buscar candidatos a la alcaldia"<<endl;
							cin>>partido;
							opcionLista.candidatosAlcaldiaConsejoPartido(partido, "Alcaldia");
							break;
						}
						case 6:{
							string partido;
							cout<<"Ingrese el partido en la que desea buscar candidatos al Consejo"<<endl;
							cin>>partido;
							opcionLista.candidatosAlcaldiaConsejoPartido(partido, "Consejo");
							
							break;
						}
						case 7:{
							opcionLista.candidatosAlcaldiaConsejoPartidoLista("Consejo");
							break;
						}
						case 8:{
							opcionLista.candidatosAlcaldiaConsejoPartidoLista("Alcaldia");
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
					//REALIZAR SIMULACION 1. SIMULAR 2. TODOS LOS VOTOS DE LA SIMULACION SE REINICIAN
                    OpcionesSimulacion opcionSimulacion;
                    system("cls");
                    SubMenuSimulacion();
                    cin>>Opcion;
                    switch(Opcion){
                        case 1:{
                            system("cls");
                            SubMenuAgregarRegistro();
                            cin>>Opcion;
                            switch(Opcion){
                                case 1:{
                                    opcionSimulacion.agregarCandidatos();
                                    break;
                                }
                                case 2:{

                                    break;
                                }
                                case 3:{

                                    break;
                                }
                            }
                            break;
                        }
                        case 2:{
                            system("cls");
                            SubMenuModificarRegistro();
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
                            }
                            break;
                        }
                        case 3:{
                            system("cls");
                            SubMenuEliminarRegistro();
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
                            }
                            break;
                        }
                        case 4:{
                            break;
                        }

                    }
					break;
				}
			case 5:
				{
					system("cls");
					//FINALIZAR Y GUARDAR EN LOS ARCHIVOS PLANOS
					break;
				}
			case 6:
				{
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
	cout<<"5. Finalizar Simulacion y guardar"<<endl;
	cout<<"6. Salir"<<endl;
}

void Simulacion::SubMenuListas(){
	cout<<"Buscar Listas por categoria"<<endl;
	cout<<"1. Ciudades para las cuales se realizar� el proceso electoral."<<endl;
	cout<<"2. Partidos legalmente reconocidos."<<endl;
	cout<<"3. Todos los candidatos al concejo de una ciudad."<<endl;
	cout<<"4. Todos los candidatos a la alcald�a de una ciudad."<<endl;
	cout<<"5. Candidatos a cada una de las alcald�as, por partido."<<endl;
	cout<<"6. Candidatos a cada uno de los concejos, por partido."<<endl;
	cout<<"7. Por cada partido, la lista de candidatos a los consejos."<<endl;
	cout<<"8. Por cada partido, la lista de candidatos a las alcald�as."<<endl;
	
}
void Simulacion::SubMenuConsultas(){
	cout<<"Realizar una consulta"<<endl;
	cout<<"1. Dado un partido y una ciudad, mostrar la lista de sus candidatos al Concejo y el candidato a la alcald�a."<<endl;
	cout<<"2. Dado un partido mostrar la lista de candidatos a alcald�as de cada una de las diferentes ciudades."<<endl;
	cout<<"3. Dado un partido mostrar las listas de candidatos a cada uno de los diferentes concejos."<<endl;
	cout<<"4. Dada una ciudad, mostrar por cada partido, el candidato a la alcald�a y los candidatos al concejo"<<endl;
	cout<<"5. Dada una ciudad, mostrar el tarjet�n de candidatos a la alcald�a."<<endl;
	cout<<"6. Dada una ciudad, mostrar el tarjet�n de candidatos al concejo."<<endl;
	cout<<"7. Censo electoral. Por cada ciudad, mostrar la cantidad de personas habilitadas para votar."<<endl;
}

void Simulacion::SubMenuEstadisticas(){
	cout<<"Estadisticas"<<endl;
	cout<<"1. Ver el reporte por ciudad"<<endl;
	cout<<"2. Ver el reporte por consejo"<<endl;
	cout<<"3. Ver el reporte total nacional"<<endl;
}

void Simulacion::SubMenuSimulacion(){
    cout<<" Simulacion"<<endl;
    cout<<"1. Agregar registro"<<endl;
    cout<<"2. Modificar registro"<<endl;
    cout<<"3. Eliminar registro"<<endl;
    cout<<"4. Simulacion proceso electoral"<<endl;
}

void Simulacion::SubMenuAgregarRegistro() {
    cout<<" Agregar registro"<<endl;
    cout<<"1. Agregar candidato"<<endl;
    cout<<"2. Agregar ciudad"<<endl;
    cout<<"3. Agregar partido "<<endl;
}

void Simulacion::SubMenuModificarRegistro() {
    cout<<" Modificar registro"<<endl;
    cout<<"1. Modificar candidato"<<endl;
    cout<<"2. Modificar ciudad"<<endl;
    cout<<"3. Modificar partido "<<endl;
}

void Simulacion::SubMenuEliminarRegistro() {
    cout<<" Eliminar registro"<<endl;
    cout<<"1. Eliminar candidato"<<endl;
    cout<<"2. Eliminar ciudad"<<endl;
    cout<<"3. Eliminar partido "<<endl;
}
