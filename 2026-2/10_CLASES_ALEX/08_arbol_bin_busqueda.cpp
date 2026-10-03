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



void Tree::inorden_stack(){

    Nodo* p = root;

    stack<Nodo*> pila;

    while(p != nullptr || !pila.empty()){

        while(p != nullptr){

            pila.push(p);

            p = p->left;
        }

        p = pila.top();

        pila.pop();

        cout<< p->valor <<" ";

        p = p->right;

    }
    cout<<endl;
}

int main(){

    Tree t;

    t.ins(50);
    t.ins(30);
    t.ins(70);
    t.ins(20);
    t.ins(40);
    t.ins(65);
    t.ins(80);
    t.ins(10);
    t.ins(25);
    t.ins(60);

    t.inorden_stack();

    t.rem(10);

    t.inorden_stack();

    t.rem(65);

    t.inorden_stack();

    t.rem(30);

    t.inorden_stack();

}


/*
Implementar 8 metodos.

inorder reverse preorder posorder.
tanto de forma recursiva como las pila

void inorder(Node* n){
if(!n returnl
inorder(n->left)'
cout<<n->valuel
norder(n->right))}

*/