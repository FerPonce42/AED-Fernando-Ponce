#include <iostream>
using namespace std;
class CVector
{
public:

    CVector(unsigned long s);
    ~CVector();
 
    void push_back(int x);
    void expand();

    void pop_back();
    void print();

    void push_front(int x);
    void pop_front();

    int& fi(unsigned long i);
    int& operator[](unsigned long i);

private:
    int* v; // v = vector dinamico
    unsigned long size, nelem; // size = tamaño fijo, nelem = contador.
};

CVector::CVector(unsigned long s)
{
    size = s;
    v = new int[size];
    nelem = 0; 
}

CVector::~CVector()
{
    delete[] v;
}

void CVector::print() 
{
    for (unsigned long i = 0; i < nelem; i++) {
        cout << v[i] << " ";
    }

    cout << endl;
}


void CVector::push_back(int x) 
{
    if (nelem < size) {
        v[nelem] = x;
        nelem++;
    }
    else if (nelem == size) {
        expand();
        v[nelem] = x;
        nelem++;
    }
}

void CVector::expand()
{
    int* v_expand = new int[size * 2];

    for (int i = 0; i < nelem; i++) {
        v_expand[i] = v[i];
    }

    int* tmp = v;
    v = v_expand;
    v_expand = tmp;

    delete[] v_expand; 

    size *= 2;
}

void CVector::pop_back()
{
    if (nelem == 0) {
        cout << "No hay elementos que sacar" << endl;
    }
    else if (nelem <= size) {
        nelem--;
    }
}



void CVector::push_front(int x)
{
    if (nelem == size) {
        expand();
    }

    for (int i = nelem - 1; i >= 0; i--) {
        v[i + 1] = v[i];
    }

    v[0] = x;
    nelem++;
}

void CVector::pop_front()
{
    if (nelem == 0) {
        cout << "No hay elementos para sacar";
    }else{

        for (int i = 0; i < nelem; i++) {
            v[i] = v[i + 1];
        }

        nelem--;
    }
}

int& CVector::fi(unsigned long i)
{
    return *(v + i);
}

int& CVector::operator[](unsigned long i)
{
    return v[i];
}

int main()
{
    CVector xv(5);

    cout << "Push Backs: " << endl;
    xv.print();
    xv.push_back(1);
    xv.push_back(6);
    xv.print();
    xv.push_back(7);
    xv.print();

    cout << "Push Fronts: " << endl;
    xv.push_front(6);
    xv.print();

    cout << "Pop Backs: " << endl;
    xv.pop_back();
    xv.print();

    cout << "Push Fronts " << endl;
    xv.pop_front();
    xv.print();


    xv.push_back(100);
    xv.print();
    cout << "[2] = 200: " << endl;
    xv[2] = 200;

    xv.print();
    return 0;


}
