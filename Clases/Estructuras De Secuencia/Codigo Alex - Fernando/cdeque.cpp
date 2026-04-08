#include <iostream>
using namespace std;

class cDeque
{
  private:
    int** mapa = NULL;
    int** M_INI = NULL;
    int** M_FIN = NULL;
    int*  V_INI = NULL;
    int*  V_FIN = NULL;

  public:
    cDeque()
    {
      mapa  = new int*[11];
      M_INI = mapa + 5;
      M_FIN = M_INI;
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

}

void cDeque::push_back(int n)
{

}

int cDeque::pop_front()
{


    return 0;
}

int cDeque::pop_back()
{


    return 0;
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
    cout << prueba.pop_back()  << endl;  // 4
    cout << prueba.pop_front() << endl;  // 20
    prueba.print();              // 10 1 2 3
}