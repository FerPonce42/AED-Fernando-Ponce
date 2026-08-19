/*
Atiende al primero
Elimina el elemento que lleva más tiempo esperando en la cola.
Método: pop()
*/

#include <iostream>
#include <queue>
using namespace std;

int main(){

    queue<string> q;

    q.push("primero");
    q.push("segundos");
    q.push("tercero");

    q.pop();
}