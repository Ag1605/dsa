#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int missingInteger(vector<int>& nums) {

        // ----------------------------------------------------
        // STEP 1: Start the sum with the first element
        // ----------------------------------------------------
        //
        // Example:
        // nums = {1, 2, 3, 5, 6}
        //
        // We start with:
        // sum = 1
        //
        // We will check whether the next elements are
        // consecutive.
        int sum = nums[0];


        // ----------------------------------------------------
        // STEP 2: Find the longest consecutive prefix
        // ----------------------------------------------------
        //
        // We start from index 1 because nums[0] is already
        // included in sum.
        //
        // Condition:
        //
        // nums[i] == nums[i - 1] + 1
        //
        // means the current number is exactly one greater
        // than the previous number.
        //
        // Example:
        //
        // 1, 2, 3
        //
        // 2 == 1 + 1  -> consecutive
        // 3 == 2 + 1  -> consecutive
        //
        // But:
        //
        // 5 != 3 + 1
        //
        // so we stop.
        for (int i = 1; i < nums.size(); i++) {

            // If the current number is NOT consecutive
            // with the previous number, stop.
            if (nums[i] != nums[i - 1] + 1) {
                break;
            }

            // Current number is consecutive,
            // so add it to the sum.
            sum += nums[i];
        }


        // ----------------------------------------------------
        // STEP 3: Store the sum in x
        // ----------------------------------------------------
        //
        // The problem says the answer should be:
        //
        // - at least the sum of the longest consecutive prefix
        // - and should NOT already exist in nums.
        //
        // So we start checking from sum.
        int x = sum;


        // ----------------------------------------------------
        // STEP 4: Find the first number >= sum
        // that does not exist in nums
        // ----------------------------------------------------
        //
        // We keep checking:
        //
        // sum
        // sum + 1
        // sum + 2
        // ...
        //
        // until we find a number that is NOT present.
        while (true) {

            // Assume x is not present initially.
            bool found = false;


            // ------------------------------------------------
            // Search for x inside the array
            // ------------------------------------------------
            //
            // Range-based for loop:
            //
            // for (int num : nums)
            //
            // means:
            // Take every element of nums one by one
            // and store it temporarily in num.
            for (int num : nums) {

                // Check whether current array element
                // is equal to x.
                if (num == x) {

                    // x exists in the array.
                    found = true;

                    // No need to search further.
                    break;
                }
            }


            // ------------------------------------------------
            // STEP 5: If x was NOT found
            // ------------------------------------------------
            //
            // !found means:
            //
            // found == false
            //
            // Therefore x is missing from nums.
            //
            // Since we started from sum and move upward,
            // this is the smallest valid answer.
            if (!found) {
                return x;
            }


            // ------------------------------------------------
            // STEP 6: x already exists
            // ------------------------------------------------
            //
            // Therefore try the next number.
            //
            // Example:
            //
            // x = 6 -> found
            // x = 7 -> found
            // x = 8 -> not found
            //
            // Answer = 8
            x++;
        }
    }
};


int main() {

    // ----------------------------------------------------
    // Example input
    // ----------------------------------------------------

    vector<int> nums = {
        1, 2, 3, 5, 6
    };


    // Create Solution object
    Solution obj;


    // Call the function
    int answer = obj.missingInteger(nums);


    // Print the answer
    cout << "Missing Integer: " << answer << endl;


    return 0;
}