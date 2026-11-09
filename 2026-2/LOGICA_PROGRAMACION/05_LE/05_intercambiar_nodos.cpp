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

Intercambia las posiciones de los nodos que contienen X e Y.

LISTA:
10 -> 20 -> 30 -> 40 -> NULL

X = 20
Y = 40

DEBE QUEDAR:
10 -> 40 -> 30 -> 20 -> NULL

IMPORTANTE:
NO intercambies solamente data.
Debes modificar los enlaces de los nodos.

CONSIDERA:
- X o Y puede ser head.
- X o Y puede no existir.
- X e Y pueden ser el mismo valor.
*/

void swapNodes(Node*& head, int x, int y)
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
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    swapNodes(head, 20, 40);
    imprimir(head);
}
