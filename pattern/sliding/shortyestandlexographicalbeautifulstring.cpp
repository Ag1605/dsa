
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:

    string shortestBeautifulSubstring(string s, int k)
    {
        int n = s.size();

        // Left pointer represents starting position
        // of the current sliding window.
        int left = 0;

        // Stores the number of ones in current window.
        int count1 = 0;

        // Stores the shortest and lexicographically
        // smallest valid substring.
        string ans = "";

        // Move right pointer from left to right.
        for (int right = 0; right < n; right++)
        {
            // STEP 1:
            // If current character is '1',
            // increase the count of ones.
            if (s[right] == '1')
            {
                count1++;
            }

            // STEP 2:
            // If we have exactly k ones,
            // our current window is valid.
            if (count1 == k)
            {
                // STEP 3:
                // Remove all leading zeros.
                // This makes our substring shorter.
                while (s[left] == '0')
                {
                    left++;
                }

                // STEP 4:
                // Extract the current valid substring.
                // Length = right - left + 1.
                string curr = s.substr(left, right - left + 1);

                // STEP 5:
                // Update answer if:
                // 1. No previous answer exists.
                // 2. Current substring is shorter.
                // 3. Both have same length but current
                //    substring is lexicographically smaller.
                if (ans == "" ||
                    curr.size() < ans.size() ||
                    (curr.size() == ans.size() && curr < ans))
                {
                    ans = curr;
                }

                // STEP 6:
                // Remove the first '1' from the window.
                // This allows us to search for the next
                // valid substring.
                left++;

                // Since one '1' is removed,
                // decrease count1.
                count1--;
            }
        }

        // Return the best substring found.
        return ans;
    }
};


int main()
{
    Solution obj;

    string s = "100011001";
    int k = 3;

    // Find shortest beautiful substring.
    string answer = obj.shortestBeautifulSubstring(s, k);

    cout << "Answer: " << answer << endl;

    return 0;
}
