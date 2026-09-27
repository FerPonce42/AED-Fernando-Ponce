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

    void print();

};


bool SortedList::find(int valor, Nodo** &p){

    while(*p != nullptr && (*p)->valor < valor){

        p = &((*p)->next);

    }

    return *p != nullptr && (*p)->valor == valor;
}


bool SortedList::ins(int valor){

    Nodo** p =  &head;

    if(find(valor, p)){
        return false;
    }else{
        Nodo* nodo = new Nodo(valor);

        Nodo* tmp = *p;
        *p = nodo;
        nodo->next = tmp; 

        ELEM++;
        return true;        
    }
}


bool SortedList::rem(int valor){
    Nodo** p =  &head;

    if(find(valor, p)){

        Nodo* tmp = *p;

        *p = (*p)->next;

        delete tmp;

        ELEM--;
        return true;    
    }else{
        return false;  
    }    
}

void SortedList::print(){

    Nodo* print = head;

    cout<<"HEAD -> ";
    while(print != nullptr){

        cout<< print->valor <<" -> ";

        print = print->next;

    }
    cout<<"NULL"<< endl;
}

int main(){

    SortedList s;

    s.ins(2);
    s.ins(5);
    s.ins(9);

    s.print();

    s.ins(7); 

    s.print();
    s.rem(7);
    s.print();

    s.rem(5);

    s.print();



}