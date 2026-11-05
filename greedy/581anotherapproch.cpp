
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {

        int n = nums.size();

        // maxm stores the maximum element seen so far
        // while traversing from left to right
        int maxm = INT_MIN;

        // mini stores the minimum element seen so far
        // while traversing from right to left
        int mini = INT_MAX;

        // l = starting index of unsorted subarray
        // r = ending index of unsorted subarray
        int l = -1;
        int r = -1;

        // ------------------------------------------------
        // STEP 1: Traverse from RIGHT to LEFT
        // Find the LEFT boundary
        // ------------------------------------------------

        for (int i = n - 1; i >= 0; i--) {

            // If current element is greater than
            // the minimum element found on its right,
            // it is in the wrong position.
            if (nums[i] > mini) {
                l = i;
            }

            // Update minimum element
            mini = min(mini, nums[i]);
        }

        // ------------------------------------------------
        // STEP 2: Traverse from LEFT to RIGHT
        // Find the RIGHT boundary
        // ------------------------------------------------

        for (int i = 0; i < n; i++) {

            // If current element is smaller than
            // the maximum element found on its left,
            // it is in the wrong position.
            if (nums[i] < maxm) {
                r = i;
            }

            // Update maximum element
            maxm = max(maxm, nums[i]);
        }

        // ------------------------------------------------
        // STEP 3: Check if array is already sorted
        // ------------------------------------------------

        if (l == -1) {
            return 0;
        }

        // ------------------------------------------------
        // STEP 4: Calculate shortest unsorted subarray
        // ------------------------------------------------

        return r - l + 1;
    }
};

int main() {

    // Input array
    vector<int> nums = {2, 6, 4, 8, 10, 9, 15};

    // Create object
    Solution obj;

    // Call function
    int result = obj.findUnsortedSubarray(nums);

    // Print result
    cout << "Shortest unsorted subarray length: "
         << result << endl;

    return 0;
}
