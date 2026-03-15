#include <iostream>
using namespace std;
/*
Implementa en C++ una estructura de datos tipo Pila que almacene enteros.
La pila debe tener una capacidad fija que el usuario defina al momento de crearla.
Debe ser posible insertar elementos, extraer el ultimo elemento insertado,
y consultar si la pila esta llena o vacia. La memoria utilizada debe liberarse
correctamente cuando la pila deje de usarse. Usa aritmetica de punteros
para el manejo interno de la estructura.
*/

struct Pila {

	int tamano;
	int* arreglo;
	int* top = nullptr;

	Pila(int n);
	~Pila();

	bool Push(int valor);

	bool Pop(int& valor);

	bool EstaLleno();

	bool EstaVacio();

};

Pila::Pila(int n) {
	tamano = n;
	arreglo = new int[tamano];
	top = nullptr;
}


Pila::~Pila() {
	delete[] arreglo;
}


bool Pila::EstaLleno() {
	if (top == (arreglo + tamano - 1)) {
		return true;
	}else{
		return false;
	}
}

bool Pila::EstaVacio() {
	if (top == nullptr) {
		return true;
	}
	else {
		return false;
	}
}



bool Pila::Push(int valor){

	if (EstaLleno()) {
		cout << "No puedo agregar mas!" << endl;
		return false;

	}else if(EstaVacio()){
		top = arreglo;
		*top = valor;
	}else{
		top++;
		*top = valor;
	}

	return true;
}

bool Pila::Pop(int& valor) {

	if (EstaVacio()) {
		cout << "No puedo sacar nada, no hay nada." << endl;
		return false;
	}else {
		valor = *top;
		top--;
	}

	if (top < arreglo) {
		cout << "Pila totalmente vacia "<<endl;
		top = nullptr;
		return false;
	}

	return true;
}


int main() {

	Pila pila1(5);

	for (int i = 0; i < 5; i++) {
		int numerito = 0;
		cout << "Ingresa: "; cin >> numerito;
		pila1.Push(numerito);
	}

	for (int i = 0; i < 5; i++) {
		int sacar = 0;
		pila1.Pop(sacar);

		cout << sacar<<endl;
	}

}