
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    // Recursive function to generate all valid binary strings
    void solve(int index, int n, string &s, vector<string> &ans)
    {
        // BASE CASE:
        // When index becomes n, we have generated
        // a binary string of the required length.
        if (index == n)
        {
            // Store the completed valid string
            ans.push_back(s);
            return;
        }

        // --------------------------------
        // CHOICE 1: Add '0'
        // --------------------------------

        // We can always add 0 because it never
        // creates consecutive 1s.
        s.push_back('0');

        // Move to the next index and generate
        // the remaining characters.
        solve(index + 1, n, s, ans);

        // BACKTRACKING:
        // Remove the last added character (0).
        // This restores the previous string so
        // that we can explore another possibility.
        s.pop_back();


        // --------------------------------
        // CHOICE 2: Add '1'
        // --------------------------------

        // Add 1 only when:
        // 1. The string is empty, OR
        // 2. The previous character is not 1.
        //
        // This condition prevents consecutive 1s.
        if (s.empty() || s.back() != '1')
        {
            // Add 1 to the current string
            s.push_back('1');

            // Recursively generate the remaining characters
            solve(index + 1, n, s, ans);

            // BACKTRACKING:
            // Remove the last added character (1)
            // before exploring another branch.
            s.pop_back();
        }
    }

    // Function to generate all valid binary strings
    vector<string> generateBinaryStrings(int n)
    {
        // Stores all valid binary strings
        vector<string> ans;

        // Initially, our binary string is empty
        string s = "";

        // Start recursion from index 0
        solve(0, n, s, ans);

        // Return all generated strings
        return ans;
    }
};

int main()
{
    Solution obj;

    int n;

    // Input the required length of binary strings
    cin >> n;

    // Generate all valid binary strings
    vector<string> ans = obj.generateBinaryStrings(n);

    // Print all generated strings
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}
