#include <iostream>
#include <vector>
using namespace std;

/*
PROBLEMA:

Dado un vector no vacío, encuentra el máximo utilizando
recursividad.

La función recibe la posición actual desde la que debe trabajar.

RESTRICCIONES:
- No utilizar ciclos.
- No utilizar std::max_element.

OBJETIVO:
Reducir el problema hasta llegar a un caso base.
*/

int maximo(const vector<int>& datos, int pos)
{

    if(pos == datos.size() - 1){
        return 0;
    }


    maximo(datos, pos + 1);

}

int main()
{
    vector<int> datos = {4, 9, 2, 7, 6};
    cout << maximo(datos, 0) << "\n";
}
