/*
PROBLEMA:

Crear una función que reciba un entero mediante
referencia constante.

La función debe imprimir el valor recibido.

Desde main():

- Crear un entero con valor 50.
- Llamar a la función.
- Intentar modificar el valor recibido dentro
  de la función.

OBJETIVO:

Comprobar qué permite y qué impide una referencia
constante.
*/
#include <iostream>
using namespace std;

void Imprimir(const int& x){
    cout << x << endl;
    //x = 10; //no permite compilar pues el argumento indica que ese entero que entre NO se puede modoficar.
}

int main(){
    int x = 5;
    Imprimir (x);

}