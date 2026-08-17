#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // ----------------------------------------------------
        // STEP 1: Create a new vector of pairs
        //
        // Each pair stores:
        // first  -> value
        // second -> original index
        //
        // Example:
        // nums = {2, 6, 5, 8, 11}
        //
        // arr will become:
        // {2, 0}
        // {6, 1}
        // {5, 2}
        // {8, 3}
        // {11, 4}
        // ----------------------------------------------------

        vector<pair<int, int>> arr;

        for (int i = 0; i < nums.size(); i++) {

            // Store the number and its original index
            arr.push_back({nums[i], i});
        }


        // ----------------------------------------------------
        // STEP 2: Sort the vector
        //
        // pair is automatically sorted by the first value.
        //
        // Before sorting:
        // {2,0} {6,1} {5,2} {8,3} {11,4}
        //
        // After sorting:
        // {2,0} {5,2} {6,1} {8,3} {11,4}
        //
        // Notice:
        // The values are sorted,
        // BUT their original indices are still saved.
        // ----------------------------------------------------

        sort(arr.begin(), arr.end());


        // ----------------------------------------------------
        // STEP 3: Create two pointers
        //
        // left  -> points to the smallest value
        // right -> points to the largest value
        //
        // Example:
        //
        // {2,0} {5,2} {6,1} {8,3} {11,4}
        //   ↑                         ↑
        // left                       right
        // ----------------------------------------------------

        int left = 0;
        int right = arr.size() - 1;


        // ----------------------------------------------------
        // STEP 4: Start the Two Pointer loop
        //
        // Continue until left and right meet.
        // ----------------------------------------------------

        while (left < right) {

            // Get the sum of the two values
            int sum = arr[left].first + arr[right].first;


            // ------------------------------------------------
            // CASE 1:
            // If sum equals target, we found the answer.
            //
            // arr[left].second  = original index of left value
            // arr[right].second = original index of right value
            // ------------------------------------------------

            if (sum == target) {

                return {
                    arr[left].second,
                    arr[right].second
                };
            }


            // ------------------------------------------------
            // CASE 2:
            // If sum is smaller than target,
            // we need a BIGGER sum.
            //
            // Because the array is sorted,
            // move left forward.
            // ------------------------------------------------

            if (sum < target) {

                left++;
            }


            // ------------------------------------------------
            // CASE 3:
            // If sum is greater than target,
            // we need a SMALLER sum.
            //
            // Move right backward.
            // ------------------------------------------------

            else {

                right--;
            }
        }


        // ----------------------------------------------------
        // STEP 5:
        // If no pair was found, return {-1, -1}
        // ----------------------------------------------------

        return {-1, -1};
    }
};


int main() {

    // Input array
    vector<int> nums = {2, 6, 5, 8, 11};

    // Required target
    int target = 14;


    // Create object of Solution class
    Solution sol;


    // Call twoSum function
    vector<int> ans = sol.twoSum(nums, target);


    // Print the two original indices
    cout << ans[0] << " " << ans[1] << endl;


    return 0;
}