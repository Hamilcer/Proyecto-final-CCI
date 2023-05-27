#include <string>

class OpcionesListas {
private:

public:
    //1. Ciudades para las cuales se realizará el proceso electoral.
    void mostrarCiudades(Lista < Ciudad > * ciudades) {

        for (int i = 0; i < ciudades -> getTam(); i++) {
            //Guardar la ciudad buscada en una variable y devolver atributo nombre
            Ciudad ciudad = ciudades -> buscar(i);
            cout << i << ". " << ciudad.getNombre() << endl;
        }

        system("Pause"); // Pausa el programa y espera a que se presione una tecla
    }

    //2. Partidos legalmente reconocidos.
    void mostrarPartidos(Lista < Partido > * partidos) {
        for (int i = 0; i < partidos -> getTam(); i++) {
            //Guardar el partido buscado y devolver el atributo nombre y representante Legal
            Partido partido = partidos -> buscar(i);
            cout << i << ". " << partido.getNombre() << " /--/ Representante Legal = " << partido.getRepresentanteLegal() << endl;
        }

        system("Pause"); // Pausa el programa y espera a que se presione una tecla
    }

    void mostrarCandidatos(Lista < Candidato > * candidatos) {
        for (int i = 0; i < candidatos -> getTam(); i++) {
            //Guardar el candidato y devolver sus atributos
            Candidato candidato = candidatos -> buscar(i);
            cout << i << ". " << candidato.getNombre() << " " << candidato.getApellido() << " " << candidato.getNumIdentificacion() << " " << candidato.getPuesto() << " " << candidato.getPartido().getNombre() << "/n" << endl;
        }
        system("Pause");
    }

    //3. Todos los candidatos al concejo de una ciudad.

    void candidatosConcejo(string ciudad, Lista < Candidato > * candidatos) {
        int cantidad = 0;
        for (int i = 0; i < candidatos -> getTam(); i++) {
            //Guardar el candidato buscado y devolver los atributos necesarios dada la validacion
            Candidato candidato = candidatos -> buscar(i);
            if (candidato.getCiudadResidencia().getNombre() == ciudad && candidato.getPuesto() == "Concejo") {
                cout << candidato.getNombre() << endl;
                cantidad++;
            }
        }

        if (cantidad == 0) {
            cout << "Esta ciudad no tiene candidatos para esta categoria, verifique el ingreso" << endl;
        }

        system("Pause"); // Pausa el programa y espera a que se presione una tecla
    }

    //4. Todos los candidatos a la alcaldía de una ciudad.

    void candidatosAlcaldia(string ciudad, Lista < Candidato > * candidatos) {
        int cantidad = 0;
        for (int i = 0; i < candidatos -> getTam(); i++) {
            //Guardar el candidato buscado y devolver los atributos necesarios dada la validacion
            Candidato candidato = candidatos -> buscar(i);
            if (candidato.getCiudadResidencia().getNombre() == ciudad && candidato.getPuesto() == "Alcaldia") {
                cout << candidatos -> buscar(i).getNombre() << endl;
                cantidad++;
            }
        }

        if (cantidad == 0) {
            cout << "Esta ciudad no tiene candidatos para esta categoria, verifique el ingreso" << endl;
        }

        system("Pause"); // Pausa el programa y espera a que se presione una tecla
    }

    //5. Candidatos a cada una de las alcaldías, por partido.
    //6. Candidatos a cada uno de los concejos, por partido.

    void candidatosAlcaldiaConsejoPartido(string partido, string puesto, Lista < Candidato > * candidatos) {
        int cantidad = 0;
        for (int i = 0; i < candidatos -> getTam(); i++) {
            //Guardar el candidato buscado y devolver los atributos necesarios dada la validacion
            Candidato candidato = candidatos -> buscar(i);
            if (candidato.getPartido().getNombre() == partido && candidato.getPuesto() == puesto) {
                cout << candidatos -> buscar(i).getNombre() << endl;
                cantidad++;
            }
        }

        if (cantidad == 0) {
            cout << "Este partido no tiene candidatos para esta categoria, verifique el ingreso" << endl;
        }

        system("Pause"); // Pausa el programa y espera a que se presione una tecla
    }

    //7. Por cada partido, la lista de candidatos a los consejos.
    //8. Por cada partido, la lista de candidatos a las alcaldías.
    void candidatosAlcaldiaConsejoPartidoLista(string cargo, Lista < Candidato > * candidatos, Lista < Partido > * partidos) {
        for (int j = 0; j < 2; j++) {
            cout << "Lista de nombres de candidatos del partido " + partidos -> buscar(j).getNombre() + " para el cargo " + cargo << endl;
            for (int i = 0; i < candidatos -> getTam(); i++) {
                //Guardar el candidato y el partido buscado y devolver los atributos necesarios dada la validacion
                Candidato candidato = candidatos -> buscar(i);
                Partido partido = partidos -> buscar(i);
                if (candidato.getPartido().getNombre() == partido.getNombre() && candidato.getPuesto() == cargo) {
                    cout << candidatos -> buscar(i).getNombre() << endl;
                }
            }
        }
        system("Pause"); // Pausa el programa y espera a que se presione una tecla
    }

};