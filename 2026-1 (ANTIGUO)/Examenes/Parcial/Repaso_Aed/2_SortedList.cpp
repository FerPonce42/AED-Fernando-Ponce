/*
 * ╔══════════════════════════════╗
 * ║    Sorted Linked List       ║
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

struct SortedList {

	Nodo* head;
	SortedList();

	bool find(int x, Nodo**& p);

	bool ins(int x);

	bool rem(int x);

	void print();
};


SortedList::SortedList() {
	head = nullptr;
}


bool SortedList::find(int x, Nodo**& p) {

	p = &head;

	while ((*p) != nullptr && x > (*p)->valor) {

		p = &((*p)->next);
	}

	return (*p) != nullptr && x == (*p)->valor;
}

bool SortedList::ins(int x) {
	Nodo** p;
	if (find(x, p)) {
		return false;
	}
	else {
		Nodo* nodo = new Nodo(x);

		nodo->next = *p;
		*p = nodo;

	}

	return true;
}



bool SortedList::rem(int x) {

	Nodo** p;

	if (!find(x, p)) {
		return false;
	}
	else {

		Nodo* tmp = *p;

		*p = (*p)->next;

		delete tmp;

	}


	return true;

}



void SortedList::print() {
	Nodo* p;
	p = head;

	while (p != nullptr) {
		cout << p->valor << " ";
		p = p->next;
	
	}
	cout << endl;
}




int main() {

	SortedList lista;

	lista.ins(6);
	lista.ins(2);
	lista.ins(19);
	lista.ins(28);
	lista.ins(14);
	lista.ins(22);
	lista.ins(16);

	lista.print();

	lista.rem(19);
	lista.print();
}