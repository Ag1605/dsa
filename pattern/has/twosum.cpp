#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // unordered_map stores:
        // key   = number from the array
        // value = index of that number
        //
        // Example:
        // nums = [4, 8, 1]
        // mp could become:
        // 4 -> 0
        // 8 -> 1
        // 1 -> 2
        unordered_map<int, int> mp;

        // Traverse the array from left to right
        for (int i = 0; i < nums.size(); i++) {

            // We need another number such that:
            //
            // nums[i] + need = target
            //
            // Therefore:
            // need = target - nums[i]
            int need = target - nums[i];

            // Check whether 'need' already exists
            // in our map.
            //
            // mp.find(need) returns:
            // - iterator to the element if found
            // - mp.end() if NOT found
            if (mp.find(need) != mp.end()) {

                // We found the two numbers!
                //
                // mp[need] = index of the previous number
                // i        = index of the current number
                //
                // Return their indices.
                return {mp[need], i};
            }

            // If 'need' was not found,
            // store the current number and its index.
            //
            // Example:
            // nums[i] = 4
            // i = 0
            // mp[4] = 0
            mp[nums[i]] = i;
        }

        // If no pair is found, return an empty vector.
        return {};
    }
};


int main() {

    // Create the input array
    vector<int> nums = {4, 8, 1, 15, 6, 23, 10, 7, 12, 3};

    // Target sum
    int target = 17;

    // Create Solution object
    Solution obj;

    // Call twoSum()
    vector<int> answer = obj.twoSum(nums, target);

    // Print the answer
    cout << "Indices: ";

    for (int index : answer) {
        cout << index << " ";
    }

    cout << endl;

    // Also print the actual numbers
    if (answer.size() == 2) {

        cout << "Numbers: "
             << nums[answer[0]]
             << " + "
             << nums[answer[1]]
             << " = "
             << target
             << endl;
    }

    return 0;
}