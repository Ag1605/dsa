#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Function to find all unique quadruplets
    // whose sum is equal to target.
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        // Vector to store all valid quadruplets.
        vector<vector<int>> ans;

        // Store the size of the array.
        int n = nums.size();


        // ------------------------------------------------
        // STEP 1: SORT THE ARRAY
        // ------------------------------------------------
        //
        // Sorting is important because it allows us
        // to use the two-pointer technique.
        //
        // It also makes it easy to skip duplicates.
        sort(nums.begin(), nums.end());


        // ------------------------------------------------
        // STEP 2: FIX THE FIRST ELEMENT
        // ------------------------------------------------
        //
        // We choose nums[i] as the first number
        // of the quadruplet.
        //
        // We need at least 3 elements after i,
        // so i goes only up to n - 4.
        for (int i = 0; i < n - 3; i++) {

            // Skip duplicate values for the first position.
            //
            // Example:
            // [-2, -2, 0, 0, 2, 2]
            //
            // If we already used the first -2,
            // we don't need to use the second -2
            // as the first element again.
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }


            // ------------------------------------------------
            // STEP 3: FIX THE SECOND ELEMENT
            // ------------------------------------------------
            //
            // Now choose nums[j] as the second number.
            //
            // We start from i + 1 because j must be
            // after i.
            for (int j = i + 1; j < n - 2; j++) {

                // Skip duplicate values for the second position.
                //
                // j > i + 1 ensures that we only skip
                // duplicates after the first occurrence.
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }


                // ------------------------------------------------
                // STEP 4: TWO POINTERS
                // ------------------------------------------------

                // left starts immediately after j.
                int left = j + 1;

                // right starts at the last element.
                int right = n - 1;


                // Continue until the two pointers meet.
                while (left < right) {

                    // Calculate the sum of four numbers.
                    //
                    // We use long long because the values
                    // can be large.
                    //
                    // int can overflow if the numbers are
                    // close to INT_MAX or INT_MIN.
                    long long sum = (long long)nums[i]
                                  + nums[j]
                                  + nums[left]
                                  + nums[right];


                    // ------------------------------------------------
                    // CASE 1: FOUND A VALID QUADRUPLET
                    // ------------------------------------------------
                    if (sum == target) {

                        // Store the four numbers.
                        ans.push_back({
                            nums[i],
                            nums[j],
                            nums[left],
                            nums[right]
                        });


                        // Move both pointers to search
                        // for another possible quadruplet.
                        left++;
                        right--;


                        // Skip duplicate values from the left.
                        //
                        // This prevents duplicate quadruplets.
                        while (left < right &&
                               nums[left] == nums[left - 1]) {
                            left++;
                        }


                        // Skip duplicate values from the right.
                        while (left < right &&
                               nums[right] == nums[right + 1]) {
                            right--;
                        }
                    }


                    // ------------------------------------------------
                    // CASE 2: SUM IS TOO SMALL
                    // ------------------------------------------------
                    else if (sum < target) {

                        // We need to increase the sum.
                        //
                        // Since the array is sorted,
                        // moving left forward gives us
                        // a larger number.
                        left++;
                    }


                    // ------------------------------------------------
                    // CASE 3: SUM IS TOO LARGE
                    // ------------------------------------------------
                    else {

                        // We need to decrease the sum.
                        //
                        // Moving right backward gives us
                        // a smaller number.
                        right--;
                    }
                }
            }
        }


        // Return all unique quadruplets.
        return ans;
    }
};


int main() {

    // Example input.
    vector<int> nums = {
        1, 0, -1, 0, -2, 2
    };

    // Target sum.
    int target = 0;


    // Create an object of Solution class.
    Solution obj;


    // Find all quadruplets whose sum is target.
    vector<vector<int>> answer = obj.fourSum(nums, target);


    // Print the result.
    cout << "Quadruplets:" << endl;

    for (const vector<int>& quad : answer) {

        cout << "[";

        for (int i = 0; i < quad.size(); i++) {

            cout << quad[i];

            if (i != quad.size() - 1) {
                cout << ", ";
            }
        }

        cout << "]" << endl;
    }


    return 0;
}