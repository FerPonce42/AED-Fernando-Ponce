/*
Tamaño del deque
Imprime cuántos elementos tiene el deque actualmente.
Método: size()
*/
#include <iostream>
#include <deque>
using namespace std;

int main(){

    deque<int> d;

    d.push_back(4);
    d.push_back(2);
    d.push_back(1);

    cout<< d.size();
}
