#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // --------------------------------------------------
        // unordered_set stores the unique characters
        // present in the current sliding window.
        // --------------------------------------------------
        unordered_set<char> st;

        // Left pointer of the sliding window
        int left = 0;

        // Stores the length of the longest valid substring
        int ans = 0;

        // --------------------------------------------------
        // Expand the window using the right pointer.
        // --------------------------------------------------
        for (int right = 0; right < s.size(); right++)
        {
            // --------------------------------------------------
            // If the current character already exists,
            // shrink the window until it becomes unique.
            // --------------------------------------------------
            while (st.count(s[right]))
            {
                // Remove the leftmost character
                st.erase(s[left]);

                // Move left pointer
                left++;
            }

            // --------------------------------------------------
            // Add the current character to the window.
            // --------------------------------------------------
            st.insert(s[right]);

            // --------------------------------------------------
            // Current window contains all unique characters.
            // Update the maximum length.
            // --------------------------------------------------
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    string s = "abcabcbb";

    cout << "Length of Longest Substring = "
         << obj.lengthOfLongestSubstring(s);

    return 0;
}