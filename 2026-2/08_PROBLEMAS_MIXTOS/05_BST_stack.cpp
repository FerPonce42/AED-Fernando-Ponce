#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

/*
PROBLEMA:

Imprime los elementos de un BST en orden DESCENDENTE.

RESTRICCIONES:
- No puedes utilizar recursividad.
- Debes utilizar std::stack.
- No puedes ordenar los datos previamente.

BST:

        8
       / \
      3   12
     / \    \
    1   5    15

SALIDA:
15 12 8 5 3 1

FUNCIÓN:
reverseInorder(...)
*/

void reverseInorder(Node* root)
{
    // TU CÓDIGO
}
