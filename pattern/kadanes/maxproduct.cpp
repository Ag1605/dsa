#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {

        // Maximum product ending at current index
        int maxpr = nums[0];

        // Minimum product ending at current index
        // (needed because a negative × negative = positive)
        int minpr = nums[0];

        // Stores the overall maximum product
        int ans = nums[0];

        // Traverse the array
        for (int i = 1; i < nums.size(); i++)
        {

            int curr = nums[i];

            // Calculate new maximum product
            int tempmax = max({curr,
                               maxpr * curr,
                               minpr * curr});

            // Calculate new minimum product
            int tempmin = min({curr,
                               maxpr * curr,
                               minpr * curr});

            // Update values
            maxpr = tempmax;
            minpr = tempmin;

            // Update final answer
            ans = max(ans, maxpr);
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
        cin >> nums[i];

    cout << obj.maxProduct(nums);

    return 0;
}