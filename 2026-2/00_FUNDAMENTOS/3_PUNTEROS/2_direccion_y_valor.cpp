/*
PROBLEMA:

Crear un entero con valor 10 y un puntero que
apunte hacia él.

Mostrar el valor de la variable utilizando
el puntero.

Después, modificar el valor de la variable
utilizando únicamente el puntero.

Finalmente, mostrar el valor desde main().

OBJETIVO:

Practicar la dereferencia de un puntero para
modificar una variable original.
*/

#include <iostream>
using namespace std;

int main(){

    int entero = 10;

    int* p = &entero;

    cout<< "valor obtenido mediante el puntero: "<< *p <<endl;

    *p = 50;

    cout<< "valor obtenido mediante el puntero: "<< *p <<endl;
}