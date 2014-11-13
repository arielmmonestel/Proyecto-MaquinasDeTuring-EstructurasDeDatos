#ifndef GRAFO_H
#define GRAFO_H
#include "HashTable/HashTable.h"

class Grafo
{
    public:
        //Constructor del objeto grafo
        //Entradas: -
        //Salida: Lista de Adyacencia
        //Restricciones: -
        Grafo() {

            HashTable<string,HashTable<string,transicion>> listaAdyacencia;




        }
        virtual ~Grafo() {}
    protected:
    private:



};

#endif // GRAFO_H
