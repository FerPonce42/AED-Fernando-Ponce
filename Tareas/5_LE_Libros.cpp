#include <iostream>
#include <string>
using namespace std;


template <class T>
struct CNode
{
    CNode(T v)
    {
        value = v; next = 0;
    }
    T value;
    CNode<T>* next;
};

/*--------- LOGICA DEL LIBRO ----------*/


struct Libro {
    string titulo;
    string autor;
    double precio;
    int calificacion;
};

/*-------ASC_LIBRO------------*/
template <class T>
struct ASC_LIBRO {

    string filtro;
    ASC_LIBRO(string);


    bool operator()(T libro1, T libro2);
};
template <class T>
ASC_LIBRO<T>::ASC_LIBRO(string f) {

    filtro = f;
}

template <class T>
bool ASC_LIBRO<T>::operator()(T libro1, T libro2) {

    if (filtro == "titulo") {
        return (libro1.titulo < libro2.titulo);
    }
    else if (filtro == "autor") {
        return (libro1.autor < libro2.autor);
    }
    else if (filtro == "precio") {
        return (libro1.precio < libro2.precio);
    }
    else if (filtro == "calificacion") {
        return (libro1.calificacion < libro2.calificacion);
    }


    return false;
}


/*-------DESC_LIBRO------------*/
template <class T>
struct DESC_LIBRO {
    string filtro;
    DESC_LIBRO(string f);


    bool operator()(T libro1, T libro2);
};


template <class T>
DESC_LIBRO<T>::DESC_LIBRO(string f) {

    filtro = f;
}


template <class T>
bool DESC_LIBRO<T>::operator()(T libro1, T libro2) {

    if (filtro == "titulo") {
        return (libro1.titulo > libro2.titulo);
    }
    else if (filtro == "autor") {
        return (libro1.autor > libro2.autor);
    }
    else if (filtro == "precio") {
        return (libro1.precio > libro2.precio);
    }
    else if (filtro == "calificacion") {
        return (libro1.calificacion > libro2.calificacion);
    }


    return false;
}



/*-------IGUAL_LIBRO------------*/

template <class T>
struct IGUAL_LIBRO {


    bool operator()(T libro1, T libro2);
};


template <class T>
bool IGUAL_LIBRO<T>::operator()(T libro1, T libro2) {

    return libro1.titulo == libro2.titulo && libro1.autor == libro2.autor;

}



/*---------LOGICA DEL SORTED LIST find ins rem ----------*/

template <class T, class O>
struct CSortedList
{
    CSortedList(string filtro);
    ~CSortedList();
    bool find(T x, CNode<T>**& p);
    bool ins(T x);
    bool rem(T x);
    void print();

    CNode<T>* head;
    string filtro;
};

template <class T, class O>
CSortedList<T, O>::CSortedList(string f)
{
    head = 0;
    filtro = f;
}


template <class T, class O>
CSortedList<T, O>::~CSortedList()
{
    CNode<T>* limpiar = head;

    while (limpiar != nullptr) {
        CNode<T>* tmp = limpiar->next;
        delete limpiar;

        limpiar = tmp;
    }

}


template <class T, class O>
bool CSortedList<T, O>::find(T x, CNode<T>**& p)
{
    O ordenamiento(filtro);
    IGUAL_LIBRO<T> igualdad;

    p = &head;

    while (*p != nullptr && ordenamiento((*p)->value, x)) {

        p = &((*p)->next);

    }

    return *p != nullptr && igualdad(x, ((*p)->value));

}



template <class T, class O>
bool CSortedList<T, O>::ins(T x)
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
bool CSortedList<T, O>::rem(T x)
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
void CSortedList<T, O>::print()
{
    CNode<T>* mover = head;

    if (mover == nullptr) {
        cout << "Vacio" << endl;
        return;
    }

    while (mover != nullptr) {
        cout << "Titulo:       " << mover->value.titulo << endl;
        cout << "Autor:        " << mover->value.autor << endl;
        cout << "Precio:       S/. " << mover->value.precio << endl;
        cout << "Calificacion: " << mover->value.calificacion << endl;
        cout << "--------------------------------------------" << endl;
        mover = mover->next;
    }
    cout << endl;
}


