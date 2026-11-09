#include <iostream>
#include <vector>
using namespace std;

/*
PROBLEMA:

Determina recursivamente si X aparece en el vector.

RESTRICCIONES:
- No utilizar ciclos.
- No utilizar find.

La función debe revisar desde la posición indicada.
*/

bool existe(const vector<int>& datos, int pos, int x)
{
    // TU CÓDIGO
    return false;
}

int main()
{
    vector<int> datos = {4, 7, 1, 9, 3};

    cout << existe(datos, 0, 9) << "\n";
    cout << existe(datos, 0, 8) << "\n";
}
