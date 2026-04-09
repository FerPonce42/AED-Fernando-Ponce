#include <iostream>
using namespace std;

class cDeque
{
private:
    int** mapa = NULL;
    int** m_ini = NULL;
    int** m_fin= NULL;
    int* v_ini = NULL;
    int* v_fin = NULL;

public:
    cDeque()
    {
        mapa = new int* [11];
        m_ini = mapa + 5;
        m_fin = m_ini;
    }

    void push_front(int n);
    void push_back(int n);
    int  pop_front();
    int  pop_back();
    int& operator[](int id);
    void print();
};

void cDeque::push_front(int n)
{
    if (*m_ini == nullptr) {

        *m_ini = new int[5];

        v_ini = (*m_ini) + 2;
        v_fin = v_ini;

        *v_ini = n;
        v_ini--;

    }else if (v_ini == *m_ini) {

        if (m_ini != mapa) {
            m_ini--;

            *m_ini = new int[5];

            v_ini = (*m_ini) + 4;

            *v_ini = n;

            v_ini--;
        }
        else {
            cout << "Se nos llenó el mapa!";
            return;
        }
    }
    else {
        *v_ini = n;

        v_ini--;
    }
    
}

int cDeque::pop_front()
{

    if (*m_ini == nullptr) {

        cout << "No hay elementos que sacar";
        return -1;
    }
    else {
        int valor_sacado = 0;
        if (v_ini == v_fin) {
            valor_sacado = *(v_ini + 1);
            delete[] *m_ini;
            m_ini = nullptr;

            return valor_sacado;
        }
        else if (v_ini == (*m_ini) + 4) {
            valor_sacado = *(v_ini);
            delete[] * m_ini;
            m_ini++;

            v_ini = *m_ini;

            return valor_sacado;
        }
        else {
            valor_sacado = *(v_ini + 1);
            v_ini++;

            return valor_sacado;
        }

    }

}


void cDeque::push_back(int n)
{
    if (*m_fin == nullptr) {

        *m_fin = new int[5];

        v_fin = (*m_fin) + 2;
        v_ini = v_fin;

        *v_fin = n;
        v_fin++;

    }
    else if (v_fin == *m_fin + 5) {

        if (m_fin != mapa + 10) {
            m_fin++;

            *m_fin = new int[5];

            v_fin = *m_fin;

            *v_fin = n;

            v_fin++;
        }
        else {
            cout << "Se nos llenó el mapa!";
            return;
        }
    }
    else {
        *v_fin = n;

        v_fin++;
    }
}


int cDeque::pop_back()
{
    if (*m_fin == nullptr) {

        cout << "No hay elementos que sacar";
        return -1;
    }
    else {
        int valor_sacado = 0;
        if (v_fin == v_ini) {
            valor_sacado = *(v_fin - 1);//
            delete[] * m_fin;
            m_fin = nullptr;

            return valor_sacado;
        }
        else if (v_fin == *m_fin + 1) {
            valor_sacado = *(v_fin - 1);
            delete[] * m_fin;
            m_fin--;

            v_fin = *m_fin;

            return valor_sacado;
        }
        else {
            valor_sacado = *(v_fin - 1);
            v_fin--;

            return valor_sacado;
        }

    }
}

int& cDeque::operator[](int id)
{

}

void cDeque::print()
{

    cout << endl;
}

int main()
{
    cDeque prueba;
    prueba.push_back(1);
    prueba.push_back(2);
    prueba.push_back(3);
    prueba.push_back(4);
    prueba.push_front(10);
    prueba.push_front(20);
    prueba.print();              // 20 10 1 2 3 4
    cout << prueba[0] << endl;  // 20
    cout << prueba[2] << endl;  // 1
    cout << prueba.pop_back() << endl;  // 4
    cout << prueba.pop_front() << endl;  // 20
    prueba.print();              // 10 1 2 3
}