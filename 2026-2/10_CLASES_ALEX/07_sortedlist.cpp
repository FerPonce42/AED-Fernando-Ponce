#include <iostream>
using namespace std;

struct Nodo{
    int valor;
    Nodo* next;

    Nodo(int v){
        valor = v;
        next = nullptr;
    }

};

// FOrward list pero solo insercciones guardadas.
struct SortedList{

    Nodo* head;

    int ELEM;


    SortedList(){
        head = nullptr;
        ELEM = 0;
    }


    //buscar:

    bool find(int valor, Nodo** &p);

    //insertar:

    bool ins(int valor);

    //borrar:

    bool rem(int valor);

};


bool SortedList::find(int valor, Nodo** &p){

    Nodo** p =  &head;
/*

(*p)->value = puntero de los datos del puntero
(**p).value = cuando tienes EL NODO accedes a sus dados
*/

// Si el valor es mayor al numero del siguiente nodo, sigue. Y!  ademas si el nodo donde estoy no es nullo. SIGO, sin o bucle error.
// aunque meor invierto el orden? para que no haya erorres
    while( *p != nullptr && valor > (*p)->valor){
        p = &((*p)->next);

    }



    return *p != nullptr && (*p)->valor == valor; // para evitar el uso de ifs.
}



int main(){


}