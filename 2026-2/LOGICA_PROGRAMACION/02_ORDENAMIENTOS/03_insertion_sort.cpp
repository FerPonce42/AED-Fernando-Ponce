#include <iostream>
#include <vector>
using namespace std;

/*
PROBLEMA:

Implementa Insertion Sort para ordenar el arreglo de menor a mayor.

RESTRICCIONES:
- No utilices std::sort.
- Debes modificar el mismo arreglo.

IDEA DEL ALGORITMO:
Insertion Sort toma un elemento y lo inserta en la posición correcta
dentro de la parte que ya está ordenada.

ARREGLO ACTUAL:
7 4 6 2 9 1

DEBE QUEDAR:
1 2 4 6 7 9
*/

void insertionSort(vector<int>& arreglo)
{
    // TU CÓDIGO
}

void imprimir(const vector<int>& arreglo)
{
    for (int x : arreglo)
        cout << x << " ";
    cout << "\n";
}

int main()
{
    vector<int> arreglo = {7, 4, 6, 2, 9, 1};

    cout << "Arreglo actual: ";
    imprimir(arreglo);

    insertionSort(arreglo);

    cout << "Arreglo tras Insertion Sort: ";
    imprimir(arreglo);
}
