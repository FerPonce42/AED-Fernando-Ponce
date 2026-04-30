/*
 * ╔══════════════════════════════╗
 * ║    Doubly Linked List       ║
 * ╚══════════════════════════════╝
 */

 #include <iostream>
using namespace std;

struct Nodo {

	int valor;
	Nodo* next;
	Nodo* prev;

	Nodo(int v) {
		valor = v;
		next = nullptr;
		prev = nullptr;
	}

};


struct List {

	Nodo* head;
	Nodo* tail;

	int n_elementos;

	List();

	void push_front(int x);
	void pop_front();

	void push_back(int x);
	void pop_back();

	int& operator[](int x);

	void print();
};


List::List() {
	head = nullptr;
	tail = nullptr;
	n_elementos = 0;
}


void List::push_front(int x) {

	if (n_elementos == 0) {
		Nodo* nodo = new Nodo(x);

		head = nodo;
		tail = nodo;


		nodo->prev = nullptr;
		nodo->next = nullptr;

		n_elementos++;
	}
	else {
		Nodo* nodo = new Nodo(x);

		Nodo* tmp = head;

		nodo->next = tmp;
		nodo->prev = nullptr;

		head->prev = nodo;

		head = nodo;

		n_elementos++;
	}


}

void List::pop_front() {

	if (n_elementos == 0) {
		cout << "No hay elementos..." << endl;
	}
	else if (n_elementos == 1) {
		delete head;
		head = nullptr;
		tail = nullptr;

		n_elementos--;
	}
	else {

		Nodo* tmp = head;

		head = head->next;

		head->prev = nullptr;

		delete tmp;

		n_elementos--;

	}

}



void List::push_back(int x) {

	if (n_elementos == 0) {
		Nodo* nodo = new Nodo(x);

		head = nodo;
		tail = nodo;


		nodo->prev = nullptr;
		nodo->next = nullptr;

		n_elementos++;
	}
	else {
		Nodo* nodo = new Nodo(x);

		Nodo* tmp = tail;

		nodo->next = nullptr;
		nodo->prev = tmp;

		tail->next = nodo;

		tail = nodo;

		n_elementos++;
	}


}


void List::pop_back(){


	if (n_elementos == 0) {
		cout << "No hay elementos..." << endl;
	}
	else if (n_elementos == 1) {
		delete tail;
		head = nullptr;
		tail = nullptr;

		n_elementos--;
	}
	else {

		Nodo* tmp = tail;

		tail = tail->prev;

		tail->next = nullptr;

		delete tmp;

		n_elementos--;

	}

}


int& List::operator[](int x) {
	Nodo* tmp = head;
	int i = 0;
	while (i < x && tmp != nullptr) {
		tmp = tmp->next;
		i++;
	}
	
	if (tmp != nullptr) {
		return tmp->valor;
	}
}


void List::print() {
	Nodo* p = head; 

	while (p != nullptr) {

		cout << p->valor << " ";
		p = p->next;
	}

	cout << endl;
}



int main() {

	List lista;


	lista.push_back(1);
	lista.push_back(3);
	lista.push_back(5);
	lista.push_back(7);
	lista.push_back(9);

	lista.push_front(2);
	lista.push_front(4);
	lista.push_front(6);
	lista.push_front(8);
	lista.push_front(10);

	lista.print();

	lista.pop_front();
	lista.pop_back();
	lista.print();

	lista.pop_front();
	lista.pop_back();
	lista.print();

	lista[2] = 1000;
	lista.print();


}