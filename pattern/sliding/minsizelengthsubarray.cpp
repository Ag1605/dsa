#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0, high = 0, sum = 0;
        int res = INT_MAX;
        int n = nums.size();

        while (high < n) {
            sum += nums[high];  // expand

            while (sum >= target) {
                int length = high - low + 1;
                res = min(res, length);

                sum -= nums[low]; // shrink
                low++;
            }

            high++;
        }

        return (res == INT_MAX) ? 0 : res;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;

    cout << obj.minSubArrayLen(target, nums);

    return 0;
}