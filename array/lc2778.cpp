#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int sumOfSquares(vector<int>& nums) {

        // n = total number of elements in the array.
        //
        // Example:
        // nums = {1, 2, 3, 4}
        // n = 4
        int n = nums.size();

        // This will store the sum of squares
        // of all special elements.
        int sum = 0;


        // i represents the POSITION of an element.
        //
        // IMPORTANT:
        // The problem uses 1-based indexing for positions.
        //
        // i = 1 means nums[0]
        // i = 2 means nums[1]
        // i = 3 means nums[2]
        // ...
        //
        // Therefore, we run from 1 to n.
        for (int i = 1; i <= n; i++) {

            // Check whether i is a divisor of n.
            //
            // If n % i == 0,
            // it means i divides n completely.
            //
            // Example:
            // n = 4
            //
            // 4 % 1 = 0  -> special
            // 4 % 2 = 0  -> special
            // 4 % 3 = 1  -> not special
            // 4 % 4 = 0  -> special
            if (n % i == 0) {

                // i is a 1-based position.
                //
                // C++ arrays/vectors use 0-based indexing.
                //
                // So:
                //
                // position 1 -> nums[0]
                // position 2 -> nums[1]
                // position 3 -> nums[2]
                //
                // Therefore we use nums[i - 1].
                //
                // Then square the element:
                //
                // nums[i - 1] * nums[i - 1]
                //
                // and add it to sum.
                sum += nums[i - 1] * nums[i - 1];
            }
        }

        // Return the final sum of squares
        // of all special elements.
        return sum;
    }
};


int main() {

    // Example input.
    vector<int> nums = {1, 2, 3, 4};

    // Create an object of Solution.
    Solution obj;

    // Call sumOfSquares().
    int result = obj.sumOfSquares(nums);

    // Print the result.
    cout << "Sum of squares = " << result << endl;

    return 0;
}