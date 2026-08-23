/*
PROBLEMA:

Crear una función que reciba dos enteros por referencia.

La función debe intercambiar los valores de ambas variables.

Desde main():

- Crear a = 10.
- Crear b = 20.
- Mostrar ambos valores antes.
- Llamar a la función.
- Mostrar ambos valores después.

OBJETIVO:

Practicar referencias modificando más de una variable
original desde una función.
*/

#include <iostream>
using namespace std;

void SwapReferencia(int&a , int& b){
    int tmp = a;
    a = b;
    b = tmp;
}

int main(){

    int a = 10;  int b = 20;

    cout<< "a: "<< a <<endl;
    cout<< "b: "<< b <<endl;

    SwapReferencia(a,b);

    cout<< "a: "<< a <<endl;
    cout<< "b: "<< b <<endl;
}