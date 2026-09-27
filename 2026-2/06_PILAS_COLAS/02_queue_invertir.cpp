#include <iostream>
#include <queue>
#include <stack>
using namespace std;

/*
PROBLEMA:

Invierte el contenido de una queue.

COLA ACTUAL:
1 2 3 4 5

DEBE QUEDAR:
5 4 3 2 1

PUEDES UTILIZAR:
- la queue recibida
- una std::stack auxiliar

OBJETIVO:
Practicar la interacción entre FIFO y LIFO.
*/

void invertir(queue<int>& cola)
{
    // TU CÓDIGO
}

void imprimir(queue<int> cola)
{
    while (!cola.empty())
    {
        cout << cola.front() << " ";
        cola.pop();
    }
}
