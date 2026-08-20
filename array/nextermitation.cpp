#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Function to rearrange the array into the
    // next lexicographically greater permutation.
    //
    // If the current permutation is already the largest,
    // it changes the array into the smallest permutation.
    void nextPermutation(vector<int>& nums) {

        // Store the size of the array.
        int n = nums.size();

        // Start from the second-last element.
        //
        // We compare nums[i] with nums[i + 1].
        int i = n - 2;


        // STEP 1:
        // Find the first element from the right
        // which is smaller than the element immediately after it.
        //
        // Example:
        // [1, 2, 5, 4, 3]
        //       ^
        //
        // We find 2 because:
        // 2 < 5
        //
        // The suffix [5,4,3] is in decreasing order.
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }


        // If i >= 0, we found a valid element
        // that can be increased.
        //
        // If i == -1, the entire array was in decreasing order,
        // meaning this is already the largest permutation.
        if (i >= 0) {

            // STEP 2:
            // Find the smallest element on the right
            // that is greater than nums[i].
            //
            // Start from the end because the suffix is
            // already in decreasing order.
            int j = n - 1;

            while (nums[j] <= nums[i]) {
                j--;
            }

            // Swap nums[i] with nums[j].
            //
            // This makes the permutation slightly larger.
            swap(nums[i], nums[j]);
        }


        // STEP 3:
        // Reverse everything after index i.
        //
        // The suffix was originally in decreasing order.
        // Reversing it makes it increasing, giving us
        // the smallest possible suffix.
        //
        // If i == -1:
        // nums.begin() + i + 1
        // = nums.begin() + 0
        //
        // So the entire array gets reversed.
        reverse(nums.begin() + i + 1, nums.end());
    }
};


int main() {

    // Example input
    vector<int> nums = {1, 2, 3};

    // Create an object of Solution class.
    Solution obj;

    // Find the next permutation.
    obj.nextPermutation(nums);

    // Print the resulting array.
    cout << "Next Permutation: ";

    for (int num : nums) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}