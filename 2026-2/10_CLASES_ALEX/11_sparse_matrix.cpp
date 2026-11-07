/*
ESte tema
es una matriz pero con restricciones ya?

El objetivo es este: 

una matriz:

    0   1   2   3
0
1
2
3

pero digamos que solo tiene unos elementos validos

    0   1   2   3
0           4
1   7
2       2   6
3               9


y el resto vacio son ceros, pero estos ocupan espacio no?


La cosa aca, es crear una matriz que realmente no guarde los valores ceros.
Que no los guarde okay?

Normalmente una maatriz que tuviera ceros, tendria algo asi: 
    0   1   2   3
0   0   0   0   4
1   7   0   0   0
2   0   2   6   0
3   0   0   0   9

se gana velocidad, pero se pierde espacio


MATRIZ  SPARSE:::

RESTRICCION: 
No puede haber ningun cero en la matriz.
Sirve ya que hay problemas matematicos que son matrices gigantes y tienen numeros validos y muchos ceros.


Formas de hacer eso?:

Puedes hacer una LE de... numeros
el (x,y) son cordenadas
h -> 7 (0,1) -> 2(1,2) -> 4(2,0) -> 6(2,2) -> 9(3,3) - > null

Las coordenadas que no estan aqui, se deducen que son ceros.
Si lo encunetras devuelves un numero valido.
NO ESTAS GUARDANDO LOS CEROS.


el ramdon acces se pierde, ya que al ser LE se vuelve lineal.
Se pierde velocidad... pero ganas espacio.





--------------------


Y en un arbol???

recuerda que lo que se buca en la LE NO es el numero. ES la coordenada. SI EXISTE O NO

Por ejemplo la coordenada pueded ser un string. de forma qeu podamos ahacer esto:


2,0
 4

Eso seria un nodo en el arbol.

El objetivo es ver si la coordenada existe en tu contendor.

en un arbol binario si miras el numero.


Digamos si yo inserto el 1,2 vendria...


        2,0
        4
    1,2     2,2
    2        6
0,1             3,3
 7               9



Lo buscas 3,3 y retornas un 9

si no retornas un 0


podria ser en cualqueir cosa.
cualquiere strutura de datos que te permita 


------------------------------------------

Otra idea seria hacer o pone un arreglo aca 


    0   1   2   3
0 ->          4(2)
1 ->  7(0)
2 ->      2(1)   6(2)
3 ->              9(3)


un array de punteros a LE cosa que cada reglon agarra a los elementos que este nen esa le

cosa uqe la cordenada seria

2 (el puntero) , 1(la pos de la matriz) = 2,1




Igula es N, pero un N mas chiquito. mejroa un poco pero que pasaria si yo qiero hacer un proceso de multiplicacion de matrices
osea acceder vertical / horizoantla.

horizontal si sirve. pero vertical se va a la mierda.

con que en el coord y es el puntero, y.. la coord x seria la que tiene el nodo



Otra forma seria... hacerl o mismo 

pero poner en los nodos ambas coordenadas.

y tanto vertical como horizontal existan punteros y bllalall


tmr me perdi ajjaa

value
x,y
next, down

la implementacion se trata de una lista de 2 listas elazads que cohexisten....



PLATEAMIENTO DE POSIBLES OPERACIONES:


CENTREMONOS EN L AANTERIOR esa que esta loca csm.

CSMatrix(4x4);

cuando yo decalro eso. 

sol oexisten esos arreglos (el vertical y horaizontal con puro null)

AHora....
vamos hacer varias operaciones aca.


a = mget(2,0); este te devuelve un 4

internamente esto originaria una busqueda...

vienes.. buscar a partir  de la vertical y buscas un vcero.
las dos buqeusdas son validas. 
si enceutnra el elemnto te da el 4 y si no te da un 0

b = mget(2,1) esto te daria nu sero ya que no lo encunetra.




hagamos otras:

m.set(3,3,5);

esta mierad hace..

en la 3,3 quiero setear el valor 5 (actulametne aqui eta el nueve, tons chancamos y metemos el 5 encima.) // 9 -> 5


pero si hago:

m.set(3,1,8);

como no esta es un INSERTAR un 8, eso implica que tenemos que isnertarlo. en la lista vertical y la lista horizontal

crear un nodo ponerle 8, y su 3,1  y ya.


ahora...

m.set(3,1,0);

en estte caso ese 0 no lo podemos meter, por ende hay que verlo como nu BORRAR.


esto haria que sacamos ese nodo de ambos listas.
ya digamso 


llo primero que hacer

el get y el set

ahora.. com ohas visto cada una de estas de aca, lo primero que hace es una busuqeda internamente.


digamos que  tenediramos nuestro

set ins rem con los caos que sabemos..


ahora bien

el profe dice
    aqui| ptr p 
h-> 3 - > 8 -> 11 -> null

la idea del profe es que el punero
se coencte antes para poder meterlo antes y seso, es la fomra qeue prefiere el profe.

etnonces 

tenemos la inserccion en una lista y blalbal esa mierda que dice csm manolooo. supongo que hace referencia a su find de toda la vida.

que deberia volver esa busqueda entonces. 

devolver un puntero al puntero que apunta al nodo donde deberia estar.

es la mejro salida que tenemos.

pero en nuestro caso qeu deberia devolver?


en realidad para insertar en medio de dos la mejor opcion es deovlver un puntero a este., pero al ser dos punteros...
puntero vertical y otro punntero horizontal.



bool findv (int x , int y, SNode** &pv); buscar vertical
bool findh (int x , int y, SNode** &ph); buscar horizontal

            ------------|
            las coordenadas / y retorna este pnutero.


luego hace esto:

bool ins(int x, int y, int v);

bool rem(int x, int y);



tons tenemos un array de puntero 


el sett hace 3 operaciones
find
ins
rem
p


lalalalal

tons 

finds ins rem son las gods

set ins rem son solo llamadas.

y finalmente lo ideal seria qe esto funconoes asi:

ahora la matriz con el oeprador ( )
a = m(2,0) -> eso sseria el llamado del get  y blalalb.
esto seria mas estetico porque usa el operador paretnesis pero es la miermda kgada p

primero las finciones bool 
lego los mget m set
y finalmetne los ( ) 


Que pasaria si metemos un rango que no entra en el no entra.

en una matriz 4,4 y le pongo para el 5,4 deberias controalr ese error p. quizas un assert

y si FUERA UN ARBOL BIN, odo cambia.

bascaimetne quire que hagamos todas
y que todas aacabem con la ilterfaz final


*/

