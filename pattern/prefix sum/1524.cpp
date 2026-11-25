
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {

        // Required modulo value
        const int MOD = 1000000007;

        // Current prefix sum
        int sum = 0;

        // Total number of odd-sum subarrays
        long long count = 0;

        // Frequency of even prefix sums
        // Initially, the empty prefix sum is 0 (even)
        long long evenCount = 1;

        // Frequency of odd prefix sums
        long long oddCount = 0;

        // Traverse the array
        for (int i = 0; i < arr.size(); i++) {

            // Update prefix sum
            sum += arr[i];

            // Check whether current prefix sum is odd
            if (sum % 2 != 0) {

                // Odd prefix - Even prefix = Odd subarray
                // Every previous even prefix creates
                // one odd-sum subarray ending at i.
                count += evenCount;

                // Store current odd prefix
                oddCount++;

            } else {

                // Even prefix - Odd prefix = Odd subarray
                // Every previous odd prefix creates
                // one odd-sum subarray ending at i.
                count += oddCount;

                // Store current even prefix
                evenCount++;
            }

            // Keep answer within the required modulo
            count %= MOD;
        }

        return count;
    }
};

int main() {

    Solution obj;

    vector<int> arr = {1, 3, 5};

    int result = obj.numOfSubarrays(arr);

    cout << "Number of odd-sum subarrays: "
         << result << endl;

    return 0;
}
