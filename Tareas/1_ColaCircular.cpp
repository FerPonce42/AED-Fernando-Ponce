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
};

//Inicializar tamaño del arreglo.
template<class T, int N>
Cola<T,N>::Cola() {
	tamano = N;
	arr = new T[tamano];
	head = nullptr;
	tail = nullptr;
}
// Liberar tamaño
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
	
	if (EstaVacio()) { // SI ESTA VACIO, NO ESTA LLENO.
		return false;
	}
	else if (tail == head) { // TAIL alcanzó a HEAD. SI ESTA LLENO
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

	}
	if(tail == arr + tamano - 1){ // Si tail esta al final, push valor y mando al inicio del arreglo.
		*tail = valor;
		tail = arr;

	}else {// SI no esta en el final, inserto valor y avanzo (Caso normal)
		*tail = valor;
		tail++;
	}

	return true;

}


// POP
template<class T, int N>
bool Cola<T, N>::Pop(T& valor) {

	if (EstaVacio()) { //Si Esta Vacio, No puedo POP
		return false;
	}

	if(head == tail - 1){ // Si HEAD esta atras de TAIl, TERMINAMOS. 
		valor = *head;
		head = nullptr;
		tail = nullptr;

	}else if ((head == arr + tamano - 1) && (tail == arr)) { // SI HEAD llego al ultimo elemento Y Alcanzó a TAIL. TERMINAMOS
		valor = *head;
		head = nullptr;
		tail = nullptr;
	}else if(head == arr + tamano - 1){ //Si head llega al ultimo elemento, lo mandamos al inicio.
		valor = *head;
		head = arr;
	}else {
		valor = *head;
		head ++; //Avanzamos head.
	}

	return true;

}



int main() {

	Cola<int,4> cola;

	cola.Push(5);
	cola.Push(7);
	cola.Push(3);
	cola.Push(1);
	// [ 5, 7, 3 , 1 ];
	int x;

	cola.Pop(x);

	// [ ignorado , 7, 3 , 1 ];

	cola.Push(13);

	// [ 13, 7, 3 , 1 ];

}