/*
 * ╔══════════════════════════════╗
 * ║           Stack             ║
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


struct Pila {

	Nodo* top;
	Nodo* head;

	int n_elementos;

	Pila();

	void push_back(int x);

	void pop_back();

	void ver_top();

	void print();

};

Pila::Pila() {
	top = nullptr;
	head = nullptr;
	n_elementos = 0;
}

void Pila::push_back(int x) {

	if (n_elementos == 0) {
		Nodo* nodo = new Nodo(x);
		
		head = nodo;
		top = nodo;

		head->prev = nullptr;
		head->next = nullptr;

		n_elementos++;
	}
	else if (n_elementos == 1) {

		Nodo* nodo = new Nodo(x);

		top = nodo;
		top->prev = head;
		top->next = nullptr;
		
		head->next = top;

		n_elementos++;
	}
	else {
		Nodo* nodo = new Nodo(x);
		Nodo* tmp = top;
		
		top = nodo;

		tmp->next = top;

		top->prev = tmp;
		top->next = nullptr;

		n_elementos++;
	}
}


void Pila::pop_back() {
	if (n_elementos == 0) {
		cout << "Hay cero elementos en la pila" << endl;
		return;
	}
	else if (n_elementos == 1) {
		Nodo* tmp = top;
		
		top = nullptr;
		head = nullptr;

		delete tmp;

		n_elementos--;
	}
	else {

		Nodo* tmp = top;

		top = top->prev;

		top->next = nullptr;

		delete tmp;

		n_elementos--;
	}
}


void Pila::ver_top() {

	if (n_elementos == 0) {
		cout << "Nada que mostrar. NO HAY TOP" << endl;
		return;
	}

	cout << "Top: " << top->valor<<endl;

}



void Pila::print() {

	if (n_elementos == 0) {
		cout << "Nada que mostrar" << endl;
		return;
	}


	int i = 0;
	Nodo* tmp = head;

	while (i < n_elementos) {

		cout << tmp->valor << " ";

		tmp = tmp->next;

		i++;
	}



}


int main() {

	Pila p;
	p.push_back(4);
	p.push_back(5);
	p.push_back(7);
	p.push_back(8);
	p.push_back(9);


	p.print(); cout << endl;



	p.ver_top();
	p.pop_back();
	p.print(); cout << endl;

	p.ver_top();
	p.pop_back();
	p.print(); cout << endl;


	p.ver_top();
	p.pop_back();
	p.print(); cout << endl;


	p.ver_top();
	p.pop_back();
	p.print(); cout << endl;


	p.ver_top();
	p.pop_back();
	p.print(); cout << endl;

	p.ver_top();
	p.pop_back();
	p.print(); cout << endl;

}