#include <iostream>
using namespace std; 


struct CNode
{
    CNode(int v)
    {   value = v; next = 0;    }
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
{   head = 0;   }

CSortedList::~CSortedList()
{
  
}

bool CSortedList::find(int x, CNode**& p)
{

}

bool CSortedList::ins(int x)
{

}

bool CSortedList::rem(int x)
{

}

void CSortedList::print()
{
  
}

int main()
{
    CSortedList l;
    l.ins(3); l.ins(14); l.ins(7); l.ins(11);
    l.print();
    l.rem(11); l.print();
    l.rem(14); l.print();
    l.rem(3); l.print();
    l.rem(7); l.print();
}