#include <iostream>
using namespace std;


/*

priority heap: maxheap - minheap

o llamado priority queue


Es un arbol binario.

obtener el numero mayor con complejidad constnate. es
va en la raiz.



arbol bin = el mayor estaria full derecha. entonces eso te cussta log 2 N



max heap = el mayor siempre se obtenga en O(K) osea la raiz esta en la raiz

luego digmaos insertas 23.

12 raiz
23 (hijo)


etnonces ahora la idea cmabia!
pues 23 pregunta si su padre es mayoro  menor, en este caso cambio pues.

ahora el 23 sube a ser padre de 12.

ahora entra 30
quiebra la regla, compara con su papa y cambia

etnoces


            30
        12      23

por esta razon max es O(n) porque solo accedes a la cabeza.



La logica de inserccion siempre es en esa forma 

1. se inserta y trepa hasta donde tenga que trepar para hacer cambios.
2. la logica de menores izq mar der ya no viene aca.

ins 15

            30
        15      23
    12

ins 17

            30
        15      23
    12      17

ins 20

            30
        15      23
    12     17  20
    
ins 4

            30
        15      23
    12     17  20  4

El objetivo siempre es dejar al mayor arriba.

La funcion TOP() es en O(K)


La inserseccion log 2 N

Complicaiones al implementarlo:
1. Como subes? doble puntero de subida y de bajada. pero se duplicaria tu memoria.
2. Como sabes la siguiente posicion a insertar.
            30
        15      23
    12     17  20  4
    x  x  x  x  x x x x <- como lo marcas? porque no haces busqueda, de una pasas al siguietne de abajo.
    como si fuera un.. arbol B+?... ni idea.
    la mierda sube y baja para enconrar el siguietne.

    Subida y Next 

    tons.. INS -> LOG 2 (N) + SUBIDA + NEXT

    y el POP ()  ó REM () SOLO DE LA CABZA.


    la logica seria cambiar el 30, por el ultimo elemento que pusiste.
    digmaos

            30
        15      23
    12     17  20  4
   6  8   11


   para:

            11
        15      23
    12     17  20  4
   6  8   30


   ahora miiramos los hijos del 11 y cambio entre ellos.

            23
        15      11
    12     17  20  4
   6  8   30

   ahora

            23
        15      20
    12     17  11  4
   6  8   30


   tons esta mierda sigue siendo lg2n + calc next + subida no hay, porque la abajad esta okay.


   Otra formade implemtnar es en ARRAY


   23 17 20 12 15 11 4 6 8
   0  1  2  3  4  5  6 7 8


   NODOS CON PUNTEROS HACIA ABAJO.

   O ARRAY

   Todos los niveles del arbol estan completos menos las hojas finales donde esta lleno de izqueirda
   a derecha. ARBOL CASI COMPLETO.


   Es por eso que tu arreglo no quedaria hueco. siempre estara lleno.

   En nodos y punteros es una mierda saber donde meter el push p.

   entonces en arreglo:

   nelem = 9

   la siguiene es 9 p. 
   entonces el calculo de la version de nodos esun a mierda, pero en el de arreglo es recontra simple.
   ya que se aascoai al tamano dle array.

   pero estando en 9 como sabes quien es su padre y asi.
   pero se puede deducir:
   digamos que esta posicion i es el 9 (donde isnerte)

   el padre de i seria... 
   p(i) = (i - 1)/ 2

   con esa trepada sube en una 


   y para borrar?

   agarra el ultimo, y lo cambias por el primero y 
   reduces el numero y ya

   el unico inconeeninte es la expansion eventual que tendra que crecer.
   y la otra cada rato recalcula todo lsu lio


   pero en C++ liberia esta implemtado como el array.


   COMO PRACITICA:

   implementa ambas formas.
   pero la de queue es más eficiente.

    DELCARA UN VECOTR NE STL
    y los push backs hacen todo lio p. cosa que solito se redimesiona 

    crea tu heap y lo metes adentro p

    std::vector<T> o un deque<T>

    pero el profe prefiere vector.


    Ahora  el profe recomeinda un tal XHEAP <int, LESS<int>> h;

    con eso solo seria 1 soal implementacion

    y solo metemos max y min

    y si te alocas mas.

    un tercer parametro para decidir si es vec o deque
   -----------------------------------------------------


   El MIN HEAP es lo mismo, pero ahora el menor a la cabeza.




*/

int main(){

}