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
VERSION 5 DE LA MATRIZ, AHORA CON EL CONTENEDOR SET QUE ASCO.

#include <iostream>
#include <set>
using namespace std;

// VERSION PARA USAR EL COMPARADOR FUERA DEL NODO:
class CNode {
public:
	int value;
	int row;
	int column;

	CNode(int v, int r, int c) {
		value = v;
		row = r;
		column = c;
	}
	// sin operator<
};

// función suelta, fuera de todas las clases
bool comparar(const CNode& a, const CNode& b) {

	if (a.row < b.row) {          // a va antes que b
		return true;
	}
	else if (a.row == b.row) {
		return a.column < b.column;
	}
	else {
		return false;
	}

}

class MatrizV5 {

private:

	set<CNode, bool(*)(const CNode&, const CNode&)> contenedor;
	int TAM_ROW;
	int TAM_COLUM;

public:

	MatrizV5(int tr, int tc) : contenedor(comparar) {
		TAM_ROW = tr;
		TAM_COLUM = tc;
	}

	// get, set, operator() no cambian
};
// NADA MAS, solo eso cambia, el resto se mantiene igual como nosoros lo habiamos hecho aqui:
// ESTA VERSION DE ABAJO SERIA LA.. MAS TRANQUILA?...

class CNode {
public:
	int value;
	int row;
	int column;

	CNode(int v, int r, int c) {
		value = v;
		row = r;
		column = c;
	}

	bool operator<(const CNode& n) const;

};

class MatrizV5;

class CX {
private:
	int r;
	int c;
	MatrizV5* pm;
public:
	CX(int row, int column, MatrizV5* direccion) {
		r = row;
		c = column;
		pm = direccion;
	}

	operator int();

	CX& operator= (int v);

};

class MatrizV5 {

private:

	set<CNode> contenedor;
	int TAM_ROW;
	int TAM_COLUM;

public:

	MatrizV5(int tr, int tc) {
		TAM_ROW = tr;
		TAM_COLUM = tc;
	}

	int get(int r, int c);

	void set(int v, int r, int c);

	CX operator() (int r, int c);

};



/// Logica para el SET
// row : el que vive dentro
// n.row : el que venimos a meter

//  Se que es un arbol, pero imaginalo como vector. no hay de otra.

bool CNode::operator<(const CNode& n) const {

	if (row < n.row) { // row va antes que n.row
		return true;
	}
	else if (row == n.row) {
		return column < n.column;
	}
	else {
		return false;
	}

}


int MatrizV5::get(int r, int c) {

	CNode n(0, r, c);

	auto encontrado = contenedor.find(n);

	if (encontrado != contenedor.end()) {
		return encontrado->value;
	}
	else {
		return 0;
	}

}

void MatrizV5::set(int v, int r, int c) {

	CNode n(v, r, c);

	auto encontrado = contenedor.find(n);

	if (v == 0) {
		
		if (encontrado != contenedor.end()) {
			contenedor.erase(encontrado); // borra porque es 0 p
		}

	}
	else {
		
		if (encontrado != contenedor.end()) { // si estaba, (no podemos reemplzar directo) ; borra e inserta.
			contenedor.erase(encontrado);
			contenedor.insert(n);
		}
		else {
			contenedor.insert(n); // si no estaba, insertar normal
		}

	}


}



CX MatrizV5::operator() (int r, int c) {

	return CX(r, c, this);

}


CX::operator int() {

	return pm->get(r,c);

}

CX& CX::operator= (int v) {

	pm->set(v,r,c);

	return *this;
}



// RELLENO PARA PODER IMPRIMIR  Y VER LOS TESTS:

void probar(const char* nombre, int obtenido, int esperado) {
	if (obtenido == esperado)
		cout << "OK    " << nombre << endl;
	else
		cout << "FALLO " << nombre << " -> salio " << obtenido
		<< ", esperaba " << esperado << endl;
}

