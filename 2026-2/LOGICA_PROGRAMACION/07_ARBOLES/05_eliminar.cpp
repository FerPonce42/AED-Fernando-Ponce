#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

/*
PROBLEMA:

Implementa la eliminación de X en un BST.

DEBES CONSIDERAR:
1. X no existe.
2. Nodo hoja.
3. Nodo con un hijo.
4. Nodo con dos hijos.
5. X es la raíz.

Después de eliminar, el árbol debe seguir siendo un BST.

FUNCIÓN A IMPLEMENTAR:
eliminar(...)
*/

void eliminar(Node*& root, int x)
{
    // TU CÓDIGO
}
