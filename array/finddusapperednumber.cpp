#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> findDisappearedNumbers(vector<int>& nums) {

        // This vector will store all the missing numbers
        vector<int> ans;


        // ============================================================
        // STEP 1: Mark the numbers that are present
        // ============================================================
        //
        // The array contains numbers from 1 to n.
        //
        // Example:
        // nums = [4,3,2,7,8,2,3,1]
        //
        // If we see number 4:
        //     number 4 corresponds to index 3
        //     because index = number - 1
        //
        // So:
        //     number 1 -> index 0
        //     number 2 -> index 1
        //     number 3 -> index 2
        //     number 4 -> index 3
        //
        // We make that index negative to indicate:
        // "This number exists in the array."
        //
        // We use abs() because some values may already have
        // been made negative.
        // ============================================================

        for (int i = 0; i < nums.size(); i++) {

            // Get the original value
            // abs() converts a negative value back to positive.
            int idx = abs(nums[i]) - 1;

            // If nums[idx] is positive, it means we haven't
            // marked this number yet.
            if (nums[idx] > 0) {

                // Make it negative.
                // Negative means:
                // "The number corresponding to this index is present."
                nums[idx] = -nums[idx];
            }
        }


        // ============================================================
        // STEP 2: Find the missing numbers
        // ============================================================
        //
        // After marking:
        //
        // Negative value -> number is present
        // Positive value -> number is missing
        //
        // Remember:
        // index 0 represents number 1
        // index 1 represents number 2
        // index 2 represents number 3
        // ...
        //
        // Therefore, if nums[i] is positive,
        // the missing number is i + 1.
        // ============================================================

        for (int i = 0; i < nums.size(); i++) {

            // Positive means this number was never found.
            if (nums[i] > 0) {

                // i represents index.
                // Actual number = i + 1.
                ans.push_back(i + 1);
            }
        }


        // Return all missing numbers
        return ans;
    }
};


int main() {

    // Example input
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};


    // Create object of Solution class
    Solution obj;


    // Call the function
    vector<int> result = obj.findDisappearedNumbers(nums);


    // Print the missing numbers
    cout << "Missing numbers are: ";

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    cout << endl;


    return 0;
}