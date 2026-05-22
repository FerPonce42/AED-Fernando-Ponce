/*
 * ╔══════════════════════════════╗
 * ║       Dynamic Array         ║
 * ╚══════════════════════════════╝
 */

 #include <iostream>
using namespace std;

struct Vector {

	int tamano = 5;

	int* vector = new int[tamano];

	int n_elementos = 0;

	void push_back(int x);
	void pop_back();

	void push_front(int x);
	void pop_front();

	int& operator[](int x);

	void expandir();
	
	void print();

};


void Vector::push_back(int x) {

	if (n_elementos == tamano) {
		expandir();
		vector[n_elementos] = x;
		n_elementos++;
	}
	else {
		vector[n_elementos] = x;
		n_elementos++;
	}

}

void Vector::pop_back() {
	if (n_elementos == 0) {
		cout << "No hay nada que retirar" << endl;
		return;
	}
	else {

		n_elementos--;
	}
}



void Vector::push_front(int x) {

	if (n_elementos == 0) {
		vector[n_elementos] = x;
		n_elementos++;

		return;

	}else if (n_elementos == tamano) {
		expandir();
		int i = n_elementos - 1;
		while (i >= 0) {
			vector[i + 1] = vector[i];
			i--;
		}

		vector[0] = x;
		n_elementos++;
	}
	else {
		int i = n_elementos - 1;
		while (i >= 0) {
			vector[i + 1] = vector[i];
			i--;
		}

		vector[0] = x;
		n_elementos++;
	}

}


void Vector::pop_front() {
	if (n_elementos == 0) {
		cout << "No hay nada que retirar" << endl;
		return;
	}
	else {
		int i = 0;
		while (i < n_elementos) {
			vector[i] = vector[i + 1];
			i++;
		}

		n_elementos--;
	}
}


int& Vector::operator[](int x) {

	return vector[x];
}


void Vector::expandir() {
	
	int* tmp = new int[tamano * 2];
	int i = 0;

	while (i < n_elementos) {

		tmp[i] = vector[i];

		i++;
	}

	delete[] vector;

	vector = tmp;
	tamano *= 2;

}

void Vector::print() {
	int i = 0;
	int* p = vector;

	while (i < n_elementos) {

		cout << *p << " ";
		p++;
		i++;
	}
}


int main() {
	Vector v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.print();
	cout << endl;

	v.push_front(0);
	v.print();
	cout << endl;

	v.pop_back();
	v.print();
	cout << endl;

	v.pop_front();
	v.print();
	cout << endl;

	v[1] = 999;
	v.print();
	cout << endl;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.print();
	cout << endl;

	v.push_back(100);
	v.push_back(200);
	v.print();
	cout << endl;
}