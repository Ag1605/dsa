#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Recursive function to remove all occurrences of character c
    void solve(string &s, char c, int index)
    {

        // Base case
        // If index reaches the end of the string, stop recursion
        if (index == s.size())
            return;

        // If current character matches c
        if (s[index] == c)
        {

            // Remove the character
            s.erase(index, 1);

            // Stay at the same index because characters shift left
            solve(s, c, index);
        }
        else
        {

            // Move to the next character
            solve(s, c, index + 1);
        }
    }

    // Function to remove all occurrences of c
    void removeCharacter(string &s, char c)
    {

        solve(s, c, 0);
    }
};

int main()
{

    Solution obj;

    string s;
    char c;

    cin >> s;
    cin >> c;

    obj.removeCharacter(s, c);

    cout << s;

    return 0;
}