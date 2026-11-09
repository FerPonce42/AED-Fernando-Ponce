/*
PROBLEMA:

Crear una función que reciba un puntero a entero.

La función debe aumentar en 5 el valor al que
apunta el puntero.

Desde main():

- Crear un entero con valor 15.
- Mostrarlo.
- Pasar su dirección a la función.
- Mostrarlo nuevamente.

OBJETIVO:

Practicar punteros como parámetros y comprender
cómo una función puede modificar una variable
mediante su dirección.
*/

#include <iostream>
using namespace std;

void Incrementar(int* x){

    *x += 5;

}

int main(){

    int entero = 15;

    Incrementar(&entero);

    cout<< entero;

}