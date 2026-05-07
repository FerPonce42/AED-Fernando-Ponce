/*
Inserta en el medio
Inserta el número 99 en la posición de índice 1 (segundo lugar) del vector.
Método: insert + iterador
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> v1;

    v1.push_back(5);
    v1.push_back(10);
    v1.push_back(15);


    cout<<"Pos 1: "<< v1.at(1)<<endl;

    v1.insert(v1.begin() + 1, 99);
    
    cout<<"Pos 1: "<< v1.at(1)<<endl;


}
