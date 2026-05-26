#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        unordered_map<int,int> f;

        f[0] = 1;

        int sum = 0;
        int count = 0;

        for(int i = 0; i < nums.size(); i++){

            sum += nums[i];

            int rem = sum % k;

            // Handle negative remainder
            if(rem < 0){
                rem += k;
            }

            count += f[rem];

            f[rem]++;
        }

        return count;
    }
};

int main() {

    vector<int> nums = {4,5,0,-2,-3,1};

    int k = 5;

    Solution obj;

    int ans = obj.subarraysDivByK(nums, k);

    cout << "Total subarrays divisible by "
         << k << " = " << ans;

    return 0;
}