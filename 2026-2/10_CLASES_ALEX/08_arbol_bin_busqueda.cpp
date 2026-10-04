#include <iostream>
#include <stack>
using namespace std;

struct Nodo{

    int valor;
    Nodo* right;
    Nodo* left;

    Nodo(int v){
        valor = v;
        right = nullptr;
        left = nullptr;
    }

};



struct Tree{

    Nodo* root;

    Tree(){
        root = nullptr;
    }


bool find(Nodo** &p, int v);

bool ins(int v);

bool rem(int v);

void inorden_stack();
void reverse_stack();
void preorden_stack();
void postorden_stack();


void inorden_s();
void reverse_s();
void preorden_s();
void postorden_s();

void inorden_r(Nodo* n);
void reverse_r(Nodo* n);
void preorden_r(Nodo* n);
void postorden_r(Nodo* n);
};


bool Tree::find(Nodo** &p, int v){

    while(*p != nullptr){
        
        if(v < (*p)->valor){
            p = &((*p)->left);
        }else if( v > (*p)->valor){
            p = &((*p)->right);
        }else{
            break;
        }
    }

    return *p != nullptr && v == (*p)->valor;
} 


bool Tree::ins(int v){
    
    Nodo** p = &root;

    if(find(p , v)){
        return false;
    }else{

        Nodo* nodo = new Nodo(v);

        *p = nodo;

        return true;
    }

}

bool Tree::rem(int v){

    Nodo** p = &root;
    Nodo* tmp = nullptr;
    Nodo** cand = nullptr;

    if(find(p , v)){

        // caso 2 hijos:
        if((*p)->left != nullptr && (*p)->right != nullptr){

            cand = p;

            cand = &((*p)->left);

            while((*cand)->right != nullptr){
                cand = &((*cand)->right);
            }

            (*p)->valor = (*cand)->valor;

            p = cand;

        }
        // caso 1 hijo:
        if((*p)->left != nullptr || (*p)->right != nullptr){

            if((*p)->left != nullptr){

                tmp = *p;

                *p = (*p)->left;

                delete tmp;

            }else{

                tmp = *p;

                *p = (*p)->right;

                delete tmp;

            }

        }
        // caso 0 hijos:
        else{

            tmp = *p;
            *p = nullptr;

            delete tmp;

        }

        return true;

    }else{
        return false;
    }



}



/*----------------------RECORRIDOS----------------------*/
/*------------------------------------------------------------------------------------*/
void Tree::inorden_stack(){

    Nodo* p = root;

    stack<Nodo*> pila;

    while(p != nullptr || !pila.empty()){

        while(p != nullptr){

            pila.push(p);

            p = p->left;
        }

        p = pila.top();

        cout<< p->valor <<" ";

        pila.pop();

        p = p->right;

    }
    cout<<endl;
}


void Tree::preorden_stack(){
    Nodo* p = root;

    stack<Nodo*> pila;

    while(p != nullptr || !pila.empty()){

        while(p != nullptr){

            cout<< p->valor <<" ";

            pila.push(p);

            p = p->left;            
        }

        p = pila.top();

        pila.pop();

        p = p->right;

    }
    cout<<endl;


}

void Tree::postorden_stack(){
    Nodo* p = root;
    Nodo* ultimo = nullptr;
    stack<Nodo*> pila;

    while(p != nullptr || !pila.empty()){

        while(p != nullptr){
            pila.push(p);
            p = p->left;
        }

        p = pila.top();

        if(p->right == nullptr || p->right == ultimo){
            cout << p->valor << " ";
            ultimo = p;
            pila.pop();
            p = nullptr;
        }else{
            p = p->right;
        }
    }

    cout << endl;
}

void Tree::reverse_stack(){

    Nodo* p = root;

    stack<Nodo*> pila;

    while(p != nullptr || !pila.empty()){

        while(p != nullptr){

            pila.push(p);

            p = p->right;
        }

        p = pila.top();

        cout<< p->valor <<" ";

        pila.pop();

        p = p->left;

    }
    cout<<endl;

}
/*------------------------------------------------------------------------------------*/

