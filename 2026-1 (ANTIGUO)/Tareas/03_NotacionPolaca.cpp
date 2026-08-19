#include <iostream>
using namespace std;

/*
----------------------------------------------------------------------------------------------------------------------------

                                                Lógica del Dque
*/

template <typename T>
struct cDeque {

    T** mapa = NULL;
    T** m_ini = NULL;
    T** m_fin = NULL;
    T* v_ini = NULL;
    T* v_fin = NULL;

    cDeque()
    {
        mapa = new T * [11];
        m_ini = mapa + 5;
        m_fin = m_ini;
    }

    ~cDeque();

    void push_front(T n);
    void print();

    T pop_front();

    void push_back(T n);
    T pop_back();

    T& operator[](int id);
};


template <typename T>
cDeque<T>::~cDeque() {
    if (v_ini == nullptr) {
        delete[] mapa;
        return;
    }

    T** m_actual = m_ini;
    T** m_final = m_fin;

    while (m_actual <= m_final) {
        delete[] * m_actual;
        m_actual++;
    }

    delete[] mapa;
}

template <typename T>
void cDeque<T>::push_front(T n)
{
    if (v_ini == nullptr) {
        *m_ini = new T[11];
        v_ini = *m_ini + 5;
        v_fin = v_ini;

        *v_ini = n;
    }
    else if (mapa == m_ini) {
        if (v_ini == *m_ini) {
            cout << "Push Fronts llenos." << endl;
        }
        else {
            v_ini--;
            *v_ini = n;
        }
    }
    else if (v_ini == *m_ini) {
        m_ini--;

        *m_ini = new T[11];
        v_ini = *m_ini + 10;

        *v_ini = n;
    }
    else {
        v_ini--;
        *v_ini = n;
    }
}

template <typename T>
T cDeque<T>::pop_front() {

    T valor = T();
    if (v_ini == nullptr) {
        cout << "Sin nada que sacar..." << endl;

        return T();
    }
    else if (m_ini == m_fin) {
        if (v_ini == v_fin) {
            valor = *v_ini;
            delete[] * m_ini;

            m_ini = mapa + 5;
            m_fin = mapa + 5;
            v_ini = nullptr;
            v_fin = nullptr;
        }
        else {
            valor = *v_ini;
            v_ini++;
        }
    }
    else if (v_ini == *m_ini + 10) {
        valor = *v_ini;
        delete[] * m_ini;
        m_ini++;
        v_ini = *m_ini;
    }
    else {
        valor = *v_ini;
        v_ini++;
    }

    return valor;
}

template <typename T>
void cDeque<T>::push_back(T n) {

    if (v_fin == nullptr) {
        *m_fin = new T[11];
        v_fin = *m_fin + 5;
        v_ini = v_fin;

        *v_fin = n;
    }
    else if (mapa + 10 == m_fin) {
        if (v_fin == *m_fin + 10) {
            cout << "Push Backs llenos." << endl;
        }
        else {
            v_fin++;
            *v_fin = n;
        }
    }
    else if (v_fin == *m_fin + 10) {
        m_fin++;

        *m_fin = new T[11];
        v_fin = *m_fin;

        *v_fin = n;
    }
    else {
        v_fin++;
        *v_fin = n;
    }
}

template <typename T>
T cDeque<T>::pop_back() {
    T valor = T();
    if (v_fin == nullptr) {
        cout << "Sin nada que sacar..." << endl;

        return T();
    }
    else if (m_ini == m_fin) {
        if (v_ini == v_fin) {
            valor = *v_fin;
            delete[] * m_fin;

            m_ini = mapa + 5;
            m_fin = mapa + 5;
            v_ini = nullptr;
            v_fin = nullptr;
        }
        else {
            valor = *v_fin;
            v_fin--;
        }
    }
    else if (v_fin == *m_fin) {
        valor = *v_fin;
        delete[] * m_fin;
        m_fin--;
        v_fin = *m_fin + 10;
    }
    else {
        valor = *v_fin;
        v_fin--;
    }

    return valor;
}

template <typename T>
T& cDeque<T>::operator[](int id) {

    int n_restantes = v_ini - *m_ini;
    int id_ini = id + n_restantes;

    int bloque = id_ini / 11;
    int posicion = id_ini % 11;

    return *(*(m_ini + bloque) + posicion);
}

template <typename T>
void cDeque<T>::print() {
    T** m_actual = m_ini;
    T* v_actual = v_ini;

    while (m_actual <= m_fin) {
        if (v_actual == nullptr) {
            cout << "Sin nada que mostrar..." << endl;
            return;
        }
        else if (m_actual == m_fin) {
            if (v_actual == v_fin) {
                cout << *v_actual << " ";
                return;
            }
            else {
                cout << *v_actual << " ";
                v_actual++;
            }
        }
        else if (v_actual == *m_actual + 10) {
            cout << *v_actual << " ";
            m_actual++;
            v_actual = *m_actual;
        }
        else {
            cout << *v_actual << " ";
            v_actual++;
        }
    }
}



/*
----------------------------------------------------------------------------------------------------------------------------
                                        Lógica de la PilaOperadores y luego para verificar, asi que templates p
*/

