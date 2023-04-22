#include <string>

class Partido {
    private:
        std::string nombre;
        std::string representanteLegal;

    public:
    	
    	Partido() {} // Constructor vac�o
    	
        Partido(std::string nombre, std::string representanteLegal) {
            this->nombre = nombre;
            this->representanteLegal = representanteLegal;
        }

        // M�todos getter para acceder a los atributos
        std::string getNombre() { return nombre; }
        std::string getRepresentanteLegal() { return representanteLegal; }
        
        // M�todo toString para la clase Partido
	    std::string toString() {
	        std::stringstream ss;
	        ss << nombre << "," << representanteLegal;
	        return ss.str();
	    }
};
