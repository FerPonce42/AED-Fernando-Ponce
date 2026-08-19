/*
Agrega en ambos extremos
Declara una list de strings. Inserta 'hola' al frente y 'mundo' al final.
Métodos: push_front, push_back
*/

#include <iostream>
#include <list>
using namespace std;

int main(){

    list<string> l;

    l.push_front("Hola");

    l.push_back("Tu hermana");


    for(auto x: l){
        cout<< x << " ";
    }
}