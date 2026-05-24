#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> f;

        f[0] = 1;

        int sum = 0;
        int count = 0;

        for(int i = 0; i < nums.size(); i++){

            sum += nums[i];

            int ques = sum - k;

            count += f[ques];

            f[sum]++;
        }

        return count;
    }
};

int main() {

    vector<int> nums = {3,4,7,2,-3,1,4,2};

    int k = 7;

    Solution obj;

    int ans = obj.subarraySum(nums, k);

    cout << "Total subarrays with sum " << k << " = " << ans;

    return 0;
}