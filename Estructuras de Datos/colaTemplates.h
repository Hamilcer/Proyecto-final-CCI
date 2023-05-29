#ifndef COLATEMPLATES_H
#define COLATEMPLATES_H

template < class T >
  class Cola {
    private: struct nodo {
      T dato;
      nodo * der, * izq;

      nodo();
      nodo(T dato);
    };

    nodo * cab,
    * fin;

    public: Cola();
    ~Cola();
    bool isVacia();
    void enqueue(T nuevo);
    T dequeue();
  };

template < class T >
  Cola < T > ::nodo::nodo(T dato) {
    this -> dato = dato;
    der = izq = NULL;
  };

template < class T >
  Cola < T > ::nodo::nodo() {
    der = izq = NULL;
  };

template < class T >
  Cola < T > ::Cola() {
    cab = new nodo;
    fin = new nodo;

    cab -> der = fin;
    fin -> izq = cab;
  }

template < class T >
  Cola < T > ::~Cola() {
    nodo * aux = cab;
    while (aux -> der != NULL) {
      aux = aux -> der;
      delete aux -> izq;
    }
    delete fin;
  }

template < class T >
  bool Cola < T > ::isVacia() {
    return cab -> der == fin;
  }

template < class T >
  void Cola < T > ::enqueue(T nuevo) {

    nodo * nuevoNodo = new nodo(nuevo);

    nuevoNodo -> der = fin;
    nuevoNodo -> izq = fin -> izq;
    fin -> izq -> der = nuevoNodo;
    fin -> izq = nuevoNodo;
  }

template < class T >
  T Cola < T > ::dequeue() {
    T dato;

    if (this -> isVacia()) {
      return dato;
    }

    nodo * extraccion = cab -> der;
    cab -> der = extraccion -> der;
    extraccion -> der -> izq = cab;
    dato = extraccion -> dato;
    delete extraccion;

    return dato;
  }

#endif