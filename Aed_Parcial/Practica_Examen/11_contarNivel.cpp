/*
 * Implementa el método contarNivel(Node* n, int k)
 * que retorne cuántos nodos hay en el nivel k del árbol.
 * La raíz está en el nivel 0.
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
    int contarNivel(Node* n, int k) {
        // IMPLEMENTAR
    }
    void print(int k) { cout << contarNivel(root, k) << endl; }
};

int main() {
    BST t;
    t.ins(50); t.ins(30); t.ins(70);
    t.ins(20); t.ins(40); t.ins(60); t.ins(80);
    t.print(0); // Esperado: 1
    t.print(1); // Esperado: 2
    t.print(2); // Esperado: 4
}