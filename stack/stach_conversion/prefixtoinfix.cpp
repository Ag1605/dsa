#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string prefixToInfix(string s)
    {
        stack<string> st;

        // Traverse the prefix expression from right to left
        for (int i = s.size() - 1; i >= 0; i--)
        {
            char ch = s[i];

            // If operand, push it into the stack
            if (isalnum(ch))
            {
                st.push(string(1, ch));
            }

            // If operator
            else
            {
                // First operand
                string op1 = st.top();
                st.pop();

                // Second operand
                string op2 = st.top();
                st.pop();

                // Form the infix expression
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

    string prefix;
    cin >> prefix;

    cout << obj.prefixToInfix(prefix);

    return 0;
}