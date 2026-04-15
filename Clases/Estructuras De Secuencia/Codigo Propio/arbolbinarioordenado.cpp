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

	if (find(x, p)) {
		return false;
	}
	else if (*p == nullptr) { // Caso sin hijos CASO 0
		delete* p;
		*p = nullptr;
	}
	else if ((*p)->right) { // Caso con 1 hijo CASO 1
		CNode* tmp = *p;

		*p = (*p)->right;
	}
	else {
		*p = (*p)->left;
	}

	delete tmp;
	// EL CASO 2 LO TRANSFORMA PAR QUE EL CASO 0  o 1 lo arregle.
}

void CTree::print() {

}








int main() {


}