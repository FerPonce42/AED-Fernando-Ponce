#include <iostream>
using namespace std;

struct Arreglo{

    static const int tamano = 10;
    int elementos;
    int ARR[tamano];

    Arreglo(){
        elementos = 0; 
    }

    void push_front(int valor); // ya ta
    void push_back(int valor); // ya ta 
    void pop_front(); // ya ta
    void pop_back(); // ya ta

    int& operator[](int valor); // No se si es con REferencia.

    int& front();
    int& back();

    void print();



};


void Arreglo::push_front(int valor){

    int* ini = ARR;
    int* p = ARR;
    int* q = ARR + elementos - 1;

    if(elementos == 0){
        *ini = valor;
        elementos++;
    }else if(elementos < tamano){
        while(q >= p){
            *(q + 1) = *q;
            q--;
        }

        *ini = valor;
        elementos++;
    }else{
        cout<<"LLENO!"<<endl;
    }


}

void Arreglo::push_back(int valor){

    int* q = ARR + elementos; 

    if(elementos < tamano ){ // primera inserccion y als que vengan

        *q = valor;
        elementos++;

    }else{

        cout<<"Arreglo FULL"<<endl;
        return;
    }


}


void Arreglo::pop_back(){

    int* q = ARR + elementos - 1;

    //  12 16 54 32 12
    // 5

    if(elementos == 0){

        cout<< "No se puede  quitar, no hay elementos"<<endl;

        return; 
    }else{

        --q;
        elementos--;
    }


}

void Arreglo::pop_front(){

    int* p = ARR;
    int* fin = ARR + elementos - 1;

    if(elementos == 1){
        p = nullptr;
        elementos--;
    }else if(elementos >= 1){

        while(p < fin){
            *p = *(p + 1);
            p++;
            
        }

        elementos--;

    }else{
        cout<<"ARR vacio, nada que sacar"<<endl;
    }


}

int& Arreglo::back(){

    int* p = ARR + elementos - 1;

    return *p;

}

int& Arreglo::front(){

    int* p = ARR;

    return *p;

}

int& Arreglo::operator[](int valor){
    int* p = ARR;
    return *(p + valor);
}

void Arreglo::print(){

    int* p = ARR;
    int* q = ARR + elementos; 

    // 10 3 5 1 = 4 elementos..
    while(p < q){

        cout<< *p <<" ";

        p++;
    }

    cout<<endl;

}



int main(){

    Arreglo arr1;

    arr1.push_front(1);
    arr1.push_front(41);
    arr1.push_front(22);
    arr1.push_front(63);
    arr1.push_front(29);

    arr1.print();


    arr1.back() = 1000;
    arr1.print();

    arr1.front() = 2000;
    arr1.print();


    arr1[2] = 100000;
    arr1.print();
}