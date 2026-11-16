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


*/


#include <iostream>
#include <thread>
using namespace std;

#include <vector>

void reparto(long* arr, int n, int* s) {

	for (int i = 0; i < n; i++) {

		*s += arr[i];

	}


}

int main() {

	long arr[] = { 2,6,3,1,7,8,9,6,4,3,2,8,9,11,13,1 };

	int s[] = { 0,0,0,0 };

	vector<thread> t(4);

	for (int i = 0; i < 4; i++) {
		t[i] = thread(reparto, arr + i*4, 4, s + i);
	}

	for (int i = 0; i < 4; i++) {

		t[i].join();

	}

	long suma = 0;

	for (int i = 0; i < 4; i++) {
		suma += s[i];
	}

	cout << suma;

}




/*

SIN MUTEX Y RESULTADO CORRECTO (RAPIDO)

long parcial[2];

void sumarmejor(int n, long* s) {

	for (int i = 0; i < n; i++) {

		*s += 1;

	}

}


int main() {

	thread t1(sumarmejor, 10000000, &parcial[0]);

	thread t2(sumarmejor, 10000000, &parcial[1]);


	t1.join();
	t2.join();


	long total = parcial[0] + parcial[1];

	cout << total;
}

*/










/*

CON MUTEX Y RESULTADO CORRECTO (LENTO)

#include <mutex>

using namespace std;

long total = 0;
mutex m;

void sumar(int n) {

	for (int i = 0; i < n; i++) {

		m.lock();
		total += 1;
		m.unlock();

	}

}

int main() {

	thread t1(sumar, 10000000);

	thread t2(sumar, 10000000);

	t1.join();
	t2.join();

	cout << total;
}

*/

/*

SIN MUTEX Y RESULTADO INCORRECTO

#include <iostream>
#include <thread>

using namespace std;

void F1(char c, int n) {

	for (int i = 0; i < n; i++) {
		cout << c;
	}

}

int main() {

	thread t1(F1, 'a', 10000);

	thread t2(F1, 'b', 10000);

	t1.join();
	t2.join();

	cout << endl;

}

*/