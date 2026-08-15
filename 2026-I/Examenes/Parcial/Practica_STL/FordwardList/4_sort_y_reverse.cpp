/*
Ordena e invierte
Ordena la lista y luego invierte su orden con dos llamadas separadas.
Métodos: sort(), reverse()
*/

#include <iostream>
#include <forward_list>
using namespace std;

int main(){

    forward_list<int> fl;

    fl.push_front(6);
    fl.push_front(1);
    fl.push_front(10);

    for(auto x : fl){
        cout<< x <<" ";
    }
    cout<<endl;
    fl.sort();

    for(auto x : fl){
        cout<< x <<" ";
    }
    cout<<endl;
    fl.reverse();

        for(auto x : fl){
        cout<< x <<" ";
    }
    cout<<endl;
}