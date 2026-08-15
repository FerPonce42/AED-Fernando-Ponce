/*
 * Implementa una PilaDoble usando únicamente
 * una instancia de std::deque<int>.
 * Una PilaDoble tiene dos pilas independientes:
 * - pilaA: opera por el frente del deque
 * - pilaB: opera por el final del deque
 * Métodos:
 * - pushA(int x): inserta en pilaA
 * - popA(): elimina el tope de pilaA
 * - topA(): retorna el tope de pilaA
 * - pushB(int x): inserta en pilaB
 * - popB(): elimina el tope de pilaB
 * - topB(): retorna el tope de pilaB
 * - print(): imprime todo el deque de izquierda a derecha
 */

#include <iostream>
#include <deque>
using namespace std;

class PilaDoble {
    deque<int> d;
public:
    void pushA(int x) {
        d.push_front(x);
    }
    void popA() {
        if (d.empty() == false) {
            d.pop_front();
        }
    }
    int topA() {
        return d.front();
    }
    void pushB(int x) {
        d.push_back(x);
    }
    void popB() {
        if (d.empty() == false) {
            d.pop_back();
        }
    }
    int topB() {
        return d.back();
    }
    void print() {
        for (int x : d) cout << x << " ";
        cout << endl;
    }
};

int main() {
    PilaDoble pd;
    pd.pushA(1); pd.pushA(2); pd.pushA(3);
    pd.pushB(10); pd.pushB(20); pd.pushB(30);
    pd.print(); // Esperado: 3 2 1 10 20 30

    cout << "topA: " << pd.topA() << endl; // Esperado: 3
    cout << "topB: " << pd.topB() << endl; // Esperado: 30

    pd.popA(); pd.print(); // Esperado: 2 1 10 20 30
    pd.popB(); pd.print(); // Esperado: 2 1 10 20
}