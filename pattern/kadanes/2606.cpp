
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:

    int maximumCostSubstring(string s, string chars, vector<int>& vals) {

        // ----------------------------------
        // Step 1: Create the character cost array
        // ----------------------------------

        // cost[i] stores the cost of character
        // whose alphabet index is i
        vector<int> cost(26);

        // Assign default alphabet values
        // a = 1, b = 2, c = 3, ..., z = 26
        for (int i = 0; i < 26; i++) {
            cost[i] = i + 1;
        }

        // ----------------------------------
        // Step 2: Update custom character costs
        // ----------------------------------

        // chars contains characters whose costs
        // are different from the default values
        for (int i = 0; i < chars.size(); i++) {

            // Convert character into an index
            // Example: 'a' - 'a' = 0
            //         'c' - 'a' = 2
            int index = chars[i] - 'a';

            // Replace default cost with custom cost
            cost[index] = vals[i];
        }

        // ----------------------------------
        // Step 3: Apply Kadane's Algorithm
        // ----------------------------------

        // Maximum substring cost ending
        // at the current index
        int currentSum = 0;

        // Maximum substring cost found so far
        // We initialize it with 0 because
        // an empty substring is allowed
        int maxSum = 0;

        // Traverse the string
        for (int i = 0; i < s.size(); i++) {

            // Get the cost of the current character
            int value = cost[s[i] - 'a'];

            // Either:
            // 1. Start a new substring from this character
            // 2. Extend the previous substring
            currentSum = max(value, currentSum + value);

            // Update the maximum cost found so far
            maxSum = max(maxSum, currentSum);
        }

        // Return the maximum substring cost
        return maxSum;
    }
};

// ----------------------------------
// Main function
// ----------------------------------

int main() {

    // Input string
    string s = "adaa";

    // Characters having custom costs
    string chars = "d";

    // Custom cost of character 'd'
    vector<int> vals = {-1000};

    // Create Solution object
    Solution obj;

    // Find maximum substring cost
    int result = obj.maximumCostSubstring(s, chars, vals);

    // Print the result
    cout << "Maximum Cost: " << result << endl;

    return 0;
}
