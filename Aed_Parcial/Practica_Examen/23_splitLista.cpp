/*
 * Implementa el método splitLista(Nodo* pivot)
 * que reordene la lista de la siguiente manera:
 * - Todos los elementos menores al pivot van a la izquierda
 * - El pivot queda en el medio
 * - Todos los elementos mayores al pivot van a la derecha
 * - head y tail deben mantenerse correctamente
 * Ejemplo:
 * Lista:    10 50 20 40 30
 * pivot = 30
 * Resultado: 10 20 30 40 50
 */

#include <iostream>
using namespace std;

class Nodo {
public:
    int valor;
    Nodo* next;
    Nodo* prev;
    Nodo(int v) { valor = v; next = nullptr; prev = nullptr; }
};

class Lista {
public:
    Nodo* head;
    Nodo* tail;
    Lista() { head = nullptr; tail = nullptr; }

    void push_back(int x) {
        Nodo* nodo = new Nodo(x);
        if (!tail) { head = tail = nodo; return; }
        nodo->prev = tail;
        tail->next = nodo;
        tail = nodo;
    }

    void splitLista(Nodo* pivot) {
        // IMPLEMENTAR
    }

    void print() {
        Nodo* p = head;
        while (p) { cout << p->valor << " "; p = p->next; }
        cout << endl;
    }
};

int main() {
    Lista l;
    l.push_back(10); l.push_back(50); l.push_back(20);
    l.push_back(40); l.push_back(30);
    l.print(); // 10 50 20 40 30

    Nodo* pivot = l.head->next->next->next->next; // nodo con valor 30
    l.splitLista(pivot);
    l.print(); // Esperado: 10 20 30 40 50
}