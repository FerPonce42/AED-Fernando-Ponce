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

Implementa:

- inorder
- preorder
- postorder
- reverse inorder

Todos deben ser recursivos.

ÁRBOL:

        8
       / \
      3   12
     / \    \
    1   5    15

SALIDAS:

inorder:
1 3 5 8 12 15

preorder:
8 3 1 5 12 15

postorder:
1 5 3 15 12 8

reverse inorder:
15 12 8 5 3 1
*/

void inorder(Node* root)
{
    // TU CÓDIGO
}

void preorder(Node* root)
{
    // TU CÓDIGO
}

void postorder(Node* root)
{
    // TU CÓDIGO
}

void reverseInorder(Node* root)
{
    // TU CÓDIGO
}
