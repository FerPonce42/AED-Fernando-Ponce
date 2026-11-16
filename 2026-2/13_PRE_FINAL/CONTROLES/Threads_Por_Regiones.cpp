//ejercicio 3 - control 2 - aed
#include <iostream>
#include <iomanip>
#include <thread>
#include <functional>
using namespace std;

int** crearMatriz(int n) {
    int** A = new int*[n];
    for (int i = 0; i < n; i++)
        A[i] = new int[n];
    return A;
}

void liberarMatriz(int** A, int n) {
    for (int i = 0; i < n; i++)
        delete[] A[i];
    delete[] A;
}

void printMatrix(int** A, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(4) << A[i][j];
        cout << endl;
    }
}

int contarNegativos(int** A, int n) {
    int c = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (A[i][j] < 0) c++;
    return c;
}

// Cada thread procesa las filas [f0, f1) y las columnas [c0, c1)
void procesarRegion(int** A, int f0, int f1, int c0, int c1, int& reemplazos) {

    // =====================================================
    // COMPLETE EL CODIGO AQUI
    // =====================================================

    // =====================================================
}

// Imprime los reemplazos de cada thread y el total, o un mensaje si T no es valido
void limpiarNegativos(int** A, int n, int T) {
    int* reemplazos = new int[T];
    thread* hilos = new thread[T];
    bool valido = true;

    for (int t = 0; t < T; t++)
        reemplazos[t] = 0;

    // =====================================================
    // COMPLETE EL CODIGO AQUI
    // =====================================================

    // =====================================================

    if (!valido)
        cout << "T = " << T << " no es valido para N = " << n;
    else {
        int total = 0;
        for (int t = 0; t < T; t++) {
            cout << reemplazos[t] << " ";
            total += reemplazos[t];
        }
        cout << "| total " << total;
    }
    cout << endl;

    delete[] reemplazos;
    delete[] hilos;
}

void runTest(int n, int T, const int* datos, bool mostrar) {
    int** A = crearMatriz(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = (datos != nullptr) ? datos[i * n + j] : ((i * 7 + j * 5) % 13) - 6;

    if (mostrar) {
        cout << "Original:" << endl;
        printMatrix(A, n);
    }

    cout << "Reemplazos por thread: ";
    limpiarNegativos(A, n, T);

    if (mostrar) {
        cout << "Resultado:" << endl;
        printMatrix(A, n);
    }

    cout << "Negativos restantes:   " << contarNegativos(A, n) << endl;

    cout << endl;
    liberarMatriz(A, n);
}

int main() {
    int m1[] = {
         3, -1,  4, -1,  5, -9,  2,
        -6,  5, -3,  5,  8, -9,  7,
         9, -3,  2, -3,  8,  4, -6,
         2, -6,  4,  3, -3,  8,  3,
        -2,  7,  9, -5,  0, -2,  8,
         8, -4,  1, -9,  7,  1, -6,
        -9,  3,  9,  9, -3,  7,  5};

    cout << "===== TEST 1 (N = 7, T = 4) =====" << endl;
    cout << "Esperado:              4 5 4 6 | total 19" << endl;
    runTest(7, 4, m1, true);

    cout << "===== TEST 2 (N = 6, T = 9) =====" << endl;
    cout << "Esperado:              2 2 1 2 2 2 2 1 2 | total 16" << endl;
    runTest(6, 9, nullptr, true);

    cout << "===== TEST 3 (N = 10, T = 9) =====" << endl;
    cout << "Esperado:              4 4 6 4 4 6 6 6 7 | total 47" << endl;
    runTest(10, 9, nullptr, false);

    cout << "===== TEST 4 (N = 5, T = 1) =====" << endl;
    cout << "Esperado:              12 | total 12" << endl;
    runTest(5, 1, nullptr, true);

    cout << "===== TEST 5 (N = 4, T = 6) =====" << endl;
    cout << "Esperado:              T = 6 no es valido para N = 4" << endl;
    runTest(4, 6, nullptr, false);

    cout << "===== TEST 6 (N = 2, T = 9) =====" << endl;
    cout << "Esperado:              T = 9 no es valido para N = 2" << endl;
    runTest(2, 9, nullptr, false);

    return 0;
}
