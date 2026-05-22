/*
 * Implementa el método imprimirCamino(Node* n, int x)
 * que imprima el camino desde la raíz hasta el nodo con valor x.
 * Si el valor no existe, no imprimas nada.
 * Ejemplo: para x=40 en el árbol de abajo, imprime: 50 30 40
 */

#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* nodes[2];
    Node(int v) { value = v; nodes[0] = nodes[1] = 0; }
};

class BST {
private:
    Node* root;

public:
    BST() { root = nullptr; }

    bool find(int x, Node**& p) {
        for (p = &root; *p && (*p)->value != x; p = &((*p)->nodes[x > (*p)->value]));
        return *p && (*p)->value == x;
    }

    bool ins(int x) {
        Node** p;
        if (find(x, p)) return false;
        *p = new Node(x);
        return true;
    }
    bool buscar(Node* n, int x) {
        if (n == nullptr) {
            return false;
        }

        if (n->value == x) {
            return true;
        }

        return buscar(n->nodes[0], x) || buscar(n->nodes[1], x);
    }

    bool imprimirCamino(Node* n, int x) {

        if (n == nullptr) {
            return false;
        }

        // Solo buscar, sin imprimir nada
        if (buscar(n, x) == false) {
            cout << "Nada" << endl;
            return false;
        }

        // Solo imprimir camino BST
        if (x < n->value) {
            cout << n->value << " ";
            imprimirCamino(n->nodes[0], x);
            return true;
        }
        else if (x > n->value) {
            cout << n->value << " ";
            imprimirCamino(n->nodes[1], x);
            return true;
        }
        else if (x == n->value) {
            cout << n->value << " ";
            return true;
        }

        return false;
    }

    void print(int x) { imprimirCamino(root, x); cout << endl; }
};

int main() {
    BST t;
    t.ins(50); t.ins(30); t.ins(70);
    t.ins(20); t.ins(40); t.ins(60); t.ins(80);
    t.print(40); // Esperado: 50 30 40
    t.print(80); // Esperado: 50 70 80
    t.print(99); // Esperado: (nada)
}