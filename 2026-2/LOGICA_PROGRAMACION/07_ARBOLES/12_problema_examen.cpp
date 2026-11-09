#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

/*
PROBLEMA ESTILO EXAMEN:

Dado un BST, elimina todos los valores menores que X.

Debes mantener la propiedad del BST.

EJEMPLO:

BST:
        8
       / \
      3   12
     / \    \
    1   5    15

X = 5

Los valores menores que 5 deben desaparecer.

DESPUÉS:
el árbol debe contener únicamente valores >= 5.

RESTRICCIÓN:
Aprovecha las propiedades del BST para evitar recorridos
innecesarios.

FUNCIÓN A IMPLEMENTAR:
eliminarMenores(...)
*/

void eliminarMenores(Node*& root, int x)
{
    // TU CÓDIGO
}
