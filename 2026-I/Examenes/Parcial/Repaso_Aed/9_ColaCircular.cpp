/*
 * ╔══════════════════════════════╗
 * ║       Circular Queue        ║
 * ╚══════════════════════════════╝
 */


 #include <iostream>
using namespace std;

struct Nodo {
	int valor;
	Nodo* next;
	Nodo* prev;

	Nodo(int v){
		valor = v;
		next = nullptr;
		prev = nullptr;
	}

};


struct ColaCircular {

	Nodo* head;
	Nodo* tail;
	int n_elementos;

	ColaCircular();

	void push_back(int x);

	void pop_front();

	void front();

	void print();


};

ColaCircular::ColaCircular() {

	head = nullptr;
	tail = nullptr;
	n_elementos = 0;
}


void ColaCircular::push_back(int x) {

	if (n_elementos == 0) {

		Nodo* nodo = new Nodo(x);

		head = nodo;
		tail = nodo;

		nodo->prev = head;
		nodo->next = tail;
		
		n_elementos++;
	}
	else if (n_elementos == 1) {
		Nodo* nodo = new Nodo(x);

		tail = nodo;

		head->prev = tail;
		head->next = tail;

		tail->prev = head;
		tail->next = head;

		n_elementos++;
	}
	else {
		Nodo* nodo = new Nodo(x);
		
		Nodo* tmp = tail;

		tail = nodo;
		tail->prev = tmp;
		tail->next = head;

		tmp->next = tail;

		head->prev = tail;

		n_elementos++;

	}


}


void ColaCircular::pop_front() {

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
		head->prev = tail;

		tail->next = head;

		delete tmp;

		n_elementos--;

	}

}

void ColaCircular::front() {

	Nodo* tmp = head;

	cout << tmp->valor << endl;
}


void ColaCircular::print() {

	if (n_elementos == 0) {
		cout << "Sin elementos" << endl;
		return;
	}

	Nodo* p = head;


	cout << p->valor << " ";
	while (p != tail) {
		
		p = p->next;
		cout << p->valor << " ";
	}

}



int main() {
	ColaCircular cl;

	cl.push_back(10);
	cl.push_back(20);
	cl.push_back(30);
	cl.push_back(40);
	cl.push_back(50);
	cl.print(); cout << endl;

	cl.front();

	cl.pop_front();
	cl.print(); cout << endl;

	cl.pop_front();
	cl.pop_front();
	cl.print(); cout << endl;

	cl.pop_front();
	cl.pop_front();
	cl.print(); cout << endl;

	cl.pop_front();
}