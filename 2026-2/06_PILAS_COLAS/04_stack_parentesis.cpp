#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
PROBLEMA:

Determina si una expresión tiene correctamente balanceados
los símbolos:

( )
[ ]
{ }

EJEMPLOS:

({[]}) -> válido
([)]   -> inválido
((())) -> válido
(()    -> inválido

UTILIZA:
std::stack<char>
*/

bool balanceado(const string& expresion)
{
    // TU CÓDIGO
    return false;
}

int main()
{
    cout << balanceado("({[]})") << "\n";
    cout << balanceado("([)]") << "\n";
}
