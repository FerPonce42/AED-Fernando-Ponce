/*
PROBLEMA:

Crear un struct Nodo que contenga:

- un entero dato;
- un puntero Nodo* siguiente.

Crear una función que reciba un Nodo**.

La función debe crear dinámicamente un nuevo nodo
y hacer que el puntero recibido apunte hacia él.

Desde main(), mostrar el dato almacenado.

OBJETIVO:

Relacionar puntero doble + struct + memoria dinámica.

NOTA:
No preocuparse todavía por implementar una lista completa.
*/

#include <iostream>
using namespace std;


struct Nodo{
    int dato;
    Nodo* next;

    Nodo(int n){
        dato = n;
        next = nullptr;
    }
};


void NuevoNodo(Nodo** nuevo, int numero){

    Nodo* nodo = new Nodo(numero);

    *(nuevo) = nodo;

}

int main(){
    
  Nodo* head = nullptr;

  int n = 10;


  NuevoNodo(&head, n);


  cout<< head->dato << endl;
}