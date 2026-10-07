#include <iostream>
#include <stack>
#include <string>
using namespace std;

int longestValidParentheses(string s)
{
    stack<int> st;
    st.push(-1);

    int ans = 0;

    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else
        {
            st.pop();

            if (st.empty())
            {
                st.push(i);
            }
            else
            {
                int len = i - st.top();
                if (len > ans)
                    ans = len;
            }
        }
    }

    return ans;
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
