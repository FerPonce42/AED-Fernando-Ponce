/*
PROBLEMA:

Crear un struct Producto con:

- nombre;
- precio.

Crear un vector de Productos.

Agregar varios productos.

Recorrer el vector e imprimir sus datos.
*/

#include <iostream>
#include <vector>
using namespace std;

struct Producto{

    string nombre;
    float precio; 
};

int main(){

    vector<Producto> v1(3);

    v1[0].nombre = "Arroz"; v1[0].precio = 10.50;
    v1[1].nombre = "Papas"; v1[1].precio = 8.50;
    v1[2].nombre = "Harina"; v1[2].precio = 20.50;


    cout<<"ABARROTES///"<<endl;
    for(int i = 0 ; i < v1.size() ; i++){

        cout<< v1[i].nombre << "-- S/. "<< v1[i].precio<<endl;

    }

}