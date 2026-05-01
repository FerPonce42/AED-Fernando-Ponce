/*
 * ╔══════════════════════════════╗
 * ║ Circular Doubly Linked List ║
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


struct ListCircular {

	Nodo* head;
	Nodo* tail;

	int n_elementos;

	ListCircular();

	void push_front(int x);
	void pop_front();

	void push_back(int x);
	void pop_back();

	int& operator[](int x);

	void print();

};

ListCircular::ListCircular() {
	head = nullptr;
	tail = nullptr;
	n_elementos = 0;
}


void ListCircular::push_front(int x) {

	if (n_elementos == 0) {
		Nodo* nodo = new Nodo(x);

		nodo->next = nodo;
		nodo->prev = nodo;

		head = nodo;
		tail = nodo;

		n_elementos++;

	}
	else {
		Nodo* nodo = new Nodo(x);

		nodo->next = head;
		nodo->prev = tail;

		head->prev = nodo;
		
		head = nodo;

		tail->next = head;


		n_elementos++;
	}

}


void ListCircular::pop_front() {

	if (n_elementos == 0) {
		cout << "No puedes borrar mas" << endl;
		return;
	}
	else if (n_elementos == 1) {

		Nodo* tmp = head;

		head = nullptr;
		tail = nullptr;

		delete tmp;

		n_elementos--;
	}
	else {

		Nodo* tmp = head;

		head = head->next;
		head->prev = tail;

		tail->next = head;

		delete tmp;

		n_elementos--;

	}
}



void ListCircular::push_back(int x) {
	if (n_elementos == 0) {
		Nodo* nodo = new Nodo(x);

		nodo->next = nodo;
		nodo->prev = nodo;

		head = nodo;
		tail = nodo;

		n_elementos++;

	}
	else if(n_elementos == 1){
		Nodo* nodo = new Nodo(x);
		
		nodo->prev = head;
		tail = nodo;

		head->next = nodo;
		head->prev = tail;

		nodo->next = head;

		n_elementos++;
	}
	else {
		Nodo* nodo = new Nodo(x);

		tail->next = nodo;

		nodo->prev = tail;

		nodo->next = head;


		tail = nodo;

		head->prev = nodo;

		n_elementos++;
	}

}
void ListCircular::pop_back() {
	if (n_elementos == 0) {
		cout << "No puedes borrar mas" << endl;
		return;
	}
	else if (n_elementos == 1) {

		Nodo* tmp = tail;

		head = nullptr;
		tail = nullptr;

		delete tmp;

		n_elementos--;
	}
	else {

		Nodo* tmp = tail;

		tail = tail->prev;
		tail->next = head;

		head->prev = tail;

		delete tmp;

		n_elementos--;

	}
}


int& ListCircular::operator[](int x) {

	Nodo* p = head;
	int i = 0;

	while (i < x) {
		i++;
		p = p->next;
	}

	return p->valor;

}



void ListCircular::print() {

	if (head == nullptr) {
		cout << "Sin nada que mostrar" << endl;
		return;
	}

	cout << head->valor << " ";

	Nodo* p = head->next;

	while (p != head) {
		cout << p->valor << " ";
		p = p->next;
	}
}



int main() {
	ListCircular lc;

	lc.push_front(3);
	lc.push_front(2);
	lc.push_front(1);
	lc.print(); cout << endl;

	lc.push_back(4);
	lc.push_back(5);
	lc.print(); cout << endl;

	lc.pop_front();
	lc.print(); cout << endl;

	lc.pop_back();
	lc.print(); cout << endl;

	cout << lc[2] << endl;
	lc[2] = 999;
	lc.print(); cout << endl;
}