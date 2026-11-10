/*

Cada SO tiene sus propios threads, cada uno es diferente pero tiene el mismo funcionamiento.

Thread : Una pieza dentro del SO...

Es la forma nativa de los SO.


TIPOS: 
------------------------
win
threads
Hay una funcion nativa que se llama: createthread

y para esperar el thread: waitforsingleobject

linux
Se llama pthread
y para esperar : join


macOs
aqui el no sabe como se llama jaja
------------------------

La idea es generar procesos en paralelo...

ACELERAR UN ALGORITMO:
***FORMAS:
- Bajar la complejidad algortimica. (menos operaciones)
- Hacerlo paralelo (lo que haremos... creo, de las 100 operaciones; 25 25 25 25 las envias a cada nucleo)


-----------------------------

Por eso nuestros threads paralelizaremos en n nucleos.

----------


La idea es evitar esto:

include <Windows.h> porque no queremos amarrarnos a un SO....

para usar las funciones....


------------------------------------------------------------------


AHORA BIEN::::::::


hay una libreria llamada boost... es como el STL.

Es lo mismo, pero fuera de C++. Tendrias que instalarlo, blalal boost.h... etc... No es nativo de C++

Pero dentro de las n cosas que boost tiene, crearon esto:


boost:thread....

Esto es un objeto para manejar threads... (2000 - 2010)

Tu cuando compilas este objeto en win/linux/etc
jala estas funciones:
waitfor..
create..
pth
join..

Trae a todas!

es una cascara que te facilita a ti estas funciones ! 

------------------------------------------------------------------------

Depsues de eso... (claro funciona hasta hora, pero requuiere que instales es amierda.)

En algun momento... en C++, como cualquiero otro lenguaje, hizo actualizaciones.

Vieron bonito al boost:rhreads y lo incluyeron dentro del STL...

y...!!

std.?
stl?

std::thread

asi como usamos vector, list, etc...


Es compatible con C++.. entonces jalas todo p


-------------------------------------------------------------






QUE ENTENDER???

cuando creas tu main(){

}

Como es algo de SO, esto se da en todos los Lenguajes de PRogramacion...

Pero aunque uses las threads de en java, igual usas las de C++.... o algo asi esta diciendo el Alex


Esto corre sencuencial..
en lagun mometno de lcodigo haras un..

int main(){


thread t1. <- aqui ya saltó un subproceso...
------<-- aqui sigue esencuacial
------
------
------
}






EJEMPLOS USANDO std::thread;

Digamos que tenemos 4 nucleos...
y yo suelto...

y yo tengo un proceso con 100 proceso que hacer..

entonces primero a A le doy a 100...
entonces B C D estan durmiendo. Es porque no tiene procesos..

osea 75% que se desperdicia.

Si esos 100 lo partes en 2.

50 para A
50 para B

pero C y D siguen sin hacer nada...

entonces..

33 para A
33 para B
34 para C

pero D sigue sin hacer nada...


y ya cuando haces
25 para A
25 para B
25 para C 
25 para D

ahora si tenemos el 100%, todos se levantan..


QUe pas si tengo 5 threads...

4 se meten a los 4 procesadores y el 5to no tiene donde
procesar...

Lo que hace el SO hace que B se levante y E(el 5to) contignua... y como B se esta atrasando trae a A y asi


osea el SO, intercala . Aunque en la practica solo trabajan 4.. osea un PSEUDOPARALELISMO.


Tengan en cuenta.

Mas threads no significa mas rapidez.

OSeA
saber el nro de nucleos que tienes, TE AYUDA! es basico!

hay uan funcion que te indica eso.

por eso tu algoritmo tienes que partirlo en esa cantidad de pedazos..

Asi que tu algoritmo saca ventaja de tu hardware.



#include <iostream>
#include <thread>
using namespace std;


este es el proceso quqe ecutaremos.
void F1(char c, int n){
    imprime ese char n veces jaja
    for(int i = 0 ; i < n ; i++){
        cout<< c;
    }

}


int main(){


    el trehad t = es un puntero a funcion... y ya. en ese momento don dde haces thread
    salta y corre a otro lado, mientras que el main sigue corriendo.

    thread t(F1, 'c',50);
    t.join();
    cout<<"\n";

}



Lo qu pasa si lo ejecutamos sin el JOIN osea //t.join();

en la terminal sale...
menos cccccc
denuvo

ccc
ccccccccccc
cccc

ccccccccccccccc

que sucede?
el main esta corrideno crea el thread y el main sigue corriendo... esta craend o2 proceso en paralelo. el main se pasa de golpe y  
el main termina! y mata a todas las demas, hayan terminado o no. mato a todos los threads que se crearon. entonces
no los dejan trabjar, el main la mata y listo. podria quedar memoria suelta , cualqueri cosa.

etnoncesp ara eso

esta el JOIN



lo que hace el join es: OBLIGA AL MAIN y se sienta a esperar.

asi conseguimos que imprima los c = 50
osea cccc....ccc n veces 


AQUI OTRO EJEMPLo...


Solo que hara el main creará N threads... PEROOO

usara la funcion

nThreads = thread:hardware_concurrency(); <- esto nos da la cantidade nucleos que tu tienetes en tu maquina...

#include <iostream>
#include <vector>
#include <thread>
using namespace std;


//este es el proceso quqe ecutaremos.
void F1(char c, int n){
    //imprime ese char n veces jaja
    for(int i = 0 ; i < n ; i++){
        cout<< c;
    }

}

int main(){
    int i = 0, nThreads = thread:hardware_concurrency();
    vector<thread> ths(nThreads); //<-- vecotr de treashs de 8, parar que cada vez que se cree se almance en este vetor.

    for(int = 0 ; i < nThreads ; i++){
        ths[i] = thread(F1, char('a'+ 1), 100); 
    }

    for(int i = 0; i < nThreads; i++){
        ths[i].join();
    }

    cout<<"\n";
}



O---------------------

otro ejepm plo:


void F1 (int x, int n){

    for(int i = 0 ; i < n ; i++){
    
        sum+=x;


    }

}

int main(){
    int i = 0, nt = thread:hardware_concurrency();
    vector<thread> ths(nt); 

    for(int = 0 ; i < nt ; i++){
        ths[i] = thread(F1, i, 1000); 
    }

    for(int i = 0; i < nt; i++){
        ths[i].join();
    }

    cout<<"\nsum: "<< sum;
}

aqui los threasd se pueden pelear por esa suma, por lo que haria q
esa varaible quede como una mazamorra, una suma incoherente.
los 8 threads sumen a la misma varaible. esa varaible esta en la ram
y lso threas estan en la misma ram...
entoncees eso daraia mala suma....

la solucion/.... bueno, esa suma es la CRITICAL SECTION.. hay race conditino.

La lectura no probelma
cunando hay escritura es el problema...

mientras mas cantidad hagan, mas proabblidad de que lancen sumas falsas. menor, cuesta mas 
y aparentenete todo suma bien pero en un momento saldra error. (compila pero no es coherente)

SOLUCION::

#include <mutex> <-- es como un boolaeano que... hace

mutex m;
long sum = 0;


void F1 (int x, int n){

    for(int i = 0 ; i < n ; i++){
    
        m.lock();

        sum+=x;

        m.unlock();

    }

}

int main(){
    int i = 0, nt = thread:hardware_concurrency();
    vector<thread> ths(nt); 

    for(int = 0 ; i < nt ; i++){
        ths[i] = thread(F1, i, 1000); 
    }

    for(int i = 0; i < nt; i++){
        ths[i].join();
    }

    cout<<"\nsum: "<< sum;
}

Con esto la suma queda perfecta... pero...
las 8 threasds estaran sumiendo secuencialmente YA NO SON PARALELAS!!!

osea lo mismo que nada jajajaj.

Entonces....

Como salimos de esto..?

usar esa version, pero perdemos lo paralelo.
Lo unic oqe hace F1, bloqueamos su coso, entonces bloqueamos TODO hace ese lio...


entonces el queire que o bueno pensamos que hagas todo, pero en cierto momento 
haces ese ojito...

para que sea menos probable que se lentee todo
osea bloqueas.. de vez en cuand oal thread reucperas esa velocidad.


mutex intrusivo : bloqueas todo. eso es malo


mutex que mutea.. cada mil veces... eso es bueno!
podrias conservar la coherencia...



Lo idea es un proceso que te alusines una forma sin MUTEX! eso seria lo ideal...

y si no hay salida...
ve la forma que el mutex no mutee mucho...



+++++++++++++++++++++++++++++++++++++++++++++++++++++++


Ahora la FORMA DE SUMAR.... SIN MUTEX?/....

no quiero mutear ni bloquear.. ni que se corrommpa el resultado.

el problemas es que todso estan sumando en el mismo resultado...



Lo ideal..
8 threads cada threas que sume en el general, haga una subsuma. solo acumulas. asi que no pides permiso a nadie...
etnonces si todos somos threas todos ahacemos nuestra sub suma y corremos en paralelo
y ya no usamos mutex..


y... leugo hacemoms una suma parcial luego del join...





*/