int main() {

	MatrizV5 m(4, 4);

	// 1. casilla vacía
	probar("vacia devuelve 0", m(0, 3), 0);

	// 2. guardar y leer
	m(0, 3) = 4;
	probar("guardar 4 en (0,3)", m(0, 3), 4);

	// 3. sobrescribir una casilla que ya existe
	m(0, 3) = 9;
	probar("sobrescribir (0,3) con 9", m(0, 3), 9);

	// 4. guardar 0 borra el nodo
	m(0, 3) = 0;
	probar("guardar 0 en (0,3)", m(0, 3), 0);

	// 5. guardar 0 en casilla vacía (no debe romper nada)
	m(2, 2) = 0;
	probar("0 en casilla vacia", m(2, 2), 0);

	// 6. varias casillas no se pisan entre sí
	m(1, 1) = 5;
	m(1, 2) = 6;
	m(2, 1) = 7;
	m(0, 0) = 8;
	probar("(1,1)", m(1, 1), 5);
	probar("(1,2)", m(1, 2), 6);
	probar("(2,1)", m(2, 1), 7);
	probar("(0,0)", m(0, 0), 8);

	// 7. borrar una no afecta a las demás
	m(1, 2) = 0;
	probar("(1,2) borrada", m(1, 2), 0);
	probar("(1,1) sigue", m(1, 1), 5);
	probar("(2,1) sigue", m(2, 1), 7);

	// 8. volver a llenar una casilla borrada
	m(1, 2) = 3;
	probar("(1,2) reinsertada", m(1, 2), 3);

	// 9. esquinas
	m(0, 3) = 1;
	m(3, 0) = 2;
	m(3, 3) = 3;
	probar("esquina (0,3)", m(0, 3), 1);
	probar("esquina (3,0)", m(3, 0), 2);
	probar("esquina (3,3)", m(3, 3), 3);

	// 10. misma fila, distinta columna / misma columna, distinta fila
	probar("(3,1) vacia", m(3, 1), 0);
	probar("(1,3) vacia", m(1, 3), 0);

	// 11. valor negativo
	m(2, 3) = -5;
	probar("negativo en (2,3)", m(2, 3), -5);

}




*/







