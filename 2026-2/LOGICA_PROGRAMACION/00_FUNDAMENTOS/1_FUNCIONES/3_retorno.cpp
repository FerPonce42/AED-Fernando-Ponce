/*
PROBLEMA:
Crear una función que reciba un entero n y calcule la suma de todos los
números desde 1 hasta n.

Ejemplo:
n = 5
resultado = 15

La función debe retornar el resultado.
*/

#include <iostream>
using namespace std;

int SumaHastaN(int a){

    int sumatoria = 0;

    for(int i = 0 ; i <= a ; i++){
        sumatoria+=i;
    }

    return sumatoria;
}


int main(){
    int n;
    cout<< "Ingresa n: ";cin>> n;

    cout<< SumaHastaN(n)<<endl;
}