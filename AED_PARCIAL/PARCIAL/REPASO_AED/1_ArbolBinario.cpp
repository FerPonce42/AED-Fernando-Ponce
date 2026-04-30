/*
 * ╔══════════════════════════════╗
 * ║     Binary Search Tree      ║
 * ╚══════════════════════════════╝
 */

#include <iostream>
using namespace std;


struct Nodo {
	int valor;
	Nodo* izq;
	Nodo* der;

	Nodo(int v) {
		valor = v;
		izq = nullptr;
		der = nullptr;
	}
};


struct Arbol {

	Nodo* raiz;

	Arbol() {
		raiz = nullptr;
	}

	bool find(int x, Nodo**& p);

	bool ins(int x);

	bool rem(int x);



	void printInorden(Nodo* p);
	void print();

};


bool Arbol::find(int x, Nodo**& p) {

	p = &raiz;

	while ((*p != nullptr) && x != (*p)->valor) {

		if (x < (*p)->valor) {
			p = &((*p)->izq);
		}
		else if (x > (*p)->valor) {
			p = &((*p)->der);
		}

	}

	return (*p != nullptr) && (x == (*p)->valor);

}



bool Arbol::ins(int x) {

	Nodo** p;

	if (find(x, p)) {
		return false;
	}
	else {

		Nodo* nuevo = new Nodo(x);

		*p = nuevo;
	}

	return true;
}





bool Arbol::rem(int x) {

	Nodo** p;

	if (!find(x, p)) {
		return false;
	}
	else if ((*p)->izq != nullptr && (*p)->der != nullptr) { //2 hijos

		Nodo** q = &(*p)->izq;

		while ((*q)->der != nullptr) {
			q = &(*q)->der;
		}

		(*p)->valor = (*q)->valor;


		Nodo* tmp = *q;

		*q = (*q)->izq;

		delete tmp;

	}
	else if ((*p)->izq != nullptr) {
		Nodo* tmp = *p;
		*p = (*p)->izq;

		delete tmp;
	}
	else if ((*p)->der != nullptr) {
		Nodo* tmp = *p;
		*p = (*p)->der;

		delete tmp;
	}
	else {

		delete* p;
		*p = nullptr;
		
	}


	return true;
}






void Arbol::printInorden(Nodo* p) {

	if (p == nullptr) {
		return;
	}

	printInorden(p->izq);

	cout << p->valor << " ";

	printInorden(p->der);

}
void Arbol::print() {

	printInorden(raiz);
}


int main() {

	Arbol arbol;
	arbol.ins(10);
	arbol.ins(5);
	arbol.ins(15);
	arbol.ins(2);
	arbol.ins(8);
	arbol.ins(13);
	arbol.ins(26);
	arbol.ins(1);
	arbol.ins(3);
	arbol.ins(11);
	arbol.ins(14);
	arbol.ins(40);

	arbol.print();
	cout << endl;
	arbol.rem(15);
	arbol.print();
	cout << endl;
	arbol.rem(14);
	arbol.print();
	cout << endl;
}