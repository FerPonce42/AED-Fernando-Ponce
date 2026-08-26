/*
PROBLEMA 1: BÚSQUEDA EN RECORRIDO INVERSO

Dado un vector de enteros, buscar la ÚLTIMA ocurrencia de un número
recorriendo el vector desde el final hacia el inicio mediante punteros.

Desde main():

- Crear un vector con números (incluyendo elementos repetidos).
- Definir un número a buscar.
- Recorrer el vector en sentido inverso (del último elemento al primero).
- Devolver la posición o índice de su última aparición.
- Mostrar un mensaje si no fue encontrado.

OBJETIVO:

Practicar decrecimiento de punteros (puntero--) y el manejo seguro
del límite inferior de memoria.
*/

#include <iostream>
using namespace std;

int EncontrarPosicionDescendente(int* arreglo, int elem, int valor){

    int* fin = arreglo + (elem - 1);
    int* ini = arreglo;
    int posicion = 0; 
    int pos_arreglo = 0;
    if(elem <= 0){
        cout<<"No hay elementos que buscar, esta vacio"<<endl;
        return 0;
    }else{

        while(fin >= ini){

            if(valor == *fin){
                posicion = (arreglo+elem-1) - fin;

                pos_arreglo = elem - posicion;
                return pos_arreglo;
            }

            fin--;

        }

        
        cout<<"El numero que buscas no esta aqui "<<endl;
        return 0;

    }

}

int main(){

    const int elem = 10 ;
    int arreglo[elem] = { 43,72,32,98,43,6,34,87,10,24};

    int posicion = EncontrarPosicionDescendente(arreglo, elem, 24);

    if(posicion != 0 ){
        cout<< "El elemento a buscar esta en la posicion: "<< posicion <<" del arreglo";
    }





}