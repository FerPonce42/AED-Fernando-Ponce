#include <iostream>
using namespace std;

/*
PROBLEMA:

Construye manualmente el siguiente árbol binario utilizando
nodos y punteros.

        8
       / \
      3   12
     / \    \
    1   5    15

OBJETIVO:
Practicar la relación:

Node -> left
Node -> right

No existe todavía una clase BST.
*/
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

int main()
{
    // CONSTRUYE EL ÁRBOL AQUÍ.

    return 0;
}
