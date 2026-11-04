/*
TAREA 8:

Caramelos...

El explicara el algoritmo:

Esto es un arbol binario, no de busqueda.


ARbol de caramelos
        5
    0       0
          0   0



Donde...
la cantidad de nodos... es igual a N

y la cantidad de Caramelos en los nodos es igual a N



5 NODOS, suma todos los numeros... = 5..
Esa es una caracteristica.


Ahora este algo feo:


        2
    0       0
          3   0

5 NODOS...

El numero qeu esta en el nodo, indica cuantos caramelos tiene esa persona.


EL OBJETIVO
es que cada uno tenga UN caramelo


OBJETIVO:
Cada nodo tenga 1 caramelo.

Si yo tengo 10 nodos, el nodo no tiene que ser superior a diez.

Si tu recorres todos los nodos tiene que tener la suma? no seu qe dijo aqui..


SOLO SE PUEDEN PASAR CARAMELOS
de padre a hijos Y de hijo a padre.

Y solo se puede pasar 1 caramelo a la vez.


Tienes que hacer una cantidad de elementos al arbol para qeu distribuya bien.


TIENES QUE PRESETNAR EL ARBOL ANTES Y DESPUES.

Y...

DECIR CUANTOS RECORRIDOS FUERON NECESARIOS.

no necesariemnte la menor de recorridos. solo los que hiciste.

por ejemplo... hacemos un recorriodo inorden 


raiz.. tengo 5
el hijo no tiene caramelo.
en este ocasion le voy a dar uno de mis paramelos...

        5
    0       0
          0   0
          
          ahora

        4
    1       0
          0   0


          al otro hijo ya no le doy. ahi acaba el recorrido...

          etnonces otro:


        3
    1       1
          0   0



          ahora..


        3
    1       0
          1   0
    ahi acaba el recorrido...







    AHORA EN ESTE CASO:



        2
    0       0
          3   0



        1
    1       0
          3   0



        1
    1       0
          3   0



          Si un hijo ya le dio al abuela... ya no le puede dar un hijo

          solo le puedas dar un caramelo a alguien a la vez...

          Hay que tener cuidado en que derepente te encuentras... no se.
          en en en .

          0
            1
                0

                tons..

                0
                    0
                        1
                        tons...
                            0 
                                1
                                    0
                                    y rebota rebota.  TEN CIDADO PARA UE NO DES VUELTAS...

    Ahora tu chamba es penser en el algoritmo..


    El objetivo al final deberia salri asi.


        1
    1       1
          1  1

          y si sumas.. 5 p fin
          4



          el truco es que en cada vuelta un padre le puede entrar o un hijo a un padre. la idea es que no estes dando dos dos. nada matematicamente, eso es tramap.
          por eso cuando haces el primer coso dibuja y dibuja y ahi te das cuenta donde esta el aerror...

          vuelta 1, ver com ose dibuja
          vuelta 2 tal
          vuvlta 3
          tal
          tal tal
          cosa qeu dibujas y lueg ocomparas con lo que te genra.

          CON ESE AROBL TIENE QUE FUNCIONAR SEGUN EL N NOS METERA WEBADAS.
*/


#include <iostream>
#include "DibujarArbol.h"
#include <queue>
using namespace std;

class CNode {

public:

	int valor;
	CNode* left;
	CNode* right;

	CNode(int v) {
		valor = v;
		left = nullptr;
		right = nullptr;
	}

};



class BinTree {

public:
	CNode* root;

	BinTree() {
		root = nullptr;
	}

	void ins(int v);

	bool EsCero(CNode* n);

	void inorder(CNode* n);

};


void BinTree::ins(int v) {

	if (root == nullptr) {
		root = new CNode(v);
		return;
	}

	CNode* p = root;

	queue<CNode*> cola;

	cola.push(p);

	while (!cola.empty()) {

		CNode* tmp = cola.front();

		cola.pop();

		if (tmp->right == nullptr) {
			tmp->right = new CNode(v);
			return;
		}
		else {
			cola.push(tmp->right);
		}


		if (tmp->left == nullptr) {
			tmp->left = new CNode(v);
			return;
		}
		else {
			cola.push(tmp->left);
		}

	}

}


bool BinTree::EsCero(CNode* n) {

	if (n == nullptr) {
		return false;
	}

	queue<CNode*> cola;
	cola.push(n);

	while (!cola.empty()) {

		CNode* tmp = cola.front();
		cola.pop();

		if (tmp->valor == 0) {
			return true;
		}

		if (tmp->left != nullptr) {
			cola.push(tmp->left);
		}
		if (tmp->right != nullptr) {
			cola.push(tmp->right);
		}
	}

	return false;
}

void BinTree::inorder(CNode* n) {

	if (n == nullptr) {
		return;
	}

	inorder(n->left);

	// padre a hijo
	if (n->valor > 1 && EsCero(n->left)) {
		n->valor--;
		n->left->valor++;
	}
	else if (n->valor > 1 && EsCero(n->right)) {
		n->valor--;
		n->right->valor++;
	}
	// hijo a padre
	else if (n->left != nullptr && n->left->valor > 1 && !EsCero(n->left)) {
		n->left->valor--;
		n->valor++;
	}
	else if (n->right != nullptr && n->right->valor > 1 && !EsCero(n->right)) {
		n->right->valor--;
		n->valor++;
	}

	inorder(n->right);

}

int main() {

	BinTree arbol;

	arbol.ins(0);
	arbol.ins(0);
	arbol.ins(0);
	arbol.ins(0);
	arbol.ins(0);
	arbol.ins(0);
	arbol.ins(7);
	cout << "ANTES" << endl;
	dibujar(arbol.root);

	int pasadas = 0;
	while (arbol.EsCero(arbol.root)) {
		arbol.inorder(arbol.root);
		pasadas++;
	}

	cout << "DESPUES" << endl;
	dibujar(arbol.root);

	cout << "Pasadas: " << pasadas << endl;

}