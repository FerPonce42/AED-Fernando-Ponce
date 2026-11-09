/*
PROBLEMA:
Crear una función que reciba dos enteros y devuelva el mayor de ellos.

Desde main():
- declarar dos números;
- llamar a la función;
- mostrar el valor retornado.

La función debe realizar la comparación.
*/

#include <iostream>
using namespace std;

int determinarMayor(int a, int b){

    if(a < b){
        
        return b;
    }else if(a == b){
        cout<<"Ambos valores son iguales: ";
        return a;
        
    }else{
        
        return a;
    }

}


int main(){
    int n1,n2;
    cout<<"Ingresa tus numeros:"<<endl; 
    cin>> n1 ; cin>>n2;

    cout<<"El mayor es: "<< determinarMayor(n1,n2);


}