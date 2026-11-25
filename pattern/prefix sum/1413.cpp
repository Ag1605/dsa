
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    int minStartValue(vector<int>& nums) {

        // Stores the current running sum
        int sum = 0;

        // Stores the minimum prefix sum
        // Initially 0 because we consider
        // the sum before processing any element
        int minSum = 0;

        // Traverse the array
        for (int i = 0; i < nums.size(); i++) {

            // Calculate the running sum
            sum = sum + nums[i];

            // Update the minimum prefix sum
            if (sum < minSum) {
                minSum = sum;
            }
        }

        // Find the minimum positive starting value
        //
        // If minimum prefix sum is -4,
        // we need at least 5 to keep the sum >= 1
        //
        // startValue = 1 - minSum
        //
        // max(1, ...) ensures the starting value
        // is always at least 1
        return max(1, 1 - minSum);
    }
};

int main() {

    // Input array
    vector<int> nums = {-3, 2, -3, 4, 2};

    // Create Solution object
    Solution obj;

    // Find the minimum starting value
    int result = obj.minStartValue(nums);

    // Print the answer
    cout << "Minimum Start Value: " << result << endl;

    return 0;
}
