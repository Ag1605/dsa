#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to check whether the parentheses are valid
    bool isValid(string s)
    {
        //------------------------------------------------------
        // Stack stores opening brackets.
        //
        // Whenever we get a closing bracket,
        // we check whether it matches the top opening bracket.
        //------------------------------------------------------

        stack<char> st;

        //------------------------------------------------------
        // Traverse every character of the string
        //------------------------------------------------------

        for (char ch : s)
        {

            //--------------------------------------------------
            // Case 1 : Opening Bracket
            //
            // Simply push it into the stack.
            //--------------------------------------------------

            if (ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch);
            }

            //--------------------------------------------------
            // Case 2 : Closing Bracket
            //--------------------------------------------------

            else
            {

                //------------------------------------------------
                // If stack is empty,
                // there is no opening bracket available.
                //
                // Example:
                // ")("
                //------------------------------------------------

                if (st.empty())
                    return false;

                //------------------------------------------------
                // Check whether current closing bracket
                // matches the opening bracket
                // present at the top of the stack.
                //------------------------------------------------

                if ((ch == ')' && st.top() == '(') ||
                    (ch == ']' && st.top() == '[') ||
                    (ch == '}' && st.top() == '{'))
                {

                    //--------------------------------------------
                    // Correct pair found.
                    // Remove opening bracket from stack.
                    //--------------------------------------------

                    st.pop();
                }
                else
                {

                    //--------------------------------------------
                    // Wrong opening bracket.
                    //
                    // Example:
                    // "(]"
                    //--------------------------------------------

                    return false;
                }
            }
        }

        //------------------------------------------------------
        // If stack is empty,
        // every opening bracket found its partner.
        //
        // Otherwise some opening brackets
        // are still unmatched.gh
        //------------------------------------------------------

        return st.empty();
    }
};

int main()
{
    Solution obj;

    string s;

    cout << "Enter Parentheses String : ";

    cin >> s;

    if (obj.isValid(s))
        cout << "\nValid Parentheses";
    else
        cout << "\nInvalid Parentheses";

    return 0;
}