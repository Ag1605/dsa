#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Function to move all zeroes to the end of the array.
    //
    // Important:
    // The relative order of non-zero elements
    // must remain the same.
    //
    // Example:
    // Input  : [0, 1, 0, 3, 12]
    // Output : [1, 3, 12, 0, 0]
    void moveZeroes(vector<int>& nums) {

        // 'slow' points to the position where
        // the next non-zero element should be placed.
        //
        // Initially, we start from index 0.
        int slow = 0;

        // 'fast' scans the entire array.
        //
        // fast looks for non-zero elements.
        for (int fast = 0; fast < nums.size(); fast++) {

            // If the current element is NOT zero,
            // we need to move it to the 'slow' position.
            if (nums[fast] != 0) {

                // Swap the non-zero element at 'fast'
                // with the element at 'slow'.
                //
                // This moves the non-zero element
                // towards the beginning of the array.
                swap(nums[slow], nums[fast]);

                // Move slow forward because we have
                // successfully placed one non-zero element.
                slow++;
            }
        }
    }
};

int main() {

    // Create the input array.
    vector<int> nums = {0, 1, 0, 3, 12};

    // Create object of Solution class.
    Solution obj;

    // Move all zeroes to the end.
    obj.moveZeroes(nums);

    // Print the resulting array.
    cout << "Array after moving zeroes: ";

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    cout << endl;

    return 0;
}