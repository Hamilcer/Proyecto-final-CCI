#include <string>

class OpcionesListas {
private:

public:
    //1. Ciudades para las cuales se realizar� el proceso electoral.
    void mostrarCiudades(Lista < Ciudad > * ciudades) {
        for (int i = 0; i < ciudades -> getTam(); i++) {
            //Guardar la ciudad buscada en una variable y devolver atributo nombre
            Ciudad ciudad = ciudades -> buscar(i);
            cout << i << ". " << ciudad.getNombre() << endl;
        }
    }

    //2. Partidos legalmente reconocidos.
    void mostrarPartidos(Lista < Partido > * partidos) {
        for (int i = 0; i < partidos -> getTam(); i++) {
            //Guardar el partido buscado y devolver el atributo nombre y representante Legal
            Partido partido = partidos -> buscar(i);
            cout << i << ". " << partido.getNombre() << " /--/ Representante Legal = " << partido.getRepresentanteLegal() << endl;
        }
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

    //4. Todos los candidatos a la alcald�a de una ciudad.

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

    //5. Candidatos a cada una de las alcald�as, por partido.
    //6. Candidatos a cada uno de los concejos, por partido.

    void candidatosAlcaldiaConsejoPartido(string puesto, Lista < Candidato > * candidatos, Lista<Partido>* partidos) {
        int cantidad = 0, Opcion;
        
        cout<<"Seleccione el partido"<<endl;
        //Se muestra la lista de los partidos existentes a seleccionar
        mostrarPartidos(partidos);
        Opcion = leerEntrada(0,partidos->getTam()-1);
        //Se guarda el nombre del partido en una variable local para no repetir el proceso de busqueda
        string nombrePartido = partidos->buscar(Opcion).getNombre();
        
        cout<<"Los siguiente candidatos se van a presentar al puesto "<<puesto<<" del partido politico "<<nombrePartido<<endl;
        for (int i = 0; i < candidatos -> getTam(); i++) {
            //Guardar el candidato buscado y devolver los atributos necesarios dada la validacion
            Candidato candidato = candidatos -> buscar(i);
            if (candidato.getPartido().getNombre() == nombrePartido && candidato.getPuesto() == puesto) {
                cout << candidato.getNombre() <<" "<<candidato.getNumIdentificacion()<<endl;
                cantidad++;
            }
        }

        if (cantidad == 0) {
            cout << "Este partido no tiene candidatos para esta categoria, verifique el ingreso" << endl;
        }

        system("Pause"); // Pausa el programa y espera a que se presione una tecla
    }

    //7. Por cada partido, la lista de candidatos a los consejos.
    //8. Por cada partido, la lista de candidatos a las alcald�as.
    void candidatosAlcaldiaConsejoPartidoLista(string cargo, Lista < Candidato > * candidatos, Lista < Partido > * partidos) {
        for (int j = 0; j < partidos->getTam(); j++) {
            cout << "Lista de nombres de candidatos del partido " + partidos -> buscar(j).getNombre() + " para el cargo " + cargo << endl;
            Partido partido = partidos -> buscar(j);
            for (int i = 0; i < candidatos->getTam(); i++) {
                //Guardar el candidato y devolver los atributos necesarios dada la validacion
                Candidato candidato = candidatos -> buscar(i);
                //Recorre el candidato y el partido
                if (candidato.getPartido().getNombre() == partido.getNombre() && candidato.getPuesto() == cargo) {
                    cout << candidatos -> buscar(i).getNombre() << endl;
                }
            }
        }
        system("Pause"); // Pausa el programa y espera a que se presione una tecla
    }

};
