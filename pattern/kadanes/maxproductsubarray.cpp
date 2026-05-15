#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();

        int bestmax = nums[0];
        int bestmin = nums[0];
        int result = nums[0];

        for (int i = 1; i < n; i++) {

            int oldbestmax = bestmax;
            int oldbestmin = bestmin;

            int v1 = oldbestmax * nums[i];
            int v2 = oldbestmin * nums[i];
            int v3 = nums[i];

            bestmax = max(v1, max(v2, v3));

            bestmin = min(v1, min(v2, v3));

            result = max(result, bestmax);
        }

        return result;
    }
};

int main() {

    vector<int> nums = {2, 3, -2, 4};

    Solution obj;

    int ans = obj.maxProduct(nums);

    cout << "Maximum Product Subarray = " << ans << endl;

    return 0;
}