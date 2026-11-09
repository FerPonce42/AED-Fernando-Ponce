/*
PROBLEMA:

Crear una función que reciba un int**.

La función debe reservar dinámicamente memoria
para un entero y asignarle el valor 50.

Desde main():

- declarar un int* sin apuntar inicialmente
  a una variable válida;
- llamar a la función;
- mostrar el valor creado dinámicamente;
- liberar correctamente la memoria.

OBJETIVO:

Practicar int**, new y delete juntos.
*/

#include <iostream> 
using namespace std;

void ReservarMD(int** p){

    *p = new int(50);

}

int main(){

    int* r = nullptr;
    ReservarMD(&r);

    cout<< *r <<endl;

    delete r;

    r = nullptr;
}