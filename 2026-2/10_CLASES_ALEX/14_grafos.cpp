/*

IDEAS QUE DARA EL PROFE:

Conjunto de datos, en este acso los A E BC son char. pero pdorian ser cualquier cosa.

La idea es que eso no siempre e char


En las aristas hay un PESO que norlamente es un int, pero puede ser algo que tien datos muchos dats.

Lo que vamos hacer con un tipo de dato en el nodo, y un tipo de dato en la lista.
Y que se puede hacer eso

de A a B = 3
A a C = 7

B a C = 1
B a D 4
D a X 2
C a E 2
E a D 5
E a X 3


        B
A               D   X
            E
    C


Puede haber:
Y -> Z

K
tambien puede aver que A apunte a A con 8  y eso...

 7   
A->A

tambien puede ser arista que venga y vaya. <->
------------------------------------------------------------------------------------
LO QUE NO DEBE EXISTIR!!
No puede haber una arista suelta. que solo salga de un nodo y que no llegue a nada
J -> NO!
-> NO!


en un arbol si hay pero.. aqui no existe eso.



Si es UNA ARISTA es porque tiene los DOS EXTREMOS
si no no hay.




--------------------------------------------------------


Encima de esos cosos. existen algoritmos

hoy haremos como implementar esa estructura...


LO MAS ISMPLE:

lo primero que se tiene uqe hacer

una busqueda....

cual seria el camino mas corto entre a y 

A B C D X..?

el punto de hacer ese resultado
tu cabeza al verlo miraste y dijsite donde ir..

eso es posible cuando el grafo es chiquito


si tu a la X la arrastras y lo pones alla 
dice que eso da igual porque las conexiones siguen igual. matematicamnte sigue esiendo el mismo grafo.
lo que quieren que noten... es bueno eso, de ddiferentes formas

en este tipo de grafo no hay mucho como orientarse.p oreso cuando tienes 
pura letra no tienes mucho como orientarte
pero
si a cada nodo lo ponemos una coordenada... y ese es otro nodo
que es otra cordenada..

Digamos que esto es Arequipa:
-------------------------------------

x,y(de aqui podrian salir varias coordenads)                          x1,y1()


-------------------------------------


Como cada uno tiene cordenadas, ahi existen una una distancia. asi que con eso rte ayudas.
y de esa forma podrias avanzar sin tener qeu barrer todo el grafo.

por eso aunque arequipa tenga 1 millon de nodos, tu terminas usando 100 nodos.

Esta versino de grafo con coordenadas ayudan porque tienes nocion de cuanto te acercas o alejas. por eso
puedes elegir entre 5 caminos y asi.



300303003030303030303

regresando al de A B C D y pesos.
no tienes una idea de saber donde es X y como llegar, asi que sol ote queda
barrer todo el grafo.
Asi qeu por fuerza bruta encontrar la salida.


DISTINCION:

SIN COORDENADAS: sin guia.
CON COORDENADAS: mejor guia, pero es graaaaaaaaande, porque lso grafos tienen coordenadas los mapas mejor ddicho.


Por eso declaramos un grafo..


CGrafo con 2 parametros (un n y un e);
n = tipo de dato que entrara al nodo.
e = tipo de dato que entrara a la arista.

Graph<N,E>


osea...

Graph<char, int> g1 (EL DE SIN CORDENADAS)


Graph<COORD, int> g2 (EL CON CORDENADAS, el COORD es un objeto p)



Aqui es mejor usar templates....

Eso es lo que haremos ahora.


Una vez hagamos el CGraph, veremos el codigo con el profe) terminar eso, en futuras clases haremos 
algoritmos encima de ello.
*/




#include <iostream>
#include <list>
using namespace std;
//clase aristsa

// from y tu es.. del nodo cero al nodo 1
template <typename E>
class Edge{
    public:
    int from;
    int to;

    E data;

    Edge(int f, int t, E d){
        from = f;
        to = t;
    }

};


template<typename N, typename E>
class Node{

    int idex;
    N data;
    list<Edge<E>> edget; // lista de aristas de tipo E

    Node(int i, N d){
        index = i;
        data = d;
    }


    void addEdge(int to, E d){
        edge.push_back(Edge<E> indexto, to, d)

    }

    
        void remove edge int to

        bool hasedge

};


template<typename N, typename E>
clas Graph{
    protect: int numVertices;
    bool directd;
    vector<Node<N,E> nodes;
    public:
    grahp (bool dir = false) // ese bool es para ver si es dirigido o no es opciononal.






    int add Nodevoid remove Nodevoid add __EDG_CONSTEXPR_ENABLED__void remove Edgebool hasedge

    node<N,e>

}

/*
basiacment solo usa lo del stl para hacer todo... ahi tiene que darle una estudiada con calma par aentederlo
y... aqui he.. esho...


graph char int 
grap coord intgrap char int
grap char int
grach __is_complete_or_unboundedgrap coord int 
rap finds .h
graph .h


lo unico que hace ese main pinta de A - > B a tal ta l con peso tal tal.

y lo describe de esa foram.

lo ideal de graph.h lo unico qeue hcae es...



añade aristas remuevve nodos solo construye o destrutyo partes del arbol...en todo caso.
es nu codigo simple,
como se los voy a pasar 


GESTIONAR EL GRAFO!!!!
de n nodos, coenftar y blalbalabl no hay ninguna lagoritmo
no hahy busqueda ni nada.es lo unico que hace. e imprimir claro..



Ahora la pregunta es.. como construir un grafo de .. una coordenada... por ejemplo.

este es otro cpp que nos pasara esegun el..

inclye el mismo grafo pero ahora crea un struct

struct CoordeP
float x
float y


y aparte crea un operador par aque puedas ser imprimod en ese formato y nada mas.


y como es un objeto no sabe como imprimor para eso se hizo ese operador  ostream& << y que imprma con cierto formato..
es solo par que imprima de otra forma.

vector.. de nodos.
y una lista de aristas y ya

con vector y lsit si sabes jusar vec y list de stl losabes.

con esos ejemplso solo vimos 2

poner y sacar.


REEEEEEEEECIEN para hacer un algoritmo esta este 3er  codigo que incluye al grafo y crea
una grafo llamado graph find peero....

fijense que es HIJO del... grahp.. ose es una clase heredada de..
y aac vemos qeue existne busqeudas..
find pathpor enplo para una busqueda cual es el camino mas corto del 0 a l 5
y de ahi me dan el que me conviene.

Como hay muchisios algoritmos de grafos.. combiene tener la clase grafo solita.. y aprtir de ella para hacerlos algortimos lo heredamos y en la clse hacemos los algoritmos de busqueda. si no 
tendriamos que meter losm imso en una sola, y un lio...


Primero:
clase grafo (generico N, E)
con eso declaras cualquiergrafo.
uno que prueba con char y ints..

y otro que es coorde y ints
como para una ciudad.


y el 3ro agraga al base y agrega otro que olo hace algortimos de busqueda
esto haremos el lunes...los 
aglorotimos estan delcadrados mas no resultso...
Segundo:



si fuese el caso..
habria un grafo base y ahi mismo aharias un algorimto..
entonces entiendan bien el grafo base...

porque en el examen pdoria venir un algorimo de eso p.

*/