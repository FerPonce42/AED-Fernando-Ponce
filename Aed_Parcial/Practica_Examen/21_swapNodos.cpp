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

class Nodo {
public:
    int valor;
    Nodo* next;
    Nodo(int v) { valor = v; next = nullptr; }
};

class Lista {
private:
    Nodo* head;

public:
    Lista() { head = nullptr; }

    void push_back(int x) {
        Nodo* nodo = new Nodo(x);
        if (!head) { head = nodo; return; }
        Nodo* p = head;
        while (p->next) p = p->next;
        p->next = nodo;
    }

void swapNodos(int x, int y) {
    if (x == y) return;

    // Buscar prevX (anterior a x) y nodoX
    Nodo* prevX = nullptr;
    Nodo* nodoX = head;
    while (nodoX && nodoX->valor != x) {
        prevX = nodoX;
        nodoX = nodoX->next;
    }

    // Buscar prevY (anterior a y) y nodoY
    Nodo* prevY = nullptr;
    Nodo* nodoY = head;
    while (nodoY && nodoY->valor != y) {
        prevY = nodoY;
        nodoY = nodoY->next;
    }

    // Si alguno no existe, no hacer nada
    if (!nodoX || !nodoY) return;

    // Reconectar el anterior de X para que apunte a nodoY
    if (prevX) prevX->next = nodoY;
    else head = nodoY;  // X era head

    // Reconectar el anterior de Y para que apunte a nodoX
    if (prevY) prevY->next = nodoX;
    else head = nodoX;  // Y era head

    // Intercambiar los next de ambos nodos
    Nodo* temp = nodoX->next;
    nodoX->next = nodoY->next;
    nodoY->next = temp;
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