/*


11 - 02 - 26

El profesor acaba de agregar: 

IMPLEMENTAR ESTO USANDO CONTENEDORES <LIST> y <SET>


ADemáß:

Volvio a reeptir la mierdaesta de los 2 vectores.

segun el 

hicimos

finv(int x, int y, NOde**& r)
findh(int x, int y , NOde**& h)

Que sigue la misma logica que hacia con una lista elenzada normal..

lo que buscabmoas era un tipo si no lo que vbuscamos es un..


la idea del profe es que el puntero tenga 

x,y
valor
ptr down, ptr right


dice que cuando lo deaclras..

SMATRIX m(4,4); matriz de 4x4

dice que la matriz  puede hacer las operaciones asi

a = m(2,0);
b = m(0,1);

aca ponemos un operador parentesis. es mas estiticap ara el no es funcional, es estetico.


*/


/*


VERSION 2 A MANO DE LA MATRIZ ESPARTANA.


#include <iostream>
using namespace std;

class CNode {

public:
	int value;
	int columna;
	CNode* next;

	CNode(int v, int c) {
		value = v;
		columna = c;
		next = nullptr;
	}
};



class MatrizV2 {

private:

	int tamano;
	CNode** FILAS;


	bool find(CNode**& p, int f, int c);

	CNode* ins(int v, int f, int c);

	bool rem(int f, int c);


public:

	MatrizV2(int t) {

		tamano = t;
		FILAS = new CNode * [tamano];

		for (CNode** tmp = FILAS; tmp < FILAS + tamano; tmp++) {
			*tmp = nullptr;

		}
	}

	~MatrizV2() {

		for (CNode** tmp = FILAS; tmp < FILAS + tamano; tmp++) {

			CNode* p = *tmp;
			CNode* borrar = nullptr;

			while (p != nullptr) {

				borrar = p;

				p = p->next;

				delete borrar;

			}

		}

		delete[]FILAS;
	}


	void set(int v, int f, int c);

	int get(int f, int c);

	int operator()(int f, int c);

	void print();


};




bool MatrizV2::find(CNode**& p, int f, int c) {

	p = FILAS + f;

	while (*p && ((*p)->columna < c) ) {
		p = &((*p)->next);
	}

	return *p && ((*p)->columna == c);

}


CNode* MatrizV2::ins(int v, int f, int c) {

	CNode** p;

	if (!find(p, f, c)) {

		CNode* nodo = new CNode(v, c);
		nodo->next = *p;
		*p = nodo;
		return nodo;

	}
	else {
		return *p;
	}


}


bool MatrizV2::rem(int f, int c) {

	CNode** p;

	if (find(p, f, c)) {

		CNode* tmp = *p;
		*p = (*p)->next;

		delete tmp;
		return true;
	}
	else {
		return false;
	}

}



void MatrizV2::set(int v, int f, int c) {

	if (f >= tamano || c >= tamano || f < 0 || c < 0) {
		cout << "TAMANO INVALIDO" << endl;
		return;
	}

	if (v == 0) {
		rem(f, c);
	}
	else {

		CNode* rmlpzar = ins(v, f, c); 

		rmlpzar->value = v;

	}
}

int MatrizV2::get(int f, int c) {

	if (f >= tamano || c >= tamano || f < 0 || c < 0) {
		cout << "TAMANO INVALIDO" << endl;
		return -1;
	}


	CNode** p;

	if (find(p, f, c)) {
		return (*p)->value;
	}
	else {
		return 0;
	}

}

int MatrizV2::operator()(int f, int c) {

	return get(f, c);

}

void MatrizV2::print() {

	CNode** q = FILAS;
	CNode* s = nullptr;

	for (int i = 0; q < FILAS + tamano; q++, i++) {

		cout << "FILA " << i << ": ";

		s = *q;
		if (s != nullptr) {

			while (s != nullptr) {
				cout << "(col " << s->columna << " = " << s->value << ")  ";
				s = s->next;
			}

		}
		else {
			cout << "vacia";
		}

		cout << endl;
	}
	cout << endl;
}

int main() {

	MatrizV2 m(4);

	// TEST 1: 1000 ceros en matriz vacia
	for (int i = 0; i < 1000; i++) {
		m.set(0, i % 4, i % 4);
	}
	m.print();
	// Las 4 filas: vacia


	// TEST 2: insertar desordenado y pisar un valor
	m.set(8, 0, 3);
	m.set(5, 0, 1);
	m.set(9, 0, 1);
	m.print();
	// FILA 0: (col 1 = 9)  (col 3 = 8)
	// FILA 1: vacia
	// FILA 2: vacia
	// FILA 3: vacia


	// TEST 3: get y operator()
	cout << m.get(0, 1) << endl;   // 9
	cout << m(0, 3) << endl;       // 8
	cout << m(2, 2) << endl;       // 0
	cout << m.get(0, 4) << endl;   // TAMANO INVALIDO y luego -1


	// TEST 4: set fuera de rango
	m.set(5, 4, 0);    // TAMANO INVALIDO
	m.set(5, 0, -1);   // TAMANO INVALIDO
	m.set(5, -1, 0);   // TAMANO INVALIDO
	m.print();
	// Igual que el TEST 2


	// TEST 5: borrar con cero
	m.set(0, 0, 1);
	m.print();
	// FILA 0: (col 3 = 8)
	// Las demas: vacia


	// TEST 6: fila llena, borrar medio, primero y ultimo
	m.set(4, 2, 3);
	m.set(2, 2, 1);
	m.set(1, 2, 0);
	m.set(3, 2, 2);
	m.print();
	// FILA 0: (col 3 = 8)
	// FILA 2: (col 0 = 1)  (col 1 = 2)  (col 2 = 3)  (col 3 = 4)

	m.set(0, 2, 1);
	m.print();
	// FILA 2: (col 0 = 1)  (col 2 = 3)  (col 3 = 4)

	m.set(0, 2, 0);
	m.print();
	// FILA 2: (col 2 = 3)  (col 3 = 4)

	m.set(0, 2, 3);
	m.print();
	// FILA 2: (col 2 = 3)


	// TEST 7: borrar algo que no existe
	m.set(0, 1, 1);
	m.set(0, 3, 2);
	m.print();
	// Igual que el anterior

	return 0;
}

*/




