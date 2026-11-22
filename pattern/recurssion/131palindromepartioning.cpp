
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    // Stores all valid palindrome partitions
    vector<vector<string>> ans;

    // Stores the current partition
    vector<string> path;


    // STEP 1: Check whether a substring is a palindrome
    bool isPalindrome(string& s, int left, int right)
    {
        // Compare characters from both ends
        while (left < right)
        {
            // If characters do not match,
            // the substring is not a palindrome.
            if (s[left] != s[right])
            {
                return false;
            }

            // Move left pointer forward
            // Move right pointer backward
            left++;
            right--;
        }

        // All characters matched
        // Therefore, the substring is a palindrome.
        return true;
    }


    // STEP 2: Backtracking function
    //
    // start represents the starting index
    // of the remaining string that we need to partition.
    void backtrack(string& s, int start)
    {
        // BASE CASE:
        //
        // If start reaches the end of the string,
        // it means we have successfully partitioned
        // the entire string into palindrome substrings.
        if (start == s.size())
        {
            // Store the current valid partition
            ans.push_back(path);

            return;
        }


        // STEP 3: Try every possible ending index
        //
        // We start from 'start' and expand the substring
        // one character at a time.
        for (int i = start; i < s.size(); i++)
        {
            // Check whether substring s[start...i]
            // is a palindrome.
            if (isPalindrome(s, start, i))
            {
                // STEP 4: CHOOSE
                //
                // Extract the palindrome substring
                // and add it to our current partition.
                //
                // substr(start, length)
                // length = i - start + 1
                path.push_back(s.substr(start, i - start + 1));


                // STEP 5: EXPLORE
                //
                // Now process the remaining string.
                // Start from i + 1 because the substring
                // from start to i has already been selected.
                backtrack(s, i + 1);


                // STEP 6: UNDO (BACKTRACK)
                //
                // Remove the last selected substring.
                // This allows us to try another partition.
                path.pop_back();
            }
        }
    }


    // Main function called by LeetCode
    vector<vector<string>> partition(string s)
    {
        // Start partitioning from index 0
        backtrack(s, 0);

        return ans;
    }
};


int main()
{
    Solution obj;

    // Input string
    string s = "aab";

    // Generate all palindrome partitions
    vector<vector<string>> result = obj.partition(s);


    // Print all valid partitions
    cout << "Palindrome partitions:" << endl;

    for (int i = 0; i < result.size(); i++)
    {
        cout << "[ ";

        for (int j = 0; j < result[i].size(); j++)
        {
            cout << "\"" << result[i][j] << "\" ";

        }

        cout << "]" << endl;
    }

    return 0;
}
