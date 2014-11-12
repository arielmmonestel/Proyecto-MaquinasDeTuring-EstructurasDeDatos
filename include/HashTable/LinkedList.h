#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "HashNode.h"
#include <stdexcept>
using namespace std;

template <typename Key, typename E>
class LinkedList
{
    private:
        HashNode<Key, E>* head;
        HashNode<Key, E>* tail;
        HashNode<Key, E>* current;
        int size;
        HashNode<Key, E>* searchPrevious(HashNode<Key, E>* pNode) {
            if (current == head) {
                return NULL;
            }
            HashNode<Key, E> *res = head;
            while (res->next != current) {
                res = res->next;
            }
            return res;
        }
    public:
        LinkedList() {
            head = tail = current = new HashNode<Key, E>();
            size = 0;
        }
        ~LinkedList() {
            clear();
            delete head;
        }
        void insert(Key pKey, E pElement) {
            current->next = new HashNode<Key, E>(pKey, pElement, current->next);
            if (current == tail) {
                tail = tail->next;
            }
            size++;
        }
        void append(Key pKey, E pElement) {
            tail->next = new HashNode<Key, E>(pKey, pElement);
            tail = tail->next;
            size++;
        }
        E remove() throw(runtime_error) {
            if (current->next == NULL) {
                throw runtime_error("No element to remove.");
            }
            E result = current->next->element;
            HashNode<Key, E> *temp = current->next;
            current->next = current->next->next;
            delete temp;
            size--;
            return result;
        }
        void clear() {
            current = head;
            while (head != NULL) {
                head = head->next;
                delete current;
                current = head;
            }
            head = tail = current = new HashNode<Key, E>();
            size = 0;
        }
        E getElement() throw(runtime_error) {
            if (current->next == NULL) {
                throw runtime_error("No element to get.");
            }
            return current->next->element;
        }
        void setElement(E pElement) throw(runtime_error) {
            if (current->next == NULL) {
                throw runtime_error("No key-element to set.");
            }
            current->next->element = pElement;
        }
        Key getKey() throw(runtime_error) {
            if (current->next == NULL) {
                throw runtime_error("No key to get.");
            }
            return current->next->key;
        }
        void goToStart() {
            current = head;
        }
        void goToEnd() {
            current = tail;
        }
        void goToPos(int nPos) throw(runtime_error) {
            if ((nPos < 0) || (nPos > size)) {
                throw runtime_error("Index out of bounds");
            }
            current = head;
            for (int i = 0; i < nPos; i++) {
                current = current->next;
            }
        }
        void previous() {
            if (current != head) {
                current = searchPrevious(current);
            }
        }
        void next() {
            if (current != tail) {
                current = current->next;
            }
        }
        int getPos() {
            int pos = 0;
            HashNode<Key, E>* temp = head;
            while (temp != current) {
                pos++;
                temp = temp->next;
            }
            return pos;
        }
        int getSize() {
            return size;
        }
        E find(Key pKey) {
            for (goToStart(); getPos() < getSize(); next()) {
                // esta línea asume que la clase que se compara
                // sobreescribe el operador de igualdad
                if (pKey == getKey()) {
                    return getElement();
                }
            }
            return NULL;
        }
        bool containsKey(Key pKey) {
            for (goToStart(); getPos() < getSize(); next()) {
                if (pKey == getKey()) {
                    return true;
                }
            }
            return false;
        }

        //se ejecuta next() hasta que getKey() != pKey no se cumpla
        void moveToNode(Key pKey){

            for(goToStart(); getKey() != pKey; next());

        }
};

#endif // LINKEDLIST_H
