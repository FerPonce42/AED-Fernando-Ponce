/*
PROBLEMA:

Reservar dinámicamente memoria para un entero.

Asignarle el valor 100.

Mostrarlo.

Liberar correctamente la memoria.

OBJETIVO:

Practicar new, dereferencia y delete.
*/

#include <iostream>
using namespace std;

int main(){

    int* numero = new int(100);

    cout<< *numero << endl;

    delete numero;

}