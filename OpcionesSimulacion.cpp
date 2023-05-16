#include "Archivos.h"
#include "iostream"
#include <string>

class OpcionesSimulacion{
	private:
        Lista<Candidato>* candidatos;
        Lista<Ciudad>* ciudades;
        Lista<Partido>* partidos;
	public:
		void agregarCandidatos(){
            std::cout<<"Agregar candidatos";
            std::string nombre = "Pepito";
            std::string apellido = "Perez";
            std::string puesto = "Alcaldia";
            std::string numIdentificacion = "1004809619";
            std::string sexoStr = "M";
            std::string estadoCivil = "Casado";
            std::string fechaNacimiento = "07/06/1985";
            std::string ciudadNacimientoNombre = "Bogota";
            std::string ciudadNacimientoDepartamento = "Cundinamarca";
            std::string ciudadResidenciaNombre = "Bogota";
            std::string ciudadResidenciaDepartamento = "Cundinamarca";
            std::string partidoNombre = "Conservador";
            std::string votos = "0";

            char sexo = sexoStr[0];
            Ciudad ciudadNacimiento(ciudadNacimientoNombre, " ", 0,0);
            Ciudad ciudadResidencia(ciudadResidenciaNombre, " ",0,0);
            Partido partido(partidoNombre," ");

            int cantVotos = stoi(votos);
            Candidato candidato(nombre, apellido, puesto, numIdentificacion, sexo, estadoCivil,
                                fechaNacimiento, ciudadNacimiento, ciudadResidencia, partido, cantVotos);
            candidatos->insertar(candidato); //no lo añade y da como un error de desbordamiento
            system("Pause");

         }

		
};
