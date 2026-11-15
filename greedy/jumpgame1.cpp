
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {

        int n = nums.size();

        // Stores the farthest index we can reach.
        int maxReach = 0;

        // Traverse the array from left to right.
        for (int i = 0; i < n; i++) {

            // Step 1: Check whether the current index is reachable.
            // If i is greater than maxReach, we are stuck.
            if (i > maxReach) {
                return false;
            }

            // Step 2: Update the farthest reachable index.
            // From index i, we can jump up to i + nums[i].
            maxReach = max(maxReach, i + nums[i]);

            // Step 3: Check whether we can reach the last index.
            if (maxReach >= n - 1) {
                return true;
            }
        }

        // If we complete the loop, the last index is reachable.
        return true;
    }
};

int main() {

    // Each element represents the maximum jump length
    // from that particular index.
    vector<int> nums = {2, 3, 1, 1, 4};

    Solution obj;

    bool result = obj.canJump(nums);

    if (result) {
        cout << "Last index is reachable." << endl;
    }
    else {
        cout << "Last index is not reachable." << endl;
    }

    return 0;
}
