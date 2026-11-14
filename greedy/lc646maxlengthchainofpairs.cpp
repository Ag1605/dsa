
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // Step 1: Comparator function.
    // Sort pairs in ascending order of their ending value.
    static bool comp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    int findLongestChain(vector<vector<int>>& pairs) {

        int n = pairs.size();

        // Handle empty input.
        if (n == 0) {
            return 0;
        }

        // Step 2: Sort all pairs by ending value.
        // We prefer pairs that finish earlier because
        // they leave more room for selecting future pairs.
        sort(pairs.begin(), pairs.end(), comp);

        // Step 3: Select the first pair.
        int count = 1;

        // Store the ending value of the last selected pair.
        int lastEnd = pairs[0][1];

        // Step 4: Traverse the remaining pairs.
        for (int i = 1; i < n; i++) {

            // Check whether the current pair can form a chain.
            // Current start must be strictly greater than
            // the ending value of the previous selected pair.
            if (pairs[i][0] > lastEnd) {

                // Select the current pair.
                count++;

                // Update the ending value.
                lastEnd = pairs[i][1];
            }
        }

        // Step 5: Return maximum chain length.
        return count;
    }
};

int main() {

    // Each pair is represented as {start, end}.
    vector<vector<int>> pairs = {
        {1, 2},
        {2, 3},
        {3, 4}
    };

    Solution obj;

    // Find the maximum length of the pair chain.
    int result = obj.findLongestChain(pairs);

    cout << "Maximum length of pair chain: "
         << result << endl;

    return 0;
}
