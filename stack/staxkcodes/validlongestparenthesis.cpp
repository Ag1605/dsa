#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the length of the longest valid parentheses substring
    int longestValidParentheses(string s)
    {

        //------------------------------------------------------
        // Stack stores indices, NOT characters.
        //
        // Why indices?
        // Because we need to calculate the length
        // of valid substrings.
        //------------------------------------------------------

        stack<int> st;

        //------------------------------------------------------
        // Push -1 initially.
        //
        // It acts as a base index before the string starts.
        //
        // Example:
        // "()"
        //
        // Length = 1 - (-1) = 2
        //------------------------------------------------------

        st.push(-1);

        //------------------------------------------------------
        // Stores maximum valid length found so far.
        //------------------------------------------------------

        int ans = 0;

        //------------------------------------------------------
        // Traverse the string
        //------------------------------------------------------

        for (int i = 0; i < s.size(); i++)
        {

            //--------------------------------------------------
            // If current character is '('
            //--------------------------------------------------

            if (s[i] == '(')
            {

                // Store its index
                st.push(i);
            }

            //--------------------------------------------------
            // Current character is ')'
            //--------------------------------------------------

            else
            {

                //------------------------------------------------
                // Remove one opening bracket
                //------------------------------------------------

                st.pop();

                //------------------------------------------------
                // If stack becomes empty,
                // current ')' cannot be matched.
                //
                // Make current index the new base.
                //------------------------------------------------

                if (st.empty())
                {

                    st.push(i);
                }

                //------------------------------------------------
                // Valid substring found
                //------------------------------------------------

                else
                {

                    //------------------------------------------------
                    // Length =
                    // Current Index - Index at Stack Top
                    //------------------------------------------------

                    ans = max(ans, i - st.top());
                }
            }
        }

        return ans;
    }
};

int main()
{

    Solution obj;

    string s = ")()())";

    cout << "String : " << s << endl;

    cout << "Longest Valid Parentheses Length = "
         << obj.longestValidParentheses(s);

    return 0;
}