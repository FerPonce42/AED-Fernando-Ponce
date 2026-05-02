/*
 * Implementa el método imprimirSobrinos(Node* n, int x)
 * que imprima los sobrinos del nodo con valor x.
 * Un nodo es sobrino de x si está en un nivel inferior
 * al de x y NO es hijo directo de x.
 * Ejemplo en el árbol de abajo:
 * sobrinos de 50 (raiz, nivel 0) => 20 40 60 80 (nivel 2)
 * sobrinos de 30 (nivel 1)       => 60 80 (hijos de 70, nivel 2)
 * sobrinos de 70 (nivel 1)       => 20 40 (hijos de 30, nivel 2)
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

    int nivelNodo(Node* n, int x, int nivel) {
        if (!n) return -1;
        if (n->value == x) return nivel;
        int l = nivelNodo(n->nodes[0], x, nivel + 1);
        if (l != -1) return l;
        return nivelNodo(n->nodes[1], x, nivel + 1);
    }

    void imprimirNivel(Node* n, int k) {
        if (!n) return;
        if (k == 0) { cout << n->value << " "; return; }
        imprimirNivel(n->nodes[0], k - 1);
        imprimirNivel(n->nodes[1], k - 1);
    }

    void imprimirSobrinos(Node* n, int x) {
        // IMPLEMENTAR
        // Pista: encuentra el nivel de x
        // luego imprime los nodos del nivel+1
        // pero excluye los hijos directos de x
    }

    void print(int x) { imprimirSobrinos(root, x); cout << endl; }
};

int main() {
    BST t;
    t.ins(50); t.ins(30); t.ins(70);
    t.ins(20); t.ins(40); t.ins(60); t.ins(80);
    t.print(50); // Esperado: 20 40 60 80
    t.print(30); // Esperado: 60 80
    t.print(70); // Esperado: 20 40
}