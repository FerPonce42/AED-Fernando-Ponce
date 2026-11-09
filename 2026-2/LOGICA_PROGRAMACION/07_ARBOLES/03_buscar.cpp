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

Implementa la búsqueda de X en un BST.

RESTRICCIÓN:
Aprovecha la propiedad del BST.
No recorras innecesariamente ambos subárboles.
*/

bool buscar(Node* root, int x)
{
    // TU CÓDIGO
    return false;
}

int main()
{
    // Árbol de prueba:
    //        8
    //       / \
    //      3   12
    //     / \    \
    //    1   5    15

    return 0;
}
