/*
PROBLEMA:

Crear un arreglo de 5 enteros.

Crear un puntero que apunte al primer elemento.

Utilizando únicamente el puntero y aritmética
de punteros:

- Recorrer todos los elementos.
- Mostrar sus valores.

No utilizar [] para recorrer el arreglo.

OBJETIVO:

Practicar la relación entre arreglos, punteros
y aritmética de punteros.
*/
#include <iostream>
using namespace std;

int main(){

    int arreglo[5] = {54,24,115,12,56};

    int* fin = (arreglo + 5);

    for(int* i = arreglo ; i < fin ; i++ ){
        cout<< *i <<" ";
    }

}