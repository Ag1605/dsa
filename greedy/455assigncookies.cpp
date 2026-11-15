
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        // Step 1: Sort both arrays in ascending order.
        // g = Greed factor of children.
        // s = Size of available cookies.
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        // Step 2: Initialize two pointers.
        int i = 0;  // Pointer for children.
        int j = 0;  // Pointer for cookies.

        int count = 0;  // Number of satisfied children.

        // Step 3: Traverse both arrays.
        while (i < g.size() && j < s.size()) {

            // Check whether the current cookie
            // is large enough for the current child.
            if (s[j] >= g[i]) {

                // Cookie satisfies the child.
                count++;

                // Move to the next child.
                i++;

                // Move to the next cookie.
                j++;
            }
            else {

                // Cookie is too small.
                // Try the next bigger cookie.
                j++;
            }
        }

        // Step 4: Return maximum satisfied children.
        return count;
    }
};

int main() {

    // Greed factors of children.
    vector<int> g = {1, 2, 3};

    // Available cookie sizes.
    vector<int> s = {1, 1};

    Solution obj;

    int result = obj.findContentChildren(g, s);

    cout << "Maximum satisfied children: " << result << endl;

    return 0;
}
