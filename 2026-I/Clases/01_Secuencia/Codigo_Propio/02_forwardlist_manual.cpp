/*
 * Estructura de Secuencia: FORWARD LIST
 * ----------------------------------------
 * Funciones implementadas:
 *   PushFront  -> O(k)
 *   PopFront   -> O(k)
 *
 * Funciones no implementadas:
 *   PushBack   -> O(n)
 *   PopBack    -> O(n)
 *   operator[] -> O(n)
 *
 * Nota: lista enlazada simple, sin tamaño fijo.
 */

#include <iostream>
using namespace std;

struct Nodo {
	int valor;
	Nodo* siguiente;
};


struct ForwardList {

	Nodo* head;

	ForwardList();

	bool PushFront(int dato);

	bool EstaVacia();
	bool PopFront();
};

ForwardList::ForwardList() {
	head = nullptr;
}

bool ForwardList::PushFront(int dato) {

	Nodo* nuevo_nodo = new Nodo;

	nuevo_nodo->valor = dato;

	nuevo_nodo->siguiente = head;

	head = nuevo_nodo;

	return true;
}


bool ForwardList::EstaVacia() {
	if (head == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

bool ForwardList::PopFront() {
	
	if (EstaVacia()) {
		return false;
	}
	else {
		Nodo* tmp;
		tmp = head->siguiente;

		delete head;

		head = tmp;
	}


	return true;
}


int main() {
	ForwardList listacontinua;
	listacontinua.PushFront(4);
	listacontinua.PushFront(1);
	listacontinua.PushFront(9);
	cout << listacontinua.head->valor <<endl;
	listacontinua.PopFront();
	cout << listacontinua.head->valor << endl;

}