void F1 (int* ar, int n, int* s){// algunas son variables de entrada y otras de salida usa... referencia o punteros. para atrapar.

    for(int i = 0 ; i < n ; i++){

        *s += ar[i];

    }

}// por si un loco te pide meter 5 o mas argumentos.. ni modo, haz un struct y a ese le pasas algo para que llene.

int main(){
    int ar[16] = {2,6,3,1,7,8,9,6,4,3,2,8,9,11,13,1};
// de algnua forma podrias pasarle los codos en 4 pedazos aquie el profe uso i* 4 como puntero o algo asi. 
// procesas tu n pedazos, los espera y luego consolidads con los pedazos que te dieron..

//1, partes
// 2. esperas
// 3. unes...

// este arreglo fue de 16... que pasa si fueraa 17 y tienes 4 nucleso?

// los pdeazos... tmr.. 4 4 4 5 no te queda de otra..

// lo mas equivalentes que puedas..

//lo que no se debe hacer son pedazos como.. 4000... no 4002! cuales serian los pedazos.. 1000 1000 1001 1001

// LO QUE NO DEBES HACER... es 1000 1000 1000 1002... entonces.. despedrdicias un nucleo porque otros acabn antes...

//haz lo q uer queiras pero que los pedazos sean masomenos equivalentes. funciona pero no es lo que buscamos...

// osea considea que las partes podrian no ser iguales... aya no 16 si no 18. asi que tiens que hacer algo para qye la operacion te salga equivalente.

// por eso esa particion equivalente es un reto.
    int xsum[4] = {0,0,0,0};
    int sum = 0;

    int i = 0, nt = 4;

    vector<thread> ths(nt);

    for(int i = 0 ; i < nt ; i++){
        ths[i] = thread(F1, &ar[i*4], 4, &xsum[i]); // le pasas la funcion y sus parametros... thread es un objeto que es un puntero a la funcion
        // con eso puede s ejecutar la fucnon y lo ejecuta dentro del thread. si es funcion retorna algo...  lo retorna a quien lo llamo..
        // y tu no tienes acceso a ese retorno... tu oslo le dices ejecuta esto.. asi que si reotrna algo o no no hay gofrma de qu tu lo tengas.
        // entonces por eso... que F1 es void. POR ENDE NO HAY UN RETURN, DESCARTA ESO! no hay forma de acceder a ese return.
        // Por eso procesar y agarra proceos y es via ... int* s (3er parametro...  de F1)

        //entonces los threads se hacen solo con fuciones VOID.


    }


    for(i = 0 ; i < nt ; i++){
        ths[i].join();
    }

    for(i = 0 ; i < nt ; i++){
        sum+=xsum[i];
    }

    cout<< "\n sum: "<<sum;

    getchar();

    return 0;
}
