#include <string>

#include "Ciudad.h"
#include "Partido.h"

class Candidato {
    private:
        std::string nombre;
        std::string apellido;
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
		
        Candidato(std::string nombre, std::string apellido, std::string numIdentificacion,
                  char sexo, std::string estadoCivil, std::string fechaNacimiento,
                  Ciudad ciudadNacimiento, Ciudad ciudadResidencia, Partido partido) {
            this->nombre = nombre;
            this->apellido = apellido;
            this->numIdentificacion = numIdentificacion;
            this->sexo = sexo;
            this->estadoCivil = estadoCivil;
            this->fechaNacimiento = fechaNacimiento;
            this->ciudadNacimiento = ciudadNacimiento;
            this->ciudadResidencia = ciudadResidencia;
            this->partido = partido;
        }

        // Métodos getter para acceder a los atributos
        std::string getNombre() { return nombre; }
        std::string getApellido() { return apellido; }
        std::string getNumIdentificacion() { return numIdentificacion; }
        char getSexo() { return sexo; }
        std::string getEstadoCivil() { return estadoCivil; }
        std::string getFechaNacimiento() { return fechaNacimiento; }
        Ciudad getCiudadNacimiento() { return ciudadNacimiento; }
        Ciudad getCiudadResidencia() { return ciudadResidencia; }
        Partido getPartido() { return partido; }
        
        // Método toString para la clase Candidato
	    std::string toString() {
	        std::stringstream ss;
	        ss << nombre << "," << apellido << "," << numIdentificacion << "," << sexo << "," << estadoCivil << ","
	           << fechaNacimiento << "," << ciudadNacimiento.getNombre() << "," << ciudadResidencia.getNombre() << "," << partido.toString();
	        return ss.str();
	    }
};
