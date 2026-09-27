#include <iostream>
#include <set>
#include <vector>
using namespace std;

/*
PROBLEMA:

Dado un vector que puede contener valores repetidos, construye
un std::set con los valores distintos.

VECTOR:
5 2 5 8 2 1 8 9

SET ESPERADO:
1 2 5 8 9

OBJETIVO:
Practicar inserción en set y comprender que no conserva duplicados.
*/

set<int> obtenerDistintos(const vector<int>& datos)
{
    // TU CÓDIGO
    return {};
}

int main()
{
    vector<int> datos = {5, 2, 5, 8, 2, 1, 8, 9};

    set<int> resultado = obtenerDistintos(datos);

    for (int x : resultado)
        cout << x << " ";
}
