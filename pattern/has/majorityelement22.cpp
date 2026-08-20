#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Function to find all elements that appear
    // more than n/3 times in the array.
    vector<int> majorityElement(vector<int>& nums) {

        // HashMap to store:
        //
        // number -> frequency
        //
        // Example:
        // nums = [3, 2, 3]
        //
        // mp:
        // 3 -> 2
        // 2 -> 1
        unordered_map<int, int> mp;

        // Vector to store the final answer.
        vector<int> ans;

        // Store the size of the array.
        int n = nums.size();


        // ------------------------------------------------
        // STEP 1: COUNT FREQUENCY OF EVERY NUMBER
        // ------------------------------------------------

        // Traverse every number in the array.
        for (int num : nums) {

            // Increase the frequency of the current number.
            //
            // If num doesn't exist in the map,
            // mp[num] starts with 0 automatically.
            //
            // Then it becomes 1.
            mp[num]++;
        }


        // ------------------------------------------------
        // STEP 2: FIND ELEMENTS APPEARING MORE THAN N/3
        // ------------------------------------------------

        // Traverse through every key-value pair
        // in the unordered_map.
        //
        // it.first  -> number
        // it.second -> frequency
        for (auto it : mp) {

            // Check if this number appears
            // more than n/3 times.
            if (it.second > n / 3) {

                // Add the number to the answer.
                ans.push_back(it.first);
            }
        }


        // Return all majority elements.
        return ans;
    }
};


int main() {

    // Example input.
    vector<int> nums = {3, 2, 3};

    // Create an object of Solution class.
    Solution obj;

    // Find the majority elements.
    vector<int> answer = obj.majorityElement(nums);


    // Print the answer.
    cout << "Majority Elements: ";

    for (int num : answer) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}