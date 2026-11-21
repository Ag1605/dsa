#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string &s)
    {

        // Start pointers from both ends
        int left = 0;
        int right = s.size() - 1;

        // Compare characters until pointers meet
        while (left < right)
        {

            // If characters don't match, it's not a palindrome
            if (s[left] != s[right])
                return false;

            // Move pointers
            left++;
            right--;
        }

        // All characters matched
        return true;
    }
};

int main()
{

    Solution obj;

    string s;
    cin >> s;

    if (obj.isPalindrome(s))
        cout << "true";
    else
        cout << "false";

    return 0;
}