template <class T>
struct PilaOperadores {

    T* arr_operadores;
    T* top;
    int elementos;

    PilaOperadores();
    ~PilaOperadores();

    void PushPila(T n);
    T& PopPila();

    T VerTop();
};

template <class T>
PilaOperadores<T>::PilaOperadores() {
    arr_operadores = new T[10];
    top = nullptr;
    elementos = 0;
}

template <class T>
PilaOperadores<T>::~PilaOperadores() {
    delete[] arr_operadores;
}

template <class T>
void PilaOperadores<T>::PushPila(T n) {
    if (top == nullptr) {
        top = arr_operadores;
        *top = n;
    }
    else {
        top++;
        *top = n;
    }
    elementos++;
}

template <class T>
T& PilaOperadores<T>::PopPila() {
    T& valor = *top;
    elementos--;
    if (elementos == 0) {
        top = nullptr;
    }
    else {
        top--;
    }
    return valor;
}

template <class T>
T PilaOperadores<T>::VerTop() {
    return *top;
}


/*
----------------------------------------------------------------------------------------------------------------------------
                                               Lógica de de de eso
*/
struct Logica {

    cDeque<char> resultado;
    PilaOperadores<char> pila;

    void RecibirNotacion(string notacion);

    bool EsNumero(char n);
    bool EsOperador(char a);
    int Jerarquia(char operador);

    int Evaluar();
};

void Logica::RecibirNotacion(string notacion) {

    for (int i = 0; i < notacion.size(); i++) {
        if (EsNumero(notacion[i])) {

            resultado.push_back(notacion[i]);
        }
        else if (EsOperador(notacion[i])) {

            while ((pila.elementos > 0) && (Jerarquia(pila.VerTop()) >= Jerarquia(notacion[i]))) {

                resultado.push_back(pila.PopPila());

            }

            pila.PushPila(notacion[i]);
        }
        else if (notacion[i] == '(') {
            pila.PushPila(notacion[i]);
        }
        else if (notacion[i] == ')') {

            while (pila.VerTop() != '(') { // sacar todo hasta encontrar el ' ( '
                resultado.push_back(pila.PopPila());
            }

            pila.PopPila(); // aqui ya sacamos el ' ( ' pues es donde el bucle murio.
        }

    }



    // para vaciar la pila:
    while (pila.elementos > 0) {
        resultado.push_back(pila.PopPila());
    }


}

bool Logica::EsNumero(char n) {
    if (n >= '1' && n <= '9') {
        return true;
    }
    else {
        return false;
    }

    return true;
}

bool Logica::EsOperador(char n) {
    switch (n) {
    case '+': return true;
    case '-': return true;
    case '*': return true;
    case '/': return true;
    default:  return false;
    }

    return true;
}

int Logica::Jerarquia(char operador) {
    switch (operador) {
    case '+': return 1;
    case '-': return 1;
    case '*': return 2;
    case '/': return 2;
    default: return 0;
    }
}





int Logica::Evaluar() {
    PilaOperadores<int> numeros;

    while (resultado.v_ini != nullptr) {
        char c = resultado.pop_front();

        if (EsNumero(c)) {

            numeros.PushPila(c - '0'); // en ascii en la primerra somos '3'- '0' eso en posicoones el 3 es 51 y el 0 es48 entonces... 51 - 38 = 3 justito el numero que queremos que sea entero.

            // entonces metemos un entero a nuestra pila templentiada

            cout << "->: " << (c - '0') << endl; //imprimir noma p.
        }
        else if (EsOperador(c)) {

            // por la naturalzea de la pila. lifo ? esa cosa.
            // primero sacaré al segnudo que es el b y luego al primero qeu es a


            int b = numeros.PopPila(); // segundo termino

            int a = numeros.PopPila(); // primer termino

            if (c == '+') {
                numeros.PushPila(a + b);
            }
            else if (c == '-') {
                numeros.PushPila(a - b);
            }
            else if (c == '*') {
                numeros.PushPila(a * b);
            }
            else if (c == '/') {
                if (b == 0) {
                    cout << "Error!!! Division entre cero no existe." << endl;
                    return 0;
                }
                numeros.PushPila(a / b);
            }

            cout << "Op: " << a << " " << c << " " << b << endl; // primer termino  "  operador   "  segundo termino
        }
    }

    cout << endl;
    cout << "=== Resultado ===" << endl;
    return numeros.PopPila(); // el ultimo elemento de la pilita, basicamente el acumulado de todas las operaciones dentro.
}



/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                            el main p
*/


int main() {
    Logica infija;

    string exp_matematica = "(8 - 2) / (1 - 1)";


    cout << "Exp. Matematica: [ ";
    for (int i = 0; i < exp_matematica.size(); i++) {
        cout << exp_matematica[i];
    }
    cout << " ] " << endl;

    infija.RecibirNotacion(exp_matematica);
    cout << "Exp. Postfija: [ ";
    infija.resultado.print();
    cout << "] ";
    cout << endl;

    cout << endl;
    cout << "=== Procedimiento ===" << endl;
    cout << infija.Evaluar() << endl;
}