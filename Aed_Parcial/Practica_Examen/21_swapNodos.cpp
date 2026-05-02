/*
 * Implementa el método swapNodos(int x, int y)
 * que intercambie las posiciones de dos nodos en una
 * lista simplemente enlazada.
 * Intercambia modificando punteros, NO valores.
 * Considera todos los casos:
 * - nodos no adyacentes
 * - nodos adyacentes
 * - uno de los nodos es head
 */

#include <iostream>
using namespace std;

struct Nodo {
    int valor;
    Nodo* next;
    Nodo(int v) { valor = v; next = nullptr; }
};

struct Lista {
    Nodo* head;
    Lista() { head = nullptr; }

    void push_back(int x) {
        Nodo* nodo = new Nodo(x);
        if (!head) { head = nodo; return; }
        Nodo* p = head;
        while (p->next) p = p->next;
        p->next = nodo;
    }

    void swapNodos(int x, int y) {
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
    l.push_back(10); l.push_back(20); l.push_back(30);
    l.push_back(40); l.push_back(50);
    l.print(); // 10 20 30 40 50

    l.swapNodos(20, 40);
    l.print(); // Esperado: 10 40 30 20 50

    l.swapNodos(10, 50);
    l.print(); // Esperado: 50 40 30 20 10

    l.swapNodos(40, 30);
    l.print(); // Esperado: 50 30 40 20 10
}