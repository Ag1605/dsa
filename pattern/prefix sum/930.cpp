
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        // Stores each prefix sum and how many times
        // that prefix sum has appeared.
        unordered_map<int, int> mp;

        // Empty prefix sum is 0.
        // This helps count subarrays starting from index 0.
        mp[0] = 1;

        // Running prefix sum
        int sum = 0;

        // Total number of subarrays having sum = goal
        int count = 0;

        // Traverse the array
        for (int i = 0; i < nums.size(); i++) {

            // Add current element to prefix sum
            sum += nums[i];

            // We need a previous prefix sum such that:
            //
            // currentPrefixSum - previousPrefixSum = goal
            //
            // Therefore:
            // previousPrefixSum = currentPrefixSum - goal
            int required = sum - goal;

            // If the required prefix sum exists,
            // its frequency tells us how many valid
            // subarrays end at the current index.
            if (mp.find(required) != mp.end()) {
                count += mp[required];
            }

            // Store the frequency of current prefix sum
            mp[sum]++;
        }

        return count;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;

    int result = obj.numSubarraysWithSum(nums, goal);

    cout << "Number of subarrays: " << result << endl;

    return 0;
}
