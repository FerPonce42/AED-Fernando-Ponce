/*
 * Implementa el método contarHojas(Node* n)
 * que retorne el número de nodos hoja del árbol.
 * Un nodo hoja es aquel que no tiene hijos.
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

    int contarHojas(Node* n) {
        
        if (n == nullptr) { // caso base fin
            return 0;
        }

        if (n->nodes[0] == nullptr && n->nodes[1] == nullptr) { // detectar que este nodo no tiene hijos
            return 1;
        }


        return contarHojas(n->nodes[0]) + contarHojas(n->nodes[1]); // llamada recursiva para avanzar el arbol y sume los numeros acumulados.

    }

    void print() { cout << contarHojas(root) << endl; }
};

int main() {
    BST t;
    t.ins(50); t.ins(30); t.ins(70);
    t.ins(20); t.ins(40); t.ins(60); t.ins(80);
    t.print(); // Esperado: 4
}