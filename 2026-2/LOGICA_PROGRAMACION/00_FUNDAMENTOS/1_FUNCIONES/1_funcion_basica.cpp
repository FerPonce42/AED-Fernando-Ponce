/*
PROBLEMA:
Crear una función que reciba un entero y determine si el número es positivo,
negativo o cero.

La función debe encargarse de toda la lógica e imprimir el resultado.
main() solamente prepara el dato y llama a la función.
*/

#include <iostream>
using namespace std;

void determina(int x){ // dentro de la funcion tiene q identificar si es positivo, cero, negativo

    if (x > 0){
        cout<< "Positivo"<<endl;
    }else if(x == 0){
        cout<< "Cero"<<endl;
    }else{
        cout<< "Negativo"<<endl;        
    }

}



int main(){

    int n = 0;
    cout<<"holi: ";  cin>>n;


    determina(n);

}