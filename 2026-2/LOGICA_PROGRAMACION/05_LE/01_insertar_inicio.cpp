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

Implementa insertarInicio.

Debe insertar un nuevo nodo antes del actual head.

LISTA ACTUAL:
5 -> 8 -> 2 -> NULL

insertarInicio(9)

DEBE QUEDAR:
9 -> 5 -> 8 -> 2 -> NULL
*/

void insertarInicio(Node*& head, int x)
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
    head->next->next = new Node(2);

    insertarInicio(head, 9);
    imprimir(head);
}
