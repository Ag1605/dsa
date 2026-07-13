#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string prefixToPostfix(string s)
    {
        stack<string> st;

        // Traverse the prefix expression from right to left
        for (int i = s.size() - 1; i >= 0; i--)
        {
            char ch = s[i];

            // If operand, push it as a string
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

                // Postfix = operand1 operand2 operator
                string temp = op1 + op2 + ch;

                // Push the new postfix expression
                st.push(temp);
            }
        }

        // Final postfix expression
        return st.top();
    }
};

int main()
{
    Solution obj;

    string prefix;
    cin >> prefix;

    cout << obj.prefixToPostfix(prefix);

    return 0;
}