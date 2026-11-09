#include <iostream>
#include <vector>
using namespace std;

struct DIVS
{
    bool operator()(int a)
    {
        return a % 3 == 0;
    }
};

/*
PROBLEMA:

Dado un vector y un functor, mueve al inicio todos los elementos
que cumplen la condición del functor.

EJEMPLO:

VECTOR:
5 6 2 9 4 3 8

DIVS:
un elemento cumple si es divisible entre 3.

RESULTADO VÁLIDO:
6 9 3 5 2 4 8

Los elementos que cumplen deben quedar antes que los demás.

RESTRICCIONES:
- No utilizar un segundo vector.
- Debes modificar el mismo vector.
- Utiliza el functor recibido.

FUNCIÓN:
split(...)
*/

template <class O>
void split(vector<int>& datos, O comparador)
{
    // TU CÓDIGO
}
