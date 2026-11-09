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

Invierte una lista simplemente enlazada.

LISTA ACTUAL:
1 -> 2 -> 3 -> 4 -> NULL

DEBE QUEDAR:
4 -> 3 -> 2 -> 1 -> NULL

RESTRICCIONES:
- No crear nuevos nodos.
- Debes modificar los enlaces existentes.
*/

void invertir(Node*& head)
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
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    invertir(head);
    imprimir(head);
}
