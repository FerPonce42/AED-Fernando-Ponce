#include <iostream>
#include <assert.h>
using namespace std;

/*

Mensaje del Alex: 




*/

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

    ~Deque(){

        int** p_map = m_ini;

        while(p_map <= m_fin){

            delete[] *p_map;
            p_map++;

        }
        
        delete[] MAPA;

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
        }
        
            m_ini--;

            *m_ini = new int[TAM_BLOQUE];

            v_ini = *m_ini + (TAM_BLOQUE - 1);

            *v_ini = valor;
        

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
        }

            m_fin++;
            *m_fin = new int[TAM_BLOQUE];

            v_fin = *m_fin;

            *v_fin = valor;

        

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
    }else if(v_fin == *m_fin){
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
    assert(ELEM > 0);

    // Version Fernando: elementos inciales

/*
    int elem_iniciales = (*m_ini + TAM_BLOQUE) - v_ini; // elementos que EXISTEN

    if(pos < elem_iniciales){
        return *(v_ini + pos);
    }else{

        pos -= elem_iniciales;

        int bloque = (pos / TAM_BLOQUE) + 1;
        int casilla = (pos % TAM_BLOQUE);

        return *(*(m_ini + bloque) + casilla);

    }
*/


    // version profe : indices inicales?

    int pos_local = v_ini - *m_ini ; // indice POR DONDE INICIAR.

    int pos_global = pos + pos_local;

    int bloque = pos_global / TAM_BLOQUE;
    int casilla = pos_global % TAM_BLOQUE;

    return *(*(m_ini + bloque) + casilla);


}

int& Deque::front(){
    assert(ELEM > 0);

    return *v_ini;
}

int& Deque::back(){
    assert(ELEM > 0);

    return *v_fin;
}

void Deque::print(){

    int** p_map = m_ini;
    int* p_val = v_ini;

    while(true){

        cout << *p_val << " ";

        if(p_map == m_fin && p_val == v_fin){
            break; // llegamos al ultimo elemento del ultimo bloque en uso
        }

        if(p_val == (*p_map + (TAM_BLOQUE - 1))){
            p_map++;
            p_val = *p_map;
        }else{
            p_val++;
        }
    }

    cout << endl;
}



int main(){

    Deque d;

    // Empezamos con algunos elementos por delante
    d.push_front(5);
    d.push_front(4);
    d.push_front(3);
    cout << "Estado inicial (solo push_front): ";
    d.print();

    // Ahora agregamos por detras
    d.push_back(6);
    d.push_back(7);
    d.push_back(8);
    cout << "Despues de agregar por detras: ";
    d.print();

    // Hacer crecer el DEQUE por el frente hasta que pida expandir el mapa
    d.push_front(2);
    d.push_front(1);
    d.push_front(0);
    d.push_front(-1);
    d.push_front(-2);
    d.push_front(-3);
    d.push_front(-4);
    d.push_front(-5);
    d.push_front(-6);
    d.push_front(-7);
    d.push_front(-8);
    cout << "Deque bien crecido por el frente: ";
    d.print();

    // Hacer crecer tambien por detras, para forzar otro expand_mapa
    d.push_back(9);
    d.push_back(10);
    d.push_back(11);
    d.push_back(12);
    d.push_back(13);
    d.push_back(14);
    d.push_back(15);
    d.push_back(16);
    cout << "Deque bien crecido por ambos lados: ";
    d.print();

    // Cambiamos algunos valores con operator[]
    d[0] = 100;
    d[5] = 200;
    cout << "Despues de cambiar valores con []: ";
    d.print();

    // Probamos front y back
    cout << "front(): " << d.front() << " | back(): " << d.back() << endl;

    // Ahora lo reducimos sacando por delante
    d.pop_front();
    d.pop_front();
    d.pop_front();
    d.pop_front();
    d.pop_front();
    d.pop_front();
    d.pop_front();
    d.pop_front();
    d.pop_front();
    d.pop_front();
    cout << "Despues de sacar varios por el frente: ";
    d.print();

    // Y tambien por detras, para forzar colapse_mapa
    d.pop_back();
    d.pop_back();
    d.pop_back();
    d.pop_back();
    d.pop_back();
    d.pop_back();
    d.pop_back();
    d.pop_back();
    cout << "Despues de sacar varios por detras: ";
    d.print();

    // Nos quedamos con pocos elementos
    cout << "front(): " << d.front() << " | back(): " << d.back() << endl;

    // Agregamos un par mas para ver que sigue funcionando bien
    d.push_front(999);
    d.push_back(888);
    cout << "Estado final: ";
    d.print();


}