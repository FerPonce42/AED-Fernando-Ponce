/*
Borra un elemento específico
Elimina el elemento que está en la posición de índice 2.
Método: erase + iterador
*/


#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> v1;

    v1.push_back(5);
    v1.push_back(10);
    v1.push_back(15);

    v1.erase(v1.begin() + 2);


    

}