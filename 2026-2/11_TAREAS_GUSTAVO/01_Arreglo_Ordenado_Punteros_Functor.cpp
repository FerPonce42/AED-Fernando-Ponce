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

    T* busquedabin(T e, int ELEM, T ARR[]); 
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

T* LISTA_ORD<T,O,N>::busquedabin(T e, int ELEM, T ARR[]){

    T* ini = nullptr;
    T* fin = nullptr;

    T* mid = nullptr;

    if(ELEM > 0){

        ini = ARR;
        fin = ARR + ELEM - 1;

        while(ini <= fin){

            mid = ini + (fin - ini) / 2 ; 

            if(e == *mid){
                return mid;
            }else if(comparador(e, *mid)){

                fin = mid - 1;

            }else{

                ini = mid + 1;
            }

        }

    }


    return nullptr;

}



template <class T, class O, int N>
bool LISTA_ORD<T,O,N>::del(T e){

    T* ptr_encontrado = busquedabin(e, ELEM, ARR);
    T* fin = nullptr; 
    T* ptr_desplazamiento = nullptr;

    if(ptr_encontrado == nullptr){
        cout<< "El elemento a eliminar, no existe en nuestro arreglo. "<<endl;
        return false;
    }else{

        fin = ARR + ELEM - 1;

        ptr_desplazamiento = ptr_encontrado + 1;

        while(ptr_desplazamiento <= fin){

            *ptr_encontrado = *ptr_desplazamiento;
            ptr_desplazamiento++;
            ptr_encontrado++;

        }

        ELEM--;

        return true;
    }

}





template <class T, class O, int N>
void LISTA_ORD<T,O,N>::print(){
    T* actual = ARR;

    if(ELEM == 0){
        cout<< "Arreglo vacio"<<endl;
        return; 
    }

    for(T* i = actual ; i < actual + ELEM; i++){
        cout<< *i << " ";
    }
    
    cout<< endl;
}

int main() {
    LISTA_ORD<int, ASC<int>, 10> holi;

    // LLenar aarreglo
    holi.add(15);
    holi.add(3);
    holi.add(28);
    holi.add(7);
    holi.add(1);
    holi.add(42);
    holi.add(19);
    holi.add(8);
    holi.add(99);
    holi.add(12);

    holi.print(); // Arreglo completo

    // Borrando hasta morir
    holi.del(1);   // 1
    holi.print();

    holi.del(3);   // 2
    holi.print();

    holi.del(7);   // 3
    holi.print();

    holi.del(8);   // 4
    holi.print();

    holi.del(12);  // 5
    holi.print();

    holi.del(15);  // 6
    holi.print();

    holi.del(19);  // 7
    holi.print();

    holi.del(28);  // 8
    holi.print();

    holi.del(42);  // 9
    holi.print();

    holi.del(99);  // 10 (vacío)
    holi.print();


}