/*
Tarea 1:

Tienes un arreglo con N cant de elementos, al inicio esta vacio.

Controla: 

una add (3);

el 3 se pone al inicio del arreglo.

actualmente:
3 

add(5)

acutlamente: 
3   5


add(4)

3 4 5 (se mueve el 5)


y si hago un del(4)

3  5


template <class T, int N = 10>

class LISTA_ORD{
    int TAM = N;
    int ELEM = 0;
    T ARR[N]; 

    public: 
    bool add (T e);
    bool del(T e);
    void print();
}

TODAS LAS OPERACIONES  CON PUNTEROS, evitar iteradores.
evitar tambien *(arr + i)
ASC por ahora,


usa int * i = 0;

Ahora agrengando la idea de FUntctores.. puntero que apunta avesoa mierda..

template <class T , class O , int N = 10>

el class O es el Functor, basicamente es el orden, ASC o DESC

template <class T>
class ASC{
public:
bool operator()(T a, T, b){
return a < b; 
}
};
*/

#include <iostream>
using namespace std;

template <class T>
class ASC{
    public:
    bool operator()(T a, T b){
        return a < b;
    }
};


template< class T, class O, int N = 10 >
class LISTA_ORD{
    int TAM = N;
    int ELEM = 0;
    T ARR[N];

    public:
        bool add(T e);
        bool del(T e);
        void print();

        bool esVacio();
        bool esLleno();

        void RecibirNumeros();
};

template<class T, class O, int N>
bool LISTA_ORD<T,O,N>::esVacio(){
    if(ELEM == 0){
        return true;
    }
}

template<class T, class O, int N>
bool LISTA_ORD<T,O,N>::esLleno(){
    if(ELEM == TAM){
        return true;
    }
}




template< class T, class O, int N >
bool LISTA_ORD<T,O,N>::add(T e){

    if(esVacio){
        //primer elemn
        int* ini = ARR;
        *ini = e;

        return true;
    }else if(){
        //asignar donde va
    }else{
        //al final
    }

}

template< class T, class O, int N >
bool LISTA_ORD<T,O,N>::del(T e){

    if(esLleno){
        //primer elemn
        int* ini = ARR;
        *ini = e;
    }else if(){
        //asignar donde va
    }else{
        //al final
    }

}

template< class T, class O, int N >
void LISTA_ORD<T,O,N>::print(){

}



template< class T, class O, int N >
void LISTA_ORD<T,O,N>::RecibirNumeros(){

}

int main(){

 
}