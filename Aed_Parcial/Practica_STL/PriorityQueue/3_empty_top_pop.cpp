/*
Procesa todos en orden
Con un loop, imprime y elimina cada elemento. ¿En qué orden salen?
Métodos: empty(), top(), pop()
*/

#include <iostream>
#include <queue>
using namespace std;

int main(){

    priority_queue<int> pq;

    pq.push(3);
    pq.push(1);
    pq.push(7);

    while(!pq.empty()){
        cout<< pq.top()<<endl;
        pq.pop();
    }
}