#include <iostream>
using namespace std;

template <class T>
struct Nodo{

    T valor;
    Nodo* next;
    Nodo(T v){
        valor = v;
        next = nullptr;
    }
};

template <class T>
struct FList{

    Nodo<T>* head;
    int ELEM;

    FList(){
        head = nullptr;
        ELEM = 0;
    };

    ~FList(){

        Nodo<T>* matar = head;

        while(matar != nullptr){

            Nodo<T>* tmp = matar -> next;

            delete matar;

            matar = tmp;

        }

    }
    

    /*
    
    OJO:

    int&  = ALIAS

    &x = DIDRECCION

    depende a quien este pegado ese hijo de perra.
    */

    void push_front(T valor);  //yata 
    void push_back(T valor);// yata
    void pop_front();  //yata
    void pop_back(); //yata

    T& operator[](int valor); // yata 

    T& front(); 
    T& back(); 

    void print_fer(); 

};

template <class T>
void FList<T>::push_front(T valor){
    // siempre se crea?
    Nodo<T>* nodo = new Nodo<T>(valor);

    nodo->next = head; // agarrar lo que el head mira.

    head = nodo; // que el head me agarre ahora a mi.

    ELEM++;
}


template <class T>
void FList<T>::push_back(T valor){

    Nodo<T>* nodo = new Nodo<T>(valor);

    if(head == nullptr){ // el nullptr es nuestro  = FIN directo.
        head = nodo;
 
    }else{

        Nodo<T>* p = head; // este puntero se mete dentro de cada NODO, y actua como uno. USA SUS FUNCIONES!

        while(p->next != nullptr){

            p = p->next;

        }

        p->next = nodo;


    }

    ELEM++;

}


template <class T>
void FList<T>::pop_back(){

/*
RECUERDA FER:

el puntero doble..

p = direccion de donde estoy parado.
*p = accedo a lo que guarda donde estoy parado.(mas en casilla... fija? / head)
**p = me meto a modificar las casillas que tiene donde estoy parado (mas en nodos) esta mierda
pasa desapercibida. cuando (*p)->  ese -> es lo mismo que poner(**p).next;

*/


    if(ELEM == 0){
        cout<< "No hay nada que eliminar POPBACK"<<endl;
        return;
    }

    Nodo<T>** p = &head;

    while(((*p)->next) != nullptr){

        p = &((*p)->next);

    }
    
    delete *p;
    *p = nullptr;

    ELEM--;
}

template <class T>
T& FList<T>::operator[](int valor){
    // static: unico en todo el codigo, si cambia en algo. Todos los objetos ven el cambio actualizado. Independientemente si ellos fueron o no los que efectuaron el cambio.
    // const =  te lo juro por diosito que este valor no se cambiara.

    Nodo<T>* p = head;

    while(valor > 0){ //  3

        p = p->next;

        valor--;
    }

    return (p->valor);

}


template <class T>
void FList<T>::pop_front(){

    if(ELEM == 0){
        cout<< "No hay nada que eliminar POPBACK"<<endl;
        return;
    }
    
    
    Nodo<T>* p = head;
    Nodo<T>* tmp = p->next;

    delete p;

    head = tmp;

    ELEM--;
}

template <class T>
T& FList<T>::front(){
    
    return head->valor;

} 
template <class T>
T& FList<T>::back(){
    Nodo<T>* p = head;

    while(p->next != nullptr){

        p = p->next;

    }

    return p->valor;
} 
template <class T>
void FList<T>::print_fer(){
    Nodo<T>* p = head;

    cout<< "HEAD -> ";

    // este webon, si o si se para encima del nullo para detener de imprimir.
    while(p != nullptr){

        cout<< p->valor <<" -> ";

        p = p->next;

    }

    if(p == nullptr){
        cout<< "NULL "<<endl;
    }
} 



