/*
Acceso por índice
Imprime el tercer elemento del deque sin verificación de rango.
Operador []
*/

#include <iostream>
#include <deque>
using namespace std;

int main(){

    deque<int> d;

    d.push_back(4);
    d.push_back(2);
    d.push_back(1);

    cout<< d[2];
}
