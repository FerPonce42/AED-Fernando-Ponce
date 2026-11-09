#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

/*
PROBLEMA:

Dado un BST, un valor X y K, imprime los K valores del árbol
más cercanos a X.

EJEMPLO:

Valores del BST:
1 3 5 8 12 15

X = 10
K = 3

Los candidatos más cercanos deben ser determinados por distancia
absoluta respecto de X.

RESTRICCIÓN:
Debes aprovechar la estructura del BST.

NOTA:
El orden exacto de impresión será definido por tu solución;
lo importante es seleccionar correctamente los K vecinos.
*/

void kneighbors(Node* root, int x, int k)
{
    // TU CÓDIGO
}
