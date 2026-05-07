/*
Inserta después de un iterador
Inserta el valor 7 justo antes del primer elemento real (usando el iterador especial de esta lista).
Método: insert_after + before_begin()
*/

#include <iostream>
#include <forward_list>
using namespace std;

int main(){

    forward_list<int> fl;

    fl.push_front(42);

    fl.insert_after(fl.before_begin(), 7);
    
}