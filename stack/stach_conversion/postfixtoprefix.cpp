#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string postfixToPrefix(string s)
    {
        stack<string> st;

        // Traverse the postfix expression from left to right
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

                // Prefix: operator comes first
                string temp = string(1, ch) + op1 + op2;

                // Push the new prefix expression
                st.push(temp);
            }
        }

        // Final prefix expression
        return st.top();
    }
};

int main()
{
    Solution obj;

    string postfix;
    cin >> postfix;

    cout << obj.postfixToPrefix(postfix);

    return 0;
}