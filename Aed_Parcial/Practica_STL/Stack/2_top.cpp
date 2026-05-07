/*
¿Qué hay arriba?
Sin eliminar nada, imprime el elemento que está en la cima del stack.
Método: top()
*/
#include <iostream>
#include <stack>
using namespace std;

int main(){

    stack<int> p;

    p.push(1);
    p.push(2);
    p.push(3);

    cout<< p.top();

}