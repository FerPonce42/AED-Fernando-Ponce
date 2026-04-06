#include <iostream>
using namespace std;

struct CNode
{
    CNode(int v)
    {
        value = v;
        next = 0;
    }
    int value;
    CNode* next;
};

class CForwardList
{
public:
    CForwardList();
    ~CForwardList();
    int& operator[](unsigned long i);
    void push_back(int x);
    void pop_back();
    void push_front(int x);
    void pop_front();
    void print();
private:
    CNode* head;
    int nelem;
};

CForwardList::CForwardList()
{
    head = 0;
    nelem = 0;
}

CForwardList::~CForwardList()
{
    CNode* exterminador = head;
    for (CNode* tmp = nullptr; exterminador != nullptr; exterminador = tmp) {
        tmp = exterminador->next;
        delete exterminador;
    }
}

void CForwardList::print()
{
    for (CNode* tmp = head; tmp != nullptr; tmp = tmp->next) {
        cout << tmp->value << " ";
    }
    cout << endl;
}

int& CForwardList::operator[](unsigned long i)
{
    CNode* tmp = head;
    unsigned long x = 0;
    for (; x < i; x++, tmp = tmp->next) {

    }


    return tmp->value;
}

void CForwardList::push_back(int x)
{}

void CForwardList::pop_back()
{}

void CForwardList::push_front(int x)
{
    CNode* nodo_actual = new CNode(x);

    if (nelem == 0) {

        nodo_actual->value = x;

        head = nodo_actual;

        head->next = nullptr;

        nelem++;
    }
    else {
        nodo_actual->value = x;

        nodo_actual->next = head;

        head = nodo_actual;

        nelem++;

    }

}

void CForwardList::pop_front()
{

    if (nelem == 1) {

        delete head;

        head = nullptr;

        nelem--;
    }
    else {
        CNode* tmp = head->next;

        delete head;

        head = tmp;

        nelem--;
    }
}

int main()
{
    CForwardList xv;

    xv.push_back(3);
    xv.push_back(8);
    xv.push_back(2);
    xv.print();
    xv.push_front(6);
    xv.push_front(5);
    xv.print();
    xv[1] = 20;
    xv.print();

    xv.pop_back();
    xv.print();
    xv.pop_front();
    xv.print();
    xv.pop_back();
    xv.pop_back();
    xv.print();
    xv.pop_back();
    xv.print();

    xv.push_back(33);
    xv.print();
    return 0;
}