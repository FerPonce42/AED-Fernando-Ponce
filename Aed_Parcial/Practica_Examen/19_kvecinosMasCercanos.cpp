/*
 * Implementa el método kvecinosMasCercanos(int x, int k)
 * que imprima los k elementos más cercanos al valor x
 * en orden ascendente.
 * Si x no existe en el árbol, considera el más cercano.
 * Ejemplo:
 * kvecinosMasCercanos(50, 3) => 40 50 60
 * kvecinosMasCercanos(35, 3) => 30 40 50
 * kvecinosMasCercanos(75, 3) => 70 80 (solo 2 si no hay más)
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
    void inorden(Node* n, int* arr, int& i) {
        if (!n) return;
        inorden(n->nodes[0], arr, i);
        arr[i++] = n->value;
        inorden(n->nodes[1], arr, i);
    }
    void kvecinosMasCercanos(int x, int k) {
        // IMPLEMENTAR
        // Pista: guarda el inorden en un array
        // luego busca la posicion mas cercana a x
        // y expande k posiciones alrededor
    }
    void print(int x, int k) { kvecinosMasCercanos(x, k); cout << endl; }
};

int main() {
    BST t;
    t.ins(50); t.ins(30); t.ins(70);
    t.ins(20); t.ins(40); t.ins(60); t.ins(80);
    t.print(50, 3); // Esperado: 40 50 60
    t.print(35, 3); // Esperado: 30 40 50
    t.print(75, 3); // Esperado: 70 80
}