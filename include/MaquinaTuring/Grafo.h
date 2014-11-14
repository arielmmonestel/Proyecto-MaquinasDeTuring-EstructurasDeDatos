#ifndef GRAFO_H
#define GRAFO_H
#include "HashTable/HashTable.h"
#include "Transicion.h"
#include "FileManager.h"
#include <iostream>
#include <fstream>

class Grafo: public FileManager
{
    private:
        HashTable<string,HashTable<char,Transicion>*>* listaAdyacencia;



        int tamSimbolosMaquina;
        char* simbolosMaquina;

        int tamSimbolosEntrada;
        char* simbolosEntrada;

        int tamEstadosAceptacion;
        string* estadosAceptacion;

        int tamEstadosRechazo;
        string* estadosRechazo;

        string estadoInicial;
        int tamAristas;

        int tamVertices;
        string* estados;

        bool Init(string pNombreArchivo){

            bool res = true;

            ifstream archivo(pNombreArchivo);

            res &= archivo.is_open();

            cout<< endl << "res open:  " << res << endl;

            string linea;
            if(res)
            {
                while(archivo.good()){
                    getline(archivo,linea);
                    char firstLeter = toupper(linea[0]);
                    linea = linea.substr(2,linea.size());
                    int arraySize;

                    string* lineas = StringSplit(',', linea, &arraySize);

                    switch(firstLeter){
                        case 'Q':

                            cout << endl << endl << "Estados" << endl;
                            estados = lineas;

                            tamVertices = arraySize;


                            for(int index = 0; index < arraySize; index++){
                                setEstado(estados[index]);

                                res &= !estados[index].empty();

                                cout << estados[index] << ", ";
                            }
                            break;

                        case 'S':

                            cout << endl << endl << "Simbolos de entrada" << endl;
                            tamSimbolosEntrada = arraySize;
                            simbolosEntrada = new char[arraySize];
                            for(int index = 0; index < arraySize; index++){
                                simbolosEntrada = lineas[index][0];
                                res &= !lineas[index].empty();
                                cout << lineas[index] << ", ";
                            }
                            delete[] lineas;
                            break;

                        case 'G':

                            cout << endl << endl << "Simbolos de maquina" << endl;
                            tamSimbolosMaquina = arraySize;
                            simbolosMaquina = new char[arraySize];
                            for(int index = 0; index < arraySize; index++){
                                simbolosMaquina = lineas[index][0];
                                res &= !lineas[index].empty();
                                cout << lineas[index] << ", ";
                            }
                            delete[] lineas;
                            break;

                        case 'T':

                            tamAristas = arraySize;
                            setTransicion(lineas[0], lineas[1][0], lineas[2], lineas[3][0], lineas[4][0]);

                            cout << endl << endl << "transicion" << endl;
                            for(int index = 0; index < arraySize; index++){
                                res &= !lineas[index].empty();
                                cout << lineas[index] << ", ";
                            }
                            delete[] lineas;

                            break;

                        case 'F':

                            cout << endl << endl << "estados aceptacion" << endl;
                            tamEstadosAceptacion = arraySize;
                            estadosAceptacion = lineas;
                            for(int index = 0; index < arraySize; index++){

                                res &= !lineas[index].empty();
                                cout << lineas[index] << ", ";
                            }
                            break;

                        case 'R':

                            cout << endl << endl << "estados rechazo" << endl;
                            tamEstadosRechazo = arraySize;
                            estadosRechazo = lineas;
                            for(int index = 0; index < arraySize; index++){

                                res &= !lineas[index].empty();
                                cout << lineas[index] << ", ";
                            }
                            break;

                        case 'I':

                            cout << endl << endl << "estado inicial" << endl;
                            estadoInicial = lineas[0];
                            res &= !lineas[0].empty();
                            cout << lineas[0] << ", ";
                            break;

                        case 'B':
                            break;

                        default:
                            cout << endl << endl << "MALO: " << linea << endl;
                            res &= false;
                            break;



                        }


                }

            }
            return res;
        }

        void setEstado(string pNombreEstado){

            HashTable<char,Transicion>* aristas = new HashTable<char,Transicion>();

            listaAdyacencia->put(pNombreEstado,  aristas);
        }

        void setTransicion(string pNombreEstado, char pSimboloLeido, string pSiguienteEstado, char pSimboloAPoner, char pDireccion){

            HashTable<char,Transicion>* tempAristasHash;


            try{
                tempAristasHash = listaAdyacencia->get(pNombreEstado);

            }catch(runtime_error){
                cout << "no se ha ingresado ningun elemento con esa llave";
                return;
            }
            Transicion transicion(pSiguienteEstado, pSimboloAPoner, pDireccion);
            //cout<< endl << "bucket: " << pNombreEstado << endl;
            tempAristasHash->put(pSimboloLeido, transicion);


        }
    //protected:

    public:

        //Constructor del objeto grafo
        //Entradas: -
        //Salida: Lista de Adyacencia
        //Restricciones: -
        Grafo(string pNombreArchivo) throw(runtime_error) {

            listaAdyacencia = new HashTable<string,HashTable<char,Transicion>*>();

            bool isCorrectInit = Init(pNombreArchivo);

            if(!isCorrectInit)
            {
                throw runtime_error("bad file");
            }


        }
            //cout << line << endl;

        bool existeEnSimboloEntrada(char pCaracter){
            bool res = false;

            for(int index = 0; index < tamSimbolosEntrada; index++){

                res |= simbolosEntrada[index] == pCaracter;

            }
            return res;

        }

        bool esEntradaValida(string pEntrada){
            bool res = false;

            for(int index = 0; index < pEntrada; index++){
                res |= existeEnSimboloEntrada(pEntrada[index]);
            }

            return res;

        }



        virtual ~Grafo() {}





};

#endif // GRAFO_H
