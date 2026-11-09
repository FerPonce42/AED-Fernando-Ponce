#include <iostream>
#include <queue>
using namespace std;

/*
PROBLEMA:

Implementa una cola ordenada utilizando UNA SOLA std::queue.

Debe soportar:

pushx(X)   -> inserta X manteniendo el orden
frontx()   -> devuelve el menor elemento
popx()     -> elimina el menor elemento
remx(X)    -> elimina todas las apariciones de X
printx()   -> imprime la cola

SE PERMITEN REPETIDOS.

RESTRICCIONES:
- Solo una std::queue.
- No vector.
- No list.
- No deque.
- No stack.
- No set/map.

OBJETIVO:
Resolver el problema respetando estrictamente la restricción.
*/

class CSortedQueue
{
private:
    queue<int> datos;

public:

    void pushx(int x)
    {
        // TU CÓDIGO
    }

    int frontx()
    {
        // TU CÓDIGO
        return 0;
    }

    void popx()
    {
        // TU CÓDIGO
    }

    void remx(int x)
    {
        // TU CÓDIGO
    }

    void printx()
    {
        // TU CÓDIGO
    }
};

int main()
{
    CSortedQueue q;

    q.pushx(7);
    q.pushx(2);
    q.pushx(5);
    q.pushx(2);
    q.pushx(9);

    q.printx();
}
