#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

/*
PROBLEMA:

Dada una lista simplemente enlazada y X, separa los elementos
en dos grupos utilizando una queue auxiliar:

- primero los menores que X
- después los mayores o iguales que X

EJEMPLO:

LISTA:
7 -> 2 -> 9 -> 4 -> 1

X = 5

RESULTADO:
2 -> 4 -> 7 -> 9 -> 1

RESTRICCIÓN:
La estructura auxiliar permitida es una std::queue.

FUNCIÓN:
resolver(...)
*/

void resolver(Node*& head, int x)
{
    // TU CÓDIGO
}
