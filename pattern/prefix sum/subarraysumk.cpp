#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Function to count the number of subarrays
    // whose sum is exactly equal to k.
    int subarraySum(vector<int>& nums, int k) {

        // unordered_map stores:
        //
        // prefix sum -> frequency
        //
        // Example:
        // mp[5] = 2
        //
        // means prefix sum 5 has appeared 2 times.
        unordered_map<int, int> mp;


        // Prefix sum 0 has appeared once.
        //
        // Why?
        // Before we process any element, the sum is 0.
        //
        // This is important for subarrays that start
        // from index 0.
        mp[0] = 1;


        // 'sum' stores the prefix sum up to
        // the current element.
        int sum = 0;

        // 'count' stores the total number of
        // subarrays whose sum is equal to k.
        int count = 0;


        // Traverse every element of the array.
        for (int num : nums) {

            // Add the current element to the prefix sum.
            sum += num;


            // We want a subarray with sum = k.
            //
            // Suppose:
            //
            // current prefix sum = sum
            //
            // We have an earlier prefix sum = previousSum.
            //
            // Sum of subarray between them:
            //
            // sum - previousSum = k
            //
            // Therefore:
            //
            // previousSum = sum - k
            //
            // So we check whether sum - k
            // already exists in the map.
            if (mp.find(sum - k) != mp.end()) {

                // Add its frequency to count.
                //
                // If sum-k appeared 3 times,
                // then there are 3 different subarrays
                // ending at the current position whose sum
                // is k.
                count += mp[sum - k];
            }


            // Store the current prefix sum.
            //
            // If it already exists, its frequency
            // is increased by 1.
            mp[sum]++;
        }


        // Return the total number of valid subarrays.
        return count;
    }
};


int main() {

    // Example input.
    vector<int> nums = {1, 1, 1};

    // Target sum.
    int k = 2;

    // Create an object of Solution class.
    Solution obj;

    // Find the number of subarrays
    // whose sum is equal to k.
    int answer = obj.subarraySum(nums, k);

    // Print the answer.
    cout << "Number of subarrays = " << answer << endl;

    return 0;
}