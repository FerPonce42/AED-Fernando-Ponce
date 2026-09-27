#include <iostream>
#include <forward_list>
using namespace std;

/*
PROBLEMA:

Dada una std::forward_list<int>, elimina la primera aparición de X.

Recuerda que forward_list no permite acceder directamente al nodo
anterior mediante una operación equivalente a list.

LISTA ACTUAL:
7 4 9 2 4 8

X = 4

DEBE QUEDAR:
7 9 2 4 8
*/

void eliminarPrimero(forward_list<int>& datos, int x)
{
    // TU CÓDIGO
}

int main()
{
    forward_list<int> datos = {7, 4, 9, 2, 4, 8};

    eliminarPrimero(datos, 4);

    for (int x : datos)
        cout << x << " ";
}
