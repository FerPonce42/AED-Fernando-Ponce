#include <iostream>
using namespace std;

struct Nodo{

    int valor;
    Nodo* next;
    Nodo* prev;

    Nodo(int v){
        valor = v;
        next = nullptr;
        prev = nullptr;
    }

};


struct List{

    Nodo* head;
    Nodo* tail;

    int ELEM;

    List(){
        head = nullptr;
        tail = nullptr;
        ELEM = 0;
    }

    ~List(){

        Nodo* kill = head;

        while(kill != nullptr){

            Nodo* tmp = kill;

            kill = kill->next;

            delete tmp;

        }
    }


    void push_front(int v); //ya
    void push_back(int v); //ya

    void pop_front();
    void pop_back();

    int& front();
    int& back();

    int& operator[](int pos);

    void print();

};



void List::push_front(int v){ 
    

    Nodo* nodo = new Nodo(v);
    
    if(ELEM == 0){ // primer elemento
        head = nodo;
        tail = nodo;
    }else{

        Nodo* tmp = head; // los que vienen
        head = nodo;

        head->next = tmp;

        tmp->prev = head;

    }

    ELEM++;



}


void List::push_back(int v){

    Nodo* nodo = new Nodo(v);

    if(ELEM == 0){ // primer elemento
        head = nodo;
        tail = nodo;
    }else{

        Nodo* tmp = tail;

        tail = nodo;

        tail->prev = tmp;

        tmp->next = tail;

    }

    ELEM++;

}

void List::pop_front(){

    if(ELEM == 0){
        cout<<" CANT ELEMENTOS 0, POP FRONT. NADA QUE SACAR"<<endl;
        return;
    }else if(ELEM == 1){

        delete head;

        head = nullptr;
        tail = nullptr;

    }else {

        Nodo* tmp = head;

        head = head->next;

        delete tmp;

        head->prev = nullptr;

    }

    ELEM--;
}


void List::pop_back(){

    if(ELEM == 0){
        cout<< "ELEMTNOS 0, nada que asacar POPBACK"<<endl;
        return;
    }else if(ELEM == 1){

        delete tail;

        tail = nullptr;
        head = nullptr;
    }else{

        Nodo* tmp = tail;

        tail = tail->prev;

        delete tmp;

        tail->next = nullptr;

    }

    ELEM--;

}

int& List::front(){
    
    return head->valor;

}
int& List::back(){

    return tail->valor;
}

int& List::operator[](int pos){

    if( pos <= ELEM / 2){ //atacar por head

        Nodo* p = head; 

        while(pos != 0){

            p = p->next;
            pos--;
        }

        return p->valor;

    }else if( pos > ELEM / 2){ //atacar por tail
        int pasos = ELEM - 1 - pos;

        Nodo* q = tail; 

        while(pasos != 0){

            q = q->prev;
            pasos--;
        }

        return q->valor;
    }

}

void List::print(){
    
    Nodo* p = head;

    while(p != nullptr){

        cout<< p->valor <<" ";
        p = p->next;

    }

    cout<<endl;
}



int main(){

}