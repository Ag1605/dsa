#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<string> &ans,
               string &current,
               int open,
               int close,
               int n)
    {

        // Base Case:
        // If the current string has length 2*n,
        // it is a valid parentheses combination.
        if (current.size() == 2 * n)
        {
            ans.push_back(current);
            return;
        }

        // Choice 1: Add '('
        // We can add '(' only if we haven't used all n opening brackets.
        if (open < n)
        {

            current.push_back('('); // Choose

            solve(ans, current, open + 1, close, n); // Explore

            current.pop_back(); // Undo (Backtrack)
        }

        // Choice 2: Add ')'
        // We can add ')' only if there are more '(' than ')'
        if (close < open)
        {

            current.push_back(')'); // Choose

            solve(ans, current, open, close + 1, n); // Explore

            current.pop_back(); // Undo (Backtrack)
        }
    }

    vector<string> generateParenthesis(int n)
    {

        vector<string> ans;

        // Stores the current combination
        string current = "";

        solve(ans, current, 0, 0, n);

        return ans;
    }
};

int main()
{

    Solution obj;

    int n;
    cin >> n;

    vector<string> ans = obj.generateParenthesis(n);

    for (string s : ans)
    {
        cout << s << endl;
    }

    return 0;
}