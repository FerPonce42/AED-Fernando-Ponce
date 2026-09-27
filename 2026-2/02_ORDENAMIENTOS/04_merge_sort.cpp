#include <iostream>
#include <vector>
using namespace std;

/*
PROBLEMA:

Implementa Merge Sort para ordenar el arreglo de menor a mayor.

RESTRICCIONES:
- No utilices std::sort.
- Puedes utilizar memoria auxiliar para la combinación.
- La función pública que debes completar es mergeSort.

IDEA DEL ALGORITMO:
Merge Sort divide el problema en partes más pequeñas, ordena cada
parte y finalmente combina dos segmentos ya ordenados.

ARREGLO ACTUAL:
8 3 7 4 9 2 6 1

DEBE QUEDAR:
1 2 3 4 6 7 8 9
*/

void mergeSort(vector<int>& arreglo, int inicio, int fin)
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
    vector<int> arreglo = {8, 3, 7, 4, 9, 2, 6, 1};

    cout << "Arreglo actual: ";
    imprimir(arreglo);

    mergeSort(arreglo, 0, (int)arreglo.size() - 1);

    cout << "Arreglo tras Merge Sort: ";
    imprimir(arreglo);
}
