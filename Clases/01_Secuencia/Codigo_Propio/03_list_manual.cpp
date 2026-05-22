/*
 * Estructura de Secuencia: LIST
 * ----------------------------------------
 * Funciones implementadas:
 *   PushFront  -> O(k)
 *   PopFront   -> O(k)
 *   PushBack   -> O(k)
 *   PopBack    -> O(k)
 *
 * Funciones no implementadas:
 *   operator[] -> O(n)
 *
 * Nota: lista doblemente enlazada, sin tamaño fijo.
 */

#include <iostream>
using namespace std;

struct Nodo {
	int valor;
	Nodo* anterior;
	Nodo* siguiente;
};

struct List {
	Nodo* head;
	Nodo* tail;

	List();

	bool EstaVacio();

	bool PushFront(int x);
	bool PopFront();

	bool PushBack(int y);
	bool PopBack();
};

List::List() {
	head = nullptr;
	tail = nullptr;
}

bool List::EstaVacio() {
	if ((head == nullptr) && (tail == nullptr)) {
		return true;
	}
	else {
		return false;
	}
}

bool List::PushFront(int x) {

	if (EstaVacio()) {
		Nodo* nuevo_front = new Nodo;
		nuevo_front->valor = x;
		nuevo_front->siguiente = nullptr;
		nuevo_front->anterior = nullptr;
		head = nuevo_front;
		tail = nuevo_front;

	}
	else {
		Nodo* nuevo_front = new Nodo;
		nuevo_front->valor = x;
		nuevo_front->siguiente = head;
		head->anterior = nuevo_front;
		head = nuevo_front;
		nuevo_front->anterior = nullptr;

	}

	return true;
}

bool List::PopFront() {
	if (EstaVacio()) {
		return false;
	}
	else {
		Nodo* tmp;
		tmp = head->siguiente;
		if (tmp != nullptr) {
			delete head;
			head = tmp;
			head->anterior = nullptr;
		}
		else if (tmp == nullptr) {
			delete head;
			head = nullptr;
			tail = nullptr;
		}
	}
	return true;
}


bool List::PushBack(int y) {
	if (EstaVacio()) {
		Nodo* nuevo_back = new Nodo;
		nuevo_back->valor = y;
		nuevo_back->siguiente = nullptr;
		nuevo_back->anterior = nullptr;
		head = nuevo_back;
		tail = nuevo_back;

	}else{
		Nodo* nuevo_back = new Nodo;
		nuevo_back->valor = y;
		nuevo_back->anterior = tail;
		tail->siguiente = nuevo_back;
		tail = nuevo_back;
		nuevo_back->siguiente = nullptr;
	}
	return true;
}

bool List::PopBack() {
	if (EstaVacio()) {
		return false;
	}
	else {
		Nodo* tmp;
		tmp = tail->anterior;
		if (tmp != nullptr) {
			delete tail;
			tail = tmp;
			tail->siguiente = nullptr;
		}
		else if (tmp == nullptr) {
			delete tail;
			head = nullptr;
			tail = nullptr;
		}
	}
	return true;
}

int main() {
	List lista;

	lista.PushFront(2);
	lista.PushFront(4);
	lista.PushFront(6);

	lista.PushBack(1);
	lista.PushBack(3);
	lista.PushBack(5);

	lista.PopFront();

	lista.PopBack();

	cout << lista.head->valor<<endl;
	cout << lista.tail->valor << endl;
}