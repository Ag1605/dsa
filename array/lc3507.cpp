#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {

        // Stores the number of merge operations performed
        int operations = 0;

        // Continue until the array becomes non-decreasing
        while (true) {

            bool sorted = true;

            // STEP 1: Check whether the array is sorted
            // Non-decreasing means nums[i] >= nums[i - 1]
            for (int i = 1; i < nums.size(); i++) {

                // If the current element is smaller than
                // the previous element, the array is unsorted
                if (nums[i] < nums[i - 1]) {
                    sorted = false;
                    break;
                }
            }

            // If the array is sorted, return the operation count
            if (sorted) {
                return operations;
            }

            // STEP 2: Find the adjacent pair with the minimum sum
            int minSum = INT_MAX;

            // Stores the starting index of the minimum-sum pair
            int index = 0;

            // Check every adjacent pair
            for (int i = 0; i < nums.size() - 1; i++) {

                // Calculate the sum of two adjacent elements
                int sum = nums[i] + nums[i + 1];

                // Update only when the sum is strictly smaller.
                // This keeps the leftmost pair if sums are equal.
                if (sum < minSum) {
                    minSum = sum;
                    index = i;
                }
            }

            // STEP 3: Merge the selected pair
            // Replace the first element with their sum
            nums[index] = minSum;

            // Remove the second element of the pair
            nums.erase(nums.begin() + index + 1);

            // Count this merge operation
            operations++;
        }
    }
};

int main() {

    // Example input
    vector<int> nums = {5, 2, 3, 1};

    Solution sol;

    // Find the minimum number of pair-removal operations
    int result = sol.minimumPairRemoval(nums);

    cout << "Minimum operations: " << result << endl;

    // Print the final array after all operations
    cout << "Final array: ";

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    cout << endl;

    return 0;
}