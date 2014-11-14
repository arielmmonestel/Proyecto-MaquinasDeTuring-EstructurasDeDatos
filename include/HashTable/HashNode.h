#ifndef HASHNODE_H
#define HASHNODE_H
#include "../MaquinaTuring/Transicion.h"
template <typename Key, typename E>
class HashNode
{
public:
    Key key;
    E element;
    HashNode<Key, E>* next;
    HashNode(Key pKey, E pElement, HashNode<Key, E>* pNext = NULL) {
        key = pKey;
        element = pElement;
        next = pNext;
    }
    HashNode(HashNode<Key, E>* pNext = NULL) {
        next = pNext;
    }
};

#endif // HASHNODE_H
