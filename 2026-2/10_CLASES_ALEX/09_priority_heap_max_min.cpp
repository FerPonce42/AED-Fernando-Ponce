#include <iostream>
#include <vector>

using namespace std;

template<class T>
struct Less {
	bool operator()(T a, T b) {
		return a < b;
	}
};

template<class T>
struct Greater {
	bool operator()(T a, T b) {
		return a > b;
	}
};


template<class T, class O>
struct HeapVector {

	vector<T> datos;

	O comparador;
	

	void ins(T v);
	void pop();

	void top();

	void print();

};


template<class T, class O>
void HeapVector<T,O>::ins(T v) {


	datos.push_back(v);

	int i = datos.size() - 1;

	int padre = (i - 1) / 2;

	while (i > 0 && comparador(datos[i] , datos[padre])) {
		T val_tmp = datos[i];
		datos[i] = datos[padre];
		datos[padre] = val_tmp;


		i = padre;
		padre = (i - 1) / 2;
	}


}


template<class T, class O>
void HeapVector<T,O>::pop() {

	if (datos.empty()) {
		cout << "VECTOR VACIO - IMPOSIBLE POP " << endl;
		return;
	}

	T val_tmp = datos.front();
	datos.front() = datos.back();
	datos.back() = val_tmp;

	datos.pop_back();


	int i = 0; 

	int h_izq = (i * 2) + 1;

	int h_der = (i * 2) + 2;

	while (h_izq < datos.size()) { 
		
		int candidato = h_izq; 

		if (h_der < datos.size() && comparador(datos[h_der] , datos[candidato])) { 
			candidato = h_der;
		}

		if (comparador(datos[candidato] , datos[i])) {

			val_tmp = datos[i];
			datos[i] = datos[candidato];
			datos[candidato] = val_tmp;

			i = candidato;

		}
		else {
			break;
		}


		h_izq = (i * 2) + 1;

		h_der = (i * 2) + 2;

	}


}


template<class T, class O>
void HeapVector<T,O>::top() {

	if (datos.empty()) {
		cout << " VECTOR VACIO " << endl;
	}
	else {
		cout << "TOP = "<< datos.front() << endl;
	}
	
}

template<class T, class O>
void HeapVector<T,O>::print() {

	for (auto x : datos) {
		cout << x << " ";
	}
	cout << endl;
}

int main() {

    cout << "========== TEST 1: MIN HEAP ==========" << endl;

    HeapVector<int, Less<int>> h1;

    h1.ins(70);
    h1.ins(30);
    h1.ins(20);
    h1.ins(50);

    h1.print();
    h1.top();
    h1.pop();
    h1.print();


    cout << "\n========== TEST 2: MAX HEAP ==========" << endl;

    HeapVector<int, Greater<int>> h2;

    h2.ins(70);
    h2.ins(30);
    h2.ins(20);
    h2.ins(50);

    h2.print();
    h2.top();
    h2.pop();
    h2.print();


    cout << "\n========== TEST 3: INSERCIONES DESORDENADAS ==========" << endl;

    HeapVector<int, Greater<int>> h3;

    for (int x : {15, 90, 35, 10, 80, 45, 100, 5, 60}) {
        h3.ins(x);
    }

    h3.print();
    h3.top();


    cout << "\n========== TEST 4: MULTIPLES POP (MAX HEAP) ==========" << endl;

    HeapVector<int, Greater<int>> h4;

    for (int x : {90, 70, 80, 40, 60, 50, 75}) {
        h4.ins(x);
    }

    cout << "Inicial: ";
    h4.print();

    while (!h4.datos.empty()) {
        h4.top();
        h4.pop();

        cout << "Despues de pop: ";
        h4.print();
    }


    cout << "\n========== TEST 5: MULTIPLES POP (MIN HEAP) ==========" << endl;

    HeapVector<int, Less<int>> h5;

    for (int x : {45, 10, 80, 5, 30, 60, 20}) {
        h5.ins(x);
    }

    cout << "Inicial: ";
    h5.print();

    while (!h5.datos.empty()) {
        h5.top();
        h5.pop();

        cout << "Despues de pop: ";
        h5.print();
    }


    cout << "\n========== TEST 6: VALORES REPETIDOS ==========" << endl;

    HeapVector<int, Greater<int>> h6;

    for (int x : {50, 20, 50, 80, 20, 80, 50}) {
        h6.ins(x);
    }

    cout << "Inicial: ";
    h6.print();

    while (!h6.datos.empty()) {
        h6.top();
        h6.pop();
    }


    cout << "\n========== TEST 7: UN SOLO ELEMENTO ==========" << endl;

    HeapVector<int, Less<int>> h7;

    h7.ins(42);
    h7.print();
    h7.top();

    h7.pop();

    cout << "Despues de pop: ";
    h7.print();

    h7.top();


    cout << "\n========== TEST 8: HEAP VACIO ==========" << endl;

    HeapVector<int, Greater<int>> h8;

    h8.top();
    h8.pop();

    cout << "Insertando despues de estar vacio..." << endl;

    h8.ins(25);
    h8.ins(10);
    h8.ins(40);

    h8.print();
    h8.top();

    return 0;
}

