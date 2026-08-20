#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Function to find all unique triplets
    // whose sum is equal to 0.
    vector<vector<int>> threeSum(vector<int>& nums) {

        // Store all valid triplets.
        vector<vector<int>> ans;


        // ------------------------------------------------
        // STEP 1: SORT THE ARRAY
        // ------------------------------------------------
        //
        // Sorting helps us:
        //
        // 1. Use the two-pointer technique.
        // 2. Easily skip duplicate values.
        //
        // Example:
        //
        // [3, -1, 2, -1, 0]
        //
        // becomes:
        //
        // [-1, -1, 0, 2, 3]
        sort(nums.begin(), nums.end());


        // Store the size of the array.
        int n = nums.size();


        // ------------------------------------------------
        // STEP 2: FIX THE FIRST ELEMENT
        // ------------------------------------------------
        //
        // We fix nums[i] and then use two pointers
        // to find two more numbers whose sum is:
        //
        // nums[left] + nums[right] = -nums[i]
        //
        // Therefore:
        //
        // nums[i] + nums[left] + nums[right] = 0
        //
        for (int i = 0; i < n - 2; i++) {

            // Skip duplicate values for the first element.
            //
            // Example:
            //
            // [-1, -1, 0, 1, 2]
            //  ↑
            //  First -1 is used.
            //
            // We don't need to use the second -1
            // as the first element because it would
            // generate duplicate triplets.
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }


            // ------------------------------------------------
            // STEP 3: TWO POINTERS
            // ------------------------------------------------

            // left starts immediately after i.
            int left = i + 1;

            // right starts at the last element.
            int right = n - 1;


            // Continue until the two pointers meet.
            while (left < right) {

                // Calculate the sum of the three numbers.
                int sum = nums[i] + nums[left] + nums[right];


                // ------------------------------------------------
                // CASE 1: SUM IS TOO SMALL
                // ------------------------------------------------
                //
                // Because the array is sorted,
                // increasing left will increase the sum.
                if (sum < 0) {
                    left++;
                }


                // ------------------------------------------------
                // CASE 2: SUM IS TOO LARGE
                // ------------------------------------------------
                //
                // Decreasing right will decrease the sum.
                else if (sum > 0) {
                    right--;
                }


                // ------------------------------------------------
                // CASE 3: SUM IS EXACTLY 0
                // ------------------------------------------------
                else {

                    // We found a valid triplet.
                    ans.push_back({
                        nums[i],
                        nums[left],
                        nums[right]
                    });


                    // Move both pointers to search
                    // for another possible triplet.
                    left++;
                    right--;


                    // ------------------------------------------------
                    // SKIP DUPLICATE LEFT VALUES
                    // ------------------------------------------------
                    //
                    // Example:
                    //
                    // [-2, 0, 0, 0, 2]
                    //
                    // After using the first 0,
                    // we skip the remaining duplicate 0s.
                    while (left < right &&
                           nums[left] == nums[left - 1]) {
                        left++;
                    }


                    // ------------------------------------------------
                    // SKIP DUPLICATE RIGHT VALUES
                    // ------------------------------------------------
                    //
                    // Same idea for the right pointer.
                    while (left < right &&
                           nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
            }
        }


        // Return all unique triplets.
        return ans;
    }
};


int main() {

    // Example input.
    vector<int> nums = {
        -1, 0, 1, 2, -1, -4
    };


    // Create an object of Solution class.
    Solution obj;


    // Find all triplets whose sum is 0.
    vector<vector<int>> answer = obj.threeSum(nums);


    // Print the answer.
    cout << "Triplets whose sum is 0:" << endl;

    for (const vector<int>& triplet : answer) {

        cout << "[";

        for (int i = 0; i < triplet.size(); i++) {

            cout << triplet[i];

            if (i != triplet.size() - 1) {
                cout << ", ";
            }
        }

        cout << "]" << endl;
    }


    return 0;
}