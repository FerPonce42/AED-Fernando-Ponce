/*
 * Implementa el método buscarMaximo(Node* n)
 * que retorne el valor máximo del árbol.
 * No uses find() ni recorras todo el árbol innecesariamente.
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

    int buscarMaximo(Node* n) {
        
        if (n == nullptr) {
            return 0;
        }


        if (n->nodes[1] == nullptr) {
            return n->value;
        }


        return buscarMaximo(n->nodes[1]);


    }

    void print() { cout << buscarMaximo(root) << endl; }
};

int main() {
    BST t;
    t.ins(50); t.ins(30); t.ins(70);
    t.ins(20); t.ins(40); t.ins(60); t.ins(80);
    t.print(); // Esperado: 80
}