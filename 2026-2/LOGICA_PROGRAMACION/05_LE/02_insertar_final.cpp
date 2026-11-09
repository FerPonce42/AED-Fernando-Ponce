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

Inserta X al final de una lista simplemente enlazada.

LISTA:
5 -> 8 -> 2 -> NULL

X = 9

DEBE QUEDAR:
5 -> 8 -> 2 -> 9 -> NULL
*/

void insertarFinal(Node*& head, int x)
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

    insertarFinal(head, 9);
    imprimir(head);
}
