#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int n = nums.size();

        int bestmax = nums[0];
        int bestmin = nums[0];

        int result = abs(nums[0]);

        for (int i = 1; i < n; i++) {

            int oldbestmax = bestmax;
            int oldbestmin = bestmin;

            // Maximum subarray sum ending here
            bestmax = max(nums[i], oldbestmax + nums[i]);

            // Minimum subarray sum ending here
            bestmin = min(nums[i], oldbestmin + nums[i]);

            result = max(result,
                        max(abs(bestmax), abs(bestmin)));
        }

        return result;
    }
};

int main() {

    vector<int> nums = {2, -5, 1, -4, 3, -2};

    Solution obj;

    cout << obj.maxAbsoluteSum(nums);

    return 0;
}