/*
Template class T

struct Nodo

T valor
CNodo *next;
CNodo(T v){
valor = v;
next = 0
}




template,clas T>
class merge

void ejecutar (CNode<T> , *L1 ; Cnode<T> * L2);

voi print(Cnode<T> * L);





L1 -> 1  -> 3 -> 8 -> 9 -> 10 -> null

L2 -> 4 -> 5 -> 11 -> null


crea la estructura con un bucle pero ya ta. pones el coso.
es el mismo merge de arrays pero con una diferencia.

van a mezclar ambas
pero vas a cmabiar llos enlaces.

ejemplo recorrido:
TODO se mezclara en L1.

1 < 4?
si
L1 apunta a 1.

3 < 4?

este enlace permanece
1 -> 3

luego
8 < 4?
no
entonces el enlace actual que tu habias puesto en lem ina creo se rompe y vas apuntar a la otra L2
cosa que L1 3 apunta a L2 4, luego


11 aputa ahi dond e8 
ahora 9 y 11?
entonce el 9 emtoncs la conecxion permanece
tons
10 y 11
cuando L1 llegue a null. lo haces apuntar al ultimo de L2

y antees de que te vayas  L2 debe apuntar a null.



AHORA
el print...

head-> 1 -> 3 -> 8 -> 9 -> 10 -> null.

merge!

L2 depues del merge se miraria asi:
head -> null;


Puede ser que la L1 sea grande y el L2 sea menor o viceversa o como sea. la idea es que sea para todo.


ESTRUCCION:
ES MOVER EL NEXT!!! por LOTANTO ESTA PROHIBIDO!!!!!!!!!!!!!!
CAMBIAR VALORES!

TAMPOCO NO CREAR Y/O BORRAR NODOS! nada de new nodo!

puedes usar punteros nodos pero nada de new! o nada de value! nada, ya fuiste!
solo cambia los nexts




*/

template <class T>
struct Merge{

    void Ejecutar(Nodo<T> *L1, Nodo<T> *L2);

    void print(Nodo<T> *L1);

};

template <class T>
void Merge<T>::Ejecutar(Nodo<T> *L1_g, Nodo<T> *L2_g){


    Nodo<T>** L1 = &L1_g;
    Nodo<T>** L2 = &L2_g;
    
    Nodo<T>* tmpL1 = nullptr;

    while(*L1 != nullptr && *L2 != nullptr){

        if((*L1)->valor < (*L2)->valor){

            L1 = &((*L1)->next);

        }else{

            tmpL1 = *L1;
            *L1 = *L2;
            *L2 = tmpL1;
            L1 = &((*L1)->next);

        }


    }


    if(*L1 == nullptr){

        *L1 = *L2;
        
    }


}

template <class T>
void Merge<T>::print(Nodo<T> *L1){
    Nodo<T>* p = L1;

    cout<< "HEAD -> ";

    while(p != nullptr){

        cout<< p->valor <<" -> ";

        p = p->next;

    }

    if(p == nullptr){
        cout<< "NULL "<<endl;
    }
}




int main(){

/*
L1 -> 1  -> 3 -> 8 -> 9 -> 10 -> null

L2 -> 4 -> 5 -> 11 -> null
*/


FList<int> L1;
FList<int> L2;


cout<< "---------------------------------------------------------------------------\n";
L1.push_back(1);
L1.push_back(3);
L1.push_back(5);
L1.push_back(7);
L1.push_back(11);
L1.push_back(13);
L1.push_back(23);
cout<< "L1 = ";
L1.print_fer();

cout<< "---------------------------------------------------------------------------\n";

L2.push_back(1);
L2.push_back(3);
L2.push_back(5);
L2.push_back(7);
L2.push_back(9);
L2.push_back(11);
L2.push_back(13);
L2.push_back(21);

cout<< "L2 = ";
L2.print_fer();

cout<< "---------------------------------------------------------------------------\n";



Merge<int> merge;

merge.Ejecutar(L1.head, L2.head);
cout<< "===========================================================================\n";
cout<< "MERGE!"<<endl;
cout<< "===========================================================================\n";
if(L1.head == nullptr || (L2.head != nullptr && L2.head->valor <= L1.head->valor)){
    L1.head = L2.head;
}
L2.head = nullptr;

cout<< "L1 = ";
merge.print(L1.head);
cout<< "L2 = ";
merge.print(L2.head);
    


/*
===========================================================================
MERGE!
===========================================================================
L1 = HEAD -> 1 -> 3 -> 4 -> 5 -> 8 -> 9 -> 10 -> 11 -> NULL 
L2 = HEAD -> NULL 

*/
}