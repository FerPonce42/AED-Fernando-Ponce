#include <iostream>
#include <vector>
using namespace std;

/*
PROBLEMA:

Implementa Selection Sort para ordenar el arreglo de menor a mayor.

RESTRICCIONES:
- No utilices std::sort.
- Debes modificar el mismo arreglo.

IDEA DEL ALGORITMO:
Selection Sort busca el menor elemento de la parte que todavía
no está ordenada y lo coloca en la posición que corresponde.

ARREGLO ACTUAL:
7 3 9 2 5 1

DEBE QUEDAR:
1 2 3 5 7 9
*/

void selectionSort(vector<int>& arreglo)
{
    int* ini = arreglo.data();
    int* fin = arreglo.data() + arreglo.size() - 1;

    int* p = ini;
    int* q = p + 1;
    int* menor_actual = p;
    int tmp = 0;


    while(p <= fin){

        while(q <= fin){

            if(*p < *q){
                q++;
            }else{
                if(*menor_actual > *q){
                    menor_actual = q;
                }
                q++;
            }

        }

        tmp = *p;
        *p = *menor_actual;
        *menor_actual = tmp;

        p++;
        q = p + 1;
        menor_actual = p;

    }


}

void imprimir(const vector<int>& arreglo)
{
    for (int x : arreglo)
        cout << x << " ";
    cout << "\n";
}

int main()
{
    vector<int> arreglo = {7, 3, 9, 2, 5, 1};

    cout << "Arreglo actual: ";
    imprimir(arreglo);

    selectionSort(arreglo);

    cout << "Arreglo tras Selection Sort: ";
    imprimir(arreglo);
}
