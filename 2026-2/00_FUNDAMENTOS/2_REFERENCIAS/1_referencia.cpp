/*
PROBLEMA:

Crear una función que reciba un entero por referencia.

La función debe modificar el número recibido,
multiplicándolo por 2.

Desde main():

- Crear un entero con valor 7.
- Mostrarlo antes de llamar a la función.
- Llamar a la función.
- Mostrarlo después.

OBJETIVO:

Practicar el uso de referencias y comprobar que
la modificación realizada dentro de la función
afecta directamente a la variable original.
*/

#include <iostream>
using namespace std;

void SacarDoble(int &numero){
    numero *= 2;
}


int main(){
    int n = 7;

    cout<< "Actual: "<< n <<endl;

    SacarDoble(n);

    cout<< "Despues: "<< n <<endl;

}