/*

VERSION 4 DE LA MATRIZ, UN ARBOL BST MODIFICADO: 

#include <iostream>
#include <assert.h>

#include <cstdlib> // para imprimir nomas



using namespace std;


class CNode {
public:
	int value;
	int row;
	int column;

	CNode* left;
	CNode* right;

	CNode(int v, int r, int c) {
		value = v;
		row = r;
		column = c;
		left = nullptr;
		right = nullptr;
	}
};

class MatrizV4;


class CX {
private:
	
	int row;
	int column;

	MatrizV4* pm;
public:
	CX(int r, int c, MatrizV4* ptr_this) {
		row = r;
		column = c;
		pm = ptr_this;
	}



	CX& operator= (int v);

	operator int();

};

class MatrizV4 {

private:

	CNode* root;

	int TAM_ROW;
	int TAM_COLUMN;

	void destruir(CNode* n);

	bool find(CNode**& p, int r, int c);
	bool ins(int v, int r , int c);
	bool rem(int r, int c);

public:

	MatrizV4(int tam_r, int tam_c) {
		TAM_ROW = tam_r;
		TAM_COLUMN = tam_c;
		root = nullptr;
	}

	~MatrizV4() {
		destruir(root);
	}

	int get(int r, int c);

	void set(int v, int r, int c);

	CX operator()(int r, int c);


	// solo para imprimir:
	void mostrar();

};

void MatrizV4::destruir(CNode* n) {
	if (n == nullptr) {
		return;
	}
	// para liberar imagina un postorden:

	destruir(n->left);

	destruir(n->right);

	delete n;
}

bool MatrizV4::find(CNode**& p, int r, int c) {

	while (*p) {

		if ((*p)->row > r) {

			p = &((*p)->left);

		}
		else if ((*p)->row == r) {

			if ((*p)->column > c) {

				p = &((*p)->left);

			}
			else if ((*p)->column == c) {

				return true;

			}
			else {

				p = &((*p)->right);

			}


		}
		else {
			p = &((*p)->right);
		}
	}

	return false;

}


bool MatrizV4::ins(int v, int r, int c) {

	CNode** p = &root;

	if (!find(p, r, c)) {
		CNode* nodo = new CNode(v, r, c);
		*p = nodo;
		return true;
	}
	else {
		(*p)->value = v;
		return false;
	}

}


bool MatrizV4::rem(int r, int c) {

	CNode** p = &root;

	if (find(p, r, c)) {

		CNode* tmp;


		if ((*p)->left != nullptr && (*p)->right != nullptr) {

			CNode* padre = *p;
			p = &((*p)->left);

			while ((*p)->right != nullptr) {
				p = &((*p)->right);
			}

			tmp = *p;

			padre->value = tmp->value;
			padre->row = tmp->row;
			padre->column = tmp->column;

		}


		if ((*p)->left != nullptr || (*p)->right != nullptr) {
			tmp = *p;
			if ((*p)->left != nullptr) {
				*p = (*p)->left;
			}
			else {
				*p = (*p)->right;
			}
		}
		else {
			tmp = *p;
			*p = nullptr;
		}
		delete tmp; 
		return true;


	}
	else {
		return false;
	}

}

int MatrizV4::get(int r, int c) {

	assert(r >= 0 && r < TAM_ROW && c >= 0 && c < TAM_COLUMN);

	CNode** p = &root;

	if (find(p, r, c)) {
		return (*p)->value;
	}
	else {
		return 0;
	}

}


void MatrizV4::set(int v, int r, int c) {

	assert(r >= 0 && r < TAM_ROW && c >= 0 && c < TAM_COLUMN);

	if (v == 0) {
		rem(r, c);
	}
	else {
		ins(v, r, c);
	}

}


CX MatrizV4::operator()(int r, int c) {

	return CX(r, c, this);

}


CX& CX::operator= (int v) {

	pm->set(v, row, column);

	return *this;

}

CX::operator int() {

	return pm->get(row, column);
}


void MatrizV4::mostrar() {
	for (int r = 0; r < TAM_ROW; r++)
		for (int c = 0; c < TAM_COLUMN; c++)
			if (get(r, c) != 0)
				cout << "(" << r << "," << c << ") = " << get(r, c) << endl;
}




int main() {
	const int N = 6;
	int fallos = 0;

	// compara una matriz contra un arreglo normal (la "verdad") y reporta
	auto verificar = [&](MatrizV4& m, int ref[N][N], const char* test) {
		for (int r = 0; r < N; r++)
			for (int c = 0; c < N; c++)
				if (m.get(r, c) != ref[r][c]) {
					cout << "FALLO " << test << " en (" << r << "," << c << "): get="
						<< m.get(r, c) << " esperado=" << ref[r][c] << endl;
					fallos++;
					return;
				}
		cout << "OK    " << test << endl;
		};

	// TEST 1: ceros en todos lados (no deben crear nada)
	{
		MatrizV4 m(N, N); int ref[N][N] = {};
		for (int r = 0; r < N; r++) for (int c = 0; c < N; c++) m.set(0, r, c);
		verificar(m, ref, "TEST 1a: set(0) en toda la matriz vacia");
		m.set(7, 2, 2); ref[2][2] = 7;
		for (int r = 0; r < N; r++) for (int c = 0; c < N; c++)
			if (r != 2 || c != 2) m.set(0, r, c);          // ceros alrededor de un unico dato
		verificar(m, ref, "TEST 1b: ceros alrededor de un dato");
	}

	// TEST 2: full bucle: llenar todo, vaciar en orden raro, volver a llenar
	{
		MatrizV4 m(N, N); int ref[N][N] = {};
		for (int r = 0; r < N; r++) for (int c = 0; c < N; c++) { m.set(r * N + c + 1, r, c); ref[r][c] = r * N + c + 1; }
		verificar(m, ref, "TEST 2a: llena completa");
		for (int r = N - 1; r >= 0; r--) for (int c = 0; c < N; c += 2) { m.set(0, r, c); ref[r][c] = 0; }
		verificar(m, ref, "TEST 2b: vaciado parcial (reves)");
		for (int c = 0; c < N; c++) for (int r = 0; r < N; r++) { m.set(0, r, c); ref[r][c] = 0; }
		verificar(m, ref, "TEST 2c: vaciada total (por columnas)");
		for (int r = 0; r < N; r++) for (int c = N - 1; c >= 0; c--) { m.set(1, r, c); ref[r][c] = 1; }
		verificar(m, ref, "TEST 2d: llena de nuevo (orden inverso)");
	}

	// TEST 3: sobrescribir, borrar inexistentes y borrar dos veces lo mismo
	{
		MatrizV4 m(N, N); int ref[N][N] = {};
		m.set(1, 4, 4); m.set(9, 4, 4); m.set(9, 4, 4); ref[4][4] = 9;
		m.set(3, 1, 1); ref[1][1] = 3;
		m.set(0, 5, 5); m.set(0, 0, 0);                     // inexistentes
		m.set(0, 1, 1); m.set(0, 1, 1); ref[1][1] = 0;      // borrar dos veces
		verificar(m, ref, "TEST 3: sobrescribir / inexistentes / doble borrado");
	}

	// TEST 4: borrar con 0, 1 y 2 hijos (incluida la raiz)
	{
		MatrizV4 m(N, N); int ref[N][N] = {};
		int datos[][2] = { {3,3},{1,1},{5,5},{0,0},{2,2},{4,4},{5,0} };   // raiz (3,3) con dos hijos
		for (auto& d : datos) { m.set(1, d[0], d[1]); ref[d[0]][d[1]] = 1; }
		int borrar[][2] = { {0,0},{5,5},{1,1},{3,3},{2,2} };               // hoja, 1 hijo, 2 hijos, raiz...
		for (auto& d : borrar) { m.set(0, d[0], d[1]); ref[d[0]][d[1]] = 0; }
		verificar(m, ref, "TEST 4: borrados con 0/1/2 hijos y raiz");
	}

	// TEST 5: estres aleatorio (~1/3 ceros), verificando cada paso
	{
		MatrizV4 m(N, N); int ref[N][N] = {};
		srand(12345);
		int antes = fallos;
		for (int i = 0; i < 30000 && fallos == antes; i++) {
			int r = rand() % N, c = rand() % N;
			int v = (rand() % 3 == 0) ? 0 : rand() % 9 + 1;
			m.set(v, r, c); ref[r][c] = v;
			for (int a = 0; a < N && fallos == antes; a++)
				for (int b = 0; b < N; b++)
					if (m.get(a, b) != ref[a][b]) {
						cout << "FALLO TEST 5 en la operacion " << i << ", celda (" << a << "," << b << ")" << endl;
						fallos++; break;
					}
		}
		if (fallos == antes) cout << "OK    TEST 5: estres aleatorio" << endl;
	}

	// TEST 6: mv4(r,c) lectura y escritura
	{
		MatrizV4 m(4, 4);
		m(1, 2) = 5; m(0, 3) = 7; m(2, 1) = 9;
		int x = m(1, 2);
		m(1, 2) = 0;
		if (x == 5 && m(1, 2) == 0 && m(0, 3) == 7) cout << "OK    TEST 6: operator()" << endl;
		else { cout << "FALLO TEST 6: operator()" << endl; fallos++; }
		m.mostrar();
	}

	cout << (fallos == 0 ? "\nTODOS LOS TESTS PASARON" : "\nHAY FALLOS") << endl;
}

*/








