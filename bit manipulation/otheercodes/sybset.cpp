#include <bits/stdc++.h>
using namespace std;

// Function to generate all subsets (Power Set)
vector<vector<int>> subsets(vector<int> &nums)
{
    // Number of elements in the array
    int n = nums.size();

    // Stores all subsets
    vector<vector<int>> ans;

    // Total number of subsets = 2^n
    // Example:
    // n = 3
    // totalSubsets = 8
    int totalSubsets = 1 << n;

    // Generate every possible subset
    // mask represents the binary representation of a subset
    for (int mask = 0; mask < totalSubsets; mask++)
    {
        // Stores the current subset
        vector<int> subset;

        // Check every bit of the current mask
        for (int i = 0; i < n; i++)
        {
            // If the i-th bit is set,
            // include nums[i] in the current subset.
            if (mask & (1 << i))
            {
                subset.push_back(nums[i]);
            }
        }

        // Store the current subset
        ans.push_back(subset);
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    // Input array
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<vector<int>> ans = subsets(nums);

    // Print all subsets
    for (auto subset : ans)
    {
        cout << "{ ";

        for (int num : subset)
        {
            cout << num << " ";
        }

        cout << "}" << endl;
    }

    return 0;
}