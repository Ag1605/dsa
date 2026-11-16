
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();

        // Stores the minimum number of jumps required.
        int jumps = 0;

        // Current boundary of the range reachable
        // using the current number of jumps.
        int currentEnd = 0;

        // Farthest index we can reach from the current range.
        int farthest = 0;

        // We stop at n - 1 because we don't need
        // to jump after reaching the last index.
        for (int i = 0; i < n - 1; i++) {

            // Step 1: Find the farthest index reachable
            // from the current index.
            farthest = max(farthest, i + nums[i]);

            // Step 2: Check whether we have reached
            // the end of the current jump range.
            if (i == currentEnd) {

                // We must take another jump
                // to move beyond the current range.
                jumps++;

                // Step 3: Update the boundary for the next jump.
                // The next jump can reach up to farthest.
                currentEnd = farthest;
            }
        }

        // Step 4: Return the minimum number of jumps.
        return jumps;
    }
};

int main() {

    // Each element represents the maximum jump
    // length from that index.
    vector<int> nums = {2, 3, 1, 1, 4};

    Solution obj;

    int result = obj.jump(nums);

    cout << "Minimum number of jumps: " << result << endl;

    return 0;
}
