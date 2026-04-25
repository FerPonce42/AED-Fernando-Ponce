#include <iostream>
#include <string>
#include <iomanip>
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
    double precio = 0.0;
    int calificacion = 0;
};

/*-------ASC_LIBRO------------*/

string toLower(string s)
{
    for (int i = 0; i < (int)s.size(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}

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
        return (toLower(libro1.titulo) < toLower(libro2.titulo));
    }
    else if (filtro == "autor") {
        return (toLower(libro1.autor) < toLower(libro2.autor));
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
        return (toLower(libro1.titulo) > toLower(libro2.titulo));
    }
    else if (filtro == "autor") {
        return (toLower(libro1.autor) > toLower(libro2.autor));
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

    return toLower(libro1.titulo) == toLower(libro2.titulo)
        && toLower(libro1.autor) == toLower(libro2.autor);

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
    int cantidad;
};

template <class T, class O>
CSortedList<T, O>::CSortedList(string f)
{
    head = 0;
    filtro = f;
    cantidad = 0;
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
        cantidad++;
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
        cantidad--;

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

        string titulo = mover->value.titulo;
        string autor = mover->value.autor;

        if (!titulo.empty()) { titulo[0] = toupper(titulo[0]); }
        if (!autor.empty()) { autor[0] = toupper(autor[0]); }

        cout << "Titulo:       " << titulo << endl;
        cout << "Autor:        " << autor << endl;
        cout << "Precio:       S/. " << fixed << setprecision(2) << mover->value.precio << endl;
        cout << "Calificacion: " << mover->value.calificacion << endl;
        mover = mover->next;
        if (mover != nullptr) {
            cout << "--------------------------------------------" << endl;
        }
    }
    cout << endl;
}


/*--------- LOGICA DEL MENU ----------*/

template <class T, class O>
void ejecutarMenu(CSortedList<T, O>& lista, string orden, string filtro)
{
    int opcion = 0;

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

            // Fix: titulo no puede estar vacio
            cout << "  Titulo: "; cin.ignore(); getline(cin, nuevo.titulo);
            while (nuevo.titulo.empty()) {
                cout << "  Titulo no puede estar vacio. Titulo: "; getline(cin, nuevo.titulo);
            }

            // Fix: autor no puede estar vacio
            cout << "  Autor:  "; getline(cin, nuevo.autor);
            while (nuevo.autor.empty()) {
                cout << "  Autor no puede estar vacio. Autor: "; getline(cin, nuevo.autor);
            }

            // Fix: precio no puede ser negativo
            cout << "  Precio: S/. "; cin >> nuevo.precio;
            while (nuevo.precio < 0) {
                cout << "  Precio no puede ser negativo. Precio: S/. "; cin >> nuevo.precio;
            }

            // Fix: validacion calificacion 1-5
            cout << "  Calificacion (1-5): "; cin >> nuevo.calificacion;
            while (nuevo.calificacion < 1 || nuevo.calificacion > 5) {
                cout << "  Opcion invalida. Calificacion (1-5): "; cin >> nuevo.calificacion;
            }
            cout << endl;

            if (lista.ins(nuevo)) {
                cout << "*************************************************" << endl;
                cout << "  >>>>>>>>>>>>>>> Libro insertado correctamente." << endl;
                cout << "*************************************************" << endl;
            }
            else {
                cout << "********************************************************" << endl;
                cout << "  >>>>>>>>>>>>>> Libro ya existe en la lista de libros." << endl;
                cout << "********************************************************" << endl;
            }

        }
        else if (opcion == 2) {

            if (lista.head == nullptr) {
                cout << "********************************************************" << endl;
                cout << "  >>>>>>>>>>>>>> La lista esta vacia." << endl;
                cout << "********************************************************" << endl;
            }
            else {
                Libro buscar;
                cout << "  Titulo del libro a eliminar: "; cin.ignore(); getline(cin, buscar.titulo);
                cout << "  Autor del libro a eliminar:  "; getline(cin, buscar.autor);
                cout << endl;

                if (lista.rem(buscar)) {
                    cout << "********************************************************" << endl;
                    cout << "  >>>>>>>>>>>>>> Libro eliminado correctamente." << endl;
                    cout << "********************************************************" << endl;
                }
                else {
                    cout << "********************************************************" << endl;
                    cout << "  >>>>>>>>>>>>>> Libro no encontrado." << endl;
                    cout << "********************************************************" << endl;
                }
            }

        }
        else if (opcion == 3) {
            cout << "======================================" << endl;
            cout << "  Orden: " << orden << "  |  Filtro: " << filtro << endl;
            cout << "  Libros en biblioteca: " << lista.cantidad << endl;
            cout << "======================================" << endl;
            lista.print();
        }
        else if (opcion != 4) {
            cout << "  >> Opcion invalida." << endl;
        }

        cout << endl;
    }
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

    if (orden == "ASC") {

        CSortedList<Libro, ASC_LIBRO<Libro>> lista(filtro);

        lista.ins({ "el nombre de la rosa",    "umberto eco",       52.10, 5 });
        lista.ins({ "ficciones",               "jorge luis borges", 38.50, 5 });
        lista.ins({ "los detectives salvajes",  "roberto bolano",   61.20, 4 });

        ejecutarMenu(lista, orden, filtro);

    }
    else {

        CSortedList<Libro, DESC_LIBRO<Libro>> lista(filtro);

        lista.ins({ "el nombre de la rosa",    "umberto eco",       52.10, 5 });
        lista.ins({ "ficciones",               "jorge luis borges", 38.50, 5 });
        lista.ins({ "los detectives salvajes",  "roberto bolano",   61.20, 4 });

        ejecutarMenu(lista, orden, filtro);

    }

}