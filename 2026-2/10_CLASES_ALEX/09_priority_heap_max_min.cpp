
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
