#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int removeDuplicates(vector<int>& nums) {

        // Store the size of the array
        int n = nums.size();


        // ---------------------------------------------------------
        // If the array has 0, 1, or 2 elements,
        // all elements are allowed.
        //
        // Example:
        // [1]       -> 1 element allowed
        // [1,1]     -> 2 elements allowed
        // ---------------------------------------------------------
        if (n <= 2)
            return n;


        // ---------------------------------------------------------
        // 'write' tells us where we should put the next valid element.
        //
        // The first two elements are already valid,
        // so we start writing from index 2.
        //
        // Example:
        //
        // nums = [1,1,2,2,3,3]
        //          0 1 2 3 4 5
        //
        // write = 2
        // ---------------------------------------------------------
        int write = 2;


        // ---------------------------------------------------------
        // 'read' scans through the array from index 2.
        //
        // We don't need to check index 0 and 1 because
        // two copies of a number are always allowed.
        // ---------------------------------------------------------
        for (int read = 2; read < n; read++) {

            // -----------------------------------------------------
            // Because the array is SORTED:
            //
            // If nums[read] == nums[write - 2],
            // then adding nums[read] would create 3 copies.
            //
            // Example:
            //
            // Current valid array:
            // [1, 1]
            //
            // write = 2
            //
            // nums[write - 2]
            // = nums[0]
            // = 1
            //
            // If nums[read] is also 1:
            //
            // [1, 1, 1]
            //       ^
            //       third 1 -> NOT allowed
            //
            // Therefore we skip it.
            // -----------------------------------------------------

            if (nums[read] != nums[write - 2]) {

                // The current element is valid.
                //
                // Put it at the 'write' position.
                nums[write] = nums[read];

                // Move write to the next position.
                write++;
            }
        }


        // 'write' represents the number of valid elements.
        //
        // The first 'write' elements of nums now contain
        // the answer.
        return write;
    }
};


int main() {

    // ---------------------------------------------------------
    // Example input
    // ---------------------------------------------------------
    vector<int> nums = {1, 1, 1, 2, 2, 3};


    // Create Solution object
    Solution obj;


    // Call the function
    int k = obj.removeDuplicates(nums);


    // ---------------------------------------------------------
    // k = number of valid elements
    //
    // Only nums[0] to nums[k-1] are important.
    // ---------------------------------------------------------

    cout << "Number of valid elements: " << k << endl;

    cout << "Modified array: ";

    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    cout << endl;


    return 0;
}