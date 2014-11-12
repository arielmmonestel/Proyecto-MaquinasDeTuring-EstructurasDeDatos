#ifndef BSTNODE_H
#define BSTNODE_H
#include <stdexcept>

using namespace std;

template <typename Key, typename E>
class BSTNode
{
private:
    Key key;
    E element;
    BSTNode<Key, E>* left;
    BSTNode<Key, E>* right;
public:
    BSTNode(BSTNode<Key, E>* pLeft = NULL, BSTNode<Key, E>* pRight = NULL) {
        left = pLeft;
        right = pRight;
    }
    BSTNode(Key pKey, E pElement, BSTNode<Key, E>* pLeft = NULL, BSTNode<Key, E>* pRight = NULL) {
        key = pKey;
        element = pElement;
        left = pLeft;
        right = pRight;
    }
    ~BSTNode() {}
    // Retorna el elemento del nodo
    E getElement() {
        return element;
    }
    // Asigna un nuevo valor al elemento
    void setElement(E pElement) {
        element = pElement;
    }
    // Retorna la llave del nodo
    Key getKey() {
        return key;
    }
    // Asigna un nuevo valor a la llave
    void setKey(Key pKey) {
        key = pKey;
    }
    // Retorna un puntero al hijo izquierdo
    BSTNode<Key, E>* getLeft() {
        return left;
    }
    // Asigna un nuevo valor al hijo izquierdo
    void setLeft(BSTNode<Key, E>* pLeft) {
        left = pLeft;
    }
    // Retorna un puntero al hijo derecho
    BSTNode<Key, E>* getRight() {
        return right;
    }
    // Asigna un nuevo valor al hijo derecho
    void setRight(BSTNode<Key, E>* pRight) {
        right = pRight;
    }
    // Retorna true si el nodo es una hoja
    bool isLeaf() {
        return (left == NULL) && (right == NULL);
    }
    // Retorna la cantidad de hijos del nodo
    int childrenCount() {
        return (left == NULL? 0 : 1) + (right == NULL? 0 : 1);
    }
    // Retorna un puntero al único hijo del nodo
    BSTNode<Key, E>* getUniqueChild() {
        return (left == NULL? right : left);
    }
    // Función auxiliar de getSuccessor()
    BSTNode<Key, E>* getSuccessorAux(BSTNode<Key, E>* pRoot) {
        if (pRoot == NULL) {
            return NULL;
        }
        if (pRoot->left == NULL) {
            return pRoot;
        } else {
            return getSuccessorAux(pRoot->left);
        }
    }
    // Retorna un puntero al nodo menor en el subárbol derecho
    BSTNode<Key, E>* getSuccessor() {
        return getSuccessorAux(right);
    }

    // Retorna el nodo a la llave indicada.
    // Lanza excepción si no lo encuentra.
    BSTNode<Key, E>* findChildNode(Key pKey) throw (runtime_error) {
        if(this == NULL) {
            throw runtime_error("Key not found.");
        }
        if (pKey < this->getKey()) {
            return this->getLeft()->findChildNode(pKey);
        }
        if (pKey > this->getKey()) {
            return this->getRight()->findChildNode(pKey);
        } else {
            return this;
        }
    }
};

#endif // BSTNODE_H
