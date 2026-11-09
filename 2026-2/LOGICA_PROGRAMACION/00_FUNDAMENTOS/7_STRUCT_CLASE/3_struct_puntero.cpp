/*
PROBLEMA:

Crear un struct Nodo con:

- int dato;
- Nodo* siguiente.

Crear dinámicamente un Nodo utilizando un puntero.

Asignarle un valor.

Mostrar el dato mediante el puntero.

Liberar la memoria.
*/

#include <iostream>
#include <vector>
using namespace std;

struct Nodo{

    int dato;
    Nodo* siguiente;
    
    Nodo(int v) : dato(v), siguiente(nullptr) {}
};

int main(){

    Nodo* nodo = new Nodo(10);

    cout << nodo->dato <<endl;

    delete nodo;


}