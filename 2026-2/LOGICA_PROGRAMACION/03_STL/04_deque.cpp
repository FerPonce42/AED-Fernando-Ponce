#include <iostream>
#include <deque>
using namespace std;

/*
PROBLEMA:

Simula una estructura que recibe elementos por ambos extremos.

Debes implementar:

- agregarInicio(X)
- agregarFinal(X)
- eliminarInicio()
- eliminarFinal()

Utiliza std::deque<int>.

OBJETIVO:
Practicar las operaciones disponibles en ambos extremos.
*/

void agregarInicio(deque<int>& datos, int x)
{
    // TU CÓDIGO
}

void agregarFinal(deque<int>& datos, int x)
{
    // TU CÓDIGO
}

void eliminarInicio(deque<int>& datos)
{
    // TU CÓDIGO
}

void eliminarFinal(deque<int>& datos)
{
    // TU CÓDIGO
}

void imprimir(const deque<int>& datos)
{
    for (int x : datos)
        cout << x << " ";
    cout << "\n";
}

int main()
{
    deque<int> datos;

    agregarFinal(datos, 5);
    agregarFinal(datos, 8);
    agregarInicio(datos, 2);
    agregarInicio(datos, 1);

    imprimir(datos);

    eliminarInicio(datos);
    eliminarFinal(datos);

    imprimir(datos);
}
