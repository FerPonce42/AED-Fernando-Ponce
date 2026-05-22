/*
Ejercicio 6
¿Está vacío?
Escribe una condición que solo imprima 'vacío' si el vector no tiene elementos.
Método: empty()
*/

#include <iostream>
#include <vector>
using namespace std;


int main(){

    vector<int> v1;

    v1.push_back(10);

    if(v1.empty()){
        cout<<"Vector vacio"<<endl;
    }else{
        cout<<"Vector con elementos"<<endl;
    }


}