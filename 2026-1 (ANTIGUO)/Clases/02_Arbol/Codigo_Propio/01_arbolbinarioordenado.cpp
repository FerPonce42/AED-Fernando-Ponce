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

	void printRecursivo(CNode* p);
	void print();
};


CTree::CTree() {
	root = nullptr;
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

		CNode** q = &((*p)->right);

		while ((*q)->left != nullptr) {
			q = &((*q)->left);
		}

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