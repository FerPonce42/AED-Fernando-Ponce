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

template <class T, class O, int N = 10>
class LISTA_ORD{
    int TAM = N;
    int ELEM = 0;
    T ARR[N]; 

    O comparador;

    public: 
    bool add (T e);
    bool del(T e);
    void print();
};

template <class T, class O, int N>
bool LISTA_ORD<T,O,N>::add(T e){

    T* q = ARR;
    T* p = nullptr;
    T valor_tmp = 0;

    if(ELEM == 0){

        *q = e;
        ELEM++;

        return true;

    }else if(ELEM == 1){

        if(comparador(e, *q)){

            valor_tmp = *q;
            q++;
            *q = valor_tmp;
            p = q - 1;
            *p = e;

            ELEM++;

            return true;

        }else{

            q++;
            *q = e;

            ELEM++;

            return true;
        }

    }else if(ELEM == TAM){

        cout << "Imposible meter otro mas, tamos full" << endl;

        return false;

    }else{

        q = ARR + (ELEM - 1);

        if(comparador(e, *q)){

            p = q - 1;

            valor_tmp = *q;
            q++;
            *q = valor_tmp;

            while(p >= ARR){

                if(p == ARR && comparador(e, *p)){

                    valor_tmp = *p;
                    *p = e;
                    p++;
                    *p = valor_tmp;

                    break;

                }else if(comparador(e, *p)){

                    valor_tmp = *p;
                    q = p + 1;
                    *q = valor_tmp;
                    p--;

                }else{

                    q = p + 1;
                    *q = e;
                    break;
                }
            }

            ELEM++;

            return true;

        }else{

            q++;
            *q = e;

            ELEM++;

            return true;
        }
    }
}


template <class T, class O, int N>
void LISTA_ORD<T,O,N>::print(){
    T* actual = ARR;

    for(T* i = actual ; i < actual + TAM ; i++){
        cout<< *i << " ";
    }
    
}

int main(){


    LISTA_ORD<int, ASC<int>, 20 > hola;
    hola.add(15);
    hola.add(3);
    hola.add(28);
    hola.add(7);
    hola.add(19);
    hola.add(2);
    hola.add(31);
    hola.add(11);
    hola.add(25);
    hola.add(1);
    hola.add(17);
    hola.add(9);
    hola.add(22);
    hola.add(5);
    hola.add(30);
    hola.add(13);
    hola.add(27);
    hola.add(4);
    hola.add(20);
    hola.add(8);

    hola.print();
}