/*--------------------------------------------------*/
int main()
{
    string orden, filtro;

    cout << "=============================================" << endl;
    cout << "|        BIBLIOTECA - LE de Libros          |" << endl;
    cout << "==============================================" << endl;
    cout << endl;

    cout << "Orden (ASC/DESC): ";
    cin >> orden;
    while (orden != "ASC" && orden != "DESC") {
        cout << "Opcion invalida. Ingresa ASC o DESC: ";
        cin >> orden;
    }

    cout << "Filtro (titulo/autor/precio/calificacion): ";
    cin >> filtro;
    while (filtro != "titulo" && filtro != "autor" && filtro != "precio" && filtro != "calificacion") {
        cout << "Opcion invalida. Ingresa titulo, autor, precio o calificacion: ";
        cin >> filtro;
    }

    cout << endl;
    cout << "============================================" << endl;
    cout << "  Orden: " << orden << "  |  Filtro: " << filtro << endl;
    cout << "============================================" << endl;
    cout << endl;

    int opcion = 0;

    if (orden == "ASC") {

        CSortedList<Libro, ASC_LIBRO<Libro>> lista(filtro);

        lista.ins({"El nombre de la rosa",    "Umberto Eco",       52.10, 5});
        lista.ins({"Ficciones",               "Jorge Luis Borges", 38.50, 5});
        lista.ins({"Los detectives salvajes",  "Roberto Bolano",   61.20, 4});

        while (opcion != 4) {

            cout << "  1. Insertar libro" << endl;
            cout << "  2. Eliminar libro" << endl;
            cout << "  3. Mostrar lista" << endl;
            cout << "  4. Salir" << endl;
            cout << endl;
            cout << "  Opcion: ";
            cin >> opcion;
            cout << endl;

            if (opcion == 1) {

                Libro nuevo;
                cout << "  Titulo:              "; cin.ignore(); getline(cin, nuevo.titulo);
                cout << "  Autor:               "; getline(cin, nuevo.autor);
                cout << "  Precio:          S/. "; cin >> nuevo.precio;
                cout << "  Calificacion (1-5):  "; cin >> nuevo.calificacion;
                cout << endl;

                if (lista.ins(nuevo)) {
                    cout << "  >> Libro insertado correctamente." << endl;
                }
                else {
                    cout << "  >> Libro ya existe en la lista." << endl;
                }

            }
            else if (opcion == 2) {

                if (lista.head == nullptr) {
                    cout << "  >> La lista esta vacia." << endl;
                }
                else {
                    Libro buscar;
                    cout << "  Titulo del libro a eliminar:         "; cin.ignore(); getline(cin, buscar.titulo);
                    cout << "  Autor del libro a eliminar:          "; getline(cin, buscar.autor);
                    cout << "  Precio del libro a eliminar:     S/. "; cin >> buscar.precio;
                    cout << "  Calificacion del libro a eliminar:   "; cin >> buscar.calificacion;
                    cout << endl;

                    if (lista.rem(buscar)) {
                        cout << "  >> Libro eliminado correctamente." << endl;
                    }
                    else {
                        cout << "  >> Libro no encontrado." << endl;
                    }
                }

            }
            else if (opcion == 3) {
                cout << "============================================" << endl;
                lista.print();
            }
            else if (opcion != 4) {
                cout << "  >> Opcion invalida." << endl;
            }

            cout << endl;
        }

    }
    else {

        CSortedList<Libro, DESC_LIBRO<Libro>> lista(filtro);

        lista.ins({"El nombre de la rosa",    "Umberto Eco",       52.10, 5});
        lista.ins({"Ficciones",               "Jorge Luis Borges", 38.50, 5});
        lista.ins({"Los detectives salvajes",  "Roberto Bolano",   61.20, 4});

        while (opcion != 4) {

            cout << "  1. Insertar libro" << endl;
            cout << "  2. Eliminar libro" << endl;
            cout << "  3. Mostrar lista" << endl;
            cout << "  4. Salir" << endl;
            cout << endl;
            cout << "  Opcion: ";
            cin >> opcion;
            cout << endl;

            if (opcion == 1) {

                Libro nuevo;
                cout << "  Titulo:              "; cin.ignore(); getline(cin, nuevo.titulo);
                cout << "  Autor:               "; getline(cin, nuevo.autor);
                cout << "  Precio:          S/. "; cin >> nuevo.precio;
                cout << "  Calificacion (1-5):  "; cin >> nuevo.calificacion;
                cout << endl;

                if (lista.ins(nuevo)) {
                    cout << "  >> Libro insertado correctamente." << endl;
                }
                else {
                    cout << "  >> Libro ya existe en la lista." << endl;
                }

            }
            else if (opcion == 2) {

                if (lista.head == nullptr) {
                    cout << "  >> La lista esta vacia." << endl;
                }
                else {
                    Libro buscar;
                    cout << "  Titulo del libro a eliminar:         "; cin.ignore(); getline(cin, buscar.titulo);
                    cout << "  Autor del libro a eliminar:          "; getline(cin, buscar.autor);
                    cout << "  Precio del libro a eliminar:     S/. "; cin >> buscar.precio;
                    cout << "  Calificacion del libro a eliminar:   "; cin >> buscar.calificacion;
                    cout << endl;

                    if (lista.rem(buscar)) {
                        cout << "  >> Libro eliminado correctamente." << endl;
                    }
                    else {
                        cout << "  >> Libro no encontrado." << endl;
                    }
                }

            }
            else if (opcion == 3) {
                cout << "============================================" << endl;
                lista.print();
            }
            else if (opcion != 4) {
                cout << "  >> Opcion invalida." << endl;
            }

            cout << endl;
        }
    }


}