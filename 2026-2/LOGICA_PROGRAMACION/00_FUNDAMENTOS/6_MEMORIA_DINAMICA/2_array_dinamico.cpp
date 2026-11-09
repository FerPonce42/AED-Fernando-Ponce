/*
PROBLEMA:

Pedir al usuario el tamaño de un arreglo.

Reservar dinámicamente un arreglo de enteros
con ese tamaño.

Llenarlo mediante un recorrido.

Mostrar todos sus elementos.

Liberar correctamente la memoria.

OBJETIVO:

Practicar new[], delete[] y memoria dinámica.
*/

#include <iostream>
using namespace std;

int main(){

    int tamano = 0;
    cout<<"Tamano del arreglo: ";cin >> tamano;

    int* arreglo = new int[tamano];

    int dato = 0 ; 
    for(int* i = arreglo ; i < arreglo + tamano ; i++){
        cout<<"Dato: "; cin>> dato;

        *i = dato;
    }

    for(int* i = arreglo ; i < arreglo + tamano ; i++){
        cout<<*i<<" ";
    }

    delete[] arreglo;
}