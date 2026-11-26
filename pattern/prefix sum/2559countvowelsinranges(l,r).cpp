
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    // Function to answer all range queries
    vector<int> vowelStrings(string s, vector<vector<int>>& queries) {

        // Length of the string
        int n = s.size();

        // Prefix sum array
        // prefix[i] stores the number of vowels
        // present from index 0 to index i
        vector<int> prefix(n, 0);

        // Lambda function to check whether
        // a character is a vowel or not
        auto isVowel = [](char ch) {

            return ch == 'a' || ch == 'e' ||
                   ch == 'i' || ch == 'o' ||
                   ch == 'u' ||
                   ch == 'A' || ch == 'E' ||
                   ch == 'I' || ch == 'O' ||
                   ch == 'U';
        };

        // ----------------------------------
        // Step 1: Build the prefix sum array
        // ----------------------------------

        for (int i = 0; i < n; i++) {

            // Copy the previous prefix sum
            if (i > 0) {
                prefix[i] = prefix[i - 1];
            }

            // If current character is a vowel,
            // increase the prefix sum by 1
            if (isVowel(s[i])) {
                prefix[i]++;
            }
        }

        // Stores answers for all queries
        vector<int> ans;

        // ----------------------------------
        // Step 2: Answer each query
        // ----------------------------------

        for (int i = 0; i < queries.size(); i++) {

            // Starting index of the range
            int l = queries[i][0];

            // Ending index of the range
            int r = queries[i][1];

            int count;

            // If range starts from index 0,
            // directly use prefix[r]
            if (l == 0) {
                count = prefix[r];
            }

            // Otherwise subtract the prefix sum
            // before the starting index
            else {
                count = prefix[r] - prefix[l - 1];
            }

            // Store the answer for this query
            ans.push_back(count);
        }

        // Return answers of all queries
        return ans;
    }
};

// ----------------------------------
// Main function
// ----------------------------------

int main() {

    // Create an object of Solution class
    Solution obj;

    // Input string
    string s = "abciiidef";

    // Queries:
    // Each query contains [left, right]
    vector<vector<int>> queries = {
        {0, 2},
        {1, 4},
        {3, 7}
    };

    // Call the function
    vector<int> result = obj.vowelStrings(s, queries);

    // Print the result
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}
