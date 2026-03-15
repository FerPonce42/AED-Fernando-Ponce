/******************************************************************************

    ESTRUCTURA DE DATOS por Gustavo Profe

*******************************************************************************/


/*

1.  REpasar punteros y templates

*/

/*
#include <iostream>
using namespace std;

struct Pila{

    int n_elem;

    int* arr;

    int* top; //parte superior de array

    Pila(int numero);

    ~Pila();

    bool lleno();
    bool vacio();

    bool Push(int val);
    bool Pop(int& val);

};


Pila::Pila(int numero) {
    n_elem = numero;
    arr = new int[n_elem];
    top = NULL;
}

bool Pila::lleno() {
    return top == arr + n_elem - 1;
}


bool Pila::vacio() {
    return !top;
}


bool Pila::Push(int val){

    if (vacio()) {
        top = arr;
    }
    else {
        if (lleno()) {
            return false;
        }
        else {
            top++;
        }
    }

    *top = val;
    return true;
}


bool Pila::Pop(int &val) {

    if (vacio()) {
        return false;

        val = *top;
        top--;

        if (top < arr) {
            top = NULL;
        }
    }
    return true;

}

Pila::~Pila() {
    delete [] arr;
}




int main(){




}
*/






/*
    2. El mismo, pero con templates para que reciba cualquier tipo
*/

#include <iostream>
using namespace std;


template <class T, int n=10>
struct Pila {

    int n_elem;

    T* arr;

    T* top; //parte superior de array

    Pila();

    ~Pila();

    bool lleno();
    bool vacio();

    bool Push(T val);
    bool Pop(T& val);

};

template <class T, int n>
Pila<T,n>::Pila() {
    n_elem = numero;
    arr = new int[n_elem];
    top = NULL;
}

template <class T, int n>
bool Pila<T, n>::lleno() {
    return top == arr + n_elem - 1;
}

template <class T, int n>
bool Pila<T, n>::vacio() {
    return !top;
}

template <class T, int n>
bool Pila<T, n>::Push(T val) {

    if (vacio()) {
        top = arr;
    }
    else {
        if (lleno()) {
            return false;
        }
        else {
            top++;
        }
    }

    *top = val;
    return true;
}

template <class T, int n>
bool Pila<T, n>::Pop(T& val) {

    if (vacio()) {
        return false;

        val = *top;
        top--;

        if (top < arr) {
            top = NULL;
        }
    }
    return true;

}
template <class T, int n>
Pila<T, n>::~Pila() {
    delete[] arr;
}




int main() {

    Pila<int, 20> P_int;

    Pila<char> P_char; // por default la pila tendra 10 elementos (ya lo colocaste en codigo asi)


    if (P_int Push(10)) {
        cout << "Ingreso 10 ";
    }
    else {
        cout << "FALLO :ingreso 10 ";
    }


}