/*
Elimina después de un iterador
Elimina el elemento que está justo después del inicio de la lista.
Método: erase_after + before_begin()
*/

#include <iostream>
#include <forward_list>
using namespace std;

int main(){

    forward_list<int> fl;

    fl.push_front(1);
    fl.push_front(2);
    fl.push_front(3);

    fl.erase_after(fl.before_begin());


}