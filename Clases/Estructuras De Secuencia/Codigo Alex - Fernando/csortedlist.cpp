#include <iostream>
using namespace std;

struct CNode
{
    CNode(int v)
    {
        value = v; next = 0;
    }
    int value;
    CNode* next;
};

class CSortedList
{
public:
    CSortedList();
    ~CSortedList();
    bool find(int x, CNode**& p);
    bool ins(int x);
    bool rem(int x);
    void print();
private:
    CNode* head;
};

CSortedList::CSortedList()
{
    head = 0;
}

CSortedList::~CSortedList()
{
    CNode* limpiar = head;
    
    while (limpiar != nullptr) {
        CNode* tmp = limpiar->next;
        delete limpiar;

        limpiar = tmp;
    }

}

bool CSortedList::find(int x, CNode**& p)
{
    p = &head;

    while (*p != nullptr && x > ((*p)->value)) {

        p = &((*p)->next);

    }

    return *p != nullptr && x == ((*p)->value);

}

bool CSortedList::ins(int x)
{
    CNode** p;

    if (find(x,p)) {
        return false;
    }
    else
    {
        CNode* nodo = new CNode(x);
        nodo->value = x;
        nodo->next = *p;

        *p = nodo;
    }

    return true;
}

bool CSortedList::rem(int x)
{
    CNode** p;

    if (find(x, p)) {
        
        CNode* tmp;
        tmp = (*p)->next;   
        delete* p;        
        *p = tmp;          
        
    }
    else
    {
        return false;
    }

    return true;
}

void CSortedList::print()
{
    CNode* mover = head;

    if (mover == nullptr) {
        cout << "Vacio" << endl;
    }

    for (mover; mover != nullptr; mover = mover->next) {
        cout << mover->value << " ";
    }
    cout << endl;
}

int main()
{
    CSortedList l;
    l.ins(3); // 3
    l.ins(14); // 3 14
    l.ins(7); // 3 14 7
    l.ins(11);// 3 14 7 11
    l.print(); // 3 7 11 14


    l.rem(11);  // 3 7 14
    l.print();
    l.rem(14); // 3 7 
    l.print();
    l.rem(3); // 7 
    l.print();
    l.rem(7); // Vacio
    l.print();
}