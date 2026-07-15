#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {

        stack<char> st;

        // Push all characters into the stack
        for (char ch : s)
        {
            st.push(ch);
        }

        // Pop characters one by one and store them back
        // Since stack follows LIFO, the string gets reversed
        int i = 0;

        while (!st.empty())
        {
            s[i] = st.top();
            st.pop();
            i++;
        }
    }
};

int main()
{

    Solution obj;

    int n;
    cin >> n;

    vector<char> s(n);

    // Input characters
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    obj.reverseString(s);

    // Print reversed string
    for (char ch : s)
    {
        cout << ch << " ";
    }

    return 0;
}