#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
PROBLEMA:

Dada una palabra, determina si es un palíndromo utilizando
std::stack.

Ejemplo:

RADAR -> true
CASA  -> false

IDEA:
Una pila permite recuperar los caracteres en orden inverso.

RESTRICCIÓN:
La comparación debe utilizar una std::stack.
*/

bool esPalindromo(const string& palabra)
{
    // TU CÓDIGO
    return false;
}

int main()
{
    cout << esPalindromo("RADAR") << "\n";
    cout << esPalindromo("CASA") << "\n";
}
