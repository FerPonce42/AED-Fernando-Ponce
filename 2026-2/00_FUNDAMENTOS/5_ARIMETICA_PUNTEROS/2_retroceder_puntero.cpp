/*
PROBLEMA:

Crear un arreglo de 5 enteros.

Colocar un puntero inicialmente sobre el último
elemento.

Utilizando aritmética de punteros:

- mostrar el último elemento;
- retroceder;
- mostrar el anterior;
- continuar hasta llegar al primero.

No utilizar [].
*/

#include <iostream>
using namespace std;

int main(){

    int arreglo[5] = {10,20,30,40,50};

    int* p = arreglo;

    p = (p + 4);

    for(int* i = p ; i >= arreglo ; i--){
        cout<< *i <<" ";
    }


}