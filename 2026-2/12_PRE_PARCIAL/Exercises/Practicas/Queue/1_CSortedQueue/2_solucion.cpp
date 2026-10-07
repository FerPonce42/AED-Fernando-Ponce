#include <iostream>
#include <queue>

class CSortedQueue
{
public:
    void pushx(int x);
    void popx();
    int frontx();
    void remx(int x);
    void printx();
    std::queue<int> q;
};

void CSortedQueue::pushx(int x)
{
    int n = q.size();
    bool inserted = false;

    for (int i = 0; i < n; i++)
    {
        int y = q.front();
        q.pop();

        if (!inserted && x < y)
        {
            q.push(x);
            inserted = true;
        }

        q.push(y);
    }

    if (!inserted)
        q.push(x);
}

void CSortedQueue::popx()
{
    if (!q.empty())
        q.pop();
}

int CSortedQueue::frontx()
{
    if (q.empty())
        return 0;
    return q.front();
}

void CSortedQueue::remx(int x)
{
    int n = q.size();

    for (int i = 0; i < n; i++)
    {
        int y = q.front();
        q.pop();

        if (y != x)
            q.push(y);
    }
}

void CSortedQueue::printx()
{
    int n = q.size();

    for (int i = 0; i < n; i++)
    {
        int x = q.front();
        q.pop();
        std::cout << x << " ";
        q.push(x);
    }

    std::cout << std::endl;
}

int main()
{
    CSortedQueue sq;
    sq.pushx(40); sq.printx();
    sq.pushx(23); sq.printx();
    sq.pushx(51); sq.printx();
    sq.pushx(12); sq.printx();
    sq.pushx(30); sq.printx();
    sq.pushx(5);  sq.printx();
    sq.pushx(40); sq.printx();
    sq.pushx(18); sq.printx();
    
    sq.remx(40);  sq.printx();
    sq.remx(23);  sq.printx();
    sq.remx(12);  sq.printx();
    sq.remx(5);  sq.printx();

    std::cout<<"\nfront => "<<sq.frontx(); sq.popx();
    std::cout<<"\nfront => "<<sq.frontx(); sq.popx();
    sq.printx();
}
