/*
PROBLEMA:

Tienes el arreglo:

{8, 3, 15, 2, 9, 4}

Pedir un número al usuario y determinar si se encuentra
dentro del arreglo.

Si se encuentra, indicar que existe.
Si no se encuentra, indicar que no existe.

OBJETIVO:

Practicar una búsqueda lineal recorriendo el arreglo
elemento por elemento.

IMPORTANTE:

No utilizar find() ni otras funciones de STL.
*/

#include <iostream>
using namespace std;
// 8, 3, 15, 2, 9, 4
bool BusquedaLineal(int valor, int*& p){
    int* fin = p + 5;

    while(p <= fin && valor != *p){
        p++;
    }

    return (p <= fin); 
}


int main(){

    int ARR[6] = {8, 3, 15, 2, 9, 4};

    int* p = ARR;
    int valor = 12;
    bool encontro = BusquedaLineal(valor, p);

    if(encontro){
        cout<<"El numero: "<< valor <<" si esta en el ARREGLO"<<endl;
    }else{
        cout<<"El numero: "<< valor <<" NOOO esta en el ARREGLO"<<endl;
    }
    
}