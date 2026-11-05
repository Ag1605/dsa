
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {

        // Modulo value to prevent integer overflow
        const int MOD = 1e9 + 7;

        // Step 1: Sort the array
        // This allows us to use two pointers
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Step 2: Precompute powers of 2
        // power[i] = 2^i % MOD

        vector<int> power(n);

        power[0] = 1;

        for (int i = 1; i < n; i++) {

            // Calculate the next power of 2
            power[i] = (2LL * power[i - 1]) % MOD;
        }

        // Step 3: Initialize two pointers
        int left = 0;
        int right = n - 1;

        // Stores the total number of valid subsequences
        int ans = 0;

        // Step 4: Traverse using two pointers
        while (left <= right) {

            // Check whether minimum + maximum <= target
            if (nums[left] + nums[right] <= target) {

                // The smallest element is fixed.
                // Every element between left and right
                // can either be selected or not selected.

                // Number of combinations = 2^(right-left)
                ans = (ans + power[right - left]) % MOD;

                // Move left pointer to the next element
                left++;
            }
            else {

                // Maximum element is too large.
                // Decrease right to try a smaller maximum.
                right--;
            }
        }

        // Step 5: Return the total count
        return ans;
    }
};

int main() {

    // Input array
    vector<int> nums = {3, 5, 6, 7};

    // Given target
    int target = 9;

    // Create Solution object
    Solution obj;

    // Call the function
    int result = obj.numSubseq(nums, target);

    // Print the answer
    cout << "Number of valid subsequences: "
         << result << endl;

    return 0;
}
