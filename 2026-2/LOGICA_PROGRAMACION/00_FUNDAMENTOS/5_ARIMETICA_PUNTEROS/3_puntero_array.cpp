/*
PROBLEMA:

Crear un arreglo de 6 enteros.

Crear una función que reciba un puntero al primer
elemento y el tamaño del arreglo.

La función debe recorrer e imprimir todos los
elementos utilizando únicamente aritmética
de punteros.

No utilizar [].
*/

#include <iostream>
using namespace std;

void Imprimir(int* inicio, int tamano){

    for(int* i = inicio ; i < inicio + tamano ; i++){
        cout<< *i <<" ";
    }

}


int main(){
    
    int arreglo[6] = {10,20,30,40,50,60};

    Imprimir(arreglo, 6);
}