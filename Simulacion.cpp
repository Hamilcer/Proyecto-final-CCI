#include <stdlib.h>  //Libreria para limpiar pantalla

class Simulacion{
	private:

	public:
		
		int Opcion;
		
		void MostrarMenu();
		void SubMenuListas();
		void SubMenuConsultas();
		void SubMenuEstadisticas();
		
		void Menu();
};

void Simulacion::Menu(){
	
	while(true){ // Bucle infinito del programa
		system("cls");
		MostrarMenu();
		cin>>Opcion;
		
		switch(Opcion){
			case 1:
				{	
					system("cls");
					SubMenuListas();
					cin>>Opcion;
					switch(Opcion){
						case 1:{
								
								break;
							}
						case 2{
							
							break;
						}
						case 3{
							
							break;
						}
						case 4{
							
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
						case 8:{
							
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
						case 2{
							
							break;
						}
						case 3{
							
							break;
						}
						case 4{
							
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
			case 3:
				{
					system("cls");
					SubMenuEstadisticas();
					cin>>Opcion;
					switch(Opcion){
						case 1:{
								
								break;
							}
						case 2{
							
							break;
						}
						case 3{
							
							break;
						}
					break;	
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
					//FINALIZAR Y GUARDAR EN LOS ARCHIVOS PLANOS
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
