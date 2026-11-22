//ejercicio 2 - control 2 - aed
#include <iostream>
#include <iomanip>
#include <utility>
using namespace std;

const int TAM = 10;

struct SNode {
    int val;
    int fila;
    int col;
    SNode* nextHor;   // siguiente nodo de la misma fila
    SNode* nextVer;   // siguiente nodo de la misma columna

    SNode(int data, int f, int c) : val(data), fila(f), col(c) {
        nextHor = nextVer = nullptr;
    }
};

class SMatrix {
private:
    SNode* arrFil[TAM];   // arrFil[i]: lista de la fila i (por nextHor), ordenada por columna
    SNode* arrCol[TAM];   // arrCol[j]: lista de la columna j (por nextVer), ordenada por fila
    int filas;
    int columnas;

    // p queda en el puntero donde esta (o deberia estar) el nodo de la columna c en la fila f
    bool findOnFil(int f, int c, SNode**& p) {
        p = &arrFil[f];
        while (*p != nullptr && (*p)->col < c)
            p = &((*p)->nextHor);
        return *p != nullptr && (*p)->col == c;
    }

    // p queda en el puntero donde esta (o deberia estar) el nodo de la fila f en la columna c
    bool findOnCol(int f, int c, SNode**& p) {
        p = &arrCol[c];
        while (*p != nullptr && (*p)->fila < f)
            p = &((*p)->nextVer);
        return *p != nullptr && (*p)->fila == f;
    }

public:
    SMatrix(int f, int c) {
        filas = f;
        columnas = c;
        for (int i = 0; i < TAM; i++) {
            arrFil[i] = nullptr;
            arrCol[i] = nullptr;
        }
    }

    ~SMatrix() {
        for (int i = 0; i < TAM; i++) {
            SNode* pos = arrFil[i];
            while (pos != nullptr) {
                SNode* temp = pos;
                pos = pos->nextHor;
                delete temp;
            }
        }
    }

    // Inserta o modifica el valor en (f, c). Si val es 0, elimina el nodo.
    void set(int val, int f, int c) {
        SNode** pF;
        SNode** pC;
        bool existe = findOnFil(f, c, pF);
        findOnCol(f, c, pC);

        if (existe) {
            if (val == 0) {
                SNode* temp = *pF;
                *pF = temp->nextHor;
                *pC = temp->nextVer;
                delete temp;
            }
            else
                (*pF)->val = val;
        }
        else if (val != 0) {
            SNode* nodito = new SNode(val, f, c);
            nodito->nextHor = *pF;
            *pF = nodito;
            nodito->nextVer = *pC;
            *pC = nodito;
        }
    }

    int get(int f, int c) {
        SNode** p;
        if (findOnFil(f, c, p))
            return (*p)->val;
        return 0;
    }

    int getFilas() const { return filas; }

    int getColumnas() const { return columnas; }

    // Imprime la matriz completa recorriendo las listas de filas
    void print() const {
        for (int i = 0; i < filas; i++) {
            SNode* pos = arrFil[i];
            for (int j = 0; j < columnas; j++) {
                if (pos != nullptr && pos->col == j) {
                    cout << setw(4) << pos->val;
                    pos = pos->nextHor;
                }
                else
                    cout << setw(4) << 0;
            }
            cout << endl;
        }
    }

    // Imprime cada lista de fila recorriendola con nextHor
    void printRows() const {
        for (int i = 0; i < filas; i++) {
            cout << "F" << i << ": ";
            SNode* pos = arrFil[i];
            if (pos == nullptr)
                cout << "-";
            while (pos != nullptr) {
                cout << "(" << pos->fila << "," << pos->col << "," << pos->val << ")";
                if (pos->nextHor != nullptr)
                    cout << " -> ";
                pos = pos->nextHor;
            }
            if (i + 1 < filas)
                cout << " | ";
        }
        cout << endl;
    }

    // Imprime cada lista de columna recorriendola con nextVer
    void printCols() const {
        for (int j = 0; j < columnas; j++) {
            cout << "C" << j << ": ";
            SNode* pos = arrCol[j];
            if (pos == nullptr)
                cout << "-";
            while (pos != nullptr) {
                cout << "(" << pos->fila << "," << pos->col << "," << pos->val << ")";
                if (pos->nextVer != nullptr)
                    cout << " -> ";
                pos = pos->nextVer;
            }
            if (j + 1 < columnas)
                cout << " | ";
        }
        cout << endl;
    }


//intento 4:

