/*


        20
    10      0
  0   0   0   0





  20
  10 50
  5 15 30 60
  3 7  11 17  40  70



  TAREA mensa

  implementa el arbol balanceado
  y lo dibujas bonito

  depsue de que lo dibjujas

  el escogera un numero...

  digamos el 11 

  entonces vamos a comvbinar

  AVL + prints?

  11... y en un color diferentes pintas los primos del 11...

  osea el  3 el 7 el 40 y el 70... primos no de matetmaica
  si no primos de.. arbol..

  es primo los hijos de su padre.




bf = 0
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include "DibujarArbolPintado.h"

using namespace std;

struct AVL {

	Nodo* root;

	AVL() {
		root = nullptr;
	}

	~AVL() {
		destruir(root);
	}

	void destruir(Nodo* n) {
		if (n == nullptr) {
			return;
		}

		destruir(n->left);
		destruir(n->right);
		delete n;
	}

	int mostrarAltura(Nodo* n);
	int mostrarFB(Nodo* n);

	void actualizarAltura(Nodo* n);

	Nodo* rotarL(Nodo* n);
	Nodo* rotarR(Nodo* n);

	Nodo* balancear(Nodo* n);

	Nodo* ins(Nodo* n, int v);

	// para evitar re declaracion:
	void ins(int v);

	// PRIMOS:
	bool find(Nodo**& p, int v, int& nivel, Nodo*& padre);
	void primos(Nodo* n, Nodo* padre, int nivel, int nivelElegido, Nodo* padreElegido, vector<Nodo*>& lista);

};

int AVL::mostrarAltura(Nodo* n) {

	if (n == nullptr) {
		return 0;
	}
	else {
		return n->altura;
	}

}

int AVL::mostrarFB(Nodo* n) {

	int hizq = mostrarAltura(n->left);
	int hder = mostrarAltura(n->right);

	return hder - hizq;

}

void AVL::actualizarAltura(Nodo* n) {

	int hizq = mostrarAltura(n->left);
	int hder = mostrarAltura(n->right);

	n->altura = max(hizq, hder) + 1;

}

Nodo* AVL::rotarL(Nodo* n) {
	// Me convierto en hijo izquierdo de mi hijo derecho

	Nodo* sube = n->right;

	n->right = n->right->left;

	sube->left = n;

	actualizarAltura(n);
	actualizarAltura(sube);

	return sube;
}

Nodo* AVL::rotarR(Nodo* n) {
	// Me convierto en hijo derecho de mi hijo izquierdo.

	Nodo* sube = n->left;

	n->left = sube->right;

	sube->right = n;

	actualizarAltura(n);
	actualizarAltura(sube);

	return sube;

}

Nodo* AVL::balancear(Nodo* n) {

	// FULL DERECHA
	if (mostrarFB(n) == 2) {

		if (mostrarFB(n->right) < 0) {
			n->right = rotarR(n->right);
		}

		return rotarL(n);
	}
	// FULL IZQUIERDA
	else if (mostrarFB(n) == -2) {

		if (mostrarFB(n->left) > 0) {
			n->left = rotarL(n->left);
		}

		return rotarR(n);
	}
	else {
		return n;
	}

}

Nodo* AVL::ins(Nodo* n, int v) {

	if (n == nullptr) {
		return new Nodo(v);
	}

	if (v > n->valor) {
		n->right = ins(n->right, v);
	}
	else if (v < n->valor) {
		n->left = ins(n->left, v);
	}

	actualizarAltura(n);

	return balancear(n);

}

void AVL::ins(int v) {
	root = ins(root, v);
}

// find para buscar al nodo marcao, su padre y su nivel.
bool AVL::find(Nodo**& p, int v, int& nivel, Nodo*& padre) {

	nivel = 0;
	padre = nullptr;

	while (*p) {

		if ((*p)->valor == v) {
			return true;
		}

		padre = *p;

		if (v > (*p)->valor) {
			p = &((*p)->right);
		}
		else {
			p = &((*p)->left);
		}

		nivel++;
	}

	return false;
}


void AVL::primos(Nodo* n, Nodo* padre, int nivel, int nivelElegido, Nodo* padreElegido, vector<Nodo*>& lista) {

	if (n == nullptr) {
		return;
	}

	if (nivel == nivelElegido) {

		if (padre != padreElegido) {
			lista.push_back(n);
		}

	}
	else {

		primos(n->left, n, nivel + 1, nivelElegido, padreElegido, lista);
		primos(n->right, n, nivel + 1, nivelElegido, padreElegido, lista);

	}

}

AVL avl;

// para dibujarlo 
void calcular(Nodo* elegido, vector<Nodo*>& lista) {

	lista.clear();

	int nivel;
	Nodo* padre;
	Nodo** p = &avl.root;

	if (avl.find(p, elegido->valor, nivel, padre)) {
		avl.primos(avl.root, nullptr, 0, nivel, padre, lista);
	}

}

int main() {

	int datos[] = { 1,3,5,7,11,13,15,2,4,6,8,9,10,12,14 };

	int n = sizeof(datos) / sizeof(datos[0]); 

	for (int i = 0; i < n; i++) {
		avl.ins(datos[i]);
	}

	dibujar(avl.root, calcular);

	return 0;
}