#include <iostream>
#include "include\GraficadorTuring.h"
#include <sstream>

using namespace std;

int main()
{
    int cant = 7;
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
    return 0;
}
