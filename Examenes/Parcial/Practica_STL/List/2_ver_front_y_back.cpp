/*
Lee primero y último
Imprime el primer y último elemento de la lista con los métodos correspondientes.
Métodos: front(), back()
*/

#include <iostream>
#include <list>
using namespace std;

int main(){

    list<int> l;

    l.push_back(13);
    l.push_front(67);


    cout<< l.front()<<endl;
    cout<< l.back()<<endl;

}