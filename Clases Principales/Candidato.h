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
        int votos;

    public:
    	Candidato() {
		    nombre = "";
		    apellido = "";
		    numIdentificacion = "";
		    sexo = 'N';
		    estadoCivil = "";
		    fechaNacimiento = "";
            votos = 0;
		}
		
        Candidato(std::string nombre, std::string apellido, std::string puesto, std::string numIdentificacion,
                  char sexo, std::string estadoCivil, std::string fechaNacimiento,
                  Ciudad ciudadNacimiento, Ciudad ciudadResidencia, Partido partido, int votos) {
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
            this->votos = votos;
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
        int getVotos(){return votos;}
        
        // M�todo toString para la clase Candidato
	    std::string toString() {

	    }

    void setNombre(const string &nombre) {
        Candidato::nombre = nombre;
    }

    void setApellido(const string &apellido) {
        Candidato::apellido = apellido;
    }

    void setPuesto(const string &puesto) {
        Candidato::puesto = puesto;
    }

    void setNumIdentificacion(const string &numIdentificacion) {
        Candidato::numIdentificacion = numIdentificacion;
    }

    void setSexo(char sexo) {
        Candidato::sexo = sexo;
    }

    void setEstadoCivil(const string &estadoCivil) {
        Candidato::estadoCivil = estadoCivil;
    }

    void setFechaNacimiento(const string &fechaNacimiento) {
        Candidato::fechaNacimiento = fechaNacimiento;
    }

    void setCiudadNacimiento(const Ciudad &ciudadNacimiento) {
        Candidato::ciudadNacimiento = ciudadNacimiento;
    }

    void setCiudadResidencia(const Ciudad &ciudadResidencia) {
        Candidato::ciudadResidencia = ciudadResidencia;
    }

    void setPartido(const Partido &partido) {
        Candidato::partido = partido;
    }

    void setVotos(int votos) {
        Candidato::votos = votos;
    }
};


