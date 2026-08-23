/*
PROBLEMA:

Crear un entero con valor 25.

Crear un puntero que almacene la dirección
de ese entero.

Mostrar:

- El valor del entero.
- La dirección del entero.
- El valor obtenido mediante el puntero.

OBJETIVO:

Diferenciar:

valor
dirección
puntero
dereferencia
*/

#include <iostream>
using namespace std;

int main(){

    int entero = 25;

    int* p = &entero;

    cout<< "valor del entero: "<< entero <<endl;
    cout<< "direccion del entero: "<< p <<endl;
    cout<< "valor obtenido mediante el puntero: "<< *p <<endl;

}