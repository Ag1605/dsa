
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    int getMaxLen(vector<int>& nums) {

        // Stores the length of the longest subarray
        // ending at the current index with a positive product
        int positive = 0;

        // Stores the length of the longest subarray
        // ending at the current index with a negative product
        int negative = 0;

        // Stores the maximum positive-product
        // subarray length found so far
        int result = 0;

        // Traverse the array
        for (int i = 0; i < nums.size(); i++) {

            // ----------------------------------
            // Case 1: Current number is positive
            // ----------------------------------
            if (nums[i] > 0) {

                // Positive product multiplied by positive
                // remains positive
                positive = positive + 1;

                // Negative product multiplied by positive
                // remains negative
                if (negative > 0) {
                    negative = negative + 1;
                }
            }

            // ----------------------------------
            // Case 2: Current number is negative
            // ----------------------------------
            else if (nums[i] < 0) {

                // Save the previous positive length
                // because we need it to calculate negative
                int oldPositive = positive;

                // Negative product multiplied by negative
                // becomes positive
                if (negative > 0) {
                    positive = negative + 1;
                }
                else {
                    // No previous negative-product subarray
                    // means we cannot form a positive product
                    positive = 0;
                }

                // Positive product multiplied by negative
                // becomes negative
                negative = oldPositive + 1;
            }

            // ----------------------------------
            // Case 3: Current number is zero
            // ----------------------------------
            else {

                // A zero product is neither positive
                // nor negative
                // So both subarrays must reset
                positive = 0;
                negative = 0;
            }

            // Update the maximum length
            // of a positive-product subarray
            result = max(result, positive);
        }

        // Return the longest positive-product subarray
        return result;
    }
};

int main() {

    // Input array
    vector<int> nums = {1, -2, -3, 4};

    // Create Solution object
    Solution obj;

    // Find maximum positive-product subarray length
    int result = obj.getMaxLen(nums);

    // Print the answer
    cout << "Maximum Length: " << result << endl;

    return 0;
}
