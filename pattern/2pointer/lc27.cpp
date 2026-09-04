#include <iostream>
#include <vector>
using namespace std;

// Function to remove all occurrences of val from nums
// and return the number of elements that are not equal to val.
int removeElement(vector<int>& nums, int val) {

    // k represents the position where we will place
    // the next valid (non-val) element.
    int k = 0;

    // i is used to scan every element of the array.
    for (int i = 0; i < nums.size(); i++) {

        // If the current element is NOT equal to val,
        // we want to keep this element.
        if (nums[i] != val) {

            // Copy the valid element to position k.
            //
            // Initially k = 0, so the first valid element
            // goes to nums[0].
            //
            // If nums[i] is already at nums[k], this simply
            // assigns the same value to itself, which is fine.
            nums[k] = nums[i];

            // Move k forward because we have placed
            // one valid element.
            k++;
        }

        // If nums[i] == val, we do nothing.
        //
        // This effectively removes/skips that element
        // from the first k positions.
    }

    // k is the number of elements that are NOT equal to val.
    return k;
}


int main() {

    // Example input
    vector<int> nums = {3, 2, 2, 3};

    // Element that we want to remove
    int val = 3;

    // Call the function
    int k = removeElement(nums, val);

    // Print the value of k
    cout << "Number of remaining elements: " << k << endl;

    // Print the first k elements.
    //
    // IMPORTANT:
    // LeetCode only cares about the first k positions.
    // Elements after position k-1 do not matter.
    cout << "Array after removing " << val << ": ";

    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    cout << endl;

    return 0;
}