/*
 * Implementa el método kesimoInorden(Node* n, int k, int& cont)
 * que retorne el k-ésimo elemento del árbol en recorrido inorden.
 * El primer elemento es k=1.
 * Ejemplo: inorden del árbol de abajo es 20 30 40 50 60 70 80
 * kesimoInorden(1) => 20
 * kesimoInorden(4) => 50
 * kesimoInorden(7) => 80
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

    int kesimoInorden(Node* n, int k, int& cont) {
        // IMPLEMENTAR
    }

    void print(int k) {
        int cont = 0;
        cout << kesimoInorden(root, k, cont) << endl;
    }
};

int main() {
    BST t;
    t.ins(50); t.ins(30); t.ins(70);
    t.ins(20); t.ins(40); t.ins(60); t.ins(80);
    t.print(1); // Esperado: 20
    t.print(4); // Esperado: 50
    t.print(7); // Esperado: 80
}