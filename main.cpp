#include <iostream>
#include <sstream>
#include "GraficadorTuring.h"
#include "MaquinaTuring/Grafo.h"


using namespace std;

int main()
{

    Grafo maquinaTuring("C:/turing.txt");

    int cant = 5;

    /*
    GraficadorTuring g(800, 650, cant);
    for (int i = 0; i < cant; i++) {
        stringstream str;
        str << "lol" << i;
        g.asignarNombreEstado(i, str.str());
    }
    for (int i = 0; i < cant; i++) {
        for (int j = 0; j < cant; j++) {
            g.asignarTransicion(i, j, "wut");
        }
    }
    g.dibujarEstados();
    getch();
    return 0;*/
}


// will baje esto no pesa mucho:
//http://www.juegosparawindows.com/assassins-creed-unity-multilenguaje-espanol-pc
