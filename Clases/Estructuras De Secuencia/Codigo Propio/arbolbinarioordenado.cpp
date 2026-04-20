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

	bool find(int x, CNode**& p);

	bool ins(int x);

	bool rem(int x);


	void print();
};


CTree::CTree() {
	root = nullptr;
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
	else if (((*p)->right == nullptr && (*p)->left == nullptr)) { // Caso 0 Hijos

		delete* p;
		*p = nullptr;

	}
	else if ((*p)->right != nullptr) {
		CNode* tmp = *p; // guardo 7

		*p = ((*p)->right); // conecto 5 con 9

		delete tmp; //mato 7
	}
	else if ((*p)->left != nullptr) {
		CNode* tmp = *p; // guardo 7

		*p = ((*p)->left); // conecto 5 con 9

		delete tmp; //mato 7
	}
}

void CTree::print() {

}








int main() {


}