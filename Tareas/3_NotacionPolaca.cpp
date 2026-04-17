#include <iostream>
using namespace std;

template <typename T>
class cDeque
{
private:
    T** mapa = NULL;
    T** m_ini = NULL;
    T** m_fin = NULL;
    T* v_ini = NULL;
    T* v_fin = NULL;

public:
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



int main()
{

}