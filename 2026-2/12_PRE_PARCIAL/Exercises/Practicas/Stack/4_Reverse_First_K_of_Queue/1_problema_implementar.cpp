#include <iostream>
#include <queue>
#include <stack>
using namespace std;
// Soluciones aqui!
//
void reverseFirstK(queue<int>& q, int k)
{
}

void print(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;
}

int main()
{
    queue<int> q1;

    for (int i = 1; i <= 5; i++)
        q1.push(i);

    cout << "Original: ";
    print(q1);

    reverseFirstK(q1, 3);

    cout << "K = 3: ";
    print(q1);

    queue<int> q2;

    for (int i = 1; i <= 6; i++)
        q2.push(i);

    reverseFirstK(q2, 2);

    cout << "K = 2: ";
    print(q2);

    queue<int> q3;

    for (int i = 1; i <= 5; i++)
        q3.push(i);

    reverseFirstK(q3, 5);

    cout << "K = 5: ";
    print(q3);

    queue<int> q4;

    for (int i = 1; i <= 5; i++)
        q4.push(i);

    reverseFirstK(q4, 10);

    cout << "K = 10: ";
    print(q4);

    return 0;
}
