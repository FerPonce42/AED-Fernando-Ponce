#include <iostream>
#include <vector>
using namespace std;

struct Registro
{
    int numero;
    int frecuencia;
};

/*
PROBLEMA:

Dado un vector de enteros, construye un vector de Registro.

Cada Registro debe representar un valor distinto y su cantidad
de apariciones.

VECTOR:
4 2 4 7 2 4 9

RESULTADO:
(4,3)
(2,2)
(7,1)
(9,1)

RESTRICCIONES:
- No utilizar map.
- No utilizar set.
- Utilizar vector<Registro>.
- Debes conservar el orden de primera aparición.

FUNCIÓN:
construirFrecuencias(...)

ESTE PROBLEMA NO TE DICE QUÉ TÉCNICA USAR.
TÚ DEBES DECIDIR CÓMO RESOLVERLO.
*/

vector<Registro> construirFrecuencias(const vector<int>& principal)
{
    // TU CÓDIGO
    return {};
}

int main()
{
    vector<int> principal = {4, 2, 4, 7, 2, 4, 9};

    vector<Registro> resultado = construirFrecuencias(principal);

    for (const Registro& r : resultado)
        cout << "(" << r.numero << "," << r.frecuencia << ") ";

    cout << "\n";
}
