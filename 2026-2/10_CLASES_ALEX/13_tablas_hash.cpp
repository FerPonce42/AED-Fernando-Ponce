/*

Concepto simple

Objetivo:

tienes un conjunto de enttradas, por ejemplo numeros, aunqeu pdoria ser aucalqueir tipo de datos.
strings.. floats..ojbetos con varios... o eso p.

por otro lado tienes una tabla, que es como un vector. es ahi donde meteras esos datos.

quizas con strings usar ASCII o sumando lso caracteres de sus nombres y asi p.
ademas hay una funcion digmaos f(x) entra uno de ess y sale una posicion...


7 9                                             0   
10 2        f(x) = x % 7                        1
1 5 6                                           2
5 6                                             3    
                                                4
                                                5
                                                6
                                                       

El objetivo...



regresando a lo de l profe...


7 9                                             0[7]   
10 2        f(x) = x % 7                        1[8]
1 5 6                                           2[9]
5 6                                             3    
                                                4[4]
                                                5
                                                6

Segun la f(x) no tiene colisiones.. esl a perfecta, pero en la practica se dan.
Hay que manejar las colisiones. suponiendo que 2 valores cane alli.

Hay varias formas:

1) Simple pero no eficiente:
Buscar la primera posicion vacia. osea.. el 2 cae en 2, pero la promera acia seria en 3[aqui]
La commplejidad es O(K)
por ende la funcion tien un orden constante.

La idea de la tabla hash es que ese sea O(K) (cuando no hay repetidos aun)

ENTRADA: O(K)
BUSQUEDA: O(K) -> salida... asi tu ecuacion sea compleja.
tu ecuceniaon debe ser constante.


2 mod 7 = 2 cae en [9]

Busnaod la primera pisicon vacia depues del n osea lel 3, pero que pasa si todas estan llenas.. y digamos la del 0 estaba vacia, 
entonces el 2 estaria lejos de 9

Que pasaria con la busqueda del dos?
se malogro porque si tienes al dos,  y no estas seguro que ni este ahi. porque se podria haber puesto en un lugar vacio.
No es eficiente, nada garantiza de que el lugar ese este vacio.

Es una forma para solucionarlo de forma punteal.. pero quiebbra el orden constante.
de todas maneras lo quiebra....


solo nos lo dice porque lo uestra en los libros.


OTRA FORMA:


Usar una 2da funcion... llamada.. fx2(x) = x² % 7
cosa qeue si f1(x) colisiona, vas a fx2..

Osea usar 2 funciones de dispersion para encontrar el lugar.
pero nohay ninguna garantiza que la 2da te de que no caiga en un lugar vacio.




DESCARTANDO ESAS IDEAS..
en la misma tabla...
la mejor salida.

es que que esa lsita sea una lista de punteros que apunte a una LE para que no haya problemas.

7 9                                             0[ ]   
10 2        f(x) = x % 7                        1[ ] -> 8 -> 1
1 5 6                                           2[ ] -> 9 -> 2
5 6                                             3[ ] -> 10  
                                                4[ ] -> 4
                                                5[ ] -> 5
                                                6[ ] -> 6

Haces todo, pero la minibusqueda que harias en las LE...

osea O(N)


osea va a ser un N pero chiquito que tiende a ser como uno o como ceor.. asi que aun se considera una tabla hash.



Si las colisiones son chiquitas de 1 o 0, tons.. en la practica es como si fuera constante..

Si por algun razon genera picos en tu diagrama de colisiones entonces es una tabla hash, tu funcion de dispersion es mala. porque 
son casi N


Mantener que las colisiones sean bajitas.. numeros bajas cercanos a cero.


No hay parametros en esa funcion..  
osea 9 datos, en 7 espacios.. entonces que pasa si.

OTRA FORMA es;;;;

si esto en vez de ser 7, le ponemos 700 hay demasiado espacios. tednria que serm ala t funcion ..

O HACS UNA MEJOR FUNCION o.. AMPLIAS EL ESPACIO DE DISPERSION.



mientras que x % primo , la posibidldad que haya colisiones se reduce....

en cambios s hacer ujn 

x%48 la probaldada de mayores ccondiciones es mas porque es muy divisible.

asi qeu nlo  norlmal es poenr n njumero proimo.



OBJETIVO:
ENTRADA Y SALIDA SEAN MASOMENOS TIEMPO CONSTANTE.

esa LE pdoria ser un vector, un arbol.. ahi seria log N 


tons..
5nn vecto de estrcturas... y la funcion.

aqui no nos complquenmos con el extendible hashing jajaaj la ocsa es que no tenga tantas c
ccolisiones yya. no comlicarnos la vida.

quizas contar la cantidad ecoolciisones que haya para cerciorarnos.


el profe pone de ejmplo un arbol digital para hacer referencia al hash.

PERO NO TOMARA ESO, ESO NO HACEMOS EN EL CURSO, SOLO ES UN EJEMPLO AL AIRE. ajjaa
es una fumada lo que esta haciendo ya nos dijo que esto no enetra a lexamen jaajjajajajajajaj

*/

