#ifndef GRAFO_H
#define GRAFO_H
#include "HashTable/HashTable.h"
#include "Transicion.h"
#include "FileManager.h"


class Grafo: public FileManager
{
    private:
        HashTable<string,HashTable<char,Transicion>*>* listaAdyacencia;
        string* simbolosMaquina;

        int tamAristas;
        int tamVertices;
    //protected:

    public:
        //Constructor del objeto grafo
        //Entradas: -
        //Salida: Lista de Adyacencia
        //Restricciones: -
        Grafo(string pNombreArchivo) {


            ifstream file(pNombreArchivo);
            string* arraydeString = FileManager::StringSplit(',', line);
            for(int index = 0; index < 5; index++){
                cout << arraydeString[index] << endl;
            }
            /*
            while(file.good()){
                getline(file,line);
                cout << line << endl;
            }*/
            //cout << line << endl;


            listaAdyacencia = new HashTable<string,HashTable<char,Transicion>*>(pTamVertices);
            tamAristas = pTamAristas;



        }

        void setEstado(string pNombreEstado){


            listaAdyacencia->put(pNombreEstado, new HashTable<char,Transicion>(tamAristas) );
        }

        void setTransicion(string pNombreEstado, string pSiguienteEstado, char pSimboloAPoner, char pDireccion){

            HashTable<char,Transicion>* tempAristasHash;

            try{
                tempAristasHash = listaAdyacencia->get(pNombreEstado);

            }catch(runtime_error){
                cout << "no se ha ingresado ningun elemento con esa llave";
                return;
            }
            Transicion transicion(pSiguienteEstado, pSimboloAPoner, pDireccion);

            tempAristasHash->put(pSimboloAPoner, transicion);
            delete tempAristasHash;

        }


        virtual ~Grafo() {}





};

#endif // GRAFO_H
