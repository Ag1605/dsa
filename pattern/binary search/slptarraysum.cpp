#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canSplit(vector<int> &nums, int k, int maxSum)
    {

        int subarrays = 1;
        int sum = 0;

        for (int num : nums)
        {

            if (sum + num <= maxSum)
            {
                sum += num;
            }
            else
            {
                subarrays++;
                sum = num;
            }
        }

        return subarrays <= k;
    }

    int splitArray(vector<int> &nums, int k)
    {

        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);

        int ans = right;

        while (left <= right)
        {

            int mid = left + (right - left) / 2;

            if (canSplit(nums, k, mid))
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return ans;
    }
};

int main()
{

    Solution obj;

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int k;
    cin >> k;

    cout << obj.splitArray(nums, k);

    return 0;
}