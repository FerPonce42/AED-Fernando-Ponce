/*
 * Implementa el método imprimirRango(Node* n, int min, int max)
 * que imprima todos los elementos en el rango [min, max]
 * en orden ascendente.
 * No recorras todo el árbol — aprovecha la propiedad del BST
 * para podar ramas que no contengan valores en el rango.
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

    void imprimirRango(Node* n, int min, int max) {
        // IMPLEMENTAR
    }

    void print(int min, int max) { imprimirRango(root, min, max); cout << endl; }
};

int main() {
    BST t;
    t.ins(50); t.ins(30); t.ins(70);
    t.ins(20); t.ins(40); t.ins(60); t.ins(80);
    t.print(25, 65); // Esperado: 30 40 50 60
    t.print(10, 35); // Esperado: 20 30
    t.print(60, 90); // Esperado: 60 70 80
}