/*
 * Implementa el método merge(Nodo* h1, Nodo* h2)
 * que mezcle dos sublistas ordenadas en una sola lista ordenada.
 * Debes reutilizar los nodos existentes, no crear nuevos.
 * Ejemplo:
 * h1: 10 -> 30 -> 50
 * h2: 20 -> 40 -> 60
 * resultado: 10 -> 20 -> 30 -> 40 -> 50 -> 60
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
public:
    Nodo* head;
    Lista() { head = nullptr; }

    void push_back(int x) {
        Nodo* nodo = new Nodo(x);
        if (!head) { head = nodo; return; }
        Nodo* p = head;
        while (p->next) p = p->next;
        p->next = nodo;
    }

    Nodo* merge(Nodo* h1, Nodo* h2) {
        // IMPLEMENTAR
        // Retorna el head de la lista mezclada
    }

    void print(Nodo* h) {
        while (h) { cout << h->valor << " "; h = h->next; }
        cout << endl;
    }
};

int main() {
    Lista l;

    Nodo* h1 = new Nodo(10);
    h1->next = new Nodo(30);
    h1->next->next = new Nodo(50);

    Nodo* h2 = new Nodo(20);
    h2->next = new Nodo(40);
    h2->next->next = new Nodo(60);

    Nodo* resultado = l.merge(h1, h2);
    l.print(resultado); // Esperado: 10 20 30 40 50 60
}