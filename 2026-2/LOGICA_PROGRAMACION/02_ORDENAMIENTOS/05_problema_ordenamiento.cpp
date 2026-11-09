#include <iostream>
#include <vector>
using namespace std;

/*
PROBLEMA:

Dado un arreglo de enteros, determina si está ordenado de menor
a mayor.

Si no está ordenado, devuelve la primera posición donde se rompe
el orden.

RESTRICCIONES:
- No puedes ordenar el arreglo.
- Debes recorrerlo una sola vez.

EJEMPLO:

ARREGLO ACTUAL:
1 2 4 3 5 8

PRIMERA POSICIÓN DONDE SE ROMPE EL ORDEN:
2

Porque arreglo[2] = 4 y arreglo[3] = 3.

DEVOLVER:
La posición encontrada.
Si todo está ordenado, devuelve -1.
*/

int primeraRuptura(const vector<int>& arreglo)
{
    // TU CÓDIGO
    return -1;
}

int main()
{
    vector<int> arreglo = {1, 2, 4, 3, 5, 8};

    cout << primeraRuptura(arreglo) << "\n";
}
