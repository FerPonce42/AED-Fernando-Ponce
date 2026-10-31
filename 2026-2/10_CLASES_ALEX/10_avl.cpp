/*

El nombre proviene de AVL p
Hay otras tecnicas de balanceo llamda: redblack
en que consiste su webada:


ejem
insert 10 20 30 40 50...

10
    20
        30
            40
                50
y terminaria siendo una LE normal.

la idea es evitar que el arbol termine asi.

La tecnica termina arreglando todo esto, para que no pierda su forma 
triangular.

Para que la busqueda siempre sea lg2N


en stl existe: std::set<T>
que usa el redblack.... usa ese mecanismo p. tambien es bueno que uses ese.
esta ese y tambie nel  std::multiset<T>

La diferencia es que el set : NO ADMITE REPETICIONES, y el multiset: SI ADMITE REPETICIONES


Pero basicamente es lo mismo....



AHORA:

30      50      80
A    <  B   <  C


tons...

30 
    50
        80

EL AVL solo admite una diferencia de altura de hasta 1.
osea..

30
    50  y ya

un lado que tiene nullptr es altura = 0
nodo sin hijos = altura 1

por ello..

30
    50

hijo izq altura= 0
hijo der altura= 1

der - izq = 1 (diferencia de alturas)

si es que la diferencia de alturas es 1, no hay problema.
AQUI ESTA BALANCEADO...


Pero si...

30
    50
        80

80 : 0 - 0 = 0
50 : 1 - 0 = 1
30 : 2 - 0 = 2! AQUI YA TENEMOS UN ERROR!



OJO:

hr = altura der
hl = altura izq

hr - hl (da lo mismo si lo haces al reves)

Como arreglamos eso para que este balanceado..?

la unica forma:

    50
30      80

y si calculas la atura dará 0 0 0 


otro caso:

        80 -> - 2
    50 ->  - 1
30 ->0


y arreglandolo:

    50
30      80

El reocmienda no aprenderse todo lo coso. ya que solo hay una soluccion general


La otra esa asi:

30 = 0 - 2 = -2 
    80 = 0 - - 1 = 1
50  0 - 1 = -1 

y su soluciion

    50
30      80


la misma!

y la ultima....



    80 : - 2
30 : 1 
    50 : 0

y regersamos a la misma solucion:
    50
30      80


SOLO 4 POSIBILIDADES... y las 4. Cada una solo tiene 1 solucion.




------------------------------------


Ahora dice el profe que con letras para entender mejor.

A
    B
        C

        y..

    B
A       C



Segun el la inserccion se da abajo. asi que todos tienen esas idrefencia s de alturas entre 0  y 1

y luego viene un coso algo de xy lalaallal eso

factor de diferencia entre izq y dedr.

para ver cual cosa que meirda comienza hablar de revisar desde la inserccion abajo hasta arriba
para ver que todos sean ceros. o no se que
si en el camino
hubo un -2, ahi tenemos que ir a arreglar


AGARRA EL ARBOL BIN NORMAL
INSERTAS

LUEGO DEBES SUBIR POR EL MISMO LUGAR POR DONDE BAJASTE.

Y SUBEINDO RECALCULAS

PARA VER SI TODO ES CERO o UNO

PERO SI HAY -2 o 2 AHI YA TIENES QUE ARREGLARLO...







PRUEBAS:


*/
#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
struct Nodo {

	T valor;
	int altura;

	Nodo* right;
	Nodo* left;

	

	Nodo(T v) {
		valor = v;
		right = nullptr;
		left = nullptr;
		altura = 1;
	}

};


template <class T>
struct AVL {

	Nodo<T>* root;

	AVL() {
		root = nullptr;
	}

	~AVL() {
		destruir(root);
	}

	void destruir(Nodo<T>* n) {
		if (n == nullptr) {
			return;
		}

		destruir(n->left);
		destruir(n->right);
		delete n;
	}




	int mostrarAltura(Nodo<T>* n); 
	int mostrarFB(Nodo<T>* n);

	void actualizarAltura(Nodo<T>* n);


	Nodo<T>* rotarL(Nodo<T>* n);
	Nodo<T>* rotarR(Nodo<T>* n);

	Nodo<T>* balancear(Nodo<T>* n);

	Nodo<T>* ins(Nodo<T>* n, T v);


	// para evitar re declaracion:
	void ins(T v);

	// ver:

	void inorder(Nodo<T>* n);


};

template <class T>
int AVL<T>::mostrarAltura(Nodo<T>* n) {

	if (n == nullptr) {
		return 0;
	}
	else {
		return n->altura;
	}


}

template <class T>
int AVL<T>::mostrarFB(Nodo<T>* n) {

	int hizq = mostrarAltura(n->left);
	int hder = mostrarAltura(n->right);

	return hder - hizq;

}

