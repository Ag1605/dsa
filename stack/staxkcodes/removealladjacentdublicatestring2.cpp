#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeDuplicates(string s, int k)
    {

        // Stack stores:
        // {character, frequency}
        stack<pair<char, int>> st;

        // Traverse the string
        for (char ch : s)
        {

            // New character
            if (st.empty() || st.top().first != ch)
            {
                st.push({ch, 1});
            }
            else
            {

                // Same character as top
                st.top().second++;

                // If frequency becomes k,
                // remove all k characters
                if (st.top().second == k)
                {
                    st.pop();
                }
            }
        }

        string ans = "";

        // Build the answer from the stack
        while (!st.empty())
        {

            // Append character 'count' times
            ans.append(st.top().second, st.top().first);

            st.pop();
        }

        // Stack gives characters in reverse order
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{

    Solution obj;

    string s;
    int k;

    cin >> s;
    cin >> k;

    cout << obj.removeDuplicates(s, k);

    return 0;
}