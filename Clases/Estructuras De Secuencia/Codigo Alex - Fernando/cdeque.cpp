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

    int pop_front();

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

int cDeque::pop_front() {

    int valor = 0;
    if (v_ini == nullptr) {
        cout << "Sin nada que sacar..." << endl;

        return 0;
    }
    else if (m_ini == m_fin) {
        if (v_ini == v_fin) {
            valor = *v_ini;
            delete[] * m_ini;

            m_ini = nullptr;
            m_fin = nullptr;
            v_ini = nullptr;
            v_fin = nullptr;
        }
        else {
            valor = *v_ini;
            v_ini++;
        }
    }
    else if (v_ini == *m_ini + 4) {
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
    cout << "PUSH FRONTS: " << endl;

    prueba.push_front(1);
    prueba.print();
    cout << endl;
    prueba.push_front(2);
    prueba.print();
    cout << endl;
    prueba.push_front(3);
    prueba.print();
    cout << endl;
    prueba.push_front(4);
    prueba.print();
    cout << endl;
    prueba.push_front(5);
    prueba.print();
    cout << endl;
    prueba.push_front(6);
    prueba.print();
    cout << endl;
    prueba.push_front(7);
    prueba.print();
    cout << endl;
    prueba.push_front(8);
    prueba.print();
    cout << endl;
    prueba.push_front(9);
    prueba.print();
    cout << endl;
    prueba.push_front(10);
    prueba.print();
    cout << endl;
    prueba.push_front(11);
    prueba.print();
    cout << endl;
    prueba.push_front(12);
    prueba.print();
    cout << endl;
    prueba.push_front(13);
    prueba.print();
    cout << endl;


    ////

    cout << "POP FRONTS: " << endl;
    prueba.pop_front();
    
    prueba.print();
    cout << endl;
    prueba.pop_front();
    prueba.print();
    cout << endl;
    prueba.pop_front();
    prueba.print();
    cout << endl;
    prueba.pop_front();
    prueba.print();
    cout << endl;
    prueba.pop_front();
    prueba.print();
    cout << endl;
    prueba.pop_front();
    prueba.print();
    cout << endl;
    prueba.pop_front();
    prueba.print();
    cout << endl;
    prueba.pop_front();
    prueba.print();
    cout << endl;
    prueba.pop_front();
    prueba.print();
    cout << endl;
    prueba.pop_front();
    prueba.print();
    cout << endl;
    prueba.pop_front();
    prueba.print();
    cout << endl;
    prueba.pop_front();
    prueba.print();
    cout << endl;
    prueba.pop_front();
    prueba.print();
    cout << endl;

}