/*

VERSION 1 - LE SIMPLE


#include <iostream>
using namespace std;

struct Nodo {

	int valor;
	int fila;
	int columna;

	Nodo* next;

	Nodo(int v, int f, int c) {
		valor = v;
		fila = f;
		columna = c;
		next = nullptr;
	}

};

struct MatrizV1 {

	Nodo* head;
	int tamano;

	MatrizV1(int t) {
		tamano = t;
		head = nullptr;
	}

	~MatrizV1() {

		Nodo* p = head;
		Nodo* tmp = nullptr;

		while (p != nullptr) {
			tmp = p;

			p = p->next;

			delete tmp;
		}

	}

	bool find(Nodo**& p, int f, int c);
	bool ins(int v, int f, int c);
	bool rem(int f, int c);

	void set(int v, int f, int c);

	int get(int f, int c);


	int operator()(int f, int c);


	void print();
};



bool MatrizV1::find(Nodo**& p, int f, int c) {

	while (*p &&  ((*p)->fila < f   ||  ((*p)->fila == f && (*p)->columna < c) ) ){
		p = &((*p)->next);
	}

	return *p && ((*p)->fila == f && (*p)->columna == c);
}



bool MatrizV1::ins(int v, int f, int c) {

	Nodo** p = &head;

	if (!find(p, f, c)) {

		Nodo* nuevo = new Nodo(v, f, c);

		nuevo->next = *p;

		*p = nuevo;

		return true;

	}
	else {
		return false;
	}

}

bool MatrizV1::rem(int f, int c) {

	Nodo** p = &head;

	if (find(p, f, c)) {

		Nodo* tmp = *p;

		*p = (*p)->next;

		delete tmp;

		return true;

	}
	else {
		return false;
	}


}

int MatrizV1::get(int f, int c) {

	if (!((f >= 0 && f < tamano) && (c >= 0 && c < tamano))) {
		cout << "TAMANO FUERA DE MATRIZ" << endl;
		return -1;
	}

	Nodo** p = &head;

	if (find(p, f, c)) {
		return (*p)->valor;
	}
	else {
		return 0;
	}


}


void MatrizV1::set(int v, int f, int c) {

	if (!((f >= 0 && f < tamano) && (c >= 0 && c < tamano))) {
		cout << "TAMANO FUERA DE MATRIZ" << endl;
		return;
	}

	if (v == 0) { // si el v es cero, llamar a remover.
		rem(f, c);
	}
	else {

		if (!ins(v, f, c)) { // el ins se ejecuta si o si. asi que ya insertamos; si no se pudo. REEMPLAZAMOS.

			Nodo** p = &head;
			find(p, f, c);

			(*p)->valor = v;

		}

	}

}


int MatrizV1::operator()(int f, int c) {

	return get(f, c);

}

void MatrizV1::print() {

	for (int i = 0; i < tamano; i++) {
		for (int j = 0; j < tamano; j++) {
			cout << get(i, j) << "\t";
		}
		cout << endl;
	}

}


int main() {

	MatrizV1 m(4);

	cout << "=== TEST 1: insertar ===" << endl;
	m.set(5, 0, 3);
	m.set(15, 1, 3);
	m.set(28, 3, 2);
	m.print();
	cout << endl;

	cout << "=== TEST 2: actualizar uno existente (1,3) -> 99 ===" << endl;
	m.set(99, 1, 3);
	cout << "m(1,3) = " << m(1, 3) << endl;
	m.print();
	cout << endl;

	cout << "=== TEST 3: borrar con 0 en (3,2) ===" << endl;
	m.set(0, 3, 2);
	cout << "m(3,2) = " << m(3, 2) << endl;
	m.print();
	cout << endl;

	cout << "=== TEST 4: posicion inexistente (2,2) ===" << endl;
	cout << "m(2,2) = " << m(2, 2) << endl;
	cout << endl;

	cout << "=== TEST 5: insertar en medio y al inicio (orden) ===" << endl;
	m.set(7, 0, 0);
	m.set(8, 0, 1);
	m.set(3, 2, 1);
	m.print();
	cout << endl;

	cout << "=== TEST 6: fuera de rango ===" << endl;
	m.set(2, 4, 4);
	m.set(2, -1, 0);
	cout << "m(0,4) = " << m(0, 4) << endl;

	return 0;
}


*/
