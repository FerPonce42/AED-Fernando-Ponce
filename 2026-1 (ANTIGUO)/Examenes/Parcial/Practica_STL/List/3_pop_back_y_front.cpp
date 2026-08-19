/*
Elimina ambos extremos
Quita el primer y el último elemento de la lista.
Métodos: pop_front, pop_back
*/

#include <iostream>
#include <list>
using namespace std;

int main(){

    list<int> l;

    l.push_back(13);
    l.push_front(67);

    l.pop_back();
    l.pop_front();


}