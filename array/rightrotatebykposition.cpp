#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Function to rotate the array to the RIGHT by k positions.
    //
    // Example:
    // nums = [1, 2, 3, 4, 5, 6, 7]
    // k = 3
    //
    // Output:
    // [5, 6, 7, 1, 2, 3, 4]
    void rotate(vector<int>& nums, int k) {

        // Store the size of the array.
        int n = nums.size();

        // If k is greater than n, we only need
        // to rotate by k % n positions.
        //
        // Example:
        // n = 7, k = 10
        //
        // 10 % 7 = 3
        //
        // Rotating 10 times is the same as
        // rotating 3 times.
        k = k % n;

        // STEP 1:
        // Reverse the entire array.
        //
        // Before:
        // [1, 2, 3, 4, 5, 6, 7]
        //
        // After:
        // [7, 6, 5, 4, 3, 2, 1]
        reverse(nums.begin(), nums.end());

        // STEP 2:
        // Reverse the first k elements.
        //
        // First k elements:
        // [7, 6, 5]
        //
        // Reverse them:
        // [5, 6, 7]
        //
        // Array becomes:
        // [5, 6, 7, 4, 3, 2, 1]
        reverse(nums.begin(), nums.begin() + k);

        // STEP 3:
        // Reverse all elements from index k
        // to the end.
        //
        // Remaining elements:
        // [4, 3, 2, 1]
        //
        // Reverse them:
        // [1, 2, 3, 4]
        //
        // Final:
        // [5, 6, 7, 1, 2, 3, 4]
        reverse(nums.begin() + k, nums.end());
    }
};

int main() {

    // Create the input array.
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};

    // Number of positions to rotate.
    int k = 3;

    // Create object of Solution class.
    Solution obj;

    // Rotate the array.
    obj.rotate(nums, k);

    // Print the rotated array.
    cout << "Array after right rotation by " << k << " positions: ";

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    cout << endl;

    return 0;
}