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

    ~cDeque();

    void push_front(int n);
    void print();

    int pop_front();

    void push_back(int n);
    int pop_back();

    int& operator[](int id);

};


cDeque::~cDeque() {
    int** m_actual = m_ini;
    int** m_final = m_fin;

    while (m_actual <= m_final) {
        delete[] * m_actual;
        m_actual++;
    }

    delete[] mapa;
}

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

            m_ini = mapa + 2;
            m_fin = mapa + 2;
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






void cDeque::push_back(int n) {

    if (v_fin == nullptr) {
        *m_fin = new int[5];
        v_fin = *m_fin + 2;
        v_ini = v_fin;

        *v_fin = n;
    }
    else if (mapa + 4 == m_fin) {
        if (v_fin == *m_fin + 4) {
            cout << "Push Backs llenos." << endl;
        }
        else {
            v_fin++;
            *v_fin = n;
        }
    }
    else if (v_fin == *m_fin+4) {
        m_fin++;

        *m_fin = new int[5];
        v_fin = *m_fin;

        *v_fin = n;
    }
    else {
        v_fin++;
        *v_fin = n;
    }

}



int cDeque::pop_back() {
    int valor = 0;
    if (v_fin == nullptr) {
        cout << "Sin nada que sacar..." << endl;

        return 0;
    }
    else if (m_ini == m_fin) {
        if (v_ini == v_fin) {
            valor = *v_fin;
            delete[] * m_fin;

            m_ini = mapa + 2;
            m_fin = mapa + 2;
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
        v_fin = *m_fin + 4;
    }
    else {
        valor = *v_fin;
        v_fin--;
    }

    return valor;
}


int& cDeque::operator[](int id) {

    int** m_actual = m_ini;
    int* v_actual = v_ini;
    int contador = 0;
    static int error = -1;

    while (m_actual <= m_fin) {
        if (v_actual == nullptr) {
            cout << "Sin nada que mostrar..." << endl;
            return error;
        }
        else if (m_actual == m_fin) {
            if (v_actual == v_fin) {
                if (contador == id) {
                    return *v_actual;
                }
                else {
                    return error;
                }
            }
            else {
                if (contador == id) {
                    return *v_actual;
                }
                else {
                    v_actual++;
                    contador++;
                }
            }
        }
        else if (v_actual == *m_actual + 4) {
            if (contador == id) {
                return *v_actual;
            }
            else {
                m_actual++;
                v_actual = *m_actual;
                contador++;
            }
        }
        else {
            if (contador == id) {
                return *v_actual;
            }
            else {
                v_actual++;
                contador++;
            }
            
        }
    }

    return error;

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

    prueba.push_front(10);
    prueba.push_back(20);
    prueba.push_front(9);
    prueba.push_back(21);
    prueba.push_front(8);
    prueba.push_back(22);
    prueba.push_front(7);
    prueba.push_back(23);
    prueba.push_front(6);

    prueba.print(); cout << endl;

    cout << "prueba[0]: " << prueba[0] << endl;
    cout << "prueba[1]: " << prueba[1] << endl;
    cout << "prueba[2]: " << prueba[2] << endl;
    cout << "prueba[3]: " << prueba[3] << endl;
    cout << "prueba[4]: " << prueba[4] << endl;
    cout << "prueba[5]: " << prueba[5] << endl;
    cout << "prueba[6]: " << prueba[6] << endl;
    cout << "prueba[7]: " << prueba[7] << endl;
    cout << "prueba[8]: " << prueba[8] << endl;
}