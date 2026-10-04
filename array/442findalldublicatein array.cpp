#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:

    vector<int> findDuplicates(vector<int>& nums) {

        // This vector will store all duplicate numbers
        vector<int> ans;

        // Traverse the entire array
        for (int i = 0; i < nums.size(); i++) {

            // Get the actual number.
            // We use abs() because we may have already
            // changed some numbers to negative.
            int x = abs(nums[i]);

            // Numbers are from 1 to n.
            // Convert the number into a valid array index.
            //
            // Example:
            // number = 1 → index = 0
            // number = 2 → index = 1
            // number = 3 → index = 2
            int index = x - 1;

            // If nums[index] is already negative,
            // it means we have seen this number before.
            //
            // Therefore, x is a duplicate.
            if (nums[index] < 0) {

                // Add the duplicate number to the answer
                ans.push_back(x);
            }

            else {

                // First time seeing this number.
                // Make nums[index] negative to mark
                // that this number has been visited.
                nums[index] = -nums[index];
            }
        }

        // Return all duplicate numbers
        return ans;
    }
};


int main() {

    // Example input
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};

    // Create Solution object
    Solution obj;

    // Call the function
    vector<int> result = obj.findDuplicates(nums);

    // Print the duplicate numbers
    cout << "Duplicate numbers: ";

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}