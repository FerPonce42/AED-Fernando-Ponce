#include <iostream>
using namespace std;

class cDeque
{
private:
    int** mapa = NULL;
    int** m_ini = NULL;
    int** m_fin = NULL;
    int* v_ini = NULL;
    int* v_fin = NULL;

public:
    cDeque()
    {
        mapa = new int* [5];
        m_ini = mapa + 2;
        m_fin = m_ini;
    }

    void push_front(int n);
    void print();

};

void cDeque::push_front(int n)
{
    if (v_ini == nullptr) {
        *m_ini = new int[5];
        v_ini = *m_ini + 2;
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

        *m_ini = new int[5];
        v_ini = *m_ini + 4;

        *v_ini = n;
    }
    else {
        v_ini--;
        *v_ini = n;
    }

}


void cDeque::print() {
    int** m_actual = m_ini;
    int* v_actual = v_ini;

    while (m_actual <= m_fin) {
        if (v_actual == nullptr) {
            cout << "Sin nada que mostrar..." << endl;
            return;
        }
        else if (m_actual == m_fin) {
            if (v_actual == v_fin) {
                cout << *v_actual<<" ";
                return;
            }
            else {
                cout << *v_actual << " ";
                v_actual++;
            }
        }
        else if (v_actual == *m_actual + 4) {
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
    cDeque prueba;
    prueba.push_front(1);
    prueba.push_front(2);
    prueba.push_front(3);
    prueba.push_front(4);
    prueba.push_front(5);
    prueba.push_front(6);
    prueba.push_front(7);
    prueba.push_front(8);
    prueba.push_front(9);
    prueba.push_front(10);
    prueba.push_front(11);
    prueba.push_front(12);
    prueba.push_front(13);
    prueba.push_front(14);
    prueba.print();

}
