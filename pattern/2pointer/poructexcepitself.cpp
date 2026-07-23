#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {

        int n = nums.size();

        // Answer array
        vector<int> ans(n);

        // ---------------- Left Product ----------------
        // ans[i] stores the product of all elements
        // to the left of index i.
        ans[0] = 1;

        for (int i = 1; i < n; i++)
        {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        // ---------------- Right Product ----------------
        // 'right' stores the product of all elements
        // to the right of the current index.
        int right = 1;

        for (int i = n - 1; i >= 0; i--)
        {

            // Multiply left product with right product
            ans[i] *= right;

            // Update right product
            right *= nums[i];
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

    vector<int> ans = obj.productExceptSelf(nums);

    for (int x : ans)
        cout << x << " ";

    return 0;
}