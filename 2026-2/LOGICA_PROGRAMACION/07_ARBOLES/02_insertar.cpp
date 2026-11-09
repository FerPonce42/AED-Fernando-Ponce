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

Implementa insertar en un BST.

REGLA:
menores -> izquierda
mayores -> derecha

ASUME:
- No existen duplicados.

INSERTAR:
8, 3, 12, 1, 5, 15

DEBE GENERAR:

        8
       / \
      3   12
     / \    \
    1   5    15
*/

void insertar(Node*& root, int x)
{
    // TU CÓDIGO
}

int main()
{
    Node* root = nullptr;

    insertar(root, 8);
    insertar(root, 3);
    insertar(root, 12);
    insertar(root, 1);
    insertar(root, 5);
    insertar(root, 15);

    return 0;
}
