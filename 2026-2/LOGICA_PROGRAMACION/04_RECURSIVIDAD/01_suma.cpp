#include <iostream>
using namespace std;

/*
PROBLEMA:

Dado N >= 0, devuelve la suma:

1 + 2 + 3 + ... + N

RESTRICCIONES:
- No utilizar ciclos.
- Resolver mediante recursividad.

OBJETIVO:
Identificar claramente:
1. Caso base.
2. Caso recursivo.
*/

int suma(int n)
{

    if(n == 0){
        return 0;
    }

    return n + suma(n-1);

}

int main()
{
    cout << suma(5) << "\n";
}
