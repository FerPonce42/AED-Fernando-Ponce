/*
 * Implementa la clase ColaOrdenada usando únicamente
 * una instancia de std::queue<int>.
 * - pushx(int x): inserta x en orden ascendente
 * - popx(): elimina el menor elemento
 * - frontx(): retorna el menor elemento
 * - remx(int x): elimina todos los elementos iguales a x
 * - printx(): imprime todos los elementos
 * No puedes usar otras estructuras adicionales.
 */

#include <iostream>
#include <queue>
using namespace std;

class ColaOrdenada {
public:
    queue<int> q;

    void pushx(int x) {
        // IMPLEMENTAR
    }

    void popx() {
        // IMPLEMENTAR
    }

    int frontx() {
        // IMPLEMENTAR
    }

    void remx(int x) {
        // IMPLEMENTAR
    }

    void printx() {
        // IMPLEMENTAR
    }
};

int main() {
    ColaOrdenada cq;
    cq.pushx(40); cq.printx();
    cq.pushx(10); cq.printx();
    cq.pushx(30); cq.printx();
    cq.pushx(20); cq.printx();

    cout << "front: " << cq.frontx() << endl; // Esperado: 10

    cq.remx(30); cq.printx(); // Esperado: 10 20 40

    cq.popx(); cq.printx(); // Esperado: 20 40
}