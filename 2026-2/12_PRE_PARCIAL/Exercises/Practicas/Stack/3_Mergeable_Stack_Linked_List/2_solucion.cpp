#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class Stack
{
private:
    Node* top;
    Node* bottom;

public:
    Stack();
    ~Stack();
    void push(int value);
    bool pop(int& value);
    void merge(Stack& other);
    void print();
};

Stack::Stack()
{
    top = nullptr;
    bottom = nullptr;
}

Stack::~Stack()
{
    while (top)
    {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

void Stack::push(int value)
{
    Node* newNode = new Node(value);

    if (!top)
    {
        top = bottom = newNode;
    }
    else
    {
        newNode->next = top;
        top = newNode;
    }
}

bool Stack::pop(int& value)
{
    if (!top)
        return false;

    Node* temp = top;
    value = temp->data;
    top = top->next;

    if (!top)
        bottom = nullptr;

    delete temp;
    return true;
}

void Stack::merge(Stack& other)
{
    if (!other.top)
        return;

    if (!top)
    {
        top = other.top;
        bottom = other.bottom;
    }
    else
    {
        bottom->next = other.top;
        bottom = other.bottom;
    }

    other.top = nullptr;
    other.bottom = nullptr;
}

void Stack::print()
{
    Node* p = top;

    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }

    cout << endl;
}

int main()
{
    Stack a;
    Stack b;

    a.push(1);
    a.push(2);
    a.push(3);

    b.push(4);
    b.push(5);
    b.push(6);

    cout << "Stack A: ";
    a.print();

    cout << "Stack B: ";
    b.print();

    a.merge(b);

    cout << "After merge A: ";
    a.print();

    cout << "After merge B: ";
    b.print();

    int x;

    while (a.pop(x))
        cout << "pop: " << x << endl;

    return 0;
}
