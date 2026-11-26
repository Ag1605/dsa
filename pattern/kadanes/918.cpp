
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    int maxSubarraySumCircular(vector<int>& nums) {

        // ----------------------------------
        // Step 1: Initialize variables
        // ----------------------------------

        // Maximum subarray sum ending
        // at the current index
        int maxEnding = 0;

        // Minimum subarray sum ending
        // at the current index
        int minEnding = 0;

        // Maximum subarray sum found so far
        int maxSum = nums[0];

        // Minimum subarray sum found so far
        int minSum = nums[0];

        // Sum of all elements in the array
        int totalSum = 0;

        // ----------------------------------
        // Step 2: Traverse the array
        // ----------------------------------

        for (int i = 0; i < nums.size(); i++) {

            // Calculate the total sum
            totalSum += nums[i];

            // ----------------------------------
            // Kadane's Algorithm for maximum sum
            // ----------------------------------

            // Either:
            // 1. Start a new subarray from nums[i]
            // 2. Extend the previous maximum subarray
            maxEnding = max(nums[i], maxEnding + nums[i]);

            // Update the maximum subarray sum
            maxSum = max(maxSum, maxEnding);

            // ----------------------------------
            // Kadane's Algorithm for minimum sum
            // ----------------------------------

            // Either:
            // 1. Start a new subarray from nums[i]
            // 2. Extend the previous minimum subarray
            minEnding = min(nums[i], minEnding + nums[i]);

            // Update the minimum subarray sum
            minSum = min(minSum, minEnding);
        }

        // ----------------------------------
        // Step 3: Handle all-negative array
        // ----------------------------------

        // If every element is negative,
        // maxSum will also be negative.
        //
        // totalSum - minSum would become 0,
        // which represents an empty subarray.
        //
        // The problem requires a non-empty subarray,
        // so return the normal maximum sum.
        if (maxSum < 0) {
            return maxSum;
        }

        // ----------------------------------
        // Step 4: Calculate circular maximum
        // ----------------------------------

        // Circular maximum subarray sum:
        //
        // Total array sum - Minimum subarray sum
        //
        // This removes the minimum subarray
        // and keeps the remaining circular elements.
        int circularSum = totalSum - minSum;

        // Return the maximum between:
        // 1. Normal maximum subarray sum
        // 2. Circular maximum subarray sum
        return max(maxSum, circularSum);
    }
};

// ----------------------------------
// Main function
// ----------------------------------

int main() {

    // Input circular array
    vector<int> nums = {5, -3, 5};

    // Create Solution object
    Solution obj;

    // Calculate maximum circular subarray sum
    int result = obj.maxSubarraySumCircular(nums);

    // Print the answer
    cout << "Maximum Circular Sum: " << result << endl;

    return 0;
}
