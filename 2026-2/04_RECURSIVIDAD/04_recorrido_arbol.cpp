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

Implementa los tres recorridos clásicos de un árbol binario:

1. Inorder
2. Preorder
3. Postorder

RESTRICCIÓN:
Los tres deben ser recursivos.

ÁRBOL DE PRUEBA:

        8
       / \
      3   12
     / \    \
    1   5    15

SALIDAS:
Inorder   : 1 3 5 8 12 15
Preorder  : 8 3 1 5 12 15
Postorder : 1 5 3 15 12 8
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

int main()
{
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(12);
    root->left->left = new Node(1);
    root->left->right = new Node(5);
    root->right->right = new Node(15);

    inorder(root);
    cout << "\n";
    preorder(root);
    cout << "\n";
    postorder(root);
    cout << "\n";
}
