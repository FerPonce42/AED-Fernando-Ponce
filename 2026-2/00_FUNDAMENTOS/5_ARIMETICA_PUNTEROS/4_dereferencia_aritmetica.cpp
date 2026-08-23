/*
PROBLEMA:

Crear un arreglo:

{5, 10, 15, 20, 25}

Crear un puntero al primer elemento.

Mostrar:

- el primer elemento;
- el elemento ubicado dos posiciones adelante;
- el elemento ubicado cuatro posiciones adelante.

Utilizar expresiones de dereferencia y aritmética
de punteros.

No utilizar [].
*/

#include <iostream>
using namespace std;



int main(){
    
    int arreglo[5] = {5, 10, 15, 20, 25};

    int* p = arreglo;

    cout<< *p <<" " << *(p+2) << " "<< *(p+4)<<endl; 

}