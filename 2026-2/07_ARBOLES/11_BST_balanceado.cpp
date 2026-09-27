#include <iostream>
#include <vector>
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

Recibes un vector de enteros ORDENADO.

Construye un BST utilizando todos sus elementos intentando
minimizar la cantidad de niveles.

VECTOR:
1 2 3 4 5 6 7

Una raíz central produce un árbol con menor altura que insertar
los elementos de izquierda a derecha.

FUNCIÓN A IMPLEMENTAR:
construir(...)

OBJETIVO:
Entender cómo la elección de la raíz afecta la altura del BST.
*/

Node* construir(const vector<int>& datos, int inicio, int fin)
{
    // TU CÓDIGO
    return nullptr;
}