/*

VERSION 3 DE LA MATRIZ 


#include <iostream>
#include <assert.h>
using namespace std;

class CNode {

public:

	int value;
	int fila;
	int columna;

	CNode* next;
	CNode* down;

	CNode(int v, int f, int c) {
		next = nullptr;
		down = nullptr;
		value = v;
		fila = f;
		columna = c;
	}
};


class MatrizV3; // declarar que mas abajo esta todo el cuerpo.

struct CX {

	int fila;
	int columna;
	MatrizV3* pm;

	CX(MatrizV3* mv3, int f, int c) {

		pm = mv3; // guardamos el objeto del main
		fila = f;
		columna = c;

	}

	operator int(); // para cuando piden get

	CX& operator= (int v);

};

class MatrizV3 {

private:


	int TAM_F;
	int TAM_C;

	CNode** FILAS;

	CNode** COLUM;


	bool findF(CNode**& p, int f, int c);

	bool findC(CNode**& p, int f, int c);


	bool ins(int v, int f, int c);

	bool rem(int f, int c);



public:



	MatrizV3(int tf, int tc) {
		TAM_F = tf;
		TAM_C = tc;


		FILAS = new CNode * [TAM_F];
		COLUM = new CNode * [TAM_C];


		for (CNode** x = FILAS; x < FILAS + TAM_F; x++) {
			*x = nullptr;
		}

		for (CNode** y = COLUM; y < COLUM + TAM_C; y++) {
			*y = nullptr;
		}

	}

	~MatrizV3() {

		CNode** p = FILAS;
		CNode* pp = nullptr;
		CNode* tmp = nullptr;

		while (p < FILAS + TAM_F) {

			pp = *p;

			while (pp != nullptr) {
				tmp = pp;
				pp = pp->next;
				delete tmp;
			}


			p++;
		}

		delete[] FILAS;
		delete[] COLUM;

	}


	int get(int f, int c);

	void set(int v, int f, int c);

	CX operator()(int f, int c);


};


bool MatrizV3::findF(CNode**& p, int f, int c) {
	
	p = FILAS + f;

	while (*p && (*p)->columna < c) {
		p = &((*p)->next);
	}

	return *p && (*p)->columna == c;

}

bool MatrizV3::findC(CNode**& p, int f, int c) {

	p = COLUM + c;

	while (*p && (*p)->fila < f) {
		p = &((*p)->down);
	}

	return *p && (*p)->fila == f;

}

bool MatrizV3::ins(int v, int f, int c) {

	CNode** pf;
	CNode** pc;

	if (!findF(pf, f, c) && !findC(pc, f, c)) {

		CNode* nodo = new CNode(v, f, c);
		nodo->next = *pf;
		*pf = nodo; 

		nodo->down = *pc;
		*pc = nodo;

		return true; 
	}
	else {
		(*pf)->value = v;
		return false;
	}


}

bool MatrizV3::rem(int f, int c) {

	CNode** pf;
	CNode** pc;

	if (findF(pf, f, c) && findC(pc, f, c)) {

		CNode* tmpfc = *pf;

		*pf = (*pf)->next;
		*pc = (*pc)->down;

		delete tmpfc;
		
		return true;

	}
	else {
		return false;
	}

}


int MatrizV3::get(int f, int c) {

	assert(f >= 0 && c >= 0 && f < TAM_F && c < TAM_C);
	CNode** pf;
	if (findF(pf, f, c)) {
		return (*pf)->value;
	}
	else {
		return 0;
	}

}

void MatrizV3::set(int v, int f, int c) {

	assert(f >= 0 && c >= 0 && f < TAM_F && c < TAM_C);

	if (v == 0) {
		rem(f, c);
	}
	else {
		ins(v, f, c); // el caso de insertar y setear un valor se resolve directamente en ins.
	}


}

// LOGICA PARA LA MATRIZ.
CX MatrizV3::operator()(int f, int c) {

	return CX(this, f, c);

}


//LOGICA QUE ESTA DENTRO DE CX, AL RECIBIR LO QUE LO ANTERIOR LE DIO

CX::operator int() {
	return pm->get(fila, columna);
}


CX& CX::operator= (int v) {

	pm->set(v, fila, columna);

	return *this;
}








// aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

void check(const char* nombre, int obtenido, int esperado) {
	cout << (obtenido == esperado ? "[OK]    " : "[FALLO] ")
		<< nombre << " -> " << obtenido
		<< " (esperado " << esperado << ")" << endl;
}

int main() {
	MatrizV3 m(4, 4);

	// 1. casilla vacía
	check("vacia (1,3)", m(1, 3), 0);

	// 2. set y get
	m(1, 3) = 7;
	check("guardar 7 en (1,3)", m(1, 3), 7);

	// 3. sobrescribir
	m(1, 3) = 8;
	check("sobrescribir (1,3)", m(1, 3), 8);

	// 4. varios nodos (fila 1 y columna 3)
	m(1, 0) = 3;
	m(1, 2) = 5;
	m(0, 3) = 4;
	m(2, 3) = 6;
	check("(1,0)", m(1, 0), 3);
	check("(1,2)", m(1, 2), 5);
	check("(0,3)", m(0, 3), 4);
	check("(2,3)", m(2, 3), 6);
	check("(1,3) sigue", m(1, 3), 8);

	// 5. borrar con 0
	m(1, 3) = 0;
	check("borrar (1,3)", m(1, 3), 0);

	// 6. los vecinos no se rompieron
	check("(1,0) intacto", m(1, 0), 3);
	check("(1,2) intacto", m(1, 2), 5);
	check("(0,3) intacto", m(0, 3), 4);
	check("(2,3) intacto", m(2, 3), 6);

	// 7. volver a insertar donde se borró
	m(1, 3) = 9;
	check("reinsertar (1,3)", m(1, 3), 9);



	// 8. borrar una casilla que ya está vacía
	m(2, 2) = 0;
	check("borrar vacia (2,2)", m(2, 2), 0);
	check("(1,3) intacto", m(1, 3), 9);


	return 0;   // aquí corre tu destructor
}


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
