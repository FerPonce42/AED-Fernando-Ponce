/*
 * Implementa el método imprimirAncestros(Node* n, int x)
 * que imprima todos los ancestros del nodo con valor x.
 * Un ancestro es cualquier nodo en el camino desde la raíz
 * hasta el nodo, sin incluir el nodo mismo.
 * Ejemplo: ancestros de 40 son: 50 30
 * Ejemplo: ancestros de 80 son: 50 70
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

    bool imprimirAncestros(Node* n, int x) {

        for (n = root; n && (n)->value != x; n = ((n)->nodes[x > (n)->value])) {
            cout << n->value <<" ";
        }

        if (n == root && n != nullptr) {
            cout << "Nada, es la raiz";
        }

        if (n != nullptr && (x == n->value)) {
            return true;
        }


        return false;
    }

    void print(int x) { imprimirAncestros(root, x); cout << endl; }
};

int main() {
    BST t;
    t.ins(50); t.ins(30); t.ins(70);
    t.ins(20); t.ins(40); t.ins(60); t.ins(80);
    t.print(40); // Esperado: 50 30
    t.print(80); // Esperado: 50 70
    t.print(50); // Esperado: (nada, es la raiz)
}