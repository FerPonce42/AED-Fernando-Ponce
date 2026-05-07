/*
Lee el frente y el fondo
Imprime quién está primero en la fila y quién está último, sin eliminar nada.
Métodos: front(), back()
*/

#include <iostream>
#include <queue>
using namespace std;

int main(){

    queue<string> q;

    q.push("primero");
    q.push("segundos");
    q.push("tercero");


    cout<< q.front()<< endl;
    cout<< q.back() << endl;

}