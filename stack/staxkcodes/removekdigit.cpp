#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {

        // Stack stores digits
        stack<char> st;

        // Traverse each digit
        for (char ch : num)
        {

            // Remove previous larger digits
            // to make the number as small as possible
            while (!st.empty() && k > 0 && st.top() > ch)
            {
                st.pop();
                k--;
            }

            // Push current digit
            st.push(ch);
        }

        // If removals are still left,
        // remove digits from the end
        while (k > 0)
        {
            st.pop();
            k--;
        }

        // Build answer from stack
        string ans = "";

        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        // Stack gives digits in reverse order
        reverse(ans.begin(), ans.end());

        // Remove leading zeros
        while (ans.size() > 1 && ans[0] == '0')
        {
            ans.erase(ans.begin());
        }

        // If all digits are removed
        if (ans.empty())
            return "0";

        return ans;
    }
};

int main()
{

    Solution obj;

    string num;
    int k;

    cin >> num;
    cin >> k;

    cout << obj.removeKdigits(num, k);

    return 0;
}