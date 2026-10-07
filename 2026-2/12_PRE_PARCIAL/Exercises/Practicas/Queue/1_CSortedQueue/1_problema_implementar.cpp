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
// Soluciones aqui!
//
void CSortedQueue::pushx(int x)
{}

void CSortedQueue::popx()
{}

int CSortedQueue::frontx()
{   return 0;   }

void CSortedQueue::remx(int x)
{}

void CSortedQueue::printx()
{}

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

