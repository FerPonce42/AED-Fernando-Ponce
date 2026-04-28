/*
// Version 1

#include <iostream>
using namespace std;

struct CNode {

	int value;

	CNode* lados[2];

	CNode(int v) {
		value = v;
		lados[0] = nullptr;
		lados[1] = nullptr;
	}
};



struct CTree {

	CNode* root;

	CTree();
	~CTree();
	void Destruir(CNode* matanza);
	bool find(int x, CNode**& p);

	bool ins(int x);

	bool rem(int x);

	bool alternar;

	CNode** buscarReemplazo(CNode** q);

	void printRecursivo(CNode* p);
	void print();
};


CTree::CTree() {
	root = nullptr;
	alternar = false;
}


void CTree::Destruir(CNode* matanza) {

	if (matanza == nullptr) {
		return;
	}
	else {
		Destruir(matanza->lados[0]);
		Destruir(matanza->lados[1]);

		delete matanza;
	}
}

CTree::~CTree() {

	Destruir(root);
}



bool CTree::find(int x, CNode**& p) {

	for (p = &root; *p != nullptr && (*p)->value != x; p = &((*p)->lados[x > (*p)->value]));

	return *p && (*p)->value == x;

}


bool CTree::ins(int x) {
	CNode** p;
	if (find(x, p)) {
		return false;
	}
	else {

		CNode* nodo = new CNode(x);

		*p = nodo;
	}

	return true;
}

bool CTree::rem(int x) {
	CNode** p;

	if (find(x, p) == false) {
		return false;
	}
	else if (((*p)->lados[1] != nullptr && (*p)->lados[0] != nullptr)) { // 2 hijos

		CNode** q = buscarReemplazo(p);

		(*p)->value = (*q)->value;

		CNode* tmp = *q;
		*q = (*q)->lados[1];
		delete tmp;


	}
	else if ((*p)->lados[1] != nullptr) { // 1 hijo derecho
		CNode* tmp = *p;

		*p = ((*p)->lados[1]);

		delete tmp;
	}
	else if ((*p)->lados[0] != nullptr) { // 1 hijo izquierdo
		CNode* tmp = *p;

		*p = ((*p)->lados[0]);

		delete tmp;
	}
	else { // 0 hijos

		delete* p;
		*p = nullptr;
	}

	return true;

}



CNode** CTree::buscarReemplazo(CNode** p) {

	CNode** q;

	for (q = &((*p)->lados[!alternar]); (*q)->lados[alternar] != nullptr; q = &((*q)->lados[alternar]));

	alternar = !alternar;

	return q;

}


void CTree::printRecursivo(CNode* p) {

	if (p == nullptr) {
		return;
	}
	else {

		printRecursivo(p->lados[0]);

		cout << p->value << " ";

		printRecursivo(p->lados[1]);
	}

}

void CTree::print() {

	printRecursivo(root);

}








int main() {
	CTree tree;
	tree.ins(50);
	tree.ins(20);
	tree.ins(70);
	tree.ins(10);
	tree.ins(30);
	tree.ins(60);
	tree.ins(80);
	tree.ins(25);
	tree.ins(35);

	cout << "Original: ";
	tree.print();
	cout << endl;

	tree.rem(20); // 2 hijos
	cout << "Rem 20: ";
	tree.print();
	cout << endl;

	tree.rem(80); // 0 hijos
	cout << "Rem 80: ";
	tree.print();
	cout << endl;

	tree.rem(70); // 1 hijo
	cout << "Rem 70: ";
	tree.print();
	cout << endl;
}

*/


//*************************************************************************************************** */

/*
// Version 0

#include <iostream>
using namespace std;

struct CNode {

	int value;
	CNode* left;
	CNode* right;

	CNode(int v) {
		value = v;
		left = nullptr;
		right = nullptr;
	}
};



struct CTree {

	CNode* root;

	CTree();
	~CTree();
	void Destruir(CNode* matanza);
	bool find(int x, CNode**& p);

	bool ins(int x);

	bool rem(int x);

	bool alternar;

	CNode** buscarReemplazo(CNode** q);

	void printRecursivo(CNode* p);
	void print();
};


CTree::CTree() {
	root = nullptr;
	alternar = false;
}


void CTree::Destruir(CNode* matanza) {

	if (matanza == nullptr) {
		return;
	}
	else {
		Destruir(matanza->left);
		Destruir(matanza->right);

		delete matanza;
	}
}

CTree::~CTree() {

	Destruir(root);
}



bool CTree::find(int x, CNode**& p) {

	p = &root;

	while (*p != nullptr && ((*p)->value != x)) {
		if (x > (*p)->value) {
			p = &((*p)->right);
		}
		else {
			p = &((*p)->left);
		}
	}

	return *p != nullptr;

}


bool CTree::ins(int x) {
	CNode** p;
	if (find(x, p)) {
		return false;
	}
	else {

		CNode* nodo = new CNode(x);

		*p = nodo;
	}

	return true;
}

bool CTree::rem(int x) {
	CNode** p;

	if (find(x, p) == false) {
		return false;
	}
	else if (((*p)->right != nullptr && (*p)->left != nullptr)) { // 2 hijos

		CNode** q = buscarReemplazo(p);

		(*p)->value = (*q)->value;

		CNode* tmp = *q;
		*q = (*q)->right;
		delete tmp;


	}
	else if ((*p)->right != nullptr) { // 1 hijo derecho
		CNode* tmp = *p;

		*p = ((*p)->right);

		delete tmp;
	}
	else if ((*p)->left != nullptr) { // 1 hijo izquierdo
		CNode* tmp = *p;

		*p = ((*p)->left);

		delete tmp;
	}
	else { // 0 hijos

		delete* p;
		*p = nullptr;
	}

	return true;

}



CNode** CTree::buscarReemplazo(CNode** p) {

	CNode** q;
	
	if (alternar == false) {

		q = &((*p)->right);

		while ((*q)->left != nullptr) {
			q = &((*q)->left);
		}
	}
	else {

		q = &((*p)->left);

		while ((*q)->right != nullptr) {
			q = &((*q)->right);
		}
	}

	alternar = !alternar;


	return q;

}


void CTree::printRecursivo(CNode* p) {

	if (p == nullptr) {
		return;
	}
	else {

		printRecursivo(p->left);

		cout << p->value << " ";

		printRecursivo(p->right);
	}

}

void CTree::print() {

	printRecursivo(root);

}








int main() {
	CTree tree;
	tree.ins(50);
	tree.ins(20);
	tree.ins(70);
	tree.ins(10);
	tree.ins(30);
	tree.ins(60);
	tree.ins(80);
	tree.ins(25);
	tree.ins(35);

	cout << "Original: ";
	tree.print();
	cout << endl;

	tree.rem(20); // 2 hijos
	cout << "Rem 20: ";
	tree.print();
	cout << endl;

	tree.rem(80); // 0 hijos
	cout << "Rem 80: ";
	tree.print();
	cout << endl;

	tree.rem(70); // 1 hijo
	cout << "Rem 70: ";
	tree.print();
	cout << endl;
}


*/