#include <cstddef>
#ifndef PILADINAMICA_H
#define PILADINAMICA_H

template <typename T>
class Pila {
    private:
        struct nodoPila {
            T clave;
            struct nodoPila *siguiente;
        };
        struct nodoPila *cabeza, *z;
    public:
        Pila() {
            cabeza = new nodoPila;
            z = new nodoPila;
            cabeza->siguiente = z;
            z->siguiente = z;
        }
        ~Pila() {
            struct nodoPila *t = cabeza;
            while (t != z) {
                cabeza = t;
                t = t->siguiente;
                delete cabeza;
            }
        }
        void meter(T V) {
            struct nodoPila *t = new nodoPila;
            t->clave = V;
            t->siguiente = cabeza->siguiente;
            cabeza->siguiente = t;
        }
        T sacar() {
            T x;
            struct nodoPila *t = cabeza->siguiente;
            cabeza->siguiente = t->siguiente;
            x = t->clave;
            delete t;
            return x;
        }
        int vacia() {
            return cabeza->siguiente == z;
        }
        
        bool estaVacia(){
            return vacia();
        }
        
        
};

#endif
