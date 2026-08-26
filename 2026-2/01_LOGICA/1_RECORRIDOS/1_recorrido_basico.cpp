/*
PROBLEMA:

Dado un vector de enteros, buscar si un número
determinado existe dentro del vector.

Desde main():

- Crear un vector con varios números.
- Pedir al usuario un número a buscar.
- Recorrer el vector.
- Determinar si el número existe.

Mostrar un mensaje indicando si fue encontrado
o no.

OBJETIVO:

Practicar búsqueda lineal.
*/


#include <iostream>
#include <vector>
using namespace std;



bool BusquedaSimple(const vector<int>& v1, int valor){ // agregar CONST para que NADA SE MODIFIQUE y mande ERROR. y... Referencia porque es un objeto. Si fuera un Arreglo bruto recibe un puntero de una.

    const int* ini = nullptr;
    const int* fin = nullptr;

    // asumire que el vector esta lleno para no redundar en.. bueno. logica de empty y eso. aunque no estaria de mas.

    if(v1.empty()){
        cout<<"Vector vacio, nada que encontrar. "<<endl;
        return false;
    }else{

        ini = v1.data(); //data nos da &arr[0];
        fin = v1.data() + v1.size() - 1; // size es cant elemetos validos.


        while(ini <= fin){
            
            if(valor == *ini){
                cout<<"El valor: "<< *ini << " fue encontrado."<<endl;  
                return true;
            }else{
                ini++;
            }

        }


        cout<<"El valor: "<< valor << " no existe en este vector."<<endl; 
        return false;
    }

}


int main(){

    vector<int> v1 = {4,9,0,70,20,25,76} ; 


    BusquedaSimple(v1, 0);

}