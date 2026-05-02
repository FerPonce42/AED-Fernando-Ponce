/*
 * Implementa el método imprimirCamino(Node* n, int x)
 * que imprima el camino desde la raíz hasta el nodo con valor x.
 * Si el valor no existe, no imprimas nada.
 * Ejemplo: para x=40 en el árbol de abajo, imprime: 50 30 40
 */

#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* nodes[2];
    Node(int v) { value = v; nodes[0] = nodes[1] = 0; }
};

struct BST {
    Node* root;
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
    bool imprimirCamino(Node* n, int x) {
        // IMPLEMENTAR
        // Retorna true si encontró x, false si no
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