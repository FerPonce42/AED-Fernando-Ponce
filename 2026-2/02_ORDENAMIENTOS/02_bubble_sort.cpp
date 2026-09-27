#include <iostream>
#include <vector>
using namespace std;

/*
PROBLEMA:

Implementa Bubble Sort para ordenar el arreglo de menor a mayor.

RESTRICCIONES:
- No utilices std::sort.
- Debes modificar el mismo arreglo.

IDEA DEL ALGORITMO:
Bubble Sort compara elementos adyacentes y los intercambia cuando
están en el orden incorrecto.

ARREGLO ACTUAL:
6 2 8 1 5

DEBE QUEDAR:
1 2 5 6 8
*/

void bubbleSort(vector<int>& arreglo)
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
    vector<int> arreglo = {6, 2, 8, 1, 5};

    cout << "Arreglo actual: ";
    imprimir(arreglo);

    bubbleSort(arreglo);

    cout << "Arreglo tras Bubble Sort: ";
    imprimir(arreglo);
}
