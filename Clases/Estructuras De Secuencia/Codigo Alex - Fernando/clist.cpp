#include <iostream>
using namespace std;
struct CNode
{
    CNode(int v)
    {
        value = v;
        next = prev = 0;
    }
    int value;
    CNode* next, * prev;
};

class CList
{
public:

    CList();
    ~CList();
    int& operator[](unsigned long i);
    void push_back(int x);
    void pop_back();
    void push_front(int x);
    void pop_front();

    void print();
private:
    CNode* head, * tail;
    int nelem;
};

CList::CList()
{
    head = tail = 0;
    nelem = 0;
}

CList::~CList()
{// pa verifcar esta cochinada eh;
    CNode* exterminador = head;
    for (CNode* tmp = nullptr; exterminador != nullptr; exterminador = tmp) {
        tmp = exterminador->next;
        delete exterminador;
    }
}

void CList::print()
{
    for (CNode* tmp = head; tmp != nullptr ; tmp = tmp->next) {
        cout << tmp->value << " ";
    }
    cout << endl;

}

int& CList::operator[](unsigned long i)
{
    CNode* tmp = head;
    unsigned long x = 0;
    for (; x < i; x++, tmp = tmp->next) {
       
    }
    

    return tmp->value;
}

void CList::push_back(int x)
{
    CNode* nodo_actual = new CNode(x);

    if (nelem == 0) {

        nodo_actual->value = x;

        head = nodo_actual;
        tail = nodo_actual;

        tail->next = nullptr;
        tail->prev = nullptr;

        nelem++;
    }
    else {
        nodo_actual->value = x;

        tail->next= nodo_actual;
        nodo_actual->prev = tail;   

        tail = nodo_actual;

        tail->next = nullptr;

        nelem++;

    }

}

void CList::pop_back()
{
    if (nelem == 1) {

        delete tail;

        tail = nullptr;
        
        head = nullptr;

        nelem--;
    }
    else {
        CNode* tmp = tail->prev;

        delete tail;

        tail = tmp;

        tail->next = nullptr;

        nelem--;
    }
}

void CList::push_front(int x)
{
    CNode* nodo_actual = new CNode(x);

    if (nelem == 0) {

        nodo_actual->value = x;

        head = nodo_actual;
        tail = nodo_actual;

        head->next = nullptr;
        head->prev = nullptr;

        nelem++;
    }
    else {
        nodo_actual->value = x;

        head->prev = nodo_actual;
        nodo_actual->next = head;

        head = nodo_actual;

        head->prev = nullptr;

        nelem++;

    }

}

void CList::pop_front()
{
    if (nelem == 1) {

        delete head;

        tail = nullptr;

        head = nullptr;

        nelem--;
    }
    else {
        CNode* tmp = head->next;

        delete head;

        head = tmp;

        head->prev = nullptr;

        nelem--;
    }
}


int main()
{
    CList xv;

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
