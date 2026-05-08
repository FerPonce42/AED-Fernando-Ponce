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
        int size = q.size();
        // meter x al final
        q.push(x);
        // rotar hasta que x quede en su posición correcta
        for (int i = 0; i < size; i++) {
            if (q.front() <= x) {
                q.push(q.front());
                q.pop();
            } else {
                break;
            }
        }
        // mover x al frente de los mayores
        q.push(q.front());
        q.pop();
        // rotar el resto
        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void popx() {
        q.pop();
    }

    int frontx() {
        return q.front();
    }

    void remx(int x) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            if (q.front() != x) {
                q.push(q.front());
            }
            q.pop();
        }
    }

    void printx() {
        queue<int> temp = q;
        while (temp.empty() == false) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
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