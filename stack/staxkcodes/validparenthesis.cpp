#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {

        stack<char> st;

        // Traverse each character
        for (char ch : s)
        {

            // If opening bracket, push into stack
            if (ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch);
            }

            // If closing bracket
            else
            {

                // No matching opening bracket
                if (st.empty())
                    return false;

                // Check if brackets match
                if ((ch == ')' && st.top() == '(') ||
                    (ch == ']' && st.top() == '[') ||
                    (ch == '}' && st.top() == '{'))
                {

                    // Matching bracket found
                    st.pop();
                }
                else
                {
                    // Mismatched bracket
                    return false;
                }
            }
        }

        // If stack is empty, all brackets matched
        return st.empty();
    }
};

int main()
{

    Solution obj;

    string s;
    cin >> s;

    if (obj.isValid(s))
        cout << "true";
    else
        cout << "false";

    return 0;
}