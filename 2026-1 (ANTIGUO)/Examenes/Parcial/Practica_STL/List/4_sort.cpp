/*
Ordena la lista
Ordena los elementos de la lista de menor a mayor.
Método: sort()
*/

#include <iostream>
#include <list>
using namespace std;

int main(){

    list<int> l;

    l.push_back(13);
    l.push_front(67);
    l.push_front(1);
    l.push_front(4);
    l.push_front(37);

    for(auto x : l){
        cout<< x << " ";
    }

    cout<<endl;

    l.sort();

    
    for(auto x : l){
        cout<< x << " ";
    }
}