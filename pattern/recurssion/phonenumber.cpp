#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<string> &ans,
               string &current,
               string &digits,
               unordered_map<char, string> &mp,
               int index)
    {
        // Base Case:
        // If we have processed all digits,
        // store the current combination.
        if (index == digits.size())
        {
            ans.push_back(current);
            return;
        }

        // Get all letters corresponding to the current digit
        string letters = mp[digits[index]];

        // Try every possible letter
        for (char ch : letters)
        {

            // Choose
            current.push_back(ch);

            // Explore the next digit
            solve(ans, current, digits, mp, index + 1);

            // Undo (Backtrack)
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {

        // If input is empty, return an empty list
        if (digits.empty())
            return {};

        // Digit to letters mapping
        unordered_map<char, string> mp;

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        vector<string> ans;
        string current = "";

        solve(ans, current, digits, mp, 0);

        return ans;
    }
};

int main()
{

    Solution obj;

    string digits;
    cin >> digits;

    vector<string> ans = obj.letterCombinations(digits);

    for (string s : ans)
    {
        cout << s << " ";
    }

    return 0;
}