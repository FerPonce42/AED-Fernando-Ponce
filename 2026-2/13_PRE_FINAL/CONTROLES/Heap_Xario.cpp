//ejercicio 1 - control 2 - aed
#include <iostream>
#include <utility>
using namespace std;

// Criterios de prioridad: prio(a, b) es true si a debe quedar mas arriba que b
struct MayorPrimero {                 // max-heap
    bool operator()(int a, int b) const { return a > b; }
};

struct MenorPrimero {                 // min-heap
    bool operator()(int a, int b) const { return a < b; }
};

// Heap X-ario (cada nodo tiene hasta X hijos) almacenado por niveles en un arreglo
template <typename T, int X, typename Prioridad>
class HeapXario {
private:
    T* datos;
    int capacidad;
    int n;
    Prioridad prio;

public:
    HeapXario(int cap) {
        capacidad = cap;
        n = 0;
        datos = new T[cap];
    }

    ~HeapXario() {
        delete[] datos;
    }

    bool empty() const { return n == 0; }

    int size() const { return n; }

    T top() const { return datos[0]; }

    void printArray() const {
        cout << "[";
        for (int i = 0; i < n; i++) {
            cout << datos[i];
            if (i + 1 < n)
                cout << ", ";
        }
        cout << "]" << endl;
    }

    // con fe compila
    void push(const T& valor) {
        if (n == capacidad) {
            return;
        }

        datos[n] = valor;
        int i = n;
        n++;

        while (i > 0) {
            int padre = (i - 1) / X;

            if (prio(datos[i], datos[padre])) {
                T val_tmp = datos[i];
                datos[i] = datos[padre];
                datos[padre] = val_tmp;

                i = padre;
            }
            else {
                break;
            }
        }
    }



    void pop() {
        if (n == 0) {
            return;
        }

        datos[0] = datos[n - 1];
        n--;

        int i = 0;

        while (true) {
            int primerHijo = X * i + 1;

            if (primerHijo >= n) {
                break;
            }

            int candidato = primerHijo;

            for (int k = 1; k < X; k++) {
                int hijo = primerHijo + k;

                if (hijo >= n) {
                    break;
                }

                if (prio(datos[hijo], datos[candidato])) {
                    candidato = hijo;
                }
            }

            if (prio(datos[candidato], datos[i])) {
                T val_tmp = datos[i];
                datos[i] = datos[candidato];
                datos[candidato] = val_tmp;

                i = candidato;
            }
            else {
                break;
            }
        }
    }

    
};

template <int X, typename Prioridad>
void runTest(const int* valores, int cantidad, int pops) {
    HeapXario<int, X, Prioridad> heap(50);

    for (int i = 0; i < cantidad; i++)
        heap.push(valores[i]);

    cout << "Tras insertar:          ";
    heap.printArray();

    for (int k = 0; k < pops; k++)
        heap.pop();

    cout << "Tras " << pops << " pop:             ";
    heap.printArray();

    cout << endl;
}

void runTestBordes() {
    HeapXario<int, 4, MenorPrimero> heap(3);

    heap.pop();                       // heap vacio: no debe hacer nada
    cout << "Pop en vacio:           ";
    heap.printArray();

    heap.push(8);
    heap.push(3);
    heap.push(6);
    heap.push(1);                     // capacidad 3: no se inserta
    cout << "Push en lleno:          ";
    heap.printArray();

    cout << endl;
}

int main() {
    int a[] = {10, 40, 5, 25, 60, 1, 30, 15, 50, 3, 45};
    int b[] = {7, 2, 9, 4, 1, 8, 3};

    cout << "===== TEST 1 (max-heap, X = 3) =====" << endl;
    cout << "Esperado tras insertar: [60, 40, 50, 45, 10, 1, 30, 5, 15, 3, 25]" << endl;
    cout << "Esperado tras 3 pop:    [40, 30, 25, 3, 10, 1, 15, 5]" << endl;
    runTest<3, MayorPrimero>(a, 11, 3);

    cout << "===== TEST 2 (min-heap, X = 3) =====" << endl;
    cout << "Esperado tras insertar: [1, 5, 3, 25, 60, 40, 30, 15, 50, 10, 45]" << endl;
    cout << "Esperado tras 3 pop:    [10, 30, 15, 25, 60, 40, 45, 50]" << endl;
    runTest<3, MenorPrimero>(a, 11, 3);

    cout << "===== TEST 3 (max-heap, X = 2) =====" << endl;
    cout << "Esperado tras insertar: [9, 4, 8, 2, 1, 7, 3]" << endl;
    cout << "Esperado tras 2 pop:    [7, 4, 3, 2, 1]" << endl;
    runTest<2, MayorPrimero>(b, 7, 2);

    cout << "===== TEST 4 (min-heap, X = 4) =====" << endl;
    cout << "Esperado tras insertar: [1, 3, 9, 4, 2, 8, 7]" << endl;
    cout << "Esperado tras 3 pop:    [4, 8, 9, 7]" << endl;
    runTest<4, MenorPrimero>(b, 7, 3);

    cout << "===== TEST 5 (bordes: heap vacio y heap lleno, X = 4) =====" << endl;
    cout << "Esperado pop en vacio:  []" << endl;
    cout << "Esperado push en lleno: [3, 8, 6]" << endl;
    runTestBordes();

    return 0;
}
