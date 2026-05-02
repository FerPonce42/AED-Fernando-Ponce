/*
 * Dado el siguiente árbol binario de búsqueda,
 * implementa el método contarNodos(Node* n)
 * que retorne el número total de nodos del árbol.
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
    int contarNodos(Node* n) {
        // IMPLEMENTAR
    }
    void print() { cout << contarNodos(root) << endl; }
};

int main() {
    BST t;
    t.ins(50); t.ins(30); t.ins(70);
    t.ins(20); t.ins(40); t.ins(60); t.ins(80);
    t.print(); // Esperado: 7
}