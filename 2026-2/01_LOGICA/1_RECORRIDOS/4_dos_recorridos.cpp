/*
PROBLEMA 2: INVERSIÓN IN-PLACE CON DOS PUNTEROS

Dado un vector de enteros, invertir el orden de sus elementos 
directamente en la memoria original (sin crear vectores auxiliares)
usando dos punteros que avanzan en sentidos opuestos.

Desde main():

- Crear un vector con varios elementos.
- Pasar el vector por referencia (vector<int>&) a la función.
- Inicializar un puntero al inicio (izq) y otro al final (der).
- Intercambiar los valores apuntados mientras los punteros no se crucen.
- Mostrar el vector resultante en main().

OBJETIVO:

Dominar la técnica de dos punteros (Two Pointers), la mutación 
directa por referencia y la condición de convergencia (izq < der).
*/

#include <iostream>
#include <vector>
using namespace std;

void InPlace(vector<int> &v){

    int* p = v.data();
    int* q = v.data() + v.size() - 1;
    int tmp = 0;
    while(p <=  q){

        tmp = *p;
        *p = *q;
        *q = tmp;

        p++;
        q--;

    }


}

void print(vector<int> &v){

    int* p = v.data();
    int* q = v.data() + v.size();


    if(v.empty()){
        return;
    }

    while( p <  q){

        cout << *p <<" ";
        p++;
    }

    cout<<endl;

}


int main(){

    vector<int> v = {1,2,3,4,5,6,7,8,9,10, 11};

    print(v);

    InPlace(v);

    print(v);

}