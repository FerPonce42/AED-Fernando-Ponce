/*
PROBLEMA:

Crear dos enteros:

a = 10
b = 20

Crear un puntero que inicialmente apunte a a.

Crear una función que reciba el puntero mediante
un puntero doble.

La función debe hacer que el puntero pase a
apuntar a b.

Desde main(), comprobar que el puntero ahora
apunta a b.

OBJETIVO:

Comprender por qué se necesita un puntero doble
cuando queremos modificar hacia dónde apunta
un puntero original.
*/

#include <iostream>
using namespace std;

void CambiaDireccion(int** nuevo, int& b){

    *nuevo = &b;

}

int main(){

    int a = 3;
    int b = 10;

    int* p = &a;
    
    cout<< *p <<endl;
    
    CambiaDireccion(&p, b);

    cout<< *p <<endl;
}