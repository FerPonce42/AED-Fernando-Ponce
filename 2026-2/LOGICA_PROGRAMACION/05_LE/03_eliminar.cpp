#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int x) : data(x), next(nullptr) {}
};

/*
PROBLEMA:

Elimina la primera aparición de X.

LISTA:
5 -> 8 -> 3 -> 8 -> 1 -> NULL

X = 8

DEBE QUEDAR:
5 -> 3 -> 8 -> 1 -> NULL

CASOS QUE DEBES CONSIDERAR:
- Lista vacía.
- X está en head.
- X está en medio.
- X está al final.
- X no existe.
*/

void eliminarPrimero(Node*& head, int x)
{
    // TU CÓDIGO
}

void imprimir(Node* head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node* head = new Node(5);
    head->next = new Node(8);
    head->next->next = new Node(3);
    head->next->next->next = new Node(8);
    head->next->next->next->next = new Node(1);

    eliminarPrimero(head, 8);
    imprimir(head);
}
