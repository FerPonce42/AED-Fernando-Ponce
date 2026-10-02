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
/*
Caso 0 : cortas
Caso 1: matas a uno
Caso 2: elige candidato para reemplazar
*/

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

}

int main(){

    Tree t;

    t.ins(52);
    t.ins(43);
    t.ins(73);
    t.ins(31);
    t.ins(47);
    t.ins(61);
    t.ins(84);

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