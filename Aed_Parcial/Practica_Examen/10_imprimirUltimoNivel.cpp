/*
 * Implementa el método imprimirUltimoNivel(Node* n)
 * que imprima solo los nodos del último nivel del árbol.
 * Puedes usar las funciones que ya tienes disponibles.
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

    int altura(Node* n) {
        if (!n) return 0;
        int l = altura(n->nodes[0]);
        int r = altura(n->nodes[1]);
        return max(l, r) + 1;
    }

    void imprimirNivel(Node* n, int k) {
        if (!n) return;
        if (k == 0) { cout << n->value << " "; return; }
        imprimirNivel(n->nodes[0], k - 1);
        imprimirNivel(n->nodes[1], k - 1);
    }

    void imprimirUltimoNivel(Node* n) {
        // IMPLEMENTAR
        // Pista: usa altura() e imprimirNivel()
    }

    void print() { imprimirUltimoNivel(root); cout << endl; }
};

int main() {
    BST t;
    t.ins(50); t.ins(30); t.ins(70);
    t.ins(20); t.ins(40); t.ins(60); t.ins(80);
    t.print(); // Esperado: 20 40 60 80
}