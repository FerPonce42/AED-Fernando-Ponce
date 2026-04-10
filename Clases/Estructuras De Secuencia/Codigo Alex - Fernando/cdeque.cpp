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
        mapa = new int* [5];
        m_ini = mapa + 2;
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
    if (v_ini == nullptr) {
        *m_ini = new int[5];
        v_ini = *m_ini + 2;
        v_fin = v_ini;

        *v_ini = n;
        v_ini--;
    }
    else if (v_ini == *m_ini) {

        if (m_ini == mapa) {
            *v_ini = n;
            cout << "Estas al limite del mapa!!!";
            return;
        }
        else {
            *v_ini = n;
            m_ini--;

            *m_ini = new int[5];
            v_ini = *m_ini + 4;
        }
    }
    else {
        *v_ini = n;
        v_ini--;
    }
    
}

int cDeque::pop_front()
{
    int valor = 0;

    if (v_ini == nullptr) {
        cout << "No hay valor para sacar";
        return 0;

    }
    else if (m_ini == mapa) {

        if (v_ini == *m_ini) {
            valor = *v_ini;
            v_ini++;
        }

    }
    else if (v_ini == *m_ini + 4) {
        valor = *v_ini;
        delete[] *m_ini;
        m_ini++;
        v_ini = *m_ini;

    }
    else if ((v_ini == *m_ini + 2) && (v_ini == v_fin)) {
        valor = *v_ini;
        delete[] * m_ini;
        m_ini = nullptr;
        v_ini = nullptr;
        v_fin = nullptr;
    }
    else {
        valor = *v_ini;
        v_ini++;
    }


    return valor;
}


void cDeque::push_back(int n)
{

}


int cDeque::pop_back()
{

}

int& cDeque::operator[](int id)
{

}

void cDeque::print()
{


}

int main()
{
    cDeque prueba;
    prueba.push_front(1);
}