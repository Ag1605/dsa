
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
using namespace std;

class Solution {
public:

    bool checkSubarraySum(vector<int>& nums, int k) {

        // Stores:
        // prefix remainder (or prefix sum when k == 0)
        // -> first index where it appeared
        unordered_map<long long, int> mp;

        // Prefix sum 0 exists before the array starts
        // This helps us handle subarrays beginning at index 0
        mp[0] = -1;

        // Stores the running prefix sum
        long long prefixSum = 0;

        // Convert k to a positive value safely
        // This also handles negative k
        long long mod = abs((long long)k);

        // Traverse the array
        for (int i = 0; i < nums.size(); i++) {

            // Add the current element to prefix sum
            prefixSum += nums[i];

            // Stores the key used in the hashmap
            long long key;

            if (k == 0) {

                // When k == 0:
                // The subarray sum must be exactly 0
                key = prefixSum;

            } else {

                // When k != 0:
                // Store the remainder of prefix sum
                key = prefixSum % mod;
            }

            // Check whether this key appeared before
            if (mp.find(key) != mp.end()) {

                // Calculate the subarray length
                //
                // Previous index = mp[key]
                // Current index = i
                int len = i - mp[key];

                // Subarray must contain at least 2 elements
                if (len >= 2) {
                    return true;
                }

            } else {

                // Store only the first occurrence
                // of this key
                //
                // Keeping the earliest index helps
                // us obtain the longest possible subarray
                mp[key] = i;
            }
        }

        // No valid subarray was found
        return false;
    }
};

int main() {

    // Example input
    vector<int> nums = {23, 2, 4, 6, 7};

    int k = 6;

    // Create Solution object
    Solution obj;

    // Check whether a valid subarray exists
    bool result = obj.checkSubarraySum(nums, k);

    // Print the result
    if (result == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
