/*
PROBLEMA:

Crear una función que reciba un entero y le sume 10.

Desde main():

- Crear un entero con valor 5.
- Mostrar su valor antes de llamar a la función.
- Llamar a la función.
- Mostrar nuevamente el valor después de llamar a la función.

OBJETIVO:

Comprobar qué ocurre cuando una función recibe un dato
por valor.

IMPORTANTE:
La función debe intentar modificar el número recibido.
*/

#include <iostream>
using namespace std;

void SumarDiez(int numero){
    numero += 10;
}


int main(){
    int n = 10;

    cout<< "Actual: "<< n <<endl;

    SumarDiez(n);

    cout<< "Despues: "<< n <<endl;

}