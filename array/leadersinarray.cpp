#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Function to find all leaders in the array.
    //
    // An element is called a leader if it is strictly
    // greater than every element to its right.
    //
    // The last element is always a leader because
    // there is no element to its right.
    vector<int> leaders(vector<int>& nums) {

        // Vector to store all the leaders.
        vector<int> ans;

        // Store the size of the array.
        int n = nums.size();

        // maxRight stores the maximum element
        // that we have seen while moving from
        // right to left.
        //
        // Initially, there is no element on the right,
        // so we use the smallest possible integer.
        int maxRight = INT_MIN;


        // Traverse the array from right to left.
        //
        // Example:
        // [16, 17, 4, 3, 5, 2]
        //
        // We start from 2 and move towards 16.
        for (int i = n - 1; i >= 0; i--) {

            // If the current element is greater than
            // every element we have already seen on
            // its right, then it is a leader.
            if (nums[i] > maxRight) {

                // Store the leader.
                ans.push_back(nums[i]);
            }

            // Update maxRight.
            //
            // We keep the largest element seen so far
            // on the right side.
            maxRight = max(maxRight, nums[i]);
        }


        // Since we traversed from right to left,
        // the leaders are currently stored in reverse order.
        //
        // Example:
        // Original order: [17, 5, 2]
        //
        // We collected: [2, 5, 17]
        //
        // Reverse it to get:
        // [17, 5, 2]
        reverse(ans.begin(), ans.end());


        // Return the leaders in their original order.
        return ans;
    }
};


int main() {

    // Example input.
    vector<int> nums = {16, 17, 4, 3, 5, 2};

    // Create an object of Solution class.
    Solution obj;

    // Call the leaders function.
    vector<int> answer = obj.leaders(nums);

    // Print the leaders.
    cout << "Leaders: ";

    for (int num : answer) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}