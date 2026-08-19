#include <iostream>
using namespace std;


void f1(int x){
    x = x+1;
}

void f2(int &y){
    y = y+1;
}

void f3(int* z){
    *z = *z + 1;
}
int main(){

// 3 formas, POR COPIA, REFERENCIA, MEDIANTE PUNTERO

int a = 3;

f1(a);
f2(a);
f3(&a);

}


/*
    int a = 3;
    int* p = &a;
    int** q = &p;
    int*** z = &q;

    cout<< "p : "<< p <<endl; 
    cout<< "q : "<< *q <<endl;


    int b = 10;

    cout<< "z : " << ***z <<endl;
    **z = &b;
    cout<< "z : "<< ***z<<endl;
*/


/*



SEGUNDO:

void Imprimir(int arreglo[]){

    for(int i = 0 ; i < 5 ; i++){
        cout<< arreglo[i] << " ";
    }
    cout<< endl;
}


    int arr[4] = {3,7,9,4}; 

    Imprimir(arr);

    int* p = arr;

    *p = 8;

    Imprimir(arr);
    *(p + 2) = 2;
    Imprimir(arr);

    *(p + 4) = 9; // fuera del arreglo
    Imprimir(arr);
*/


/*
    PRIMERO : 
    int a = 3; 
    int* p; 

    p = &a;

    *p = 8; 

    cout<<" a: " << a <<endl;
    // a esto se le llama: refenencia de a. Pues es otra forma de llamar a "a"", como un AS en SQL
    int& r = a;
    //r = 7;

    cout<<" r pero que es a: " << r <<endl;
    int x = 5;
    int* q = &x;
    
    int* & qq = q;


    cout<< *q <<endl;


    cout<< *qq <<endl;


*/