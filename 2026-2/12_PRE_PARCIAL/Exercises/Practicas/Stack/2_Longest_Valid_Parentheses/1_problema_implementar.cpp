#include <iostream>
#include <stack>
#include <string>
using namespace std;

int longestValidParentheses(string s)
{
}

int main()
{
    cout << longestValidParentheses("") << endl;
    cout << longestValidParentheses("()") << endl;
    cout << longestValidParentheses(")()())") << endl;
    cout << longestValidParentheses("()(()") << endl;
    cout << longestValidParentheses("()(())") << endl;
    cout << longestValidParentheses("((()))") << endl;
    cout << longestValidParentheses("())((())") << endl;
    return 0;
}
