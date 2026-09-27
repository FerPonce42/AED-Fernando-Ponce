#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

/*
PROBLEMA:

Dado un vector de enteros, construye una lista enlazada que
contenga únicamente los valores que aparecen EXACTAMENTE UNA VEZ.

VECTOR:
4 7 2 7 9 4 1

LISTA ESPERADA:
2 -> 9 -> 1

RESTRICCIONES:
- No utilices set.
- No utilices map.
- Debes construir la lista con nodos.

FUNCIÓN A IMPLEMENTAR:
resolver(...)

La impresión ya está disponible.
*/

Node* resolver(const vector<int>& datos)
{
    // TU CÓDIGO
    return nullptr;
}

void imprimir(Node* head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
