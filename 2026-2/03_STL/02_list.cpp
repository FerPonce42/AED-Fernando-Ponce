#include <iostream>
#include <list>
using namespace std;

/*
PROBLEMA:

Dada una std::list<int>, elimina la primera aparición de X.

Si X no existe, la lista debe permanecer igual.

LISTA ACTUAL:
5 8 3 8 1

X = 8

DEBE QUEDAR:
5 3 8 1

OBJETIVO:
Practicar recorrido e inserción/eliminación en std::list.
*/

void eliminarPrimero(list<int>& datos, int x)
{
    // TU CÓDIGO
}

int main()
{
    list<int> datos = {5, 8, 3, 8, 1};

    eliminarPrimero(datos, 8);

    for (int x : datos)
        cout << x << " ";
}
