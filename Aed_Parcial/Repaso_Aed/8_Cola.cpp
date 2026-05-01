/*
 * ╔══════════════════════════════╗
 * ║           Queue             ║
 * ╚══════════════════════════════╝
 */

 #include <iostream>
using namespace std;

struct Nodo {

	int valor;
	Nodo* next;

	Nodo(int v) {
		valor = v;
		next = nullptr;
	}
};


struct Cola {

	Nodo* head;
	Nodo* tail;

	int n_elementos;

	Cola();

	void push_back(int x);

	void pop_front();

	void front();

	void print();


};


Cola::Cola() {
	head = nullptr;
	tail = nullptr;
	n_elementos = 0;
}

void Cola::push_back(int x) {
	
	if (n_elementos == 0) {

		Nodo* nodo = new Nodo(x);

		head = nodo;
		tail = nodo;

		tail->next = nullptr;

		n_elementos++;
	}
	else if (n_elementos == 1) {
		Nodo* nodo = new Nodo(x);

		tail = nodo;
		head->next = tail;
		tail->next = nullptr;
		n_elementos++;
	}
	else {
		
		Nodo* nodo = new Nodo(x);

		tail->next = nodo;
		tail = nodo;
		tail->next = nullptr;
		n_elementos++;
	}
}

void Cola::pop_front() {

	if (n_elementos == 0) {

		cout << "No hay elementos que retirar" << endl;
		return;
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

		delete tmp;
		n_elementos--;
	}

}

void Cola::front() {

	Nodo* front = head;

	cout << front->valor << endl;
}

void Cola::print() {

	Nodo* p = head;

	while (p != nullptr) {

		cout << p->valor << " ";
		p = p->next;
		
	}

}


int main() {
	Cola c;

	c.push_back(1);
	c.push_back(2);
	c.push_back(3);
	c.print(); cout << endl;

	c.front();

	c.pop_front();
	c.print(); cout << endl;

	c.pop_front();
	c.print(); cout << endl;

	c.pop_front();
	c.print(); cout << endl;

	c.pop_front();
}