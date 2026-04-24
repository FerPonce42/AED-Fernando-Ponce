#include <iostream>
using namespace std;


template <class T>
struct CNode
{
    CNode(int v)
    {
        value = v; next = 0;
    }
    T value;
    CNode<T>* next;    
};


////////////////////////////////////////////////////////////////////////

/*-------ASC------------*/
template <class T>
struct ASC{
    bool operator()(T a, T b);
};

template <class T>
bool ASC<T>::operator()(T a, T b) {
    return a > b;
}


/*-------DESC------------*/
template <class T>
struct DESC {
    bool operator()(T a, T b);
};


template <class T>
bool DESC<T>::operator()(T a, T b) {
    return a < b;
}


/*-------------------*/

template <class T, class O>
class CSortedList
{
public:
    CSortedList();
    ~CSortedList();
    bool find(T x, CNode<T>**& p);
    bool ins(T x);
    bool rem(T x);
    void print();
private:
    CNode<T>* head;
};

template <class T, class O>
CSortedList<T,O>::CSortedList()
{
    head = 0;
}


template <class T, class O>
CSortedList<T,O>::~CSortedList()
{
    CNode<T>* limpiar = head;

    while (limpiar != nullptr) {
        CNode<T>* tmp = limpiar->next;
        delete limpiar;

        limpiar = tmp;
    }

}


template <class T, class O>
bool CSortedList<T,O>::find(T x, CNode<T>**& p)
{
    O ordenamiento;

    p = &head;

    while (*p != nullptr && ordenamiento(x , ((*p)->value))) {

        p = &((*p)->next);

    }

    return *p != nullptr && (x == ((*p)->value));

}



template <class T, class O>
bool CSortedList<T,O>::ins(T x)
{
    CNode<T>** p;

    if (find(x, p)) {
        return false;
    }
    else
    {
        CNode<T>* nodo = new CNode<T>(x);
        nodo->value = x;
        nodo->next = *p;

        *p = nodo;
    }

    return true;
}


template <class T, class O>
bool CSortedList<T,O>::rem(T x)
{
    CNode<T>** p;

    if (find(x, p)) {

        CNode<T>* tmp;
        tmp = (*p)->next;
        delete* p;
        *p = tmp;

    }
    else
    {
        return false;
    }

    return true;
}



template <class T, class O>
void CSortedList<T,O>::print()
{
    CNode<T>* mover = head;

    if (mover == nullptr) {
        cout << "Vacio" << endl;
    }

    for (mover; mover != nullptr; mover = mover->next) {
        cout << mover->value << " ";
    }
    cout << endl;
}

int main()
{
    CSortedList<int, ASC<int>> listaASC;

    cout << "ASCENDENTE: " << endl;

    listaASC.ins(5);
    listaASC.ins(10);
    listaASC.ins(8);
    listaASC.ins(2);
    listaASC.ins(33);
    listaASC.ins(24);
    listaASC.ins(42);
    listaASC.ins(15);
    listaASC.print();


    CSortedList<int, DESC<int>> listaDESC;

    cout << "DESCENDENTE: " << endl;

    listaDESC.ins(5);
    listaDESC.ins(10);
    listaDESC.ins(8);
    listaDESC.ins(2);
    listaDESC.ins(33);
    listaDESC.ins(24);
    listaDESC.ins(42);
    listaDESC.ins(15);
    listaDESC.print();
}