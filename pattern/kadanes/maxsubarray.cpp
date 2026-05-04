#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best = nums[0];
        int ans  = nums[0];

        for(int i = 1; i < nums.size(); i++) {  // start from 1 (important fix)
            int v1 = best + nums[i];
            int v2 = nums[i];

            best = max(v1, v2);
            ans  = max(ans, best);
        }
        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    int result = obj.maxSubArray(nums);

    cout << "Maximum Subarray Sum = " << result << endl;

    return 0;
}