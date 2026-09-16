/*
PROBLEMA:

Tienes el arreglo:

{10, 25, 7, 18, 30, 4}

Pedir un número al usuario.

Si el número existe, mostrar la posición en la que
se encuentra por primera vez.

Si no existe, indicarlo.

OBJETIVO:

Además de encontrar un elemento, aprender a conservar
la posición donde fue encontrado.
*/


#include <iostream>
using namespace std;

int BusquedaPosicion(int valor, int*& p){

    int* fin = p + 5;
    int* ARR = p;

    while(p <= fin && *p != valor){

        p++;

    }

    int indice = p - ARR;

    if(p > fin){
        return -1;
    }else{
        return indice;
    }
    
}


int main(){

    int ARR[6] = {10, 25, 7, 18, 30, 4};
    int* p = ARR;

    int valor = 888;
    
    int hey = BusquedaPosicion(valor, p);
    if (hey == -1) {
        cout << "El numero " << valor << " NO existe en el arreglo." << endl;
    } else {
        cout << "El numero " << valor << " si esta en la pos: " << hey << endl;
    }

}