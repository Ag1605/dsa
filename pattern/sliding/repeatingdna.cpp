
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    vector<string> findRepeatedDnaSequences(string s)
    {
        // Store the size of the input string.
        int n = s.size();

        // Stores all repeated DNA sequences.
        vector<string> ans;

        // If string length is less than 10,
        // no substring of length 10 is possible.
        if (n < 10)
        {
            return ans;
        }

        // Hash map:
        // Key   = DNA substring of length 10
        // Value = Number of times it appears.
        unordered_map<string, int> freq;

        // Left pointer of the sliding window.
        int low = 0;

        // Move the right pointer through the string.
        for (int high = 0; high < n; high++)
        {
            // Calculate current window size.
            int windowSize = high - low + 1;

            // We need a fixed window of exactly 10 characters.
            if (windowSize == 10)
            {
                // Extract 10 characters starting from low.
                string sub = s.substr(low, 10);

                // Increase the frequency of this substring.
                freq[sub]++;

                // If frequency becomes 2,
                // this is the first time we have detected
                // that the substring is repeated.
                if (freq[sub] == 2)
                {
                    ans.push_back(sub);
                }

                // Move left pointer forward by one.
                // This removes the first character of
                // the current window.
                low++;
            }
        }

        // Return all repeated DNA sequences.
        return ans;
    }
};


int main()
{
    Solution obj;

    // Input DNA string.
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";

    // Find repeated DNA sequences.
    vector<string> res = obj.findRepeatedDnaSequences(s);

    // Print the result.
    cout << "Repeated DNA Sequences: ";

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    cout << endl;

    return 0;
}
