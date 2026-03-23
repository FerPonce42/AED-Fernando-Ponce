/*

Tarea 1:
Ahora haras una cola, que mrd es cola???
Cola controlada por un arreglo.
El arreglo sera de n elementos. n, es ingresado por templates.
Arr -> tipo de dato -> template (no necesariamente int, si no otros)

Tendra un Head que apunte a la cabeza
Y un Tail que apunta a la Cola

FIRST INPUT, FIRST OUTPUT. El primero que entra, el primero que sale.

Entra por la cola sale por la cabeza



Atributos:

arr -> elementos
nro_elemento -> igual que la cola
head = NULL el head apunta siempre cabeza
tras un pop el head avanza 1, de forma que el head ya no considera al primer elemeno ingresado
tail = NULL el tail se mueve


en caso de meter un push teniendo el hueco del primer elemento. hacer que el tail vaya al primer elemenot y sobreescriba al primner elemento.
Si hay espacio, se reutiliza!!!


ESTA VACIO
Cuando el H < T hay doble logica
CUando el T < H

Metodos:

Constructor
Destructor
bool Lleno()
bool Vacio()

bool Push(T elemento) : METE POR LA OCLA

bool Pop(T& elemento) : SACA POR LA CABEZA

si llego a pop al utlimo elemento, todos apuntan a nullptr ya no hay mas p
*/
#include <iostream>
using namespace std;

template<class T>
struct Cola {
	int tamano;

	T* arr;
	T* head = nullptr;
	T* tail = nullptr;

	Cola(int nro_tamano);
	~Cola();

	bool EstaLleno();
	bool EstaVacio();
	bool Push(T valor);
	bool Pop(T& valor);
};

//Inicializar tamaño del arreglo.
template<class T>
Cola<T>::Cola(int nro_tamano) {
	tamano = nro_tamano;
	arr = new T[tamano];
	head = arr;
	tail = arr;
}
// Liberar tamaño
template<class T>
Cola<T>::~Cola() {
	delete[] arr;
}





template<class T>
bool Cola<T>::EstaVacio() {
	
	if (tail == head) { // tail y head apuntan a lo mismo
		return true;
	}
	else {
		return false;
	}

}


template<class T>
bool Cola<T>::EstaLleno() {
	
	if (tail + 1 == head) { //caso normal: si tail alcanzó a head
		return true;
	}
	else if ((tail == arr + tamano - 1) && (head == arr)) { //caso cuando dió una vuelta
		return true;
	}
	else {
		return false; // en caso de no estar lleno.
	}
}


// PUSH 
template<class T>
bool Cola<T>::Push(T valor) {

	if (EstaLleno()) {
		return false;
	}
	else if ((tail == arr + tamano - 1)) {
		*tail = valor;
		tail = arr; 
	}
	else {
		*tail = valor;
		tail++;
	}

	return true;

}



template<class T>
bool Cola<T>::Pop(T& valor) {

	if (EstaVacio()) {
		return false;
	}else if ((head == arr + tamano - 1)) {
		valor = *head;
		head = arr;
	}else{
		valor = *head;
		head++;
	}

	return true;

}



int main() {

	Cola<int> cola(4);

	cola.Push(5);
	cola.Push(7);
	cola.Push(3);
	cola.Push(1);

	int x;

	cola.Pop(x);

	cola.Push(13);



}