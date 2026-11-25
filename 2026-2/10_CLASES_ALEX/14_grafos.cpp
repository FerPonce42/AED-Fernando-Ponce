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



/*
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

*/

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


/*
EN TEORIY A A ESTAN LOS CODIGOS DE EESE PERRO EN EL DRIVE... con fe nomas.
*/









/*

CLASE DEL LUNES:::


La clase grafo que les he propuesto se define asi:


Grap<char,int> g;

con eso

Gestionas insertados elimnr de arsitas y eso. Es lo ujnico que hace.

Si entrase una pregunta del examen... seria basado en ESTE GRAFO.

Parte de la pregunta seria ese grafo + una funcion que acceda.

El vector es un vecto de NODOS...

y cada nodo tiene una LISTA de aristas...

Todo con STL claro

osea vector y  list


y recorridos de vectors y de lists...

Igual revisenlo para que lo tengan en mente...



La idea del grafo... es..
que si usamos este grafo para el de una ciudad... seria...


class CityGraph : public Graph<Coord,int>

algo asi seria el examen hipoteticamente hablando.



Esto de grafos.. se ve mas en ADA

algoritmos diseós de alogirnos..


Este curso se ddedica a la estructura como tal.






DADO ESTO se pueden hacer 2 cosas..

cual seria la forma para lir de A hasta X...

el caminimo minimo...

Como no hay cordenadas... esto es matematico...

Como no hay forma de orientarnos...


BARRE TODO NOMAS.

De A ve por todas las aristas. recursivamente... y sales de a AC co.. ac = 7
luego de AB seria ab3
luego abc5 y con c ace y asi contodoslos caminos...

una qeudaria abce9
y otro
abcex11

y eventualmente llegan a todos los lados...
abdx7

abcedx20...

de todos los caminos se escoge el que tiene menor peso p. ese fue el camino mas corto.

pero es un costo computacional fuerte. pero recorres todo p
osea consigues pero ese el problem...

lo qu podrias hacer es qeu  ac7 vs abc5 y crear optimizaciones para crear caminos y asi p.

Ese bueno.. el algorimo base...

SI FUERA UNA PREGUNTA EN EL EXAMENS
VER EL GRAFO PROPUESTO
RECORRER SUS VECTORS Y LISTS...
LA IDEA ES RECORRER PRO TODO LADO, OSEA... ES ReCURSIVO...

en este caso fue para letras..


Esto solo tiene sentido para grafos pequenos...

pero esto se convertitira en algo cuadratico.




ese fue el algorimo basico...



AHORA:


otro caso.. que pasaria si...


fuesen coordenadas... si hbuieran 100000 milloes de elementos..



x,y             x,y


Con ese algorimo barre todo lo de arriba sin mas, porque va por todo lado..
ESO ES IMPENSABLE!


Usando las coordenadas...

buscas las opciones de salida de la coordenada 


SACANDO LA DISTANCIA ECLIDIANA entre las salidas al nodo al que quieres llegar.

haz los 2 algoritmos

el generico que sale a todo lado
y el especifico que sale por cordenadas de prioridad de eso.


ambos basasdos en el grafo que tenemos como codigo.




UN CASO:

el profe nos podria poner..

Este fue... una pregunta de une examen.. les planteo la idea...

tienes 50 nodos..
un grafo con 50 nodos...
con 30 mejor.

y te digo

haz una funcion para que busque cualquier camine de cualqueri nodo a cuqlueir nodo...

haz un algoritmo pero en tiempo ... CONSTANTE!

Cosntatne = acceso a un array / maatriz.. o una ecuacinos que calcuals algo y ya sale constante..

ahi hay varais claves:

asi sea un grafo chiquit ocom oeste...
si tu...

digmaoas 6 nodos. si te mueves de aca aca pierdes.

osea no hagas la busqueda en el tiempo qeu te la pida.
osea el acceso es..


EL TIEMPO QUE SEA CONSANTE...


es que tengas todos los caminos de todos contra todos..

ya contados

osea los 30 vs los 30


osea haz una tabla.. de todos contra todos..
de A a B
y ahi registras el camino..


Enotnces si tuvieras es tabla de todos los caminos posibles...


Esta mierda lo hace MAPS

  A B C D E
A 
B
C
D
E


eso ya estaria y solo vas y lo sacas.


Entonces esta pregunta implica... precalculalo al iniciar tu main..

y y acon esa matriz lista...


ahora con la funcion de consulta... vas y tomas esa p.



osea tu main tendrai qu eser algo asi:



main()


declaragracion de grafo... g;

g.precalc();
esa funcoion calcula todos contra todos y lo guarda en una matriz.

y...

g.path('A','B'); y esta chekea lo que ya fue calculado y retorna el coso



oseason 2 proceso...


el precalculo... 1 vez por semana...


de lgrap coord tiene precalc y el otro solo usa path.. (EJEMPLO DENTRO DEL OS CODIGOS QUE ESTE SINVERGUENZA SUBIO A SU DRIVE)


ESE PRECALCULO....


tons haz 3 csas.

1. algoritmo de busqeuda intensiva. (acplicado en grafo no automatizado con char int )


2. algoritmo con coordenadas. porque en vez de solir por todo sales por el que mas se acerca. es una pequena optimizacion 


3. hacer UN PRECALCULO... dependiendo de la RAM y del tamano del grafo. osea hacesu na funcion de precalculos que haga todo.
y cuando vayas a buscar hace un accesos tipo tabla hash y pam


*/