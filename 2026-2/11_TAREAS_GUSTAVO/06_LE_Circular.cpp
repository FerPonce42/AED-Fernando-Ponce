/*

La tarea sera eso.

H-> A -> B -> C -> D -> C -> A -> B
 

class CClist{

constructor -> n - elementos. (EN EL CONSUTRCITOR! LO HACES)

27 elemetnos.

de que?
lleno de letras.

template<> si quieres p. pero letras

A B C D E.... Z?

se me acabaron las letras... si ya llegaste a la Z, ya p A B..


Y vas a crear un metodo...  llamado kill (matar)
matar la LE 


metodo kill (numero)

ese numero de orden que tu quieres matar los elementos, vamos a suponer... una LE..

H -> A -> B -> C -> D -> E -> F ->G -> H -> A -> ...

CLSIT MIA (5); EN EL MAIN UNA LISTA CON 5 ELEMENTOS.

LUEGO ...

MIA.KILL(3);

MATA DESDE LA CABEZA 

CADA QUE MATA IMPRIME.


RECORRER LA LE E IR MANTANDO.

PROBLEMA: CUANDO MUERE HEAD... NO PIERDAS LA CABEZA.

OSEA CADA QEUE MATE..

ESTARIA IMPRIMEIMDNOP...

C F A E B H D G

EL PROFE CONTO Y ESO. INCIA A CUENTA 1 2 3 PAM MATO AL C Y ASI. COS QUE SE VA ACTUALIZANDO ESTA MIERDA.  LUEGO YA NO 
DESDE C SI NO DESDE B CUENTA 1 2 3 PAM MATA AL F LUEGO DESDE E 1 2 3 MATA A...
Y ASI

}


*/
#include <iostream>
using namespace std;

struct Nodo{

    char valor;
    Nodo* prev;
    Nodo* next;

    Nodo(char v){
        valor = v;
        prev = nullptr;
        next = nullptr;
    }

};


struct CList{

    Nodo* head;
    int ELEM;

    CList(int n){
        head = nullptr;
        ELEM = n;

        for(int i = 0 ; i < ELEM ; i++){

            char letra = 'A' + (i % 26);

            Nodo* nodo = new Nodo(letra);

            if(i == 0){
                head = nodo;
                nodo->prev = head;
                nodo->next = head;
            }else{

                nodo->next = head;
                nodo->prev = head->prev;

                head->prev = nodo;
                nodo->prev->next = nodo;

            }
        }
    }


};





int main(){

    CList cl(27);

    Nodo* p = cl.head;

    for(int i = 0 ; i < 27 ; i++){


        cout<< p->valor<<" ";

        p = p->prev;

    }



}