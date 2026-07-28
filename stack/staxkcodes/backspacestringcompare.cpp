#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to build the final string after processing backspaces
    string build(string s)
    {

        // Works like a stack
        string ans;

        for (char ch : s)
        {

            // If current character is '#'
            if (ch == '#')
            {

                // Remove last character if string is not empty
                if (!ans.empty())
                    ans.pop_back();
            }
            else
            {

                // Otherwise insert current character
                ans.push_back(ch);
            }
        }

        return ans;
    }

    // Compare the final processed strings
    bool backspaceCompare(string s, string t)
    {

        return build(s) == build(t);
    }
};

int main()
{

    Solution obj;

    string s, t;

    cin >> s;
    cin >> t;

    if (obj.backspaceCompare(s, t))
        cout << "True";
    else
        cout << "False";

    return 0;
}