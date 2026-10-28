/*

TAREA 7:

Usa SFML, el recomienda esa.

el menciona algo de nuggets

2019 instalar en el proyecto

es de color azul.

Quiere que probemos...

dibujar

Haran un arbol bonito.

SFML 2.5 es el mas simple y viejo.

Implementa el arbol binario

Y agrega un metodo que permita lo siguiente:


Tienes un ARREGLO:

A = [ 1 , 5 , 8, 3, 20, 11 ,7 , 8]



Tu tienes tus nodos.

1 5 8 3 20 11 7 8


Y a estos dos y les pegas un padre.
osea.

Nodo 1 y 5 su padre es 6: ya que 1 +  = 6

y asi sucesivamente


1   5   8   3   20  11  7   8


luego:
  6       11      31      15
1   5   8   3   20  11  7   8



Luego
	  17              46
  6       11      31      15
1   5   8   3   20  11  7   8


Luego

			  63
	  17              46
  6       11      31      15
1   5   8   3   20  11  7   8



En tu metodo... osea.. ya tienes tu arbol. agregale un nuevo metodo.

Que tenga


ArmarSuma(ARRAY, + ARRAY + CANTELEMENTOS){
}


Quiere que sea simétrico...

La base es 2 ^n


Entonces la cantidad de elementos seria...

ARRAY + ARRAY + (2 ^ cant elementos)


Primero que se arme el arbol.

Luegoooo

recien arbol.draw();

PORFA, que no sea un grafico huachafa
*/

#include <iostream>
#include "DibujarArbol.h"
using namespace std;

template <class T>
struct Nodo {

	T valor;
	Nodo* right;
	Nodo* left;

	Nodo(T v) {
		valor = v;
		right = nullptr;
		left = nullptr;
	}

};


template <class T>
struct BinTreeSearch {

	Nodo<T>* root;

	BinTreeSearch() {
		root = nullptr;
	}

	~BinTreeSearch() {
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

	//bool find(T v, Nodo<T>**& p);
	//bool ins(T v);
	//bool rem(T v);
	bool armarSuma(T* A, int cant);

	//void inorder(Nodo<T>* n);

};

/*

template <class T>
bool BinTreeSearch<T>::find(T v, Nodo<T>**& p) {

	while (*p != nullptr) {

		if (v > (*p)->valor) {
			p = &((*p)->right);
		}
		else if ((v < (*p)->valor)) {
			p = &((*p)->left);
		}
		else {
			break;
		}
	}

	return *p != nullptr && v == (*p)->valor;

}


template <class T>
bool BinTreeSearch<T>::ins(T v) {

	Nodo<T>** p = &root;

	if (find(v, p)) {
		cout << "Ya existe este elemento!" << endl;
		return false;
	}
	else {

		*p = new Nodo<T>(v);

		return true;

	}

}


template <class T>
bool BinTreeSearch<T>::rem(T v) {

	Nodo<T>** p = &root;

	if (find(v, p)) {

		Nodo<T>* tmp = nullptr;

		if ((*p)->left != nullptr && (*p)->right != nullptr) {

			Nodo<T>** r = &((*p)->right);

			while ((*r)->left != nullptr) {
				r = &((*r)->left);
			}

			(*p)->valor = (*r)->valor;

			tmp = *r;
			*r = tmp->right;

			delete tmp;

		}
		else if ((*p)->left != nullptr || (*p)->right != nullptr) {

			tmp = *p;

			if (tmp->left != nullptr) {
				*p = tmp->left;
			}
			else {
				*p = tmp->right;
			}

			delete tmp;

		}
		else {

			tmp = *p;
			*p = nullptr;

			delete tmp;

		}

		return true;

	}
	else {

		return false;

	}

}


template <class T>
void BinTreeSearch<T>::inorder(Nodo<T>* n) {

	if (n == nullptr) {
		return;
	}

	inorder(n->left);
	cout << n->valor << " ";
	inorder(n->right);
}


*/

template <class T>
bool BinTreeSearch<T>::armarSuma(T* A, int cant) {

	int potencia = 1;
	while (potencia < cant) {
		potencia = potencia * 2;
	}

	if (cant <= 0 || potencia != cant) {
		return false;
	}

	Nodo<T>** nodos = new Nodo<T>*[cant];

	for (int i = 0; i < cant; i++) {
		nodos[i] = new Nodo<T>(A[i]);
	}

	while (cant > 1) {

		for (int i = 0; i < cant; i = i + 2) {

			Nodo<T>* padre = new Nodo<T>(nodos[i]->valor + nodos[i + 1]->valor);
			padre->left = nodos[i];
			padre->right = nodos[i + 1];

			nodos[i / 2] = padre;
		}

		cant = cant / 2;
	}

	root = nodos[0];
	delete[] nodos;

	return true;

}



int main() {

	BinTreeSearch<int> arbol;

	int A[] = { 1, 5, 8, 3, 20, 11, 7, 8 };

	arbol.armarSuma(A, 8);

	dibujar(arbol.root);

}