/*
HASH

V1: un vector normal, vector<int>. Se llena "feo" porque si la casilla está ocupada, avanzas a la siguiente.
V2: también un vector normal, vector<int>. Lo único distinto es que al colisionar usas f2 en vez de avanzar. El vector no hace doble cosa, 
la que hace doble cosa es tu función.
V3: un vector de listas enlazadas, vector<list<int>>. Eso sí cambia la estructura.
*/


/*-------------------------------------------------------------------------------------------------------------------------------------------------*/



/*
// V1 Vector normal
#include <iostream>
#include <vector>

using namespace std;


class HashV1 {

private:
	// numero, colision
	vector<pair<int,int>> v;
	int tam;
	int elem;

public:

	HashV1(int t) {

		tam = t;
		elem = 0;
		v.assign(t, make_pair(-1,0));

	}

	void buscar(int x);

	void insertar(int x);

	int hash(int x);


	void mostrar();

};


int HashV1::hash(int x) {

	int pos = x % tam;

	return pos;
}

void HashV1::buscar(int x) {

	int i = hash(x); 
	int cont = 0;


	if (v[i].first == -1) {
		cout << x << " -> " << "NO" << endl;
		return;
	}
	else {

		while (cont < tam && v[i].first != -1) {

			if (v[i].first == x) {
				cout << x << " -> " << "SI" << endl;
				return;
			}

			i = (i + 1) % tam;
			cont++;

		}

	}

	cout << x << " -> " << "NO" << endl;
}

void HashV1::insertar(int x) {

	if (elem == tam) {
		cout << "CASILLAS LLENAS" << endl;
		return;
	}

	int i = hash(x);
	int cont = 0;

	while (cont < tam && v[i].first != -1) {

		v[i].second += 1; // entrar a lbucle + 1 colision a ese lleno.
		
		i = (i + 1) % tam;
		cont++;
	}

	if (v[i].first == -1) {
		v[i].first = x;
		elem++;
		
	}

}



void HashV1::mostrar() {

	cout << "====== TABLA HASH - V1 ======" << endl;
	cout << "-------------------------" << endl;
	cout << "POS"<<"  -  " << "DATO" << "    -    " << "COLISIONES" << endl;
	cout<< "-------------------------" << endl;

	for (int p = 0; p < v.size(); p++) {

		cout << "["<<p<<"]"<<"  |  " << v[p].first << "      |      " << v[p].second << endl;

	}


}

int main() {

	HashV1 h(7);

	cout << "--- TABLA VACIA ---" << endl;
	h.mostrar();

	cout << endl << "--- INSERTANDO 2, 9, 16, 5, 12, 23 ---" << endl;
	h.insertar(2);
	h.insertar(9);
	h.insertar(16);
	h.insertar(5);
	h.insertar(12);
	h.insertar(23);
	h.mostrar();

	cout << endl << "--- INSERTANDO 6 ---" << endl;
	h.insertar(6);

	cout << endl << "--- ANTES de intentar el 13 ---" << endl;
	h.mostrar();

	cout << endl << "--- intento insertar 13 ---" << endl;
	h.insertar(13);

	cout << endl << "--- DESPUES de intentar el 13 ---" << endl;
	h.mostrar();

	cout << endl << "--- INSERTANDO 30 (ya no hay espacio) ---" << endl;
	h.insertar(30);

	cout << endl << "--- BUSQUEDAS ---" << endl;
	h.buscar(9);
	h.buscar(23);
	h.buscar(13);
	h.buscar(6);
	h.buscar(4);
	h.buscar(30);
}

*/