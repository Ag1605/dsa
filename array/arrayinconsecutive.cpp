#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // Function to check whether the array contains
    // consecutive numbers
    bool isConsecutive(vector<int>& nums) {

        // Step 1:
        // Sort the array in increasing order.
        //
        // Example:
        // nums = {4, 2, 3, 1}
        //
        // After sorting:
        // nums = {1, 2, 3, 4}
        //
        // Now it becomes easy to check whether
        // every number is exactly 1 greater than
        // the previous number.
        sort(nums.begin(), nums.end());


        // Step 2:
        // Start checking from the second element.
        //
        // We compare:
        // nums[1] with nums[0]
        // nums[2] with nums[1]
        // nums[3] with nums[2]
        //
        // If the difference is not 1,
        // then the array is NOT consecutive.
        for (int i = 1; i < nums.size(); i++) {

            // Check the difference between
            // the current element and previous element.
            //
            // For consecutive numbers:
            // 2 - 1 = 1
            // 3 - 2 = 1
            // 4 - 3 = 1
            //
            // If we get anything other than 1,
            // return false immediately.
            if (nums[i] - nums[i - 1] != 1) {
                return false;
            }
        }

        // If we reach here, every adjacent pair
        // had a difference of exactly 1.
        //
        // Therefore, the array is consecutive.
        return true;
    }
};


int main() {

    // Create an example array
    vector<int> nums = {4, 2, 3, 1};

    // Create an object of Solution class
    Solution obj;

    // Call the isConsecutive() function
    bool result = obj.isConsecutive(nums);

    // Print the result
    if (result) {
        cout << "Array is consecutive" << endl;
    }
    else {
        cout << "Array is not consecutive" << endl;
    }

    return 0;
}