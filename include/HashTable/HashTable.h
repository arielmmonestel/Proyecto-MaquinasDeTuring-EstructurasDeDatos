#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "HashNode.h"
#include "LinkedList.h"
#include <stdexcept>
#include <math.h>
#include <cstdlib>

using namespace std;

template <typename Key, typename E>
class HashTable
{
private:
    int maxSize;
    int size;
    LinkedList<Key, E>* elements;

    // Función hash
    int h(Key pKey) {

        return compress(hashCodePolynomial(pKey));
    }

    // Genera un código hash polinomial con constante de 33
    template <typename T>
    int hashCodePolynomial(T pKey) {
        int a = 33;
        int result = 0;

        int exponente = 0;

        while(pKey > 0){
            int numPosicional = pKey % 10;
            //pKey = pKey / 10,
            pKey /= 10;
            result += numPosicional * pow(a,exponente);
            exponente++;
        }

        return result;
    }

    int hashCodePolynomial(string pKey) {
        int a = 33;
        int result = 0;

        //cout << pKey << ": ";

        int exponente = 0;

        for(unsigned int i = 0; i < pKey.length(); i++){
            int numPosicional = (int)pKey.at(i);
            result += numPosicional * pow(a,i);
        }

        return result;
    }
    // Gemera un código hash con corrimiento cíclico con corrimientos
    // de 7 hacia la izquierda y 25 a la derecha. Usa XOR para unir
    // los bits.
    template <typename T>
    int hashCodeCyclicShift(T pKey) {
        int result = 0;
        char* bytes = reinterpret_cast<char*>(&pKey);
        for (unsigned int i = 0; i < sizeof(pKey); i++) {
            result = (result << (7)) ^ (result >> (25));
            result += (int) bytes[i];
        }
        return result;
    }
    // Caso especial de la misma función para strings
    int hashCodeCyclicShift(string pKey) {
        int result = 0;
        for (unsigned int i = 0; i < pKey.length(); i++) {
            result = (result << (7)) ^ (result >> (25));
            result += (int) pKey.at(i);
        }
        return result;
    }
    // Función de compresión por multiplicación, suma y división
    int compress(int pHashCode) {

        int res = 0;

        int a = 1097;
        int b = 1279;
        //int N = 547;

        res = abs(a*pHashCode+b) % maxSize;
        //cout <<"compress: " << res << endl;
        return res;

    }
    // Función que dibuja los bits de un entero, para propósitos
    // de prueba
    void printBits(int n) {
        int value = n;
        string result = "";
        for (int i = 0; i < 32; i++) {
            result = (value % 2? "o" : "_") + result;
            value = value / 2;
        }
        cout << result << endl;
    }



public:
    HashTable(int pMaxSize = 1024) {
        maxSize = pMaxSize;
        elements = new LinkedList<Key,E>[maxSize];
        size = 0;
        //cout << ">>>>>>>>>>>>>>>>>>>>>>>> index: " << maxSize << endl;
    }
    ~HashTable() {
        delete [] elements;
    }
    // Retorna true si la llave indicada se encuentra
    // en la tabla hash.
    bool containsKey(Key pKey) {
        return elements[h(pKey)].containsKey(pKey);
    }
    // Inserta un nuevo par llave valor.
    // Lanza excepción si la llave ya se encuentra en
    // la tabla hash.
    void put(Key pKey, E pElement) throw(runtime_error) {
        int index = h(pKey);
        //cout << endl << "----- key: " << pKey  << ", index put: " << index << ", max size: " << maxSize << endl;
        if (elements[index].containsKey(pKey)) {
            throw runtime_error("Key already exists.");
        }

        elements[index].append(pKey,pElement);
        size++;
    }
    // Actualiza el elemento asociado a la llave indicada.
    // Lanza excepción si la llave no se encuentra.
    void set(Key pKey, E pElement) throw(runtime_error) {
        int index = h(pKey);
        //cout<< "hola";
        if (!(elements[index].containsKey(pKey))) {
            throw runtime_error("Key not found.");
        }

        elements[index].moveToNode(pKey);

        elements[index].setElement(pElement);

    }
    // Retorna el elemento asociado a la llave indicada.
    // Lanza excepción si la llave no se encuentra.
    E get(Key pKey) throw(runtime_error) {
        int index = h(pKey);
        if (!(elements[index].containsKey(pKey))) {
            throw runtime_error("Key not found.");
        }
        //cout << "get ********************> " << pKey << ", index: " << index <<endl;
        elements[index].moveToNode(pKey);
        return elements[index].getElement();
    }
    // Elimina el nodo con la llave indicada.
    // Lanza excepción si la llave no se encuentra.
    E remove(Key pKey) throw(runtime_error) {
        int index = h(pKey);
        if (!(elements[index].containsKey(pKey))) {
            throw runtime_error("Key not found.");
        }
        elements[index].moveToNode(pKey);
        E res = elements[index].remove();
        size--;
        return res;
    }
    // Retorna la cantidad de nodos en la tabla hash.
    int getSize() {
        return size;
    }

    // Retorna la cantidad de nodos en la tabla hash.
    int getMaxSize() {
        return maxSize;
    }
};

#endif // HASHTABLE_H
