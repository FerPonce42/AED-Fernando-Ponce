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

	bool find(T v, Nodo<T>**& p);
	bool ins(T v);
	bool rem(T v);

	void inorder(Nodo<T>* n);
	void destruir(Nodo<T>* n);

};

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


template <class T>
void BinTreeSearch<T>::destruir(Nodo<T>* n) {

	if (n == nullptr) {
		return;
	}

	destruir(n->left);
	destruir(n->right);
	delete n;
}

int main() {

	BinTreeSearch<int> bts;

	bts.ins(20);
	bts.ins(10);
	bts.ins(30);
	bts.ins(5);
	bts.ins(25);
	bts.ins(27);
	bts.ins(50);
	bts.ins(40);

	bts.inorder(bts.root); cout << endl;

	bts.rem(5);
	bts.inorder(bts.root); cout << endl;

	bts.rem(50);
	bts.inorder(bts.root); cout << endl;

	bts.rem(20);
	bts.inorder(bts.root); cout << endl;

	cout << bts.rem(99) << endl;

	bts.rem(25);
	bts.inorder(bts.root); cout << endl;

}