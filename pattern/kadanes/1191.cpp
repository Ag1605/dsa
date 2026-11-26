
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    int kConcatenationMaxSum(vector<int>& arr, int k) {

        // Required modulo value
        const long long MOD = 1000000007;

        // Size of the original array
        int n = arr.size();

        // ----------------------------------
        // Step 1: Calculate total array sum
        // ----------------------------------

        // Sum of one complete copy of arr
        long long totalSum = 0;

        for (int i = 0; i < n; i++) {
            totalSum += arr[i];
        }

        // ----------------------------------
        // Step 2: Apply Kadane's Algorithm
        // ----------------------------------

        // Current maximum subarray sum
        // ending at the current index
        long long currentSum = 0;

        // Maximum subarray sum found so far
        // 0 is allowed because an empty subarray
        // can be considered
        long long maxSum = 0;

        // If k == 1, process only one copy
        // Otherwise, process two copies
        int copies = (k == 1) ? 1 : 2;

        // Traverse one or two copies
        // without creating a new concatenated array
        for (int i = 0; i < n * copies; i++) {

            // Use modulo to access the original array
            // After reaching the end, start again
            // from index 0
            int value = arr[i % n];

            // Kadane's Algorithm:
            // Either extend the previous subarray
            // or start a new subarray
            currentSum = max(0LL, currentSum + value);

            // Update the maximum subarray sum
            maxSum = max(maxSum, currentSum);
        }

        // ----------------------------------
        // Step 3: Handle k == 1
        // ----------------------------------

        // Only one copy of the array exists
        // So Kadane's result is the final answer
        if (k == 1) {
            return maxSum % MOD;
        }

        // ----------------------------------
        // Step 4: Handle additional copies
        // ----------------------------------

        // If total sum of one array is positive,
        // every additional complete copy
        // can increase the maximum subarray sum
        if (totalSum > 0) {

            // We already processed two copies
            // Add the sum of remaining k - 2 copies
            maxSum += (long long)(k - 2) * totalSum;
        }

        // Return the answer modulo 10^9 + 7
        return maxSum % MOD;
    }
};

// ----------------------------------
// Main function
// ----------------------------------

int main() {

    // Input array
    vector<int> arr = {1, 2};

    // Number of concatenations
    int k = 3;

    // Create Solution object
    Solution obj;

    // Calculate maximum concatenation sum
    int result = obj.kConcatenationMaxSum(arr, k);

    // Print the result
    cout << "Maximum Sum: " << result << endl;

    return 0;
}
