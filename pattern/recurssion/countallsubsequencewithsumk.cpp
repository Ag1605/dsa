
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    int solve(int index, int sum, int k, vector<int>& nums)
    {
        // Base case: all elements have been processed
        if (index == nums.size())
        {
            // If current subsequence sum equals k,
            // count this subsequence
            if (sum == k)
            {
                return 1;
            }

            // Otherwise, this is not a valid subsequence
            return 0;
        }

        // Choice 1: Pick the current element
        // Add nums[index] to the current sum
        int pick = solve(index + 1, sum + nums[index], k, nums);

        // Choice 2: Do not pick the current element
        // Current sum remains unchanged
        int notPick = solve(index + 1, sum, k, nums);

        // Total valid subsequences from both choices
        return pick + notPick;
    }

    int countSubsequenceSum(vector<int>& nums, int k)
    {
        // Start from index 0 with sum 0
        return solve(0, 0, k, nums);
    }
};

int main()
{
    Solution obj;

    int n, k;
    cin >> n;

    vector<int> nums(n);

    // Input array
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // Target sum
    cin >> k;

    cout << obj.countSubsequenceSum(nums, k);

    return 0;
}
