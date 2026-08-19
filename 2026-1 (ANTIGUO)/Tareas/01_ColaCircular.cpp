/*
Tarea 1:
Ahora haras una cola

Cola controlada por un arreglo.
- El arreglo sera de n elementos. n, es ingresado por templates.
- Arr -> tipo de dato -> template (no necesariamente int, si no otros)
- Tendra un Head que apunte a la cabeza y un Tail que apunta a la Cola
- FIRST INPUT, FIRST OUTPUT. El primero que entra, el primero que sale.
- Entra por la cola, sale por la cabeza

Atributos:
- arr          -> elementos
- nro_elemento -> igual que la cola
- head = NULL  -> apunta siempre a la cabeza
				  tras un pop el head avanza 1, de forma que ya no considera al primer elemento ingresado
- tail = NULL  -> el tail se mueve
				  en caso de meter un push teniendo el hueco del primer elemento,
				  hacer que el tail vaya al primer elemento y sobreescriba al primer elemento.
				  Si hay espacio, se reutiliza!!!

Esta Vacio:
- Cuando el H < T hay doble logica
- Cuando el T < H

Metodos:
- Constructor
- Destructor
- bool Lleno()
- bool Vacio()
- bool Push(T elemento) : METE POR LA COLA
- bool Pop(T& elemento) : SACA POR LA CABEZA
						  si llego a pop al ultimo elemento, todos apuntan a nullptr, ya no hay mas p
*/
#include <iostream>
using namespace std;

template<class T, int N = 10>
struct Cola {
	int tamano;

	T* arr;
	T* head = nullptr;
	T* tail = nullptr;

	Cola();
	~Cola();

	bool EstaLleno();
	bool EstaVacio();
	bool Push(T valor);
	bool Pop(T& valor);

	void Print();
};

template<class T, int N>
Cola<T,N>::Cola() {
	tamano = N;
	arr = new T[tamano];
	head = nullptr;
	tail = nullptr;
}

template<class T, int N>
Cola<T, N>::~Cola() {
	delete[] arr;
}

/*

FFUNCIONESS

*/
template<class T, int N>
bool Cola<T, N>::EstaVacio() {
	
	if ((head == nullptr) && (tail == nullptr)) { // head y tail no apuntan a nada, SI ESTAVACIO
		return true;
	}
	else {
		return false; //NO VACIO
	}

}


template<class T, int N>
bool Cola<T, N>::EstaLleno() {

	if (EstaVacio()) { // SI ESTA VACIO, NO ESTA LLENO. (no criticar)
		return false;
	}
	else if (tail + 1 == head || (tail == arr + tamano - 1 && head == arr)) { // TAIL alcanzó a HEAD. SI ESTA LLENO
		return true;
	}
	else {
		return false; //NO LLENO
	}
}


// PUSH 
template<class T, int N>
bool Cola<T, N>::Push(T valor) {

	if (EstaLleno()) { // SI esta lleno, no puedo hacer push.
		return false;
	}

	if (EstaVacio()) { // Si esta vacio. inicializo al primer elemento.
		head = arr;
		tail = arr;
		*tail = valor; // Inserto y me quedo aqui, tail apunta al elemento insertado
		return true;
	}

	if (tail == arr + tamano - 1) { // tail esta al final, lo mando al inicio
		tail = arr;
	} else {
		tail++; // Avanzo al siguiente hueco
	}

	*tail = valor; // Inserto en la nueva posicion

	return true;

}


// POP
template<class T, int N>
bool Cola<T, N>::Pop(T& valor) {

	if (EstaVacio()) { //Si Esta Vacio, No puedo POP
		return false;
	}

	if (head == tail) { // Solo queda un elemento, TERMINAMOS.
		valor = *head;
		head = nullptr;
		tail = nullptr;
	} else if (head == arr + tamano - 1) { // head llega al final, regreso al inicio
		valor = *head;
		head = arr;
	} else {
		valor = *head;
		head++;
	}

	return true;

}


// PRINT
template<class T, int N>
void Cola<T, N>::Print() {

	if (EstaVacio()) {
		cout << "[ ]" << endl;
		return;
	}

	T* ptr = head;
	cout << "[ ";

	while (ptr != tail) {
		cout << *ptr << " ";
		if (ptr == arr + tamano - 1) ptr = arr; 
		else ptr++;
	}

	cout << *ptr << " ]" << endl; 

}

int main() {

	Cola<int, 5> cola;

	cola.Push(1);
	cola.Push(2);
	cola.Push(5);
	cola.Push(4);
	cola.Push(8);
	cola.Print();
	// [ 1 2 5 4 8 ]

	int x;
	cola.Pop(x);
	cola.Pop(x);
	cola.Pop(x);
	cola.Pop(x);
	cola.Print();
	// [ 8 ]

	cola.Push(50);
	cola.Push(23);
	cola.Push(16);
	cola.Push(15);
	cola.Print();
	// [ 8 50 23 16 15 ]

}