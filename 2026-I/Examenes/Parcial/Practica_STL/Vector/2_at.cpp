/*
Lee un elemento
Dado el vector anterior, imprime el segundo elemento usando acceso seguro (con verificación de rango).
Método: at()
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> v1;

    v1.push_back(5);
    v1.push_back(10);
    v1.push_back(15);


    cout<< v1.at(1)<< endl;

}