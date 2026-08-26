/*
PROBLEMA:

Dado un vector de enteros y un número buscado,
encontrar la posición donde aparece dicho número.

Si el número no existe, indicar que no fue encontrado.

Desde main():

- Crear un vector.
- Pedir un número.
- Buscarlo.
- Mostrar su posición.

OBJETIVO:

Diferenciar entre:

valor

posición

índice
*/
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


int BusquedaConCondicion(const vector<int>& v1, int valor){

    const int* ini  = v1.data();
    const int* fin = v1.data() + v1.size() - 1;

    int posicion = 0;


    if(v1.empty()){
        cout<< "Arreglo vacio, nada que encontrar"<<endl;
        return 0;
    }else{

        while(ini <= fin){

            if(valor == *ini){
                
                posicion = v1.size() - (fin - ini);

                return posicion;
            }

            ini++;
        }

        cout<<"El numero que buscas no esta aqui "<<endl;
        return 0;

    }
    
}



int main(){

    vector<int> v1 = {4,9,0,70,20,25,76} ; 


    int posicion = BusquedaConCondicion(v1, 0);

    if(posicion != 0 ){
        cout<< "El elemento a buscar esta en la posicion: "<< posicion <<" del arreglo";
    }

}

