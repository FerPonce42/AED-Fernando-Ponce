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


struct FList{

    Nodo* head;
    int ELEM;

    FList(){
        head = nullptr;
        ELEM = 0;
    };

    ~FList(){

        Nodo* matar = head;

        while(matar != nullptr){

            Nodo* tmp = matar -> next;

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

    void push_front(int valor);  //yata 
    void push_back(int valor);// yata
    void pop_front();  //yata
    void pop_back(); //yata

    int& operator[](int valor); // yata 

    int& front(); 
    int& back(); 

    void print(); 

};


void FList::push_front(int valor){
    // siempre se crea?
    Nodo* nodo = new Nodo(valor);

    nodo->next = head; // agarrar lo que el head mira.

    head = nodo; // que el head me agarre ahora a mi.

    ELEM++;
}



void FList::push_back(int valor){

    Nodo* nodo = new Nodo(valor);

    if(head == nullptr){ // el nullptr es nuestro  = FIN directo.
        head = nodo;
 
    }else{

        Nodo* p = head; // este puntero se mete dentro de cada NODO, y actua como uno. USA SUS FUNCIONES!

        while(p->next != nullptr){

            p = p->next;

        }

        p->next = nodo;


    }

    ELEM++;

}



void FList::pop_back(){

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

    Nodo** p = &head;

    while(((*p)->next) != nullptr){

        p = &((*p)->next);

    }
    
    delete *p;
    *p = nullptr;

    ELEM--;
}


int& FList::operator[](int valor){
    // static: unico en todo el codigo, si cambia en algo. Todos los objetos ven el cambio actualizado. Independientemente si ellos fueron o no los que efectuaron el cambio.
    // const =  te lo juro por diosito que este valor no se cambiara.

    Nodo* p = head;

    while(valor > 0){ //  3

        p = p->next;

        valor--;
    }

    return (p->valor);

}



void FList::pop_front(){

    if(ELEM == 0){
        cout<< "No hay nada que eliminar POPBACK"<<endl;
        return;
    }
    
    
    Nodo* p = head;
    Nodo* tmp = p->next;

    delete p;

    head = tmp;

    ELEM--;
}


int& FList::front(){
    
    return head->valor;

} 
int& FList::back(){
    Nodo* p = head;

    while(p->next != nullptr){

        p = p->next;

    }

    return p->valor;
} 

void FList::print(){
    Nodo* p = head;
    // este webon, si o si se para encima del nullo para detener de imprimir.
    while(p != nullptr){

        cout<< p->valor <<" ";

        p = p->next;

    }

  
} 




int main(){


}