/*
Vacía el stack con un loop
Escribe un while que imprima y elimine cada elemento hasta que el stack esté vacío.
Métodos: empty(), top(), pop()
*/

#include <iostream>
#include <stack>
using namespace std;

int main(){

    stack<int> p;

    p.push(1);
    p.push(2);
    p.push(3);

    while(!p.empty()){
        cout<< p.top()<< endl;
        p.pop();
    }

}