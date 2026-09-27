#include <iostream>
#include <map>
#include <string>
using namespace std;

/*
PROBLEMA:

Una universidad registra la cantidad de créditos de cada curso.

Usa std::map<string, int> para almacenar:

curso -> créditos

Luego, dado el nombre de un curso, devuelve sus créditos.

Si el curso no existe, devuelve -1.
*/

int obtenerCreditos(const map<string, int>& cursos, const string& nombre)
{
    // TU CÓDIGO
    return -1;
}

int main()
{
    map<string, int> cursos;

    cursos["AED"] = 4;
    cursos["BD2"] = 3;
    cursos["SO"] = 4;

    cout << obtenerCreditos(cursos, "AED") << "\n";
    cout << obtenerCreditos(cursos, "Oratoria") << "\n";
}
