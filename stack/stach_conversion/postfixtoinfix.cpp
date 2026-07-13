#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string postfixToInfix(string s)
    {
        stack<string> st;

        // Traverse each character of postfix expression
        for (char ch : s)
        {
            // If operand, push it as a string
            if (isalnum(ch))
            {
                st.push(string(1, ch));
            }

            // If operator
            else
            {
                // Second operand
                string op2 = st.top();
                st.pop();

                // First operand
                string op1 = st.top();
                st.pop();

                // Form infix expression
                string temp = "(" + op1 + ch + op2 + ")";

                // Push the new expression back
                st.push(temp);
            }
        }

        // Final infix expression
        return st.top();
    }
};

int main()
{
    Solution obj;

    string postfix;
    cin >> postfix;

    cout << obj.postfixToInfix(postfix);

    return 0;
}