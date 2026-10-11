/*
Ejercicio feo, pero ya se hizo.
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s)
{

    stack<char> stack;

    for (int i = 0; i < s.size(); i++) {

        if (s[i] == '(' || s[i] ==  '[' || s[i] ==  '{') {
            stack.push(s[i]);
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {

            if (stack.empty()) {
                return false;
            }

            if ((stack.top() == '(' && s[i] == ')') || (stack.top() == '[' && s[i] == ']') || stack.top() == '{' && s[i] == '}') {
                stack.pop();
            }
            else {
                return false;

            }

        }

    }

    
    return stack.empty();
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