template <class T>
void AVL<T>::actualizarAltura(Nodo<T>* n) {

	int hizq = mostrarAltura(n->left);
	int hder = mostrarAltura(n->right);

	n->altura = max(hizq, hder) + 1;

}

template <class T>
Nodo<T>* AVL<T>::rotarL(Nodo<T>* n) {
	// Me convierto en hijo izquierdo de mi hijo derecho

	Nodo<T>* sube = n->right;

	n->right = n->right->left;

	sube->left = n;

	actualizarAltura(n);
	actualizarAltura(sube);


	return sube;
}

/*
	ROTAR L (cuando el peso es a la derecha) 
	  30
  20      50
		40  70
			  80
*/


template <class T>
Nodo<T>* AVL<T>::rotarR(Nodo<T>* n) {
	// Me convierto en hijo derecho de mi hijo izquierdo.

	Nodo<T>* sube = n->left;

	n->left = sube->right;

	sube->right = n;

	actualizarAltura(n);

	actualizarAltura(sube);

	return sube;

}
/*
	ROTAR R (cuando el peso esta a la izquierda)

		  80
	  60      90
	40  50
  30

*/


template <class T>
Nodo<T>* AVL<T>::balancear(Nodo<T>* n) {

	// FULL DERECHA
	if (mostrarFB(n) == 2) {

		if (mostrarFB(n->right) < 0) { // cambio de signo?
			n->right = rotarR(n->right);
		}

		return rotarL(n);
	}
	//FULL IZQUIERDA
	else if (mostrarFB(n) == -2) {

		if (mostrarFB(n->left) > 0) {
			n->left = rotarL(n->left);
		}

		return rotarR(n);
	}
	else {
		return n; // Nunca hubo desbalanceo, tons toma noma esto y no jodas
	}


}

/*

	ESTE HIJO DE PERRA
		50
	20      60
  10  30
	25

*/
template <class T>
Nodo<T>* AVL<T>::ins(Nodo<T>* n, T v) {

	if (n == nullptr) {
		return new Nodo<T>(v);
	}

	if (v > n->valor) {
		n->right = ins(n->right, v); // (guardarlos en varaibles pra que se aplique la recursivdad de ida y vuelta)
	}
	else if (v < n->valor) {
		n->left = ins(n->left,v);
	}

	actualizarAltura(n);

	return balancear(n);

}

template <class T>
void AVL<T>::ins(T v) {
	root = ins(root, v);
}


template <class T>
void AVL<T>::inorder(Nodo<T>* n) {

	if (n == nullptr) {
		return;
	}

	inorder(n->left);
	cout << n->valor <<" ";
	inorder(n->right);
}

#include <string>

template <class T>
void mostrar(const string& titulo, AVL<T>& avl) {

	cout << "=== " << titulo << " ===" << endl;
	cout << "inorder: ";
	avl.inorder(avl.root);
	cout << endl;

	if (avl.root == nullptr) {
		cout << "arbol vacio" << endl << endl;
		return;
	}

	cout << "root: " << avl.root->valor << "  altura: " << avl.root->altura << endl;

	cout << "hijo izq: ";
	if (avl.root->left != nullptr) cout << avl.root->left->valor;
	else cout << "-";

	cout << "  hijo der: ";
	if (avl.root->right != nullptr) cout << avl.root->right->valor;
	else cout << "-";

	cout << endl << endl;
}

int main() {

	{
		AVL<int> avl;
		avl.ins(10);
		avl.ins(20);
		avl.ins(30);
		mostrar("TEST 1: RR (10, 20, 30)", avl);
	}

	{
		AVL<int> avl;
		avl.ins(30);
		avl.ins(20);
		avl.ins(10);
		mostrar("TEST 2: LL (30, 20, 10)", avl);
	}

	{
		AVL<int> avl;
		avl.ins(50);
		avl.ins(20);
		avl.ins(30);
		mostrar("TEST 3: LR (50, 20, 30)", avl);
	}

	{
		AVL<int> avl;
		avl.ins(10);
		avl.ins(30);
		avl.ins(20);
		mostrar("TEST 4: RL (10, 30, 20)", avl);
	}

	{
		AVL<int> avl;
		avl.ins(50);
		avl.ins(20);
		avl.ins(60);
		avl.ins(10);
		avl.ins(30);
		avl.ins(25);
		mostrar("TEST 5: LR con subarboles (50, 20, 60, 10, 30, 25)", avl);
	}

	{
		AVL<int> avl;
		for (int i = 10; i <= 100; i += 10) {
			avl.ins(i);
		}
		mostrar("TEST 6: creciente (10 a 100)", avl);
	}

	return 0;
}