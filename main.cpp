#include "Simulacion.cpp"
#include <locale.h>
#include <iostream>

int main() {
    setlocale(LC_ALL, "Spanish");
    cout << "Inicializando .." << endl;
    Simulacion simulacion;
    
    simulacion.Menu();
    
    return 0;
}

