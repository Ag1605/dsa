#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        unordered_map<int,int> f;

        // sum 0 before array starts
        f[0] = -1;

        int sum = 0;
        int maxi = 0;

        for(int i = 0; i < nums.size(); i++){

            // Convert:
            // 0 -> -1
            // 1 -> +1

            if(nums[i] == 0){
                sum += -1;
            }
            else{
                sum += 1;
            }

            // If same sum appeared before
            if(f.find(sum) != f.end()){

                int len = i - f[sum];

                maxi = max(maxi, len);
            }
            else{

                // Store first occurrence only
                f[sum] = i;
            }
        }

        return maxi;
    }
};

int main() {

    vector<int> nums = {0,1,1,0,1,0,0,1};

    Solution obj;

    int ans = obj.findMaxLength(nums);

    cout << "Maximum Length = " << ans;

    return 0;
}