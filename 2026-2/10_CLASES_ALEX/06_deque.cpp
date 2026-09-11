#include <iostream>
using namespace std;


struct Deque{

    int ELEM;

    const int TAM_MIN_MAPA = 5;

    const int TAM_BLOQUE = 5;

    int TAM_MAPA = 5;



    int** MAPA = new int*[TAM_MAPA];

    int** m_ini;
    int** m_fin;

    int* v_ini;
    int* v_fin;

    Deque(){

        ELEM = 0;

        int** p = MAPA;

        while(p < MAPA + TAM_MAPA){

            *p = nullptr;

            p++;
        }

        m_ini = MAPA + (TAM_MAPA/2);
        m_fin = MAPA + (TAM_MAPA/2);

        v_ini = nullptr;
        v_fin = nullptr;
    }

    void push_front(int valor);
    void push_back(int valor); 

    void pop_front();
    void pop_back();

    int& front();
    int& back();

    int& operator[](int pos);

    void print();    

    void expand_mapa();
    void colapse_mapa();

};


void Deque::expand_mapa(){

    TAM_MAPA *= 2;
    if(TAM_MAPA % 2 == 0){
        TAM_MAPA++;
    }

    int** MAPA_E = new int*[TAM_MAPA];

    int** p_ini = (MAPA_E + (TAM_MAPA/2)) - (m_fin - m_ini + 1);
    int** q_fin = p_ini;

    while(m_ini <= m_fin){

        *q_fin = *m_ini;

        q_fin++;
        m_ini++;

    }

    m_ini = p_ini;
    m_fin = q_fin - 1; // menos uno, porque hice un q_fin++ despues de haber copiado el ultimo.

    delete[] MAPA;

    MAPA = MAPA_E;

}

void Deque::colapse_mapa(){

    TAM_MAPA /= 2;
    if(TAM_MAPA % 2 == 0){
        TAM_MAPA++;
    }

    int** MAPA_C = new int*[TAM_MAPA];

    int** p_ini = (MAPA_C + (TAM_MAPA/2)) - (m_fin - m_ini + 1);
    int** q_fin = p_ini;

    while(m_ini <= m_fin){

        *q_fin = *m_ini;

        q_fin++;
        m_ini++;

    }

    m_ini = p_ini;
    m_fin = q_fin - 1; // menos uno, porque hice un q_fin++ despues de haber copiado el ultimo.

    delete[] MAPA;

    MAPA = MAPA_C;

}


void Deque::push_front(int valor){

    if(ELEM == 0){ // PRIMER ELEMENTO

        *m_ini = new int[TAM_BLOQUE];

        v_ini = *m_ini + (TAM_BLOQUE/2);
        v_fin = *m_ini + (TAM_BLOQUE/2);

        *v_ini = valor;

    }else if(v_ini == *m_ini){ // CUANDO LLEGO AL BORDE DELANTERO

        if(m_ini == MAPA){ // VERIFCAR QUE HALLA ESPACIO EN EL MAPA
            expand_mapa();
        }else{
        
            m_ini--;

            *m_ini = new int[TAM_BLOQUE];

            v_ini = *m_ini + (TAM_BLOQUE - 1);

            *v_ini = valor;
        }

    }else{ // CASO NORMAL

        v_ini--;

        *v_ini = valor;
    }

    ELEM++;

}


void Deque::push_back(int valor){

    if(ELEM == 0){

        *m_fin = new int[TAM_BLOQUE];

        v_fin = *m_fin + (TAM_BLOQUE/2);
        v_ini = *m_fin + (TAM_BLOQUE/2);

        *v_fin = valor;

    }else if(v_fin == *m_fin + (TAM_BLOQUE - 1)){

        if(m_fin == MAPA + (TAM_MAPA - 1)){
            expand_mapa();
        }else{

            m_fin++;
            *m_fin = new int[TAM_BLOQUE];

            v_fin = *m_fin;

            *v_fin = valor;

        }

    }else{

        v_fin++;
        *v_fin = valor;
    }

    ELEM++;
}



void Deque::pop_front(){

    if(ELEM == 0){
        cout<<"DEQUE VACIO POPFRONT"<<endl;
        return;

    }else if(v_ini == v_fin){

        v_ini = nullptr;
        v_fin = nullptr;

        delete[] *m_ini;

        m_ini = MAPA + (TAM_MAPA/2);
        m_fin = MAPA + (TAM_MAPA/2);

    }else if(v_ini == *m_ini + (TAM_BLOQUE - 1)){

        delete[] *m_ini;

        m_ini++;

        v_ini = *m_ini;

    }else{

        v_ini++;

    }

    ELEM--;

    if((TAM_MAPA > TAM_MIN_MAPA) && ((m_fin - m_ini + 1) < (TAM_MAPA / 4))){
        colapse_mapa();
    }
    

}


void Deque::pop_back(){

    if(ELEM == 0){
        cout<< "NADA QUE SACAR, POP BACK"<<endl;
        return;
    }else if(v_ini == v_fin){
        delete[] *m_fin;
        v_ini = nullptr;
        v_fin = nullptr;

        m_ini = MAPA + (TAM_MAPA/2);
        m_fin = MAPA + (TAM_MAPA/2);
    }else if(v_fin == *m_fin + (TAM_BLOQUE - 1)){
        delete[] *m_fin;
        m_fin--;
        v_fin = *m_fin + (TAM_BLOQUE - 1);
    }else{
        v_fin--;
    }

    ELEM--;


    if((TAM_MAPA > TAM_MIN_MAPA) && ((m_fin - m_ini + 1) < (TAM_MAPA / 4))){
        colapse_mapa();
    }
}

int& Deque::operator[](int pos){
    //aqui
}

int& Deque::front(){

}

int& Deque::back(){

}

void Deque::print(){
    
}


int main(){

    Deque d; 

    d.push_front(6);
    d.push_front(1);
    d.push_front(9);


}