/*
Elimina de ambos extremos
Quita el primer elemento y luego el último del deque.
Métodos: pop_front, pop_back
*/
#include <iostream>
#include <deque>
using namespace std;

int main(){

    deque<int> d;

    d.push_front(1);
    d.push_back(2);

    d.pop_front();
    d.pop_back();
}