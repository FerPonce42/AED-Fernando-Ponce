/*
PROBLEMA:

Crear un struct Persona que contenga:

- nombre;
- edad.

Crear una Persona desde main() y asignarle valores.

Mostrar sus datos.
*/

#include <iostream> 
using namespace std;

struct Persona{
    string nombre;
    int edad; 
};

int main(){

    Persona p1;

    p1.nombre =  "Fernando";
    p1.edad = 20 ;


    cout<< p1.nombre <<" y tiene  "<<p1.edad <<endl;
}