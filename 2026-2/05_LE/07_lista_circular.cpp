#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int x) : data(x), next(nullptr) {}
};

/*
PROBLEMA:

Tienes una lista simplemente enlazada circular y ordenada.

Implementa:

ADD(X)
DEL(X)

La lista debe conservar su orden después de cada operación.

EJEMPLO:

LISTA:
2 -> 5 -> 8 -> 12 -> vuelve a 2

ADD(7)

DEBE QUEDAR:
2 -> 5 -> 7 -> 8 -> 12 -> vuelve a 2

CONSIDERA:
- lista vacía
- un solo nodo
- insertar antes del primero
- insertar al final
- eliminar primero
- eliminar último
- eliminar inexistente
*/

void add(Node*& head, int x)
{
    // TU CÓDIGO
}

void del(Node*& head, int x)
{
    // TU CÓDIGO
}
