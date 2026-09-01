/*
La cumbia de los minions
*/

#include <iostream>
using namespace std;

struct Vector{

    int ELEM;
    int TAM = 6;

    int* ARR = new int[TAM];

    Vector(){
        ELEM = 0; 
    }

    ~Vector(){
        delete[] ARR;
    }


    void colapse(); // YA

    void expand(); // YA

    void push_front(int valor);  //YA

    void push_back(int valor); //YA
    void pop_front();  //YA
    void pop_back(); //YA

    int& operator[](int valor); //ya ta 

    int& front(); // ya ta
    int& back(); // ya ta 

    void print(); //ya ta

};


void Vector::expand(){
    TAM*=2;
    int* ARR_E = new int[TAM];

    int* p = ARR;
    int* q = ARR_E;

    int* fin = ARR + ELEM;

    while(p < fin){
        *q = *p; 
        p++;
        q++;
    }

    delete[] ARR;
    ARR = ARR_E;
}


void Vector::colapse(){
    //if (TAM / 2 < 2) return; // Guardián: no achicar la capacidad a menos de 2 ESTE CASO ESTA PARA VER. FER NO LO IMPLEMENTO
    TAM/=2;

    int* ARR_C = new int[TAM];

    int* p = ARR;
    int* fin_ARR = ARR + ELEM;
    int* q = ARR_C;

    while(p < fin_ARR){

        *q = *p;
        p++;
        q++;

    }

    delete[] ARR;

    ARR = ARR_C;

}


void Vector::push_back(int valor){

    if(ELEM == TAM){
        expand();
    }

    int* p = ARR;

    *(p + ELEM) = valor;

    ELEM++;

}

void Vector::push_front(int valor){

    if(ELEM == TAM){
        expand();
    }

    int* p = ARR;
    int* q = ARR + ELEM;
    while(p < q){

        *q = *(q - 1);
        q--;

    }

    *p = valor;

    ELEM++;

}

void Vector::pop_back(){
    if(ELEM == 0){
        cout<<"VACIO! nada que sacar."<<endl;
        return;
    }
    
    ELEM--;

    if(ELEM <= TAM / 2){
         // 2 <= 3
        colapse();
    }
}

void Vector::pop_front(){

    if(ELEM == 0){
        cout<<"NADA QUE SACAR, VACIO!"<<endl;
        return;       
    }

    int* p = ARR;
    int* q = ARR + ELEM - 1;

    while(p < q){

        *p = *(p + 1);
        p++;
    }

    ELEM--;

    if(ELEM <= TAM/2){
        colapse();
    }

}

int& Vector::operator[](int valor){
    return *(ARR + valor);
}


int& Vector::front(){

    return *ARR;

}
int& Vector::back(){

    return *(ARR+ELEM-1);
}




void Vector::print(){
    int* p = ARR;
    int* q = ARR + ELEM;

    while(p < q){
        cout<< *p <<" ";
        p++;
    }

    cout<<endl;
    
}


int main() {
    Vector v;

    cout << "=== CAPACIDAD INICIAL ===" << endl;
    cout << "TAM inicial: " << v.TAM << " | ELEM: " << v.ELEM << endl << endl;

    cout << "=== 1. LLENANDO PARA FORZAR EXPAND() ===" << endl;
    for (int i = 1; i <= 15; i++) {
        v.push_back(i * 5);
        cout << "Agregado " << i * 5 << "\t| ELEM: " << v.ELEM << "\t| TAM: " << v.TAM << "\t| Vector: ";
        v.print();
    }

    cout << endl << "=== 2. VACIANDO PARA FORZAR COLAPSE() ===" << endl;
    while (v.ELEM > 0) {
        v.pop_back();
        cout << "Sacado elemento\t| ELEM: " << v.ELEM << "\t| TAM: " << v.TAM << "\t| Vector: ";
        v.print();
    }

    cout << endl << "=== TODO SOBREVIVIO SIN CRASH ===" << endl;

    return 0;
}