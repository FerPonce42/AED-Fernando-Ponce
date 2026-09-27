#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;

    Node(int x) : data(x), prev(nullptr), next(nullptr) {}
};

struct Lista
{
    Node* head;
    Node* tail;

    Lista() : head(nullptr), tail(nullptr) {}
};

/*
PROBLEMA:

Dada una lista doblemente enlazada y un nodo pivote:

- Los valores menores que pivot->data deben quedar antes.
- El pivote debe quedar en el centro.
- Los valores mayores deben quedar después.
- Debes conservar los nodos existentes.
- head y tail deben quedar correctamente actualizados.

EJEMPLO:

ANTES:
7 <-> 2 <-> 9 <-> 4 <-> 6

PIVOTE:
4

UNA SALIDA VÁLIDA:
2 <-> 4 <-> 7 <-> 9 <-> 6

La posición relativa entre elementos del mismo grupo no es
el objetivo principal.

RESTRICCIÓN:
No crear una segunda lista de nodos.
*/

void split_list(Lista& lista, Node* pivot)
{
    // TU CÓDIGO
}