/*
                                                                                                    HEAP VERSION ARBOL


#include <iostream>
#include <queue>
using namespace std;

template <class T>
struct Less {

    bool operator()(T a, T b) {
        return a < b;
    }
};

template <class T>
struct Greater {

    bool operator()(T a, T b) {
        return a > b;
    }
};

template <class T>
struct Nodo {

    T valor;

    Nodo* left;
    Nodo* right;
    Nodo* parent;

    Nodo(T v) {
        valor = v;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

template <class T, class O>
struct Heap {

    Nodo<T>* heap;

    int ELEM;

    O comparador;

    Heap() {
        heap = nullptr;
        ELEM = 0;
    }

    void top();
    void pop();
    void ins(T v);
    void print_level();
};

template <class T, class O>
void Heap<T, O>::ins(T v) {

    // LOGICA DE ENTRAR DONDE METER O(LOG N)

    if (heap == 0) {
        heap = new Nodo<T>(v);
        ELEM++;
        return;
    }

    int pos_ins = ELEM + 1;

    int pos_padre = pos_ins / 2;

    int camino = 1;

    while (camino <= pos_padre / 2) {
        camino *= 2;
    }

    Nodo<T>* actual = heap;

    while (camino > 1) {

        camino /= 2;

        if ((pos_padre / camino) % 2 == 0) {
            actual = actual->left;
        }
        else {
            actual = actual->right;
        }
    }

    Nodo<T>* nodo_insertado = new Nodo<T>(v);
    nodo_insertado->parent = actual;

    if (pos_ins % 2 == 0) {
        actual->left = nodo_insertado;
    }
    else {
        actual->right = nodo_insertado;
    }

    // LOGICA DE REPOSICIONAMIENTO

    actual = nodo_insertado;

    while (actual->parent != nullptr && comparador(actual->valor, actual->parent->valor)) {

        T val_tmp = actual->valor;
        actual->valor = actual->parent->valor;
        actual->parent->valor = val_tmp;

        actual = actual->parent;
    }

    ELEM++;
}

template <class T, class O>
void Heap<T, O>::pop() {

    if (heap == nullptr) {
        cout << "NO HAY ELEMENTOS" << endl;
        return;
    }

    int pos_ultimo = ELEM;

    int camino = 1;

    Nodo<T>* ultimo_ins = heap;

    while (camino <= pos_ultimo / 2) {
        camino *= 2;
    }

    while (camino > 1) {

        camino /= 2;

        if ((pos_ultimo / camino) % 2 == 0) {
            ultimo_ins = ultimo_ins->left;
        }
        else {
            ultimo_ins = ultimo_ins->right;
        }
    }

    // Intercambio

    T tmp = ultimo_ins->valor;
    ultimo_ins->valor = heap->valor;
    heap->valor = tmp;

    // Eliminacion

    if (heap == ultimo_ins) {

        delete heap;
        heap = 0;
    }
    else {

        if (ultimo_ins->parent->left == ultimo_ins) {
            ultimo_ins->parent->left = 0;
        }

        if (ultimo_ins->parent->right == ultimo_ins) {
            ultimo_ins->parent->right = 0;
        }

        delete ultimo_ins;
    }

    ELEM--;

    // Reposicionamiento

    if (heap != 0) {

        Nodo<T>* cambio = heap;

        while (cambio != 0) {

            T tmp = cambio->valor;
            Nodo<T>* prioritario = 0;

            // Elegir cual hijo tiene prioridad

            if (cambio->left != 0) {
                prioritario = cambio->left;
            }

            if (cambio->right != 0) {
                if (prioritario == 0 || comparador(cambio->right->valor, prioritario->valor)) {
                    prioritario = cambio->right;
                }
            }

            // Si el hijo tiene prioridad sobre el padre, intercambiar

            if (prioritario != 0 && comparador(prioritario->valor, cambio->valor)) {

                tmp = cambio->valor;
                cambio->valor = prioritario->valor;
                prioritario->valor = tmp;

                cambio = prioritario;
            }
            else {
                break;
            }
        }
    }
}

template <class T, class O>
void Heap<T, O>::top() {

    if (heap != nullptr) {
        cout << heap->valor << endl;
    }
    else {
        cout << "Sin elementos " << endl;
    }
}

template <class T, class O>
void Heap<T, O>::print_level() {

    queue<Nodo<T>*> cola;

    if (heap == nullptr) {
        cout << "SIN VALORES" << endl;
    }
    else {

        cola.push(heap);

        while (!cola.empty()) {

            Nodo<T>* tmp = cola.front();
            cola.pop();

            cout << tmp->valor << " ";

            if (tmp->left != nullptr) {
                cola.push(tmp->left);
            }

            if (tmp->right != nullptr) {
                cola.push(tmp->right);
            }
        }
    }

    cout << endl;
}

int main() {

    Heap<int, Less<int>> heap_test;

    heap_test.ins(30);
    heap_test.ins(20);
    heap_test.ins(25);
    heap_test.ins(15);
    heap_test.ins(10);
    heap_test.ins(50);

    heap_test.print_level();

    heap_test.pop();
    heap_test.print_level();

    heap_test.pop();
    heap_test.print_level();

    heap_test.pop();
    heap_test.print_level();

    heap_test.pop();
    heap_test.print_level();

    heap_test.pop();
    heap_test.print_level();

    heap_test.pop();
    heap_test.print_level();

    return 0;
}


*/