void Tree::inorden_r(Nodo* n){

    if(n == nullptr){
        return;
    }

    inorden_r(n->left);

    cout<< n->valor <<" ";
    
    inorden_r(n->right);


}


void Tree::preorden_r(Nodo* n){
    if(n == nullptr){
        return;
    }

    cout<< n->valor <<" ";

    preorden_r(n->left);
    
    preorden_r(n->right);



}

void Tree::postorden_r(Nodo* n){
    if(n == nullptr){
        return;
    }

    postorden_r(n->left);
    
    postorden_r(n->right);

    cout<< n->valor <<" ";
    

}

void Tree::reverse_r(Nodo* n){

    if(n == nullptr){
        return;
    }

    

    reverse_r(n->right);
    cout<< n->valor <<" ";
    reverse_r(n->left);    

    

}

/*------------------------------------------------------------------------------------*/

void Tree::inorden_s(){

    Nodo* p = root;

    stack<pair<Nodo*,int>> pila;

    while(p != nullptr || !pila.empty()){

        if(p != nullptr){
            pila.push({p, 0});
            p = nullptr;
        }

        auto par = pila.top();
        pila.pop();

        switch(par.second){

            case 0:
                pila.push({par.first, 1});
                p = par.first->left;
                break;

            case 1:
                cout << par.first->valor << " ";
                pila.push({par.first, 2});
                p = par.first->right;
                break;

            case 2:
                break;
        }
    }

    cout << endl;
}

void Tree::preorden_s(){

    Nodo* p = root;

    stack<pair<Nodo*,int>> pila;

    while(p != nullptr || !pila.empty()){

        if(p != nullptr){
            pila.push({p, 0});
            p = nullptr;
        }

        auto par = pila.top();
        pila.pop();

        switch(par.second){

            case 0:
                cout << par.first->valor << " ";
                pila.push({par.first, 1});
                p = par.first->left;
                break;

            case 1:
                pila.push({par.first, 2});
                p = par.first->right;
                break;

            case 2:
                break;
        }
    }

    cout << endl;
}

void Tree::postorden_s(){

    Nodo* p = root;

    stack<pair<Nodo*,int>> pila;

    while(p != nullptr || !pila.empty()){

        if(p != nullptr){
            pila.push({p, 0});
            p = nullptr;
        }

        auto par = pila.top();
        pila.pop();

        switch(par.second){

            case 0:
                pila.push({par.first, 1});
                p = par.first->left;
                break;

            case 1:
                pila.push({par.first, 2});
                p = par.first->right;
                break;

            case 2:
                cout << par.first->valor << " ";
                break;
        }
    }

    cout << endl;
}

void Tree::reverse_s(){

    Nodo* p = root;

    stack<pair<Nodo*,int>> pila;

    while(p != nullptr || !pila.empty()){

        if(p != nullptr){
            pila.push({p, 0});
            p = nullptr;
        }

        auto par = pila.top();
        pila.pop();

        switch(par.second){

            case 0:
                pila.push({par.first, 1});
                p = par.first->right;
                break;

            case 1:
                cout << par.first->valor << " ";
                pila.push({par.first, 2});
                p = par.first->left;
                break;

            case 2:
                break;
        }
    }

    cout << endl;
}


/*

                 CASE 0       CASE 1       CASE 2

INORDEN          IZQUIERDA     IMPRIMIR      DERECHA
PREORDEN         IMPRIMIR      IZQUIERDA     DERECHA
POSTORDEN        IZQUIERDA     DERECHA       IMPRIMIR
REVERSE          DERECHA       IMPRIMIR      IZQUIERDA

*/

/*------------------------------------------------------------------------------------*/

int main(){

    Tree t;

    t.ins(40);
    t.ins(20);
    t.ins(60);
    t.ins(20);
    t.ins(10);
    t.ins(30);
    t.ins(25);
    t.ins(50);
    t.ins(70);

    cout<< "INORDEN: ";
    t.inorden_s();

    cout<< "PREORDEN: ";
    t.preorden_s();

    cout<< "POSTORDEN: ";
    t.postorden_s();

    cout<< "REVERSE: ";
    t.reverse_s();
}