    void rotate90() {
        SNode* nuevoFil[TAM];
        SNode* nuevoCol[TAM];

        for (int i = 0; i < TAM; i++) {
            nuevoFil[i] = nullptr;
            nuevoCol[i] = nullptr;
        }

        for (int i = 0; i < filas; i++) {
            nuevoCol[filas - 1 - i] = arrFil[i];
        }

        for (int j = 0; j < columnas; j++) {
            SNode* anterior = nullptr;
            SNode* actual = arrCol[j];

            while (actual != nullptr) {
                SNode* siguiente = actual->nextVer;
                actual->nextVer = anterior;
                anterior = actual;
                actual = siguiente;
            }

            nuevoFil[j] = anterior;
        }

        for (int j = 0; j < columnas; j++) {
            SNode* pos = nuevoFil[j];

            while (pos != nullptr) {
                SNode* siguiente = pos->nextVer;
                int filaVieja = pos->fila;

                pos->nextVer = pos->nextHor;
                pos->nextHor = siguiente;

                pos->fila = pos->col;
                pos->col = filas - 1 - filaVieja;

                pos = siguiente;
            }
        }

        for (int i = 0; i < TAM; i++) {
            arrFil[i] = nuevoFil[i];
            arrCol[i] = nuevoCol[i];
        }

        int temp = filas;
        filas = columnas;
        columnas = temp;
    }



};

// elementos: tripletas {val, fila, col}
void runTest(int f, int c, const int elementos[][3], int cantidad, int rotaciones) {
    SMatrix m(f, c);

    for (int i = 0; i < cantidad; i++)
        m.set(elementos[i][0], elementos[i][1], elementos[i][2]);

    cout << "Original:" << endl;
    m.print();

    for (int r = 0; r < rotaciones; r++)
        m.rotate90();

    cout << "Rotada:" << endl;
    m.print();

    cout << "Filas:             ";
    m.printRows();
    cout << "Columnas:          ";
    m.printCols();

    cout << endl;
}

int main() {
    int t1[][3] = {{5, 0, 1}, {7, 1, 0}, {2, 1, 3}, {9, 2, 2}};
    int t2[][3] = {{1, 0, 0}, {4, 0, 3}, {6, 1, 1}, {8, 2, 2}, {3, 3, 0}, {5, 3, 2}};
    int t3[][3] = {{3, 0, 0}, {8, 0, 2}, {1, 0, 4}};
    int t4[][3] = {{1, 0, 0}, {2, 0, 2}, {3, 1, 1}, {4, 2, 0}};
    int t6[][3] = {{1, 0, 0}, {2, 0, 2}, {3, 1, 1}};

    cout << "===== TEST 1 (3 x 4, 1 rotacion) =====" << endl;
    cout << "Esperado filas:    F0: (0,1,7) | F1: (1,2,5) | F2: (2,0,9) | F3: (3,1,2)" << endl;
    cout << "Esperado columnas: C0: (2,0,9) | C1: (0,1,7) -> (3,1,2) | C2: (1,2,5)" << endl;
    runTest(3, 4, t1, 4, 1);

    cout << "===== TEST 2 (4 x 4, 1 rotacion) =====" << endl;
    cout << "Esperado filas:    F0: (0,0,3) -> (0,3,1) | F1: (1,2,6) | F2: (2,0,5) -> (2,1,8) | F3: (3,3,4)" << endl;
    cout << "Esperado columnas: C0: (0,0,3) -> (2,0,5) | C1: (2,1,8) | C2: (1,2,6) | C3: (0,3,1) -> (3,3,4)" << endl;
    runTest(4, 4, t2, 6, 1);

    cout << "===== TEST 3 (1 x 5, 1 rotacion) =====" << endl;
    cout << "Esperado filas:    F0: (0,0,3) | F1: - | F2: (2,0,8) | F3: - | F4: (4,0,1)" << endl;
    cout << "Esperado columnas: C0: (0,0,3) -> (2,0,8) -> (4,0,1)" << endl;
    runTest(1, 5, t3, 3, 1);

    cout << "===== TEST 4 (3 x 3, 4 rotaciones) =====" << endl;
    cout << "Esperado filas:    F0: (0,0,1) -> (0,2,2) | F1: (1,1,3) | F2: (2,0,4)" << endl;
    cout << "Esperado columnas: C0: (0,0,1) -> (2,0,4) | C1: (1,1,3) | C2: (0,2,2)" << endl;
    runTest(3, 3, t4, 4, 4);

    cout << "===== TEST 5 (2 x 3 vacia, 1 rotacion) =====" << endl;
    cout << "Esperado filas:    F0: - | F1: - | F2: -" << endl;
    cout << "Esperado columnas: C0: - | C1: -" << endl;
    runTest(2, 3, t1, 0, 1);

    cout << "===== TEST 6 (2 x 3, 2 rotaciones) =====" << endl;
    cout << "Esperado filas:    F0: (0,1,3) | F1: (1,0,2) -> (1,2,1)" << endl;
    cout << "Esperado columnas: C0: (1,0,2) | C1: (0,1,3) | C2: (1,2,1)" << endl;
    runTest(2, 3, t6, 3, 2);

    return 0;
}
