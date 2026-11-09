#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;

    Node(int x) : data(x), prev(nullptr), next(nullptr) {}
};

struct Lista
{
    Node* head;
    Node* tail;

    Lista() : head(nullptr), tail(nullptr) {}
};

/*
PROBLEMA:

Elimina la primera aparición de X de una lista doblemente
enlazada.

Debes actualizar correctamente:
- prev
- next
- head
- tail

CASOS:
- único nodo
- head
- tail
- nodo intermedio
- inexistente
*/

void eliminar(Lista& lista, int x)
{
    // TU CÓDIGO
}

void imprimir(Lista& lista)
{
    Node* p = lista.head;
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int main()
{
    Lista lista;

    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);

    lista.head = a;
    lista.tail = c;

    a->next = b;
    b->prev = a;
    b->next = c;
    c->prev = b;

    eliminar(lista, 20);
    imprimir(lista);
}
