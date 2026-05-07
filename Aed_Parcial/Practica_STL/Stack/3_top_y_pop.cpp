/*
Desapila y mira
Elimina el elemento de arriba y luego imprime el nuevo elemento en la cima.
Métodos: pop(), top()
*/

#include <iostream>
#include <stack>
using namespace std;

int main(){

    stack<int> p;

    p.push(1);
    p.push(2);
    p.push(3);

    p.pop();

    cout<< p.top();

}