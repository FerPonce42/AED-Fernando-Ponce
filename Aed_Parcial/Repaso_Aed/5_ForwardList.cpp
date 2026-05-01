/*
 * ╔══════════════════════════════╗
 * ║    Singly Linked List       ║
 * ╚══════════════════════════════╝
 */

 #include <iostream>
using namespace std;

struct Nodo {
	int valor; 
	Nodo* next;

	Nodo(int v){
		valor = v;
		next = nullptr;
	}
};




struct ForwardList {

	Nodo* head;

	int n_elementos;

	ForwardList();

	void push_front(int x);
	void pop_front();

	void push_back(int x);
	void pop_back();

	int& operator[](int x);

	void print();


};

ForwardList::ForwardList() {
	head = nullptr;
	n_elementos = 0;
}



void ForwardList::push_front(int x) {

	if (n_elementos == 0) {
		Nodo* nodo = new Nodo(x);

		head = nodo;

		head->next = nullptr;

		n_elementos++;
	}
	else {
		Nodo* nodo = new Nodo(x);

		nodo->next = head;

		head = nodo;

		n_elementos++;

	}

}


void ForwardList::pop_front() {

	if (n_elementos == 0) {
		cout << "Sin elementos que retirar..." << endl;
		return;
	}
	else if (n_elementos == 1) {
		Nodo* tmp = head;

		head = nullptr;

		delete tmp;

		n_elementos--;
	}
	else {

		Nodo* tmp = head;

		head = head->next;

		delete tmp;

		n_elementos--;
	}


}


void ForwardList::push_back(int x) {

	if(n_elementos == 0) {
		Nodo* nodo = new Nodo(x);

		head = nodo;

		head->next = nullptr;

		n_elementos++;
	}
	else {
		Nodo* tmp = head;
		int i = 0;
		for (tmp; i < n_elementos - 1; tmp = tmp->next, i++);

		Nodo* nodo = new Nodo(x);

		tmp->next = nodo;

		nodo->next = nullptr;


		n_elementos++;
	}

}



void ForwardList::pop_back() {
	if (n_elementos == 0) {
		cout << "Sin elementos que retirar..." << endl;
		return;
	}
	else if (n_elementos == 1) {
		Nodo* tmp = head;

		head = nullptr;

		delete tmp;

		n_elementos--;
	}
	else {

		Nodo* tmp = head;
		int i = 0;
		for (tmp; i < n_elementos - 2; tmp = tmp->next, i++);

		Nodo* quitar = tmp->next;

		tmp->next = nullptr;

		delete quitar;

		n_elementos--;
	}
}



int& ForwardList::operator[](int x) {
	Nodo* p = head;
	int i = 0;
	while (i < x) {
		p = p->next;
		i++;
	}

	return p->valor;
}


void ForwardList::print() {

	Nodo* p = head;

	while (p != nullptr) {
		cout << p->valor << " ";
		p = p->next;
	}
	cout << endl;
}




int main() {

	ForwardList fl;

	fl.push_front(4);
	fl.push_front(10);
	fl.push_front(2);

	fl.print();

	fl.push_back(50);
	fl.push_back(40);
	fl.push_back(90);
	fl.print();

	fl[4] = 1000;

	fl.print();
}