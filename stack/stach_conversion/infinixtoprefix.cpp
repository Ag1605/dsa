class Solution
{
public:
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
        // Step 1: Reverse the expression
        reverse(s.begin(), s.end());

        // Step 2: Swap brackets
        for (char &ch : s)
        {
            if (ch == '(')
                ch = ')';
            else if (ch == ')')
                ch = '(';
        }

        stack<char> st;
        string ans = "";

        // Step 3: Convert modified infix to postfix
        for (char ch : s)
        {
            if (isalnum(ch))
            {
                ans += ch;
            }
            else if (ch == '(')
            {
                st.push(ch);
            }
            else if (ch == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }

                st.pop();
            }
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

        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        // Step 4: Reverse postfix to get prefix
        reverse(ans.begin(), ans.end());

        return ans;
    }
};