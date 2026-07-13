#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return precedence of operators
    int precedence(char ch)
    {
        if (ch == '^')
            return 3;

        if (ch == '*' || ch == '/')
            return 2;

        if (ch == '+' || ch == '-')
            return 1;

        return -1;
    }

    string infixToPrefix(string s)
    {
        // Step 1: Reverse the infix expression
        reverse(s.begin(), s.end());

        // Step 2: Swap '(' with ')' and vice versa
        for (char &ch : s)
        {
            if (ch == '(')
                ch = ')';
            else if (ch == ')')
                ch = '(';
        }

        stack<char> st;
        string ans = "";

        // Step 3: Convert reversed infix to postfix
        for (char ch : s)
        {
            // If operand, add directly
            if (isalnum(ch))
            {
                ans += ch;
            }

            // If opening bracket
            else if (ch == '(')
            {
                st.push(ch);
            }

            // If closing bracket
            else if (ch == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }

                st.pop(); // Remove '('
            }

            // If operator
            else
            {
                while (!st.empty() &&
                       st.top() != '(' &&
                       (precedence(st.top()) > precedence(ch) ||
                        (precedence(st.top()) == precedence(ch) && ch != '^')))
                {
                    ans += st.top();
                    st.pop();
                }

                st.push(ch);
            }
        }

        // Pop remaining operators
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        // Step 4: Reverse postfix to obtain prefix
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    Solution obj;

    string s;
    cin >> s;

    cout << obj.infixToPrefix(s);

    return 0;
}