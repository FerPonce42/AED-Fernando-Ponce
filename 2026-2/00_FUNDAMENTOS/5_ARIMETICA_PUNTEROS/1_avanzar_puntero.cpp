/*
PROBLEMA:

Crear un arreglo:

{10, 20, 30, 40, 50}

Crear un puntero al primer elemento.

Mostrar:

- primer elemento;
- segundo elemento;
- tercer elemento;

utilizando aritmética de punteros.

No utilizar [].
*/

#include <iostream>
using namespace std;

int main(){

    int arreglo[5] = {10,20,30,40,50};

    int* p = arreglo;

    cout<< *p <<endl;
    cout<< *(p+1) <<endl;
    cout<< *(p+2) <<endl;
}