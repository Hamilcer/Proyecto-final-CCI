#ifndef Multilista_h
#define Multilista_h

#include <iostream>

using namespace std;

struct InfoCandidato
{
    Candidato candidato;

    // Posiciones de lista
    int sigNumID;   // numero de identificacion
    int sigPuesto;  // Puesto a l que aspira
    int sigCuidad;  // Ciudad donde participa
    int sigPartido; // partido al que pertenece
};

struct Cabeceras
{
    string nLista; // nombre de la lista
    int pos;       // posición de la cabeza
};

class Multilista1
{
    InfoCandidato *Multi;
    Cabeceras *cab; // Es el arreglo de cabeceras
    int fin;
    int numListas;

public:
    Multilista1(int numElementos, int numListas)
    {
        Multi = new InfoCandidato[numElementos + 1];
        cab = new Cabeceras[numListas]; // numListas cuantas cabeceras de lista vamos a tener
        fin = 0;
        this->numListas = numListas;

        // Inicializar las cabeceras
        cab[0] = {"numID", 0};
        cab[1] = {"Alcalde", 0};
        cab[2] = {"Consejo", 0};
        cab[3] = {"Bogota", 0};
        cab[4] = {"Villavicencio", 0};
        cab[5] = {"Barranquilla", 0};
        cab[6] = {"Liberal", 0};
        cab[7] = {"Conservador", 0};
        cab[8] = {"CentroDemocratico", 0};
        cab[9] = {"ColombiaHumana", 0};
    }

    bool multilista_vacia();
    void insertar(Candidato nuevo);

    void imprimir(string categoria1,string categoria2);

    //~Multilista1();
};

// funcion para verificar si esta vacia
bool Multilista1::multilista_vacia()
{
    if (fin == 0)
    {
        return true;
    }
    return false;
}

// funcion para insertar a la multilista
void Multilista1::insertar(Candidato cNuevo)
{
    fin++;
    InfoCandidato nuevo = {cNuevo};

    /*
        numero identificacion se agrega al final
    */

    if (fin == 1) // Comprueba si es el primero
    {
        cab[0].pos = fin;
        nuevo.sigNumID = 0;
    }
    else
    {
        int posNumID = cab[0].pos;
        while (Multi[posNumID].sigNumID != 0)
        {
            posNumID = Multi[posNumID].sigNumID;
        }

        Multi[posNumID].sigNumID = fin;
        nuevo.sigNumID = 0;
    }

    // Puesto se agrega al final
    int posPuesto = (nuevo.candidato.getPuesto() == "Alcalde") ? 1 : 2;

    if (cab[posPuesto].pos == 0)
    {
        cab[posPuesto].pos = fin;
        nuevo.sigPuesto = 0;
    }
    else
    {
        int i = cab[posPuesto].pos;
        while (Multi[i].sigPuesto != 0)
        {
            i = Multi[i].sigPuesto;
        }
        Multi[i].sigPuesto = fin;
        nuevo.sigPuesto = 0;
    }

    // Ciudad se agrega al final
    int posCiudad;
    for (int i = 0; i < numListas; i++)
    {
        if (nuevo.candidato.getCiudadResidencia().getNombre() == cab[i].nLista)
        {
            posCiudad = i;
            break;
        }
    }

    if (cab[posCiudad].pos == 0)
    {
        cab[posCiudad].pos = fin;
        nuevo.sigPuesto = 0;
    }
    else
    {
        int i = cab[posCiudad].pos;
        while (Multi[i].sigCuidad != 0)
        {
            i = Multi[i].sigCuidad;
        }
        Multi[i].sigCuidad = fin;
        nuevo.sigCuidad = 0;
    }

    // Partido se agrega al final
    int posPartido;
    for (int i = 0; i < numListas; i++)
    {
        if (nuevo.candidato.getPartido().getNombre() == cab[i].nLista)
        {
            posPartido = i;
        }
    }

    if (cab[posPartido].pos == 0)
    {
        cab[posPartido].pos = fin;
        nuevo.sigPuesto = 0;
    }
    else
    {
        int i = cab[posPartido].pos;
        while (Multi[i].sigPartido != 0)
        {
            i = Multi[i].sigPartido;
        }
        Multi[i].sigPartido = fin;
        nuevo.sigPartido = 0;
    }

    Multi[fin] = nuevo;
}

void Multilista1::imprimir(string categoria1 = "", string categoria2 = "" )
{
    int j = 0;
    for (int i = 0; i < numListas; i++)
    {
        if (cab[i].nLista == categoria1)
        {
            j = i;
            break;
        }
    }

    int posAux = cab[j].pos;

    cout << endl
         << categoria1 << ": " << endl;

    if (j == 0)
    {
        while (Multi[posAux].sigNumID != 0)
        {
            cout << Multi[posAux].candidato.toString() << endl;
            posAux = Multi[posAux].sigNumID;
        }
    }
    else if (j == 1 || j == 2)
    {
        while (Multi[posAux].sigPuesto != 0)
        {
            cout << Multi[posAux].candidato.toString() << endl;
            posAux = Multi[posAux].sigPuesto;
        }
    }
    else if (j < 6 && j >2)
    {
        while (Multi[posAux].sigCuidad != 0)
        {
            cout << Multi[posAux].candidato.toString() << endl;
            posAux = Multi[posAux].sigCuidad;
        }
    }
    else if (j < 10 && j >5)
    {
        while (Multi[posAux].sigPartido != 0)
        {
            cout << Multi[posAux].candidato.toString() << endl;
            posAux = Multi[posAux].sigPartido;
        }
    }

    cout << Multi[posAux].candidato.toString() << endl;
}

#endif

/*
    COSAS A TENER EN CUENTA

    -si se agrega una ciudad o partido, las cabeceras NO deberian tener valores estaticos
    - La funcion imprimir solo es para probar, no debe estar aqui
*/