#ifndef CANDIDATO_H
#define CANDIDATO_H

#include <string>
#include "Ciudad.h"
#include "Partido.h"

class Candidato {
    private:
        std::string nombre;
        std::string apellido;
        std::string puesto; //puesto al que aspira
        std::string numIdentificacion;
        char sexo;
        std::string estadoCivil;
        std::string fechaNacimiento;
        Ciudad ciudadNacimiento;
        Ciudad ciudadResidencia;
        Partido partido;

    public:
    	Candidato() {
		    nombre = "";
		    apellido = "";
		    numIdentificacion = "";
		    sexo = 'N';
		    estadoCivil = "";
		    fechaNacimiento = "";
		}
		
        Candidato(std::string nombre, std::string apellido, std::string puesto, std::string numIdentificacion,
                  char sexo, std::string estadoCivil, std::string fechaNacimiento,
                  Ciudad ciudadNacimiento, Ciudad ciudadResidencia, Partido partido) {
            this->nombre = nombre;
            this->apellido = apellido;
            this->puesto = puesto;
            this->numIdentificacion = numIdentificacion;
            this->sexo = sexo;
            this->estadoCivil = estadoCivil;
            this->fechaNacimiento = fechaNacimiento;
            this->ciudadNacimiento = ciudadNacimiento;
            this->ciudadResidencia = ciudadResidencia;
            this->partido = partido;
        }

        // M�todos getter para acceder a los atributos
        std::string getNombre() { return nombre; }
        std::string getApellido() { return apellido; }
        std::string getNombreCompleto() { return nombre+" "+apellido; }
        std::string getPuesto() { return puesto; }
        std::string getNumIdentificacion() { return numIdentificacion; }
        char getSexo() { return sexo; }
        std::string getEstadoCivil() { return estadoCivil; }
        std::string getFechaNacimiento() { return fechaNacimiento; }
        Ciudad getCiudadNacimiento() { return ciudadNacimiento; }
        Ciudad getCiudadResidencia() { return ciudadResidencia; }
        Partido getPartido() { return partido; }
        
        // M�todo toString para la clase Candidato
	    std::string toString() {

	    }
};

#endif