#include <iostream>
#include <queue>
using namespace std;

/*
PROBLEMA:

Dada una cola de números, atiende a cada elemento en el mismo
orden en que llegó.

Debes imprimir los elementos mientras salen de la cola.

OBJETIVO:
Comprender FIFO.

COLA:
4 7 2 9

SALIDA:
4 7 2 9
*/

void atender(queue<int>& cola)
{
    // TU CÓDIGO
}

int main()
{
    queue<int> cola;

    cola.push(4);
    cola.push(7);
    cola.push(2);
    cola.push(9);

    atender(cola);
}
