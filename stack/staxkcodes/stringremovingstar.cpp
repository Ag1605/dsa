#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to remove stars from the string
    string removeStars(string s)
    {

        // Works like a stack
        string ans;

        for (char ch : s)
        {

            // If current character is '*'
            // remove the last inserted character
            if (ch == '*')
            {
                ans.pop_back();
            }
            else
            {
                // Otherwise add current character
                ans.push_back(ch);
            }
        }

        return ans;
    }
};

int main()
{

    Solution obj;

    string s;
    cin >> s;

    cout << obj.removeStars(s);

    return 0;
}