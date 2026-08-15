/*
 * Implementa el método espejo(Node* n)
 * que invierta el árbol — es decir, que para cada nodo
 * intercambie su hijo izquierdo con su hijo derecho.
 * Luego imprime inorden para verificar.
 * Ejemplo: inorden normal:  20 30 40 50 60 70 80
 * Ejemplo: inorden espejo:  80 70 60 50 40 30 20
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

    void inorden(Node* n) {
        if (!n) return;
        inorden(n->nodes[0]);
        cout << n->value << " ";
        inorden(n->nodes[1]);
    }

    void espejo(Node* n) {
        if (n == nullptr) {
            return;
        }
        if (n != nullptr) {
            Node* tmp = n->nodes[0];
            n->nodes[0] = n->nodes[1];
            n->nodes[1] = tmp;
        }
        espejo(n->nodes[0]);

        espejo(n->nodes[1]);


    }

    void print() {
        espejo(root);
        cout << endl;
        inorden(root);
        cout << endl;
    }
};

int main() {
    BST t;
    t.ins(50); t.ins(30); t.ins(70);
    t.ins(20); t.ins(40); t.ins(60); t.ins(80);
    t.print(); // Esperado: 80 70 60 50 40 30 20
}