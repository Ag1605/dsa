
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    // Recursive function to check whether
    // a subsequence with sum K exists.
    //
    // index = Current array index
    // sum   = Sum of selected elements so far
    // k     = Required target sum
    // nums  = Input array

    bool solve(int index, int sum, int k, vector<int>& nums)
    {
        // Store the size of the array.
        int n = nums.size();

        // BASE CASE 1:
        // If current sum becomes equal to target,
        // we have found a valid subsequence.
        if (sum == k)
        {
            return true;
        }

        // BASE CASE 2:
        // If all elements have been processed
        // and target sum is not found,
        // no valid subsequence exists in this path.
        if (index == n)
        {
            return false;
        }

        // CHOICE 1: PICK
        //
        // Include the current element in the subsequence.
        // Move to the next index.
        // Add nums[index] to the current sum.
        bool pick = solve(
            index + 1,
            sum + nums[index],
            k,
            nums
        );

        // CHOICE 2: NOT PICK
        //
        // Skip the current element.
        // Move to the next index.
        // Current sum remains unchanged.
        bool notPick = solve(
            index + 1,
            sum,
            k,
            nums
        );

        // If either choice finds a valid subsequence,
        // return true.
        return pick || notPick;
    }


    // Main function to check subsequence sum.
    bool checkSubsequenceSum(vector<int>& nums, int k)
    {
        // Start from index 0.
        // Initially, selected sum is 0.
        return solve(0, 0, k, nums);
    }
};


int main()
{
    Solution obj;

    int n, k;

    // Input number of elements.
    cin >> n;

    vector<int> nums(n);

    // Input array elements.
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // Input target sum.
    cin >> k;

    // Check whether a valid subsequence exists.
    if (obj.checkSubsequenceSum(nums, k))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}
