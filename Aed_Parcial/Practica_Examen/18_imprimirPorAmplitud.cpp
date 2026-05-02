/*
 * Implementa el método imprimirPorAmplitud(Node* n)
 * que imprima el árbol nivel por nivel (BFS).
 * Usa std::queue para implementarlo.
 * Ejemplo:
 * Nivel 0: 50
 * Nivel 1: 30 70
 * Nivel 2: 20 40 60 80
 */

#include <iostream>
#include <queue>
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
    void imprimirPorAmplitud(Node* n) {
        // IMPLEMENTAR
        // Pista: usa queue<Node*>
    }
    void print() { imprimirPorAmplitud(root); cout << endl; }
};

int main() {
    BST t;
    t.ins(50); t.ins(30); t.ins(70);
    t.ins(20); t.ins(40); t.ins(60); t.ins(80);
    t.print(); // Esperado: 50 30 70 20 40 60 80
}