#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s)
{
}

int main()
{
    cout << isValid("()") << endl;
    cout << isValid("()[]{}") << endl;
    cout << isValid("(]") << endl;
    cout << isValid("([)]") << endl;
    cout << isValid("{[]}") << endl;
    cout << isValid("") << endl;
    cout << isValid("(({") << endl;
    return 0;
}
