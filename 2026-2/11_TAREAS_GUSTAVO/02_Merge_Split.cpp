/*

Nueva tarea:


template< class O>
strurct UTIL{


void split(int* ini ; int* mid ; int * fin; O comparador);

void merge(int* ini ; int* mid ; int * fin);

};



array N elementos

1 2 5 7 30 3 5 11 23 25


MERGE recibe 3 punteros...

INI es 1
MID es .. el 3
fin es 25

MERGE = MEZCLAR 

Debes mezclar los 2 arrays en uno solo.. es como si dividieras el ini a mid y mid a fin otootro arreglo qeuadria asi:

1 2 3 5 5 7 11 23 25 30

CONDICIONES:

OPERACIONES CON PUNTEROS DENTRO DEL METODO.


EVITA HACER OTRO ARREGLO.. TIENE QUE SER DENTRO DELM MISMO ARREGLO.



PARA EL SPLITE::

inifio fin y O compradorar ahi en el struct creo un functor...

EL SPLIT DIVIDIRA!

SEGUN EL CRITERIO QUE TIENE CCOMP

struct DIV3{
    bool operator()(int a){
    return !(a%3) o == 0 para que sea falso.
    ,}
}


SI ELCRITERIO SE CUMPMLE...
SE QUEDA AL INICIO, Y SI NO SE CUMPLE, SE MANDA AL FINAL.
1%3 NO (enviar atras)
..
.
3%3 = SI (inicio)

queadaria:

3 30 1 2 5 5 7 11 23 25


SEGUMIS ECON EL MISMI OARREGLO
*/


#include <iostream>
using namespace std;


struct DIVS{
    bool operator()(int a){
        return (a % 3 == 0);
    }
};

template <class O>
struct UTIL{

    O comparador;

    void Split(int* ini, int* fin);

    void Merge(int* ini, int* mid, int* fin);

    void print(int* ini, int* fin);

};


template <class O>
void UTIL<O>::Merge(int* ini, int* mid, int* fin){

    int *p = ini;
    int *q = mid;
    int valor_tmp = 0;


    while(mid <= fin){

        if(p == mid){
            break; // para el p ++ infinito   
        }
        else if(*p <= *q){
            p++;
        }else{
            valor_tmp = *q;
            while( q > p){
                *q = *(q - 1); //desplazo hacia atras pa meter el otro number
                q--;
            }
            *p = valor_tmp;
            mid++;
            p++;
            q = mid;
        }

    }


//tengo sueño

}


template <class O>
void UTIL<O>::Split(int* ini, int* fin){

    int* p = ini;
    int* r = nullptr;
    int* fin_div = nullptr;
    int valor_tmp = 0;
    fin_div = ini;
    while(p <= fin){

        if(comparador(*p)){
      
            r = p;
            valor_tmp = *p;

            while(r > fin_div){
                *r = *(r - 1);
                r--;
            }

            *r = valor_tmp;
            fin_div++;
            r = p;

        }

        p++; // SOLUCION: fuera  del else, para que atienda tambien al caso si haay un divislb en el primer pos. (bug infinito)

    }


}

template <class O>
void UTIL<O>::print(int* ini, int* fin){

    while(ini <= fin){

        cout<< *ini << " ";
        ini++;
    }

    cout<<endl;

}


int main(){

    const int elementos = 10;
    int ARR[elementos] = {1, 2, 5, 7, 30, 3, 5, 11, 23, 25};

    int* ini = ARR;
    int* fin = ARR + (elementos - 1);
    int* segundo_arreglo = ARR + (elementos/2);

    UTIL<DIVS> arr;
    
    cout<<"ARREGLO ACTUAL: "<<endl;
    arr.print(ini, fin);


    cout<<"ARREGLO MERGE: "<<endl;
    arr.Merge(ini,segundo_arreglo, fin);
    arr.print(ini, fin);
    
    
    cout<<"ARREGLO SPLIT: "<<endl;
    arr.Split(ini, fin);
    arr.print(ini, fin);

}