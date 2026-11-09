#include <iostream>
#include <vector>
using namespace std;

/*
PROBLEMA:

Dado un vector de enteros, elimina todas las apariciones de X.

RESTRICCIONES:
- Trabaja sobre el mismo vector.
- No utilices otra estructura auxiliar.

EJEMPLO:

VECTOR ACTUAL:
4 2 7 2 9 2 5

X = 2

DEBE QUEDAR:
4 7 9 5
*/

void eliminarX(vector<int>& datos, int x)
{
    // TU CÓDIGO
}

int main()
{
    vector<int> datos = {4, 2, 7, 2, 9, 2, 5};
    eliminarX(datos, 2);

    for (int x : datos)
        cout << x << " ";
}
