/*
¿Quién tiene más prioridad?
Sin eliminar nada, imprime el elemento con mayor prioridad.
Método: top()
*/

#include <iostream>
#include <queue>
using namespace std;

int main(){

    priority_queue<int> pq;

    pq.push(3);
    pq.push(1);
    pq.push(7);


    cout<<  pq.top();

}