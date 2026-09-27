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

Dado un BST y dos valores MIN y MAX, imprime en orden ascendente
todos los valores dentro del rango [MIN, MAX].

ÁRBOL:

        8
       / \
      3   12
     / \    \
    1   5    15

MIN = 4
MAX = 13

DEBE IMPRIMIR:
5 8 12

RESTRICCIÓN:
No recorras ramas que sabes que no pueden contener valores
pertenecientes al rango.

FUNCIÓN A IMPLEMENTAR:
printRange(...)
*/

void printRange(Node* root, int min, int max)
{
    // TU CÓDIGO
}
