/*

// Version 3:

#include <iostream>
#include <deque>
#include <stack>

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


	void printInorden(CNode* p);

	void printPreorden(CNode* p);
	void printPostorden(CNode* p);
	void printReversa(CNode* p);


	void printInordenStack(CNode* p);
	void printPreordenStack(CNode* p);
	void printPostordenStack(CNode* p);
	void printReversaStack(CNode* p);

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


void CTree::printInorden(CNode* p) {

	if (p == nullptr) {
		return;
	}
	else {

		printInorden(p->lados[0]);

		cout << p->value << " ";

		printInorden(p->lados[1]);
	}

}

void CTree::printPreorden(CNode* p) {

	if (p == nullptr) {
		return;
	}
	else {

		cout << p->value << " ";

		printPreorden(p->lados[0]);

		printPreorden(p->lados[1]);
	}

}


void CTree::printInordenStack(CNode* p) { 

	stack<pair<int, CNode*>> pila;

	pila.push(make_pair(0, p));



	while ( ! pila.empty()) {

		int& estado = pila.top().first;

		CNode* nodo = pila.top().second;

		switch (pila.top().first) {

		case 0:
			estado++;
			if (nodo->lados[0]) {
				pila.push(make_pair(0,nodo->lados[0]));
			}

			break;
		case 1:
			estado++;
			cout << nodo->value <<" ";

			break;
		case 2:
			estado++;
			if (nodo->lados[1]) {
				pila.push(make_pair(0, nodo->lados[1]));
			}

			break;
		case 3:
			pila.pop();

			break;
		}
	}
}




void CTree::printPreordenStack(CNode* p) {

	stack<pair<int, CNode*>> pila;

	pila.push(make_pair(0, p));



	while (!pila.empty()) {

		int& estado = pila.top().first;

		CNode* nodo = pila.top().second;

		switch (pila.top().first) {

		case 0:

			estado++;
			cout << nodo->value << " ";

			break;
		case 1:
			estado++;
			if (nodo->lados[0]) {
				pila.push(make_pair(0, nodo->lados[0]));
			}

			break;
		case 2:
			estado++;
			if (nodo->lados[1]) {
				pila.push(make_pair(0, nodo->lados[1]));
			}

			break;
		case 3:
			pila.pop();

			break;
		}
	}
}



void CTree::printPostordenStack(CNode* p) {

	stack<pair<int, CNode*>> pila;

	pila.push(make_pair(0, p));



	while (!pila.empty()) {

		int& estado = pila.top().first;

		CNode* nodo = pila.top().second;

		switch (pila.top().first) {

		case 0:
			estado++;
			if (nodo->lados[0]) {
				pila.push(make_pair(0, nodo->lados[0]));
			}

			break;
		case 1:
			estado++;
			if (nodo->lados[1]) {
				pila.push(make_pair(0, nodo->lados[1]));
			}

			break;
		case 2:

			estado++;
			cout << nodo->value << " ";

			break;
		case 3:
			pila.pop();

			break;
		}
	}
}




void CTree::printReversaStack(CNode* p) {

	stack<pair<int, CNode*>> pila;

	pila.push(make_pair(0, p));



	while (!pila.empty()) {

		int& estado = pila.top().first;

		CNode* nodo = pila.top().second;

		switch (pila.top().first) {

		case 0:
			estado++;
			if (nodo->lados[1]) {
				pila.push(make_pair(0, nodo->lados[1]));
			}

			break;
		case 1:
			estado++;
			cout << nodo->value << " ";

			break;
		case 2:
			estado++;
			if (nodo->lados[0]) {
				pila.push(make_pair(0, nodo->lados[0]));
			}

			break;
		case 3:
			pila.pop();

			break;
		}
	}
}


void CTree::printPostorden(CNode* p) {

	if (p == nullptr) {
		return;
	}
	else {

		printPostorden(p->lados[0]);

		printPostorden(p->lados[1]);

		cout << p->value << " ";
	}
}
void CTree::printReversa(CNode* p) {


	if (p == nullptr) {
		return;
	}
	else {

		printReversa(p->lados[1]);

		cout << p->value << " ";

		printReversa(p->lados[0]);
	}

}






void CTree::print() {

	cout << "Inorden: ";
	printInorden(root);
	cout << endl;

	cout << "Preorden: ";
	printPreorden(root);
	cout << endl;

	cout << "Postorden: ";
	printPostorden(root);
	cout << endl;

	cout << "Reversa: ";
	printReversa(root);
	cout << endl;


	cout << "==================================================" << endl;

	cout << "InordenStack: ";
	printInordenStack(root);
	cout << endl;

	cout << "PreordenStack: ";
	printPreordenStack(root);
	cout << endl;

	cout << "PostordenStack: ";
	printPostordenStack(root);
	cout << endl;

	cout << "ReversaStack: ";
	printReversaStack(root);
	cout << endl;


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

	tree.print();



}
*/


/***************************************************************************************************/


/*

// Version 2:

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


	void printInorden(CNode* p);
	
	void printPreorden(CNode* p);
	void printPostorden(CNode* p);
	void printReversa(CNode* p);



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


void CTree::printInorden(CNode* p) {

	if (p == nullptr) {
		return;
	}
	else {

		printInorden(p->lados[0]);

		cout << p->value << " ";

		printInorden(p->lados[1]);
	}

}

void CTree::printPreorden(CNode* p) {

	if (p == nullptr) {
		return;
	}
	else {

		cout << p->value << " ";

		printPreorden(p->lados[0]);

		printPreorden(p->lados[1]);
	}

}
void CTree::printPostorden(CNode* p) {

	if (p == nullptr) {
		return;
	}
	else {

		printPostorden(p->lados[0]);

		printPostorden(p->lados[1]);

		cout << p->value << " ";
	}
}
void CTree::printReversa(CNode* p) {


	if (p == nullptr) {
		return;
	}
	else {

		printReversa(p->lados[1]);

		cout << p->value << " ";

		printReversa(p->lados[0]);
	}

}






void CTree::print() {

	cout << "Inorden: ";
	printInorden(root);
	cout << endl;

	cout << "Preorden: ";
	printPreorden(root);
	cout << endl;

	cout << "Postorden: ";
	printPostorden(root);
	cout << endl;

	cout << "Reversa: ";
	printReversa(root);
	cout << endl;


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

	tree.print();



}

*/


/************************************************************************************************** */

/*
// Version 1:

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
// Version 0:

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