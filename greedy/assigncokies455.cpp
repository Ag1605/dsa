
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
// greedy sortingand two pointers approach
        // Step 1: Sort greed factors of children
        // Smallest greed factor comes first
        sort(g.begin(), g.end());

        // Step 2: Sort cookie sizes
        // Smallest cookie comes first
        sort(s.begin(), s.end());

        // i = pointer for children
        // j = pointer for cookies
        int i = 0;
        int j = 0;

        // Step 3: Traverse both arrays
        while (i < g.size() && j < s.size()) {

            // Check whether the current cookie
            // is sufficient for the current child
            if (s[j] >= g[i]) {

                // Child is satisfied
                // Move to the next child
                i++;
            }

            // Move to the next cookie
            // Whether the cookie satisfies the child or not
            j++;
        }

        // i represents the total number of satisfied children
        return i;
    }
};

int main() {

    // Greed factor of each child
    vector<int> g = {1, 2, 3};

    // Available cookie sizes
    vector<int> s = {1, 1};

    Solution obj;

    // Call the function
    int result = obj.findContentChildren(g, s);

    // Print the answer
    cout << "Maximum satisfied children: " << result << endl;

    return 0;
}
