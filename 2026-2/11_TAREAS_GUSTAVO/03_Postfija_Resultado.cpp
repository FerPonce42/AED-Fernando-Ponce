/*

TAREA 3: 

PRIMERA PARTE

3 vectores aqui? alglo como 2 colas y no se que


Algoritmo para convertir expresiones infijas es postfijas (RPN)

usaremos el  vector.


La operacion.. esta la subirá al moodle.

Lo que hay que hacer es tranformar

operaciones pos fijas a in fijas.

Ejemplo:


-(3+5) * (7-4)


TUS EXPRESIONES tendran sentido con 1 digito. para no pelear con 2 digitos.

Para la operacion sip uedn hacerlo con todo los dijistos.
primero ingreso

El vector es todo esto 


TU VECTOR se comportara como una pila.


tendras que convertirlo a Templates.

y vas a necesitar numeros]

SIGNOS VAN A LA PILA

LOS NUMEROS VAN AL DESPLIEGUE ESTE FUNCIONA COMO UNA COLA


cuando detecta el ) hace pop a la pila o algo asi entendi y lueg o continua con lo que fatla.

osea parentesis que cierra saca todos los elementos ahasta encontrar el partenisis que abre. 

ya no hay nada en la lista de ingreso.

coge lo que esta en la pila y lo metes al desplique.

al final te queda algo como
3 5 + 7 4 - *

INFIJA -> POSTFUJA


SEGUNDA PARTE DEL ALGORITMO:
Usando ese resultado comenzaremos a operar para tener el resultado.


SI NO ES OEPRADOR mete a la pila!

EL QUE VENGA OPERADOR sacas los que estan en la pila y lo pegas
hay que tener cuidado en la operacion 
5 + 3 = 8

SE DEBIO HAABER HECHO:  5 + 3? no se quediablos dijo el profe qeu se equivocó en su diapo.

el orden es...
7 - 4 = 3
(CORRECTO)

finalmente agarramos el utlimo elemento y agarra los que estan e la mipila y balbl en si las oeperaciones se hacen deotro de la pila aparentemnete.


ENTREGABLE:

INGRES AEXPRESION
EVALUE 
Y DE RESULTADO

REVISA EL PPTX QUE DEJO EN EL MOODLE, SI OISTE BIEN, AL FIN USAN EL MOODLE

*/

/*
La cumbia de los minions
*/

#include <iostream>
using namespace std;



template<class T>
struct Vector{

    int ELEM;
    int TAM = 6;

    T* ARR = new T[TAM];

    Vector(){
        ELEM = 0; 
    }

    ~Vector(){
        delete[] ARR;
    }


    void colapse(); // YA

    void expand(); // YA

    void push_front(T valor);  //YA

    void push_back(T valor); //YA
    void pop_front();  //YA
    void pop_back(); //YA

    T& operator[](int valor); //ya ta 

    T& front(); // ya ta
    T& back(); // ya ta 

    void print(); //ya ta

};

template<class T>
void Vector<T>::expand(){
    TAM*=2;
    T* ARR_E = new T[TAM];

    T* p = ARR;
    T* q = ARR_E;

    T* fin = ARR + ELEM;

    while(p < fin){
        *q = *p; 
        p++;
        q++;
    }

    delete[] ARR;
    ARR = ARR_E;
}

template<class T>
void Vector<T>::colapse(){

    if(TAM <= 6) return;
    TAM/=2;

    T* ARR_C = new T[TAM];

    T* p = ARR;
    T* fin_ARR = ARR + ELEM;
    T* q = ARR_C;

    while(p < fin_ARR){

        *q = *p;
        p++;
        q++;

    }

    delete[] ARR;

    ARR = ARR_C;

}

template<class T>
void Vector<T>::push_back(T valor){

    if(ELEM == TAM){
        expand();
    }

    T* p = ARR;

    *(p + ELEM) = valor;

    ELEM++;

}

template<class T>
void Vector<T>::push_front(T valor){

    if(ELEM == TAM){
        expand();
    }

    T* p = ARR;
    T* q = ARR + ELEM;
    while(p < q){

        *q = *(q - 1);
        q--;

    }

    *p = valor;

    ELEM++;

}

template<class T>
void Vector<T>::pop_back(){
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

template<class T>
void Vector<T>::pop_front(){

    if(ELEM == 0){
        cout<<"NADA QUE SACAR, VACIO!"<<endl;
        return;       
    }

    T* p = ARR;
    T* q = ARR + ELEM - 1;

    while(p < q){

        *p = *(p + 1);
        p++;
    }

    ELEM--;

    if(ELEM <= TAM/2){
        colapse();
    }

}


template<class T>
T& Vector<T>::operator[](int valor){
    return *(ARR + valor);
}

template<class T>
T& Vector<T>::front(){

    return *ARR;

}

template<class T>
T& Vector<T>::back(){

    return *(ARR+ELEM-1);
}



template<class T>
void Vector<T>::print(){
    T* p = ARR;
    T* q = ARR + ELEM;

    while(p < q){
        cout<< *p <<" ";
        p++;
    }

    cout<<endl;
    
}


int main() {

}