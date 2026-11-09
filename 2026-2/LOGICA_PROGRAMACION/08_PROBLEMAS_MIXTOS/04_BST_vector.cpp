#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

/*
PROBLEMA:

Dado un vector de enteros, construye un BST insertando sus
elementos en el orden recibido.

Después, dado X, devuelve cuántos valores del BST son menores
que X.

VECTOR:
8 3 12 1 5 15

X = 8

RESULTADO:
3

Porque:
1, 3, 5 son menores que 8.

FUNCIÓN A IMPLEMENTAR:
contarMenores(...)

La construcción del BST se encuentra proporcionada.
*/

int contarMenores(Node* root, int x)
{
    // TU CÓDIGO
    return 0;
}
