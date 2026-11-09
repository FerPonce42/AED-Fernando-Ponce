/*
PROBLEMA:

Crear un entero con valor 30.

Crear un puntero que apunte al entero.

Crear un puntero doble que apunte al puntero.

Mostrar el valor del entero utilizando el
puntero doble.

OBJETIVO:

Comprender la relación:

int
int*
int**
*/

#include <iostream>
using namespace std;

int main(){

    int n1 = 10;

    int* p = &n1;

    int** q = &p;

    cout<< **q <<endl;

}