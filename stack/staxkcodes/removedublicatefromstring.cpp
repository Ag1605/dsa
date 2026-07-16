#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeDuplicates(string s)
    {

        stack<char> st;

        // Traverse the string
        for (char ch : s)
        {

            // If current character is same as stack top,
            // remove the duplicate
            if (!st.empty() && st.top() == ch)
            {
                st.pop();
            }
            else
            {
                // Otherwise push the current character
                st.push(ch);
            }
        }

        string ans = "";

        // Convert stack into a string
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        // Characters are in reverse order,
        // so reverse the string
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{

    Solution obj;

    string s;
    cin >> s;

    cout << obj.removeDuplicates(s);

    return 0;
}