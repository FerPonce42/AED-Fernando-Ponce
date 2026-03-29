/*
 * Estructura de Secuencia: VECTOR
 * --------------------------------
 * Funciones implementadas:
 *   PushBack   -> O(k)
 *   PopBack    -> O(k)
 *   operator[] -> O(k)
 *
 * Funciones no implementadas:
 *   PushFront  -> O(n)
 *   PopFront   -> O(n)
 *
 * Nota: sin redimensionamiento, capacidad fija.
 */

#include <iostream>
using namespace std;


struct Vector {

	int* data;
	int* size;
	int capacity;

	Vector(int n);
	~Vector();

	bool EstaLleno();
	bool EstaVacio();
	bool PushBack(int valor);
	bool PopBack(int& valor);
	int& operator[](int i);
};


Vector::Vector(int n) {
	capacity = n;
	data = new int[capacity];
	size = data;
}

Vector::~Vector(){
	delete[] data;
}


bool Vector::EstaLleno() {
	if (size == data + capacity) {
		return true;
	}
	else {
		return false;
	}
}

bool Vector::EstaVacio() {
	if (size == data) {
		return true;
	}
	else {
		return false;
	}
}

bool Vector::PushBack(int valor) {
	if (EstaLleno()) {
		return false;
	}

	if (EstaVacio()) {
		*size = valor;
		size++;
	}
	else {
		*size = valor;
		size++;
	}

	return true;
}

bool Vector::PopBack(int& valor){

	if (EstaVacio()) {
		return false;
	}else{ 
		size--;
		valor = *size;
	}

	return true;
}


int& Vector::operator[](int i) {
	
	return *(data + i);

}

int main() {

	Vector Vector(5);
	Vector.PushBack(4);
	Vector.PushBack(2);
	Vector.PushBack(1);
	Vector.PushBack(9);

	int x;
	Vector.PopBack(x);

	cout<<"[2]: "<< Vector[2]<<endl;

	Vector[2] = 5;
	cout<<"[2]:  " << Vector[2] << endl;

}