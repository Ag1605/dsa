#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:

    vector<int> applyOperations(vector<int>& nums) {

        // ============================================================
        // STEP 1: Apply the operations
        // ============================================================
        //
        // We compare every element with the element immediately
        // to its right.
        //
        // If both elements are equal:
        //
        //      nums[i] == nums[i + 1]
        //
        // then:
        //
        //      nums[i] = nums[i] * 2
        //      nums[i + 1] = 0
        //
        // Example:
        //
        //      [1, 2, 2, 3]
        //
        // At i = 1:
        //
        //      nums[1] = 2
        //      nums[2] = 2
        //
        // They are equal, so:
        //
        //      nums[1] = 4
        //      nums[2] = 0
        //
        // Result:
        //
        //      [1, 4, 0, 3]
        //
        // ============================================================

        for (int i = 0; i < nums.size() - 1; i++) {

            // Check whether the current element and
            // the next element are equal.
            if (nums[i] == nums[i + 1]) {

                // Double the current element.
                nums[i] = nums[i] * 2;

                // Replace the next element with zero.
                nums[i + 1] = 0;
            }
        }


        // ============================================================
        // STEP 2: Move all non-zero elements to the front
        // ============================================================
        //
        // After Step 1, the array may contain zeros in between
        // the useful elements.
        //
        // Example:
        //
        //      [1, 4, 0, 3, 0]
        //
        // We want:
        //
        //      [1, 4, 3, 0, 0]
        //
        // We use k as the position where the next non-zero
        // element should be placed.
        //
        // k starts from 0.
        //
        // ============================================================

        int k = 0;


        // Go through every element of the array.
        for (int i = 0; i < nums.size(); i++) {

            // If the current element is NOT zero,
            // we want to keep it.
            if (nums[i] != 0) {

                // Put the non-zero element at position k.
                nums[k] = nums[i];

                // Move k to the next position.
                k++;
            }
        }


        // ============================================================
        // STEP 3: Fill the remaining positions with zero
        // ============================================================
        //
        // After moving all non-zero elements to the front,
        // positions from k onward should contain zero.
        //
        // Example:
        //
        //      [1, 4, 3, ?, ?]
        //             ^
        //             k
        //
        // We fill:
        //
        //      [1, 4, 3, 0, 0]
        //
        // ============================================================

        while (k < nums.size()) {

            // Put zero at the current position.
            nums[k] = 0;

            // Move to the next position.
            k++;
        }


        // Return the modified array.
        return nums;
    }
};


int main() {

    // ============================================================
    // INPUT
    // ============================================================

    vector<int> nums = {1, 2, 2, 1, 1, 0};


    // Create an object of Solution class.
    Solution solution;


    // Call applyOperations() and store the returned array.
    vector<int> result = solution.applyOperations(nums);


    // ============================================================
    // OUTPUT
    // ============================================================

    cout << "Array after applying operations: ";

    // Print every element of the resulting array.
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    cout << endl;


    return 0;
}