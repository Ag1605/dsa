
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        // Stores the frequency of each oddCount
        unordered_map<int, int> mp;

        // Initially, the empty prefix contains 0 odd numbers
        // This helps count subarrays starting from index 0
        mp[0] = 1;

        // Number of odd elements seen so far
        int oddCount = 0;

        // Total number of nice subarrays
        int count = 0;

        // Traverse the array
        for (int i = 0; i < nums.size(); i++) {

            // If current number is odd, increase oddCount
            if (nums[i] % 2 != 0) {
                oddCount++;
            }

            // We need a previous prefix containing:
            // oddCount - k odd numbers
            int required = oddCount - k;

            // If this prefix count exists,
            // it creates valid subarrays ending at index i
            if (mp.find(required) != mp.end()) {
                count += mp[required];
            }

            // Store frequency of the current oddCount
            mp[oddCount]++;
        }

        return count;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;

    int result = obj.numberOfSubarrays(nums, k);

    cout << "Number of nice subarrays: "
         << result << endl;

